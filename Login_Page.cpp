#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int c;
    cout << "\t\t\t___________________________________________________________\n\n\n";
    cout << "\t\t\t				Welcome to Login Page						  \n\n\n";
    cout << "\t\t\t__________________________Menu_____________________________\n\n\n";
    cout << "																  \n\n\n";
    cout << "\t| Press 1 to Login								|\n";
    cout << "\t| Press 2 to Register							|\n";
    cout << "\t| Press 3 if You Forgot Your Password			|\n";
    cout << "\t| Press 4 to Exit								|\n";
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;

    switch (c) {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout << "\t\t\t Thank you!\n\n\n";
            break;

        default:
            cout << "\t\t\t Please select from the options given above\n\n";
            main();
    }

    return 0;
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password :\n";
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1) {
        cout << userId << "\n Your LOGIN is successful.\n Thanks for logging in!\n";
        main();
    } else {
        cout << "Invalid username or password. Please try again.\n";
        main();
    }
}

void registration() {
    string ruserId, rpassword;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();

    system("cls");
    cout << "\n\t\t\t Registration is successful!\n";
    main();
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries.\n";
    cout << "Press 1 to search your id by username.\n";
    cout << "Press 2 to go back to the main menu.\n";
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sid, spass;
            cout << "\n\t\t\t Enter the username which you remembered: ";
            cin >> suserId;

            ifstream f2("records.txt");
            while (f2 >> sid >> spass) {
                if (sid == suserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();

            if (count == 1) {
                cout << "\n\n Your account is found.\n";
                cout << "\n Your Password is: \n" << spass << endl;
                main();
            } else {
                cout << "\n\t Sorry, your account is not found!\n";
                main();
            }
            break;
        }

        case 2:
            main();
            break;

        default:
            cout << "\t\t\t Wrong Choice! Please try again.\n";
            forgot();
            break;
    }
}

