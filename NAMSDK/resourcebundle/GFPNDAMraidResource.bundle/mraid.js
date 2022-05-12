(function() {
    var isIOS = (/iphone|ipad|ipod/i).test(window.navigator.userAgent.toLowerCase());
    if (isIOS) {
        console = {};
        console.log = function(log) {
            var iframe = document.createElement('iframe');
            iframe.setAttribute('src', 'mraid-log: ' + log);
            document.documentElement.appendChild(iframe);
            iframe.parentNode.removeChild(iframe);
            iframe = null;
        };
        console.debug = console.info = console.warn = console.error = console.log;
    }
  }());
  
  
  (function() {
    var mraid = window.mraid = {};
    window.MRAID_ENV = {
        version : '3.0',
        sdk: 'GFPSDK',
        sdkVersion: '2.0.0',
        appId: '' ,
        ifa:'',
        limitAdTracking: false,
        coppa:false
    };
  
    // Constants, Enums ////////////////////////////////////////////////////////////////////////////////////
  
    var STATES = mraid.STATES = {
        LOADING: 'loading',
        DEFAULT: 'default',
        EXPANDED: 'expanded',
        HIDDEN: 'hidden',
        RESIZED: 'resized'
    };
  
    var EVENTS = mraid.EVENTS = {
        ERROR: 'error',
        INFO: 'info',
        READY: 'ready',
        STATECHANGE: 'stateChange',
        VIEWABLECHANGE: 'viewableChange',
        SIZECHANGE: 'sizeChange',
        EXPOSURECHANGE: 'exposureChange',
        AUDIOVOLUMECHANGE: 'audioVolumeChange'
    };
  
    var PLACEMENT_TYPES = mraid.PLACEMENT_TYPES = {
        UNKNOWN: 'unknown',
        INLINE: 'inline',
        INTERSTITIAL: 'interstitial'
    };
  
    // Properties which define the behavior of an expandable ad.
    var expandProperties = {
        width: false,
        height: false,
        useCustomClose: false,
        isModal: true
    };
  
    // Properties which define the behavior of an resizable ad.
    var resizeProperties = {
        width: false,
        height: false,
        offsetX: false,
        offsetY: false,
        customClosePosition: 'top-right',
        allowOffscreen: true
    };
  
    var orientationProperties = {
        allowOrientationChange: true,
        forceOrientation: "none"
    };
  
    var currentAppOrientation = {
        orientation: "none",
        locked: false
    };
  
    var supportProperties = {
        sms: false,
        tel: false,
        calendar: false,
        storePicture: false,
        vpaid: false,
        inlineVideo: false
    };
  
    // default is undefined so that notifySizeChangeEvent can track changes
    var lastSizeChangeProperties;
  
    var maxSize = {};
  
    var currentPosition = {};
  
    var defaultPosition = {};
  
    var screenSize = {};
  
    var hasSetCustomClose = false;
  
    var listeners = {};
  
    // Internal MRAID state. Modified by the native SDK and this js on close. /////////////////////////////////////////////
    var state = STATES.LOADING;
  
    var isViewable = false;
  
    var placementType = PLACEMENT_TYPES.UNKNOWN;
  
    //////////////////////////////////////////////////////////////////////////////////////////////////
    // mediator interface to SDK
  
    var mediator = window.mraidmediator = {
        nativeSDKFiredReady: false,
        lastSizeChangeProperties: null
    };    
    var nativeCallQueue = [];
  
    function dequeue() {        
        window.location = nativeCallQueue.shift(); 
        if (nativeCallQueue.length > 0) setTimeout(dequeue, 0);
    }
  
    mediator.executeNativeCall = function(args) {
        var command = args.shift();
  
        if (!this.nativeSDKFiredReady) {
            console.log('rejecting ' + command + ' because mraid is not ready');
            mediator.notifyErrorEvent('mraid is not ready', command);
            return;
        }
  
        var call = 'mraid://' + command;
  
        var key, value;
        var isFirstArgument = true;
  
        for (var i = 0; i < args.length; i += 2) {
            key = args[i];
            value = args[i + 1];
  
            if (value === null) continue;
  
            if (isFirstArgument) {
                call += '?';
                isFirstArgument = false;
            } else {
                call += '&';
            }
  
            call += encodeURIComponent(key) + '=' + encodeURIComponent(value);
        }
        
  
        nativeCallQueue.push(call);
        if (nativeCallQueue.length == 1) setTimeout(dequeue, 0);                
    };
  
  
    mediator.setCurrentPosition = function(x, y, width, height) {
        currentPosition = {
            x: x,
            y: y,
            width: width,
            height: height
        };
        infoEvent('Set current position to ' + stringify(currentPosition));
    };
  
    mediator.setDefaultPosition = function(x, y, width, height) {
        defaultPosition = {
            x: x,
            y: y,
            width: width,
            height: height
        };
        infoEvent('Set default position to ' + stringify(defaultPosition));
    };
  
    mediator.setMaxSize = function(width, height) {
        maxSize = {
            width: width,
            height: height
        };
        infoEvent('Set max size to ' + stringify(maxSize));
    };
  
    mediator.setPlacementType = function(_placementType) {
        placementType = _placementType;
        console.log('placementtype : ' + placementType);
        infoEvent('Set placement type to ' + stringify(placementType));
    };
  
    mediator.setScreenSize = function(width, height) {
        screenSize = {
            width: width,
            height: height
        };
        infoEvent('Set screen size to ' + stringify(screenSize));
    };
  
    mediator.setIsViewable = function(_isViewable) {
        isViewable = _isViewable;
        infoEvent('Set isViewable to ' + stringify(isViewable));
        broadcastEvent(EVENTS.VIEWABLECHANGE, isViewable);
    };
  
    mediator.setSupports = function(sms, tel, calendar, storePicture, inlineVideo, vpaid, location) {
        supportProperties = {
            sms: sms,
            tel: tel,
            calendar: calendar,
            storePicture: storePicture,
            inlineVideo: inlineVideo,
            vpaid: vpaid,
            location: location
        };
    };
  
    mediator.setSupportsOne = function(feature, value) {
        supportProperties[feature] = value;
    }
  
    mediator.resetOrientationProperties = function() {
        orientationProperties.allowOrientationChange = true;
        orientationProperties.forceOrientation = "none";
    }
  
    mediator.notifyReadyEvent = function() {
        this.nativeSDKFiredReady = true;
        broadcastEvent(EVENTS.READY);
    };
  
    mediator.notifyErrorEvent = function(message, action) {
        broadcastEvent(EVENTS.ERROR, message, action);
    };
  
    // Temporary aliases while we migrate to the new API
    mediator.fireReadyEvent = mediator.notifyReadyEvent;
    mediator.fireErrorEvent = mediator.notifyErrorEvent;
  
    mediator.notifySizeChangeEvent = function(width, height) {
        if (this.lastSizeChangeProperties &&
            width == this.lastSizeChangeProperties.width && height == this.lastSizeChangeProperties.height) {
            return;
        }
  
        this.lastSizeChangeProperties = {
            width: width,
            height: height
        };
        if (state != STATES.LOADING) {
            broadcastEvent(EVENTS.SIZECHANGE, width, height);
        }
    };
  
  
    mediator.notifyStateChangeEvent = function(new_state) {
        if (state === new_state && state != STATES.RESIZED) return;
        infoEvent('Set state to ' + stringify(new_state));
        state = new_state;
        if (new_state === STATES.HIDDEN) {
            mediator.setIsViewable(false);
        }
        broadcastEvent(EVENTS.STATECHANGE, state);
    };
  
    mediator.notifyViewableChangeEvent = function() {
        infoEvent('Set isViewable to ' + stringify(isViewable));
        broadcastEvent(EVENTS.VIEWABLECHANGE, isViewable);
    };
  
    mediator.setCurrentAppOrientation = function(orientation,locked) {
        currentAppOrientation.orientation  = orientation;
        currentAppOrientation.locked  = locked;
        infoEvent('Set currentApp Orientation' + stringify(currentAppOrientation));
    }    
    
    mediator.exposureChangeEvent = function(exposureObject) {
        if (state === STATES.LOADING) return;
        broadcastEvent(EVENTS.EXPOSURECHANGE, exposureObject.exposedPercentage,exposureObject.visibleRectangle,exposureObject.occlusionRectangles);
    };

    mediator.setMRAIDEnv = function(newEnv){        
        window.MRAID_ENV.version = newEnv.version;
        window.MRAID_ENV.sdk = newEnv.sdk;
        window.MRAID_ENV.sdkVersion = newEnv.sdkVersion;
        window.MRAID_ENV.ifa = newEnv.ifa;
        window.MRAID_ENV.limitAdTracking = newEnv.limitAdTracking;
        window.MRAID_ENV.coppa = newEnv.coppa;
    };

    mediator.audioVolumeChange = function(volumePer){
        infoEvent('audio volume change : ' + stringify(volumePer));
        broadcastEvent(EVENTS.AUDIOVOLUMECHANGE, volumePer);
    };
  
    //////////////////////////////////////////////////////////////////////////////////////////////////
  
    var EventListeners = function(event) {
        this.event = event;
        this.count = 0;
        var listeners = {};
  
        this.add = function(func) {
            var id = String(func);
            if (!listeners[id]) {
                listeners[id] = func;
                this.count++;
            }
        };
  
        this.remove = function(func) {
            var id = String(func);
            if (listeners[id]) {
                listeners[id] = null;
                delete listeners[id];
                this.count--;
                return true;
            } else {
                return false;
            }
        };
  
        this.removeAll = function() {
            for (var id in listeners) {
                if (listeners.hasOwnProperty(id)) this.remove(listeners[id]);
            }
        };
  
        this.broadcast = function(args) {
            for (var id in listeners) {
                if (listeners.hasOwnProperty(id)) listeners[id].apply(mraid, args);
            }
        };
  
        this.toString = function() {
            var out = [event, ':'];
            for (var id in listeners) {
                if (listeners.hasOwnProperty(id)) out.push('|', id, '|');
            }
            return out.join('');
        };
    };
  
    var infoEvent = function(infostring) {
        broadcastEvent(EVENTS.INFO, infostring);
    }
  
    var errorEvent = function(errorstring) {
        console.log(errorstring);
        broadcastEvent(EVENTS.ERROR, errorstring);
    }
  
    var broadcastEvent = function() {
        var args = new Array(arguments.length);
        var l = arguments.length;
        for (var i = 0; i < l; i++) args[i] = arguments[i];
        var event = args.shift();
        if (listeners[event]) listeners[event].broadcast(args);
    };
  
    var contains = function(value, array) {
        for (var i in array) {
            if (array[i] === value) return true;
        }
        return false;
    };
    
    var stringify = function(obj) {
        if (typeof obj === 'object') {
            var out = [];
            if (obj.push) {
                // Array.
                for (var p in obj) out.push(obj[p]);
                return '[' + out.join(',') + ']';
            } else {
                // Other object.
                for (var p in obj) out.push("'" + p + "': " + obj[p]);
                return '{' + out.join(',') + '}';
            }
        } else return String(obj);
    };
  
    
    mraid.addEventListener = function(event, listener) {
        if (!event || !listener) {
            errorEvent('Both event and listener are required.', 'addEventListener');
        } else if (!contains(event, EVENTS)) {
            errorEvent('Unknown MRAID event: ' + event, 'addEventListener');
        } else {
            if (!listeners[event]) {
                listeners[event] = new EventListeners(event);
            }
            listeners[event].add(listener);
        }
    };
  
    mraid.close = function() {
                
        switch (this.getState()) {
            case STATES.LOADING:
                errorEvent("mraid.close() called while state is 'loading'.", "mraid.close");
                break;
            case STATES.DEFAULT:
                mediator.executeNativeCall(['close']);
                mediator.notifyStateChangeEvent(STATES.HIDDEN);                
                break;
            case STATES.EXPANDED:
                mediator.executeNativeCall(['close']);
                mediator.notifyStateChangeEvent(STATES.DEFAULT);
                break;
            case STATES.HIDDEN:
                errorEvent("mraid.close() called while ad was already hidden", "mraid.close");
                break;
            case STATES.RESIZED:
                mediator.executeNativeCall(['close']);
                mediator.notifyStateChangeEvent(STATES.DEFAULT);
                break;
        }
    };

    mraid.unload = function(){
        mediator.executeNativeCall(['unload']);
    };
  
    mraid.expand = function(URL) {
        console.log('expand' + this.getState());
        switch (this.getState()) {
            case STATES.DEFAULT:
            case STATES.RESIZED:
                if (placementType !== PLACEMENT_TYPES.INLINE) {
                    errorEvent('Ad can only be expanded only inline placement type', 'expand');
                    return;
                } else {
                    var args = ['expand', 'shouldUseCustomClose', expandProperties.useCustomClose];
                    if (URL) {
                        args = args.concat(['url', URL]);
                    }
                    mediator.executeNativeCall(args);
                }
                break;
  
            default:
                errorEvent('Ad can only be expanded from the default or resized state.', 'expand');
                break;
        }
    };
  
    mraid.getExpandProperties = function() {
        var properties = {
            width: expandProperties.width,
            height: expandProperties.height,
            useCustomClose: expandProperties.useCustomClose,
            isModal: expandProperties.isModal
        };
        return properties;
    };
  
  
    mraid.getCurrentPosition = function() {
        return {
            x: currentPosition.x,
            y: currentPosition.y,
            width: currentPosition.width,
            height: currentPosition.height
        };
    };
  
    mraid.getDefaultPosition = function() {
        return {
            x: defaultPosition.x,
            y: defaultPosition.y,
            width: defaultPosition.width,
            height: defaultPosition.height
        };
    };
  
    mraid.getMaxSize = function() {
        return {
            width: maxSize.width,
            height: maxSize.height
        };
    };
  
    mraid.getPlacementType = function() {
        return placementType;
    };
  
    mraid.getScreenSize = function() {
        return {
            width: screenSize.width,
            height: screenSize.height
        };
    };
  
    mraid.getState = function() {
        return state;
    };
  
    mraid.isViewable = function() {
        return isViewable;
    };
  
    mraid.getVersion = function() {
        return window.MRAID_ENV.version;
    };
  
    mraid.getCurrentAppOrientation = function() {
        return currentAppOrientation;
    }
  
    mraid.open = function(URI) {
        if (!URI) errorEvent('URI is required.', 'open');
        else mediator.executeNativeCall(['open', 'uri', URI]);
    };
  
    mraid.removeEventListener = function(event, listener) {
        if (!event) {
            errorEvent('Event is required.', 'removeEventListener');
            return;
        }
  
        if (listener) {
            // If we have a valid event, we'll try to remove the listener from it.
            var success = false;
            if (listeners[event]) {
                success = listeners[event].remove(listener);
            }
  
            // If we didn't have a valid event or couldn't remove the listener from the event, broadcast an error and return early.
            if (!success) {
                errorEvent('Listener not currently registered for event.', 'removeEventListener');
                return;
            }
  
        } else if (!listener && listeners[event]) {
            listeners[event].removeAll();
        }
  
        if (listeners[event] && listeners[event].count === 0) {
            listeners[event] = null;
            delete listeners[event];
        }
    };
  
    mraid.setExpandProperties = function(properties) {
        if (typeof properties === "undefined") {
            errorEvent("Invalid expandProperties. Retaining default values.", "mraid.setExpandProperties()");
            return;
        }
        if (!isNaN(properties.width)) {
            expandProperties.width = properties.width;
        }
        if (!isNaN(properties.height)) {
            expandProperties.height = properties.height;
        }
        if (typeof properties.useCustomClose === "boolean") {
            expandProperties.useCustomClose = properties.useCustomClose;
        }
    };
  
  
  
    mraid.useCustomClose = function(shouldUseCustomClose) {
        expandProperties.useCustomClose = shouldUseCustomClose;
        hasSetCustomClose = true;
        mediator.executeNativeCall(['usecustomclose', 'shouldUseCustomClose', shouldUseCustomClose]);
    };
  
    // MRAID 2.0 APIs ////////////////////////////////////////////////////////////////////////////////
  
    mraid.createCalendarEvent = function(parameters) {
        CalendarEventParser.initialize(parameters);
        if (CalendarEventParser.parse()) {
            mediator.executeNativeCall(CalendarEventParser.arguments);
        } else {
            errorEvent(CalendarEventParser.errors[0], 'createCalendarEvent');
        }
    };
  
    mraid.supports = function(feature) {
        return supportProperties[feature];
    };
  
    mraid.playVideo = function(uri) {
        if (!mraid.isViewable()) {
            errorEvent('playVideo cannot be called until the ad is viewable', 'playVideo');
            return;
        }
  
        if (!uri) {
            errorEvent('playVideo must be called with a valid URI', 'playVideo');
        } else {
            mediator.executeNativeCall(['playVideo', 'uri', uri]);
        }
    };
  
    mraid.storePicture = function(uri) {
        if (!mraid.isViewable()) {
            errorEvent('storePicture cannot be called until the ad is viewable', 'storePicture');
            return;
        }
  
        if (!uri) {
            errorEvent('storePicture must be called with a valid URI', 'storePicture');
        } else {
            mediator.executeNativeCall(['storePicture', 'uri', uri]);
        }
    };
  
  
    //50x50 close region spec
    var resizePropertyValidators = function(properties, callingFunctionName) {
        if (typeof properties === "undefined") {
            errorEvent("Invalid resizeProperties", callingFunctionName);
            return false;
        }
        if (isNaN(properties.width) || isNaN(properties.height) || isNaN(properties.offsetX) || isNaN(properties.offsetY)) {
            errorEvent("Incomplete resizeProperties. width, height, offsetX, offsetY required", callingFunctionName);
            return false;
        }
        if (properties.width < 50) {
            errorEvent("Resize properties width below the minimum 50 pixels", callingFunctionName);
            return false;
        }
        if (properties.height < 50) {
            errorEvent("Resize properties height below the minimum 50 pixels", callingFunctionName);
            return false;
        }
        return true;
    }
  
    mraid.setOrientationProperties = function(properties) {
  
        if (properties.hasOwnProperty('allowOrientationChange')) {
            orientationProperties.allowOrientationChange = properties.allowOrientationChange;
        }
  
        if (properties.hasOwnProperty('forceOrientation')) {
            orientationProperties.forceOrientation = properties.forceOrientation;
        }
  
        var args = ['setOrientationProperties',
            'allowOrientationChange', orientationProperties.allowOrientationChange,
            'forceOrientation', orientationProperties.forceOrientation
        ];
        mediator.executeNativeCall(args);
    };
  
    mraid.getOrientationProperties = function() {
        return {
            allowOrientationChange: orientationProperties.allowOrientationChange,
            forceOrientation: orientationProperties.forceOrientation
        };
    };
  
    mraid.resize = function() {
        if (!resizePropertyValidators(resizeProperties, "setResizeProperties")) {
            errorEvent("mraid.resize() called without properly setting setResizeProperties", "resize");
            return;
        }
  
        switch (this.getState()) {
            case STATES.DEFAULT:
            case STATES.RESIZED: {
                var args = ['resize',
                    'width', resizeProperties.width,
                    'height', resizeProperties.height,
                    'offsetX', resizeProperties.offsetX || 0,
                    'offsetY', resizeProperties.offsetY || 0,
                    'customClosePosition', resizeProperties.customClosePosition,
                    'allowOffscreen', !!resizeProperties.allowOffscreen
                ];
  
                mediator.executeNativeCall(args);
                break;
            }
            default:
                errorEvent('Ad can only be resized from the default or resized state.', 'resize');
                break;
        }
    };
  
    mraid.getResizeProperties = function() {
        var properties = {
            width: resizeProperties.width,
            height: resizeProperties.height,
            offsetX: resizeProperties.offsetX,
            offsetY: resizeProperties.offsetY,
            customClosePosition: resizeProperties.customClosePosition,
            allowOffscreen: resizeProperties.allowOffscreen
        };
        return properties;
    };
  
    mraid.setResizeProperties = function(properties) {
        if (resizePropertyValidators(properties, "setResizeProperties")) {
            if (typeof properties.customClosePosition === "undefined") {
                properties.customClosePosition = 'top-right';
            }
            if (typeof properties.allowOffscreen === "undefined") {
                properties.allowOffscreen = true;
            }
            resizeProperties = properties;
        }
    };
  
    mraid.getLocation = function() {
        var locationProperty = {
            lat: -1, 
            lon: -1
        };
        return locationProperty;
    };
    // Determining SDK version ///////////////////////////////////////////////////////////////////////
  
    mraid.getHostSDKVersion = function() {
        return window.MRAID_ENV.sdkVersion;
    };
  
    // Calendar helpers //////////////////////////////////////////////////////////////////////////////
  
    var CalendarEventParser = {
        initialize: function(parameters) {
            this.parameters = parameters;
            this.errors = [];
            this.arguments = ['createCalendarEvent'];
        },
  
        parse: function() {
            if (!this.parameters) {
                this.errors.push('The object passed to createCalendarEvent cannot be null.');
            } else {
                this.parseDescription();
                this.parseLocation();
                this.parseSummary();
                this.parseStartAndEndDates();
                this.parseReminder();
                this.parseRecurrence();
                this.parseTransparency();
            }
  
            var errorCount = this.errors.length;
            if (errorCount) {
                this.arguments.length = 0;
            }
  
            return (errorCount === 0);
        },
  
        parseDescription: function() {
            this._processStringValue('description');
        },
  
        parseLocation: function() {
            this._processStringValue('location');
        },
  
        parseSummary: function() {
            this._processStringValue('summary');
        },
  
        parseStartAndEndDates: function() {
            this._processDateValue('start');
            this._processDateValue('end');
        },
  
        parseReminder: function() {
            var reminder = this._getParameter('reminder');
            if (!reminder) {
                return;
            }
  
            if (reminder < 0) {
                this.arguments.push('relativeReminder');
                this.arguments.push(parseInt(reminder) / 1000);
            } else {
                this.arguments.push('absoluteReminder');
                this.arguments.push(reminder);
            }
  
        },
  
        parseRecurrence: function() {
            var recurrenceDict = this._getParameter('recurrence');
            if (!recurrenceDict) {
                return;
            }
  
            this.parseRecurrenceInterval(recurrenceDict);
            this.parseRecurrenceFrequency(recurrenceDict);
            this.parseRecurrenceEndDate(recurrenceDict);
            this.parseRecurrenceArrayValue(recurrenceDict, 'daysInWeek');
            this.parseRecurrenceArrayValue(recurrenceDict, 'daysInMonth');
            this.parseRecurrenceArrayValue(recurrenceDict, 'daysInYear');
            this.parseRecurrenceArrayValue(recurrenceDict, 'monthsInYear');
        },
  
        parseTransparency: function() {
            var validValues = ['opaque', 'transparent'];
  
            if (this.parameters.hasOwnProperty('transparency')) {
                var transparency = this.parameters.transparency;
                if (contains(transparency, validValues)) {
                    this.arguments.push('transparency');
                    this.arguments.push(transparency);
                } else {
                    this.errors.push('transparency must be opaque or transparent');
                }
            }
        },
  
        parseRecurrenceArrayValue: function(recurrenceDict, kind) {
            if (recurrenceDict.hasOwnProperty(kind)) {
                var array = recurrenceDict[kind];
                if (!array || !(array instanceof Array)) {
                    this.errors.push(kind + ' must be an array.');
                } else {
                    var arrayStr = array.join(',');
                    this.arguments.push(kind);
                    this.arguments.push(arrayStr);
                }
            }
        },
  
        parseRecurrenceInterval: function(recurrenceDict) {
            if (recurrenceDict.hasOwnProperty('interval')) {
                var interval = recurrenceDict.interval;
                if (!interval) {
                    this.errors.push('Recurrence interval cannot be null.');
                } else {
                    this.arguments.push('interval');
                    this.arguments.push(interval);
                }
            } else {
                // If a recurrence rule was specified without an interval, use a default value of 1.
                this.arguments.push('interval');
                this.arguments.push(1);
            }
        },
  
        parseRecurrenceFrequency: function(recurrenceDict) {
            if (recurrenceDict.hasOwnProperty('frequency')) {
                var frequency = recurrenceDict.frequency;
                var validFrequencies = ['daily', 'weekly', 'monthly', 'yearly'];
                if (contains(frequency, validFrequencies)) {
                    this.arguments.push('frequency');
                    this.arguments.push(frequency);
                } else {
                    this.errors.push('Recurrence frequency must be one of: "daily", "weekly", "monthly", "yearly".');
                }
            }
        },
  
        parseRecurrenceEndDate: function(recurrenceDict) {
            var expires = recurrenceDict.expires;
  
            if (!expires) {
                return;
            }
  
            this.arguments.push('expires');
            this.arguments.push(expires);
        },
  
        _getParameter: function(key) {
            if (this.parameters.hasOwnProperty(key)) {
                return this.parameters[key];
            }
  
            return null;
        },
  
        _processStringValue: function(kind) {
            if (this.parameters.hasOwnProperty(kind)) {
                var value = this.parameters[kind];
                this.arguments.push(kind);
                this.arguments.push(value);
            }
        },
  
        _processDateValue: function(kind) {
            if (this.parameters.hasOwnProperty(kind)) {
                var dateString = this._getParameter(kind);
                this.arguments.push(kind);
                this.arguments.push(dateString);
            }
        }
    };
  
  
  }());
  
