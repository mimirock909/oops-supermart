#include "cart.h"
#include <iostream>
#include <string>
using namespace std;

int cart::AddToCart(Item item) {
    if (items.size() >= 20)
        throw out_of_range("Cart is full! Maximum 20 items allowed.");
    if (item.getQuantity() <= 0)
        throw runtime_error("'" + item.getName() + "' is out of stock.");
    int qty;
    cout << "Enter quantity (available: " << item.getQuantity() << "): ";
    cin >> qty;
    if (qty <= 0)
        throw invalid_argument("Quantity must be at least 1.");
    if (qty > item.getQuantity())
        throw invalid_argument("Requested quantity exceeds stock available.");
    item.quantity = qty;            // FIX: was -= instead of =
    total += item.getPrice() * qty;
    items.push_back(item);
    cout << "'" << item.getName() << "' added to cart!\n";
    return qty;
}

 void cart::DeleteFromCart() {
	vector<Item> inventory=loadInventory();
	int qty=0;
	bool foundInCart = false;
    if (items.empty())
        throw runtime_error("Cart is empty. Nothing to remove.");
    string name;
    cout << "Enter name to remove: "; cin >> name;
    for (vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == name) {
        	qty=it->getQuantity();
            total -= it->getPrice() * it->getQuantity();
            items.erase(it);
            foundInCart = true;
            cout << "Item removed from cart.\n";
            break;
        }
    }
    if (!foundInCart) {
        throw runtime_error("'" + name + "' not found in cart.");
    }
    for(int i=0;i<(int)inventory.size();i++){
    	 if (inventory[i].getName() == name){
		    int currentStock = inventory[i].getQuantity();
            inventory[i].setQuantity(currentStock + qty);
			saveInventory(inventory);
			return;
		 }
	}
}

void cart::ViewCart() const {
    if (items.empty())
        throw runtime_error("Your cart is empty.");
    cout << "\n" << string(58, '#') << "\n";
    cout << "  ID\tName\t\tPrice\t\tQty\tSubtotal\n";
    cout << string(58, '-') << "\n";
    for (int i = 0; i < (int)items.size(); i++)
        cout << "  " << items[i].getID()    << "\t"
             << items[i].getName()          << "\t\t"
             << "Rs." << items[i].getPrice()<< "\t\t"
             << items[i].getQuantity()      << "\t"
             << "Rs." << items[i].getPrice() * items[i].getQuantity() << "\n";
    cout << string(58, '#') << "\n";
}

void cart::CheckOut() const {
    if (items.empty())
        throw runtime_error("Nothing to checkout. Your cart is empty.");
    ViewCart();
    cout << "\n  *** Total Bill: Rs." << total << " ***\n";
}
