#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;
//General information
class Info{
protected:
    string Name, ID, Age, Course;
public:
    Info();
    Info(string N, string I, string A, string C);
    ~Info();
    
    virtual void Input();
    virtual void Output();
};
Info::Info(){
    Name = "";
    ID = "";
    Age = "";
    Course = "";
}
Info::Info(string N, string I, string A, string C){// Parameterized constructor
        N = Name;
        I = ID;
        A = Age;
        C = Course;
}
Info::~Info(){} // Deconstructor
void Info::Input(){
    do{
            cout << "Enter your full name, please: " << endl;
            getline(cin,Name);
    }while(Name.empty());
    do{
            cout << "Enter your age, please: " << endl;
            getline(cin,Age);
    }while(Age.empty());
    do{
            cout << "Enter your identification, please: " << endl;
            getline(cin,ID);
    }while(ID.empty());
    do{
            cout << "Enter your course, please: " << endl;
            getline(cin,Course);
    }while(Course.empty());
}
void Info::Output(){
    cout << "Information of student: " << "Name is: " << Name << "\t; " << "Age" << Age << "\t; " << "ID: " << ID << "\t; " << "Course: " << Course << endl;
}
// Class point of students
class Point{
private:
//    vector<Subject> subject;
public:
};
// K61
class K61 : public Info{
protected:
    string Name, ID, Age, Course;
public:
    K61(); // Default constructor
    K61(string N, string I, string A, string C); // Parameterized constructor
    void Input();
    void Output();
};
//K60
class K60 : public Info{
protected:
    string Name, ID, Age, Course;
public:
    K60(); // Default constructor
    K60(string N, string I, string A, string C); // Parameterized constructor
    void Input();
    void Output();
};
//K59
class K59 : public Info{
protected:
    string Name, ID, Age, Course;
public:
    K59(); // Default constructor
    K59(string N, string I, string A, string C); // Parameterized constructor
    void Input();
    void Output();
};
//K58
class K58 : public Info{
protected:
    string Name, ID, Age, Course;
public:
    K58(); // Default constructor
    K58(string N, string I, string A, string C); // Parameterized constructor
    void Input();
    void Output();
};
int main(){
    Info a;
    a.Input();
    a.Output();
    return 0;
}
