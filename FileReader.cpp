#include<iostream>
//fstream header file to ifstream, ofstream,fstream classes
#include<fstream>
using namespace std;
//Driver code
int main(){
    //Creation of fstream class object
    fstream fio;
    string line;
    fio.open("./src/Baitapchepcode/sample.txt", ios::trunc |ios::out|ios::in);
//    Execute a loop If file successfully Opened
    while(fio){
//        Read a line from standard input
        getline(cin, line);
//        Press -1 to exit
        if(line=="-1")
            break;
//        Write line in file
        fio<<line<<endl;
    }
//    Execute a loop untill EOF(end of line
//    point read pointer at beginning of file
    fio.seekg(0, ios::beg);
    while(fio){
//        Read a line from File
        getline(fio, line);
//        print line in console
        cout<<line<<endl;
    }
//    Close the file
    fio.close();
    return 0;
}
