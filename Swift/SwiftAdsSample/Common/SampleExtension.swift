//
//  SampleExtension.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import UIKit

//MARK: - BundleExtension

extension Bundle {
    
    static var currentVersion : String {
        return self.main.infoDictionary?["CFBundleShortVersionString"] as? String ?? ""
    }
    
    static var buildVersion : String {
        return self.main.infoDictionary?["CFBundleVersion"] as? String ?? ""
    }
}

//MARK: - CalendarExtension

extension Calendar {
    
    static var currentYear : Int {
        return Calendar.current.component(Calendar.Component.year, from: Date())
    }
    
}

//MARK: - LocaleExtension

extension Locale {
    
    static var countryCode : String {
        return Locale.current.regionCode ?? ""
    }
    
}


//MARK: - UIExtension

extension UIApplication {
    
    static var isStatusBarLandscape : Bool {
        get {
            return UIApplication.shared.statusBarOrientation.isLandscape
        }
    }
    
}

extension UITableView {
    
    func register<T: UITableViewCell> (_ :T.Type) where T: NibLoadable {
        self.register(T.self, forCellReuseIdentifier: T.nibId)
    }
    
    func registerNib<T: UITableViewCell> (_ :T.Type) where T : NibLoadable {
        let nib = UINib(nibName: T.nibId, bundle: nil)
        self.register(nib, forCellReuseIdentifier: T.nibId)
    }
    
    func registerHeaderView<T: UITableViewHeaderFooterView> (_ :T.Type) where T: NibLoadable {
        self.register(T.self, forHeaderFooterViewReuseIdentifier: T.nibId)
    }
    
    func registerHeaderViewNib<T: UIView> (_ :T.Type) where T: NibLoadable {
        let nib = UINib(nibName: T.nibId, bundle: nil)
        self.register(nib, forHeaderFooterViewReuseIdentifier: T.nibId)
    }

    
    func dequeReusableCell<T: UITableViewCell> (_ :T.Type, for indexPath: IndexPath) -> T where T : NibLoadable {
        guard let cell = self.dequeueReusableCell(withIdentifier: T.nibId, for: indexPath) as? T else {
            fatalError("Count not find \(T.nibId)")
        }
        
        return cell
    }
    
}

extension UIButton {
    
    static var reloadButton: UIButton {
        let button = UIButton.init(frame: CGRect.zero)
        button.setTitle("Reload", for: .normal)
        button.setTitleColor(UIColor.black, for: .normal)
        button.updateSize(size: CGSize.init(width: 70, height: 60))
        return button
    }
    
}

extension UIView {
    
    //MARK: - Enum
    
    enum SizeType : Int {
        case height
        case width
    }
    
    enum ViewAlignment {
        case left
        case top
        case right
        case bottom
    }

    enum ViewConrner {
        case leftBottom
        case rightBottom
    }

    enum ViewCenterAligment {
        case horizontalCenter
        case verticalCenter
    }
    
    //MARK: - Computed Property
    
    var topSafeInsets : CGFloat {
        get {
            if #available(iOS 11.0, *) {
                return self.safeAreaInsets.top
            } else {
                return 0.0
            }
        }
    }
    
    var topBottomSafeAreaInsets : CGFloat {
        get {
            if #available(iOS 11.0, *) {
                return self.topSafeInsets - self.safeAreaInsets.bottom
            } else {
                return 0.0
            }
        }
    }
    
    var leftSafeInsets : CGFloat {
        get {
            if #available(iOS 11.0, *) {
                return self.safeAreaInsets.left
            } else {
                return 0.0
            }
        }
    }
    
    var rightSafeInsets : CGFloat {
        get {
            if #available(iOS 11.0, *) {
                return self.safeAreaInsets.right
            } else {
                return 0.0
            }
        }
    }
    
    var sideSafeAreaInsets : CGFloat {
        return self.leftSafeInsets + self.rightSafeInsets
    }
    

    //MARK: - Instance Method
    
    func updateSize(size : CGSize) {
        var currentRect = self.frame
        currentRect.size = size
        self.frame = currentRect
    }
    
    func updateSize(type : SizeType, value : CGFloat) {
        var currentRect = self.frame
        
        if type == .height {
            currentRect.size.height = value
        } else {
            currentRect.size.width = value
        }
        
        self.frame = currentRect
    }
    
    func updateOrigin(origin : CGPoint) {
        var currentRect = self.frame
        currentRect.origin = origin
        self.frame = currentRect
    }
    
    func showDebugBorder(withColor color: UIColor) {
        self.layer.borderColor = color.cgColor
        self.layer.borderWidth = 1.0
    }
    
    func move(to: ViewAlignment, margin: CGFloat = 0) {
        guard let superView = self.superview else {
            return
        }

        switch to {
        case .left:
            self.frame.origin.x = superView.bounds.origin.x + margin
        case .top:
            self.frame.origin.y = margin
        case .right:
            self.frame.origin.x = superView.bounds.size.width - self.frame.size.width - margin
        case .bottom:
            self.frame.origin.y = superView.bounds.origin.y + superView.bounds.size.height - self.frame.size.height - margin
        }
    }

    func move(to: ViewConrner, margin: CGSize = CGSize.zero) {
        switch to {
        case .leftBottom:
            self.move(to: .left, margin: margin.width)
            self.move(to: .bottom, margin: margin.height)
        case .rightBottom:
            self.move(to: .right, margin: margin.width)
            self.move(to: .bottom, margin: margin.height)
        }
    }

    func move(to: ViewCenterAligment) {
        guard let superView = self.superview else {
            return
        }

        switch to {
        case .horizontalCenter:
            self.frame.origin.x = floor((superView.bounds.size.width - self.bounds.size.width) / 2.0)
        case .verticalCenter:
            self.frame.origin.y = floor((superView.bounds.size.height - self.bounds.size.height) / 2.0)
        }
    }

    func move(to: ViewAlignment, of view: UIView, gap: CGFloat = 0) {
        switch to {
        case .left:
            self.frame.origin.x = view.frame.minX - gap - self.frame.size.width
        case .top:
            self.frame.origin.y = view.frame.minY - gap - self.frame.size.height
        case .right:
            self.frame.origin.x = view.frame.maxX + gap
        case .bottom:
            self.frame.origin.y = view.frame.maxY + gap
        }
    }
    
    //MARK: - Class Method
    
    class func instantiateFromNib<T: UIView>(_ type: T.Type) -> T where T: NibLoadable {
        if let bundle = Bundle.main.loadNibNamed(T.nibId, owner: self, options: Dictionary()),
            let view = bundle.first as? T {
            return view
        }
        
        fatalError("Could not find View \(T.nibId)")
    }
    
    // TODO: - 이건 이렇게 처리하면 안된다.
    static func loadView(name : String) -> UIView? {
        return Bundle.main.loadNibNamed(name, owner: nil, options: nil)?.first as? UIView
    }
    
}

extension UIViewController {
    
    var gap: CGFloat {
        return UIApplication.isStatusBarLandscape ? 20.0 + self.view.leftSafeInsets : 20.0
    }
    
    
}


