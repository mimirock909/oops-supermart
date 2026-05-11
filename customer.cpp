#include "customer.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void customer::browseAndAdd(cart& c){
	 vector<Item> inventory = loadInventory();
        if (inventory.empty())
            throw runtime_error("No items available in the store yet!");
        if (inventory.empty()) {
            cout << "No items available in the store yet!\n";
            return;
        }

        cout << "\n=== STORE INVENTORY ===\n";
        cout << string(72, '#') << "\n";
        cout << "  ID \t  Name      \t      Category    \t    Price   \t    Qty   Expiry\n";
        cout << string(72, '#') << "\n";
        for (int i = 0; i < (int)inventory.size(); i++) {
            string tag = (inventory[i].getQuantity() <= 0) ? " [OUT OF STOCK]" : "";
            cout << "  "    << inventory[i].getID()
                 << "\t"    << inventory[i].getName()
                 << "\t\t"  << inventory[i].getCategory()
                 << "\tRs." << inventory[i].getPrice()
                 << "\t"    << inventory[i].getQuantity()
                 << "\t"    << inventory[i].getExpiry()
                 << tag     << "\n";
        }
        cout << string(72, '#') << "\n";

        string name;
        cout << "\nType item NAME to add to cart (or 0 to cancel): ";
        cin >> name;
        if (name == "0") return;

        for (int i = 0; i < (int)inventory.size(); i++) {
            if (inventory[i].getName() == name) {
            	int newquant=inventory[i].getQuantity()-c.AddToCart(inventory[i]);
                inventory[i].setQuantity(newquant);
				saveInventory(inventory);
                return;
            }
        }
     throw runtime_error("Item '" + name + "' not found. Check spelling (case-sensitive).");
    }
void customer::customerMenu(){
	 int choiceC;
        cart basicCart;

        while (true) {
            cout << "\n\t\t\t_____________________________\n";
            cout <<   "\t\t\t WELCOME TO OOP'S SUPER MART \n";
            cout <<   "\t\t\t_____________________________\n";
            cout <<   "\t\t\t1) Browse store & Add to cart\n";
            cout <<   "\t\t\t2) Remove item from cart\n";
            cout <<   "\t\t\t3) View cart\n";
            cout <<   "\t\t\t4) Checkout\n";
            cout <<   "\t\t\t5) Return to main menu\n";
            cout <<   "\t\t\tEnter your choice: "; cin >> choiceC;
            system("cls"); system("color 64");
		   try{
            switch (choiceC) {
                case 1: browseAndAdd(basicCart);        break;
                case 2: basicCart.DeleteFromCart();     break;
                case 3: basicCart.ViewCart();           break;
                case 4: basicCart.CheckOut();           break;
                case 5: return;
               default:
                        throw out_of_range("Invalid choice. Please enter 1–5.");
                }
            } catch (const invalid_argument& e) {
                cout << "[Input Error] " << e.what() << "\n";
            } catch (const out_of_range& e) {
                cout << "[Range Error] " << e.what() << "\n";
            } catch (const runtime_error& e) {
                cout << "[Runtime Error] " << e.what() << "\n";
            }
            cout << "\nPress Enter to continue...";
            cin.ignore(); cin.get();
            system("cls"); system("color 64");
        }
    }
