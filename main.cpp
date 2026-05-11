#include "admin.h"
#include "customer.h"
#include "adminSession.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
using namespace std;

void adminLogin() {
    int    password;
    string id;
    system("cls"); system("color 57");
    cout << "id       : "; cin >> id;
    cout << "password : "; cin >> password;

    // Singleton pattern: get the one and only AdminSession instance
    AdminSession& session = AdminSession::getInstance();

    if (!session.login(id, password)) {
        cout << "[Login Error] Incorrect password or session already active.\n";
        cout << "\nPress Enter to continue...";
        cin.ignore(); cin.get();
        return;
    }

    system("cls"); system("color 57");
    cout << "\nWelcome, " << session.getAdminID() << "!\n";
    cin.ignore();cin.get();
    cout<<"press enter to continue...";
    system("cls"); system("color 57");

    try {
        admin a;
        a.AdminMenu();
    } catch (const runtime_error& e) {
        cout << "[Runtime Error] " << e.what() << "\n";
    }

    session.logout();   // clear session on exit
}

int main() {
    system("color 57");
    int choice;
    while (true) {
        cout << "\n\t\t\t_____________________________\n";
        cout <<   "\t\t\t      OOP'S SUPER MART\n";
        cout <<   "\t\t\t_____________________________\n";
        cout <<   "\t\t\t1) Admin\n\t\t\t2) Customer\n\t\t\t3) Exit\n";
        cout <<   "\t\t\tEnter choice: "; cin >> choice;
        system("cls"); system("color 57");
        try {
            switch (choice) {
                case 1: adminLogin();                      break;
                case 2: { customer c; c.customerMenu(); } break;
                case 3: cout << "Thank you for shopping!\n"; return 0;
                default: throw out_of_range("Invalid choice. Please enter 1, 2, or 3.");
            }
        } catch (const invalid_argument& e) { cout << "[Input Error] "   << e.what() << "\n"; }
          catch (const out_of_range& e)     { cout << "[Range Error] "   << e.what() << "\n"; }
          catch (const runtime_error& e)    { cout << "[Runtime Error] " << e.what() << "\n"; }
          catch (...)                        { cout << "[Unknown Error] An unexpected error occurred.\n"; }
    }
}
