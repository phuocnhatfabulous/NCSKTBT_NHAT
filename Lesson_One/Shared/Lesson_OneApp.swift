//
//  Lesson_OneApp.swift
//  Shared
//
//  Created by Phước Nhật on 15/11/2020.
//

import SwiftUI

@main
struct Lesson_OneApp: App {
    var body: some Scene {
        DocumentGroup(newDocument: Lesson_OneDocument()) { file in
            ContentView(document: file.$document)
        }
    }
}
