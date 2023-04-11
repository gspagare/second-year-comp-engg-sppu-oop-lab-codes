//Name - Venkatesh Shamsundar Soni
//Class - SE Computer B
//Roll - 20CO136


/*
Problem Statement - Develop an object oriented program in C++ to create a database of student 
                    information system containing the following information: Name, Roll 
                    number, Class, division, Date of Birth, Blood group, Contact address, 
                    telephone number, driving license no. etc Construct the database with 
                    suitable member functions for initializing and destroying the data viz 
                    constructor, default constructor, Copy constructor, destructor, static member 
                    functions, friend class, this pointer, inline code and dynamic memory 
                    allocation operators-new and deletE
*/

#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class personal_info
{
    char address[20], license[20], insurance[20];
    long int contact;

    public:
    personal_info() //Default constructor
    {
        strcpy(address, "XYZ");
        strcpy(license, "XY-0000000000");
        strcpy(insurance, "XY00000000X");
        contact = 000000000;
    }

    ~personal_info() //Destructor
    {
        cout << "I am Destructor";
    }

    friend class person; //Declaring Friend class
};

class person //Defining Friend Class
{
    char name[20], date_of_birth[10], blood_group[10];
    float height, weight;
    static int count;
    personal_info *pi;

    public:
    person() {
        strcpy(name, "XYZ");
        strcpy(date_of_birth, "dd/mm/yy");
        strcpy(blood_group, "A+");
        height = 0;
        weight = 0;
        pi = new personal_info;
    }
    person(person *p1) /*copy Constructor*/ {
        strcpy(name, p1 -> name);
        strcpy(date_of_birth, p1 -> date_of_birth);
        strcpy(blood_group, p1 -> blood_group);
        height = p1 -> height;
        weight = p1 -> weight;
        pi = new personal_info;
        strcpy(pi -> address, p1 -> pi -> address);
        strcpy(pi -> license, p1 -> pi -> license);
        strcpy(pi -> insurance, p1 -> pi -> insurance);
        pi -> contact = p1 -> pi -> contact;
    }
    static void show_count() /*Static member function*/ {
        cout << "\nNumber of records count = " << count << "\n";
    }
    ~person() /*Destructor*/ {
        cout << "\nI am in Destructor\n";
    }
    void get_data(char name[20]);
    inline void display(); //Inline function declaration

};

void person::get_data(char name[20]) {
    strcpy(this -> name, name); //This pointer
    cout << "\nEnter date of birth: ";
    cin >> date_of_birth;
    cout << "\nEnter blood group: ";
    cin >> blood_group;
    cout << "\nEnter height: ";
    cin >> height;
    cout << "\nEnter weight: ";
    cin >> weight;
    cout << "\nEnter address: ";
    cin >> pi -> address;
    cout << "\nEnter license number: ";
    cin >> pi -> license;
    cout << "\nEnter Insurance Policy number: ";
    cin >> pi -> insurance;
    cout << "\nEnter contact number: ";
    cin >> pi -> contact;
    count++;
}

void person::display() /*inline function definition*/ 
{
    cout <<"\t" << name;
    cout <<"\t" << date_of_birth;
    cout <<"\t" << blood_group;
    cout <<"\t" << height;
    cout <<"\t" << weight;
    cout <<"\t" << pi -> address;
    cout <<"\t" << pi -> license;
    cout <<"\t" << pi -> insurance;
    cout <<"\t" << pi -> contact;
}

int person::count; //Static variable definition

int main() //main function
{
    person *p1, *p2;
    int ch;
    p1 = new person; //calling default constructor and dynamic memory allocation
    p2 = new person(p1); //calling copy constructor
    cout << "\tName";
    cout << "\tDate of birth";
    cout << "\tBlood group";
    cout << "\tHeight";
    cout << "\tWeight";
    cout << "\tAddress";
    cout << "\tLicense";
    cout << "\tInsurance";
    cout << "\tContact number";
    cout << endl;
    cout << "Default constructor value \n";
    p1 -> display();
    cout << "\n";
    cout << "Copy constructor value \n";
    p2 -> display();
    cout << "\nHow many records do you want?\n";
    int number_of_records;
    cin >> number_of_records;
    person p3[number_of_records]; //array of object
    char name[20];
    int x=0;
    
    do {
        cout << "\nWelcome to Personal Database System";
        cout << "\n1.Enter the record";
        cout << "\n2.Display the record";
        cout << "\n3.Exit";
        cin >> ch;
        switch(ch) {
            case 1:
            {
                cout << "\nEnter the name ";
                cin >> name;
                p3[x].get_data(name);
                person::show_count(); //calls static function
                x++;
            break;
            }
            case 2:
            {
                cout << "\tName ";
                cout << "\tDate of birth ";
                cout << "\tBlood group ";
                cout << "\tHeight ";
                cout << "\tWeight ";
                cout << "\tAddress ";
                cout << "\tLicense Number ";
                cout << "\tInsurance Policy Number ";
                cout << "\tContact Number ";
                for(int i{0}; i < number_of_records; i++)
                {
                    cout << "\n";
                    p3[i].display(); //Calls inline function
                }
            break;
            }
        }
    } while(ch!=3);
    //dynamic memory de-allocation
    delete p1; 
    delete p2;
    return 0;
}