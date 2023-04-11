//Name - Venkatesh Shamsundar Soni
//Class - SE Computer B
//Roll - 20CO136


/*
Problem Statement - Imagine a publishing company which does marketing for book and audio
                    cassette versions. Create a class publication that stores the title
                    (a string) and price(type float) of publications. From this class 
                    derive two classes: book which adds a page count(type int) and tape 
                    which adds a playing time in minutes(type float).
                    Write a program that instantiates tbhe book and tape class, allows 
                    user to enter data and displays the data members. If an exception is 
                    caught, replace all the data member values with zero values.
*/


# include<iostream>
# include<stdio.h>
using namespace std;

class publication                 /*declaring class Publication*/ {
    private:
        string title;
        float price;
    public:
        void add() {
            cout << "\nEnter the Publication information : " << endl;
            cout << "Enter Title of the Publication : ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Price of Publication : ";
            cin >> price;
            }
        void display()  {
            cout << "\n--------------------------------------------------";
            cout << "\nTitle of Publication : " << title;
            cout << "\nPublication Price : " << price;
            }
};

class book : public publication  /*declaring class book which inherits class publication in public mode.*/{
    private:
        int page_count;
    public:
        void add_book() {
            try
            {
                add();
                cout << "Enter Page Count of Book : ";
                cin >> page_count;
                if (page_count <= 0)
                {
                    throw page_count;
                }
            }
            catch(...)  {
                cout << "\nInvalid Page Count!!!";
                page_count = 0;
                }
            }
            void display_book()     {
                display();
                cout << "\nPage Count : " << page_count;
                cout << "\n--------------------------------------------------\n";
                }
 };
 
class tape : public publication     /*declaring class tape which inherits class publication in public mode*/ {
    private:
        float play_time;
    public:
        void add_tape() {
            try {
                add();
                cout << "Enter Play Duration of the Tape : ";
                cin >> play_time;
                if (play_time <= 0)
                throw play_time;
                }
            catch(...) {
                cout << "\nInvalid Play Time!!!";
                play_time = 0;
                }
        }
        void display_tape() {
                display();
                cout << "\nPlay Time : " <<
                play_time << " min";
                cout << "\n--------------------------------------------------\n";
        }
 };

int main()  {
    book book1[10];            // object of class book
    tape tape1[10];            // object of class tape
    int ch, b_count = 0, t_count = 0;
    do  {
        cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Add Information to Books";
        cout << "\n2. Add Information to Tapes";
        cout << "\n3. Display Books Information";
        cout << "\n4. Display Tapes Information";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ch;
        switch(ch)  {
            case 1:
            book1[b_count].add_book();
            b_count++;
            break;
            case 2:
            tape1[t_count].add_tape();
            t_count++;
            break;
            case 3:
            cout << "\n* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *";
            for (int j=0;j < b_count;j++)   {
                book1[j].display_book();
            }
            break;
            case 4:
            cout << "\n* * * * TAPE PUBLICATION DATABASE SYSTEM * * * *";
            for (int j=0;j < t_count;j++)   {
                tape1[j].display_tape();
            }
            break;
            case 5:
            exit(0);
            }
    }while (ch != 5);

return 0;
}