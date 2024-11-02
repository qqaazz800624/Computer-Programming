#include <iostream>

using namespace std;

class Person {
    public:
        void inputPerson(){
            char str[128];
            cout << "Enter personal data: " << endl;
            cout << "Name: ";
            fflush(stdin);
            cin.getline(str, 128);
            Name = str;
            cout << "Phone: ";
            cin >> Phone;
            cout << "Email: ";
            cin >> Email;
        }

        void outputPerson(){
            cout << "Print personal data: " << endl;
            cout << "Name: " << Name << endl;
            cout << "Phone: " << Phone << endl;
            cout << "Email: " << Email << endl;
        }

    //private:
    protected:
        string Name;
        string Phone;
        string Email;
};

class Student: public Person{
    public:
        void inputStudent(){
            cout << "Enter student data: " << endl;
            //inputPerson();
            cin >> Name;  // Name is protected in Person class
            cout << "Student ID: ";
            cin >> StudentID;
            cout << "Department: ";
            cin >> Department;
        }

        void outputStudent(){
            cout << "Print student data: " << endl;
            outputPerson();
            cout << "Student ID: " << StudentID << endl;
            cout << "Department: " << Department << endl;
        }

    private:
        string StudentID;
        string Department;
};

class Teacher: public Person{
    public:
        void inputTeacher(){
            cout << "Enter teacher data: " << endl;
            inputPerson();
            cout << "Title: ";
            cin >> Title;
            cout << "Department: ";
            cin >> Department;
        }

        void outputTeacher(){
            cout << "Print teacher data: " << endl;
            outputPerson();
            cout << "Title: " << Title << endl;
            cout << "Department: " << Department << endl;
        }

    private:
        string Title;
        string Department;
};

int main(){

    Person p1;
    Student s1;
    Teacher t1;
    //s1.inputPerson();
    s1.inputStudent();
    cout << endl;
    //s1.outputPerson();
    s1.outputStudent();
    cout << endl;
    //t1.inputPerson();
    t1.inputTeacher();
    cout << endl;
    //t1.outputPerson();
    t1.outputTeacher();


    return 0;
}