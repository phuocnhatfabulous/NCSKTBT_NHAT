#include<iostream>
#include<string>
#include<vector>
#include"Header.h"

using namespace std;
// General infomation

//General information
Info::In(){
 //   strcpy_s ;
    cout << "Enter your full name: " << endl;
    getline(cin,Name);
    if (Name.empty()){
        cout << "Enter your full name, please: " << endl;
        getline(cin,Name);
    }
    cout << "Enter your age: " << endl;
    cin >> Age;
    
    
    
}
int main (){
    
    
}
