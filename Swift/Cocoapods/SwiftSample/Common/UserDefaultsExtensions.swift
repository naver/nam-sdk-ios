//
//  UserDefaultExtensions.swift
//
//  NAM(Naver Ad Manager) SDK for iOS
//  Copyright 2022-present NAVER Corp.
//  Unauthorized use, modification and redistribution of this software are strongly prohibited.
//

import Foundation
import GFPSDK

@propertyWrapper
struct Persisted<Value: Codable> {

    var key: String

    var defaultValue: Value

    var isValueType: Bool { Mirror(reflecting: defaultValue).displayStyle == nil }

    var wrappedValue: Value {
        get {
            if isValueType {
                return UserDefaults.standard.load(forKey: key) ?? defaultValue
            } else {
                guard let encoded = UserDefaults.standard.object(forKey: key) as? Data else { return defaultValue }
                let decoder = JSONDecoder()
                let decoded = try? decoder.decode(Value.self, from: encoded)
                return decoded ?? defaultValue
            }
        }
        set {
            if isValueType {
                UserDefaults.standard.persist(newValue, forKey: key)
            } else {
                let encoder = JSONEncoder()
                if let encoded = try? encoder.encode(newValue) {
                    let defaults = UserDefaults.standard
                    defaults.set(encoded, forKey: key)
                }
            }
        }
    }
}

@propertyWrapper
struct PersistedProviderSetting<Value: GFPAdProviderSetting> {

    var key: String

    var defaultValue: Value

    var wrappedValue: Value {
        get {
            UserDefaults.standard.loadProviderSetting(forKey: key) as? Value ?? defaultValue
        }
        set {
            UserDefaults.standard.persistProviderSetting(newValue, forKey: key)
        }
    }
}

extension UserDefaults {

    func persist<T>(_ value: T?, forKey key: String) {
        self.set(value, forKey: key)
    }

    func load<T>(forKey key: String) -> T? {
        guard let value = self.object(forKey: key) as? T else {return nil}
        return value
    }


    func persistProviderSetting(_ value: GFPAdProviderSetting?, forKey key: String) {
        self.persist(value?.type.rawValue ?? nil, forKey: key+".type")
        self.persist(value?.isTestMode ?? nil, forKey: key+".isTestMode")
    }

    func loadProviderSetting(forKey key: String) -> GFPAdProviderSetting? {
        guard let rawValue: Int = self.load(forKey: key+".type") else {return nil}
        let type: GFPAdProviderSettingType = .init(rawValue: rawValue)
        guard let isTestMode: Bool = self.load(forKey: key+".isTestMode")  else { return nil }

        return GFPAdProviderSetting.type(type, testMode: isTestMode)
    }

}
