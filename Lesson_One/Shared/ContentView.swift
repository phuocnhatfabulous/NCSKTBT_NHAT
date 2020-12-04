//
//  ContentView.swift
//  Shared
//
//  Created by Phước Nhật on 15/11/2020.
//

import SwiftUI

struct ContentView: View {
    @Binding var document: Lesson_OneDocument

    var body: some View {
        TextEditor(text: $document.text)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView(document: .constant(Lesson_OneDocument()))
    }
}
