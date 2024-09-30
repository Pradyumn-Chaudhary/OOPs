#include<iostream>
#include<string>
using namespace std;

void fun();

class Teacher {
//non-parameterized constructor
public:
Teacher(){
    cout << "HI,I AM CONSTRUCTOR" << endl;
}
private:
    double salary;
public:
    //properties
    string name;
    string department;
    string subject;
    

    //method
    void change_department(string newDepartment){
        department = newDepartment;
    }

    //setter
    void setSalary(double s){
        salary = s;
    }

    //getter
    double getSalary(){
        return salary;
    }
};

class Account {
//Parameterized constructor
public:
    Account(double bal,string ps, string acc, string n)
    {
        balance = bal;
        pass = ps;
        accountId = acc;
        name = n;
    }

private:
    double balance;
    string pass;  //data hiding

public:
    string accountId;
    string name;

    double getBal(){
        return balance;
    }
};

class Student{
public:
string name;
double* cgpaPtr;

Student(string name,double cgpa){
    this->name = name;
    cgpaPtr = new double;
    *cgpaPtr = cgpa;
}

Student(Student &obj){
    this->name = obj.name;
   // this->cgpaPtr = obj.cgpaPtr; // Shallow Copy
    cgpaPtr = new double;
    *this->cgpaPtr = *obj.cgpaPtr; // Deep Copy
}

//Destructor
~Student(){
    cout << "HI,I AM DESTRUCTOR" << endl;
    delete cgpaPtr;
}
};

class Person{
public:
    string name;
    int age;

    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
};

class UG_Student : public Person{
    public:
    UG_Student(string name,int age,int rollNo):Person(name,age){
        this->name = name;
        this->age = age;
        this->rollNo = rollNo;
    }
        int rollNo;

    void getInfo(){
        cout << name << "\n"
             << age << "\n"
             << rollNo << endl;
    }
};

class PG_Student:public UG_Student{
public:
PG_Student(string name,int age,int rollNo,string researchArea):UG_Student(name,age,rollNo){
    this->name = name;
    this->age = age;
    this->rollNo = rollNo;
    this->researchArea = researchArea;
}
string researchArea;

void getStudentInfo(){
    cout << name << "\n"
         << age << "\n"
         << rollNo << "\n"
         << researchArea << endl;
}
};

class Shape{ //abstract class
    virtual void draw() = 0; // pure virtual class
};

class Circle:public Shape{
    public:
    void draw(){
        cout << "Drawing a Circle" << endl;
    }
};

int main(){
    Teacher t1; //constructor call
    t1.name = "Shradha Khapra";
    t1.department = "CSE";
    t1.subject = "OOPs";
    t1.setSalary(50000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    Account A1(6000,"0000","hifs", "Shradha");
    cout << A1.getBal() << endl;

    Student S1("Neha",9.2);
    Student S2(S1);
    *S2.cgpaPtr = 8.9;
    cout << S1.name << endl;
    cout << *S1.cgpaPtr << endl;

    UG_Student U1("Rahul", 20, 27);
    U1.getInfo();

    PG_Student P1("Tejaswini", 22, 1432, "AI & ML");
    P1.getInfo();
    P1.getStudentInfo();

    Circle C1;
    C1.draw();

    fun();
    fun();
    fun();

    return 0;
}

void fun(){
    static int x = 0;
    cout << "x = " << x++ << endl;

}