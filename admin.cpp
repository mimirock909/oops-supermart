#include "admin.h"
#include "utils.h"    // function template searchByID (Week 12)
#include <iostream>
#include <cstdlib>
#include<string.h>
using namespace std;

admin::admin() {
    try {
        inventory = loadInventory();
    } catch (const runtime_error& e) {
        cout << "[WARNING] Could not load inventory: " << e.what() << "\n";
        cout << "Starting with an empty inventory.\n";
    }
}

void admin::AdminMenu() {
    int choice;
    while (true) {
        cout << "\n\t\t\t______________________________\n";
        cout <<   "\t\t\t     ADMINISTRATOR MENU\n";
        cout <<   "\t\t\t______________________________\n";
        cout <<   "\t\t\t 1) Add item\n\t\t\t 2) Delete item\n\t\t\t 3) Modify item\n\t\t\t 4) Show inventory\n\t\t\t 5) Back\n";
        cout <<   "\t\t\tEnter choice: "; cin >> choice;
        system("cls"); system("color 64");
        try {
            switch (choice) {
                case 1: addItem();       break;
                case 2: deleteItem();    break;
                case 3: modifyItem();    break;
                case 4: showInventory(); break;
                case 5: return;
                default: throw out_of_range("Invalid choice. Please enter 1-5.");
            }
        } catch (const invalid_argument& e) { cout << "[Input Error] "   << e.what() << "\n"; }
          catch (const out_of_range& e)     { cout << "[Range Error] "   << e.what() << "\n"; }
          catch (const runtime_error& e)    { cout << "[Runtime Error] " << e.what() << "\n"; }
        cout << "\n\t\t\tPress Enter to continue...";
        cin.ignore(); cin.get();
        system("cls"); system("color 64");
    }
}

void admin::addItem() {
    Item newItem;
    newItem.AdminAddItem();
    // Use function template searchByID to check for duplicates
    if (searchByID(inventory, newItem.getID()) != nullptr)
        throw runtime_error("An item with this ID already exists.");
    inventory.push_back(newItem);
    saveInventory(inventory);
    cout << "Item added and saved to '" << INVENTORY_FILE << "'.\n";
}

void admin::deleteItem() {
    int id;
    cout << "Enter ID to delete: "; cin >> id;
    if (id <= 0) throw invalid_argument("ID must be a positive integer.");
    for (vector<Item>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getID() == id) {
            inventory.erase(it);
            saveInventory(inventory);
            cout << "Item deleted and file updated.\n";
            return;
        }
    }
    throw runtime_error("No item found with this ID.");
}

void admin::modifyItem() {
    int id;
    cout << "Enter ID to modify: "; cin >> id;
    if (id <= 0) throw invalid_argument("ID must be a positive integer.");
    // Use function template searchByID  returns pointer for in-place edit
    Item* found = searchByID(inventory, id);
    if (!found) throw runtime_error("No item found with this ID.");
    found->ShowItem();
    found->modifyItem();
    saveInventory(inventory);
    cout << "Item modified and file updated.\n";
}

void admin::showInventory() const {
    if (inventory.empty()) throw runtime_error("No items in inventory.");
    cout << "\n=== INVENTORY (" << inventory.size() << " items) ===\n";
    for (int i = 0; i < (int)inventory.size(); i++) {
        inventory[i].ShowItem();
        cout << string(58,'_')<<"\n";
    }
}
