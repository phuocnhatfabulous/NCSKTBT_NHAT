//Header file
#include<iostream>
#include<string>

using namespace std;
class Info{
protected:
    string Name, ID, Age, Course;
public:
    Info(){// Default constructor
        Name = "";
        ID = "6051071000";
        Age = "18";
        Course = "";
    }
    Info(string N, string I, string A, string C){// Parameterized constructor
        N = Name;
        I = ID;
        A = Age;
        C = Course;
    }
    ~Info(){} // Deconstructor
    virtual void In();
    virtual void Out();
};
// K61
class K61 : protected Info{
protected:
    string Name, ID, Age, Course;
public:
    K61(); // Default constructor
    K61(string N, int I, int A, int C); // Parameterized constructor
    void In();
    void Out();
};
//K60
class K60 : protected Info{
protected:
    string Name, ID, Age, Course;
public:
    K60(); // Default constructor
    K60(string N, int I, int A, int C); // Parameterized constructor
    void In();
    void Out();
};
//K59
class K59 : protected Info{
protected:
    string Name, ID, Age, Course;
public:
    K59(); // Default constructor
    K59(string N, int I, int A, int C); // Parameterized constructor
    void In();
    void Out();
};
//K58
class K58 : protected Info{
protected:
    string Name, ID, Age, Course;
public:
    K58(); // Default constructor
    K58(string N, int I, int A, int C); // Parameterized constructor
    void In();
    void Out();
};
