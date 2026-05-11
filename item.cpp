#include "item.h"
#include <iostream>
using namespace std;

Item::Item() { id = 0; price = 0.0f; quantity = 0; }
void   Item::setQuantity(int qty){
	quantity=qty;
}
int    Item::getID()           const { return id; }
string Item::getName()         const { return name; }
string Item::getCategory()     const { return category; }
float  Item::getPrice()        const { return price; }
int    Item::getQuantity()     const { return quantity; }
string Item::getAvailability() const { return availability; }
string Item::getExpiry()       const { return dateOfExpiry; }

void Item::AdminAddItem() {
    cout << "\t\t\tEnter id       : "; cin >> id;
    if (id <= 0)
        throw invalid_argument("Item ID must be a positive integer.");
    cout << "\t\t\tEnter name     : "; cin >> name;
    cout << "\t\t\tEnter category : "; cin >> category;
    cout << "\t\t\tEnter price    : "; cin >> price;
    if (price < 0)
        throw invalid_argument("Price cannot be negative.");
    cout << "\t\t\tEnter quantity : "; cin >> quantity;
    if (quantity < 0)
        throw invalid_argument("Quantity cannot be negative.");
    availability = (quantity <= 0) ? "OutOfStock" : "InStock";
    cout << "\t\t\tEnter expiry   : "; cin >> dateOfExpiry;
}

void Item::ShowItem() const {
    cout << "\t\t\t ID          : " << id           << "\n";
    cout << "\t\t\t NAME        : " << name         << "\n";
    cout << "\t\t\t CATEGORY    : " << category     << "\n";
    cout << "\t\t\t PRICE       : Rs." << price     << "\n";
    cout << "\t\t\t QUANTITY    : " << quantity     << "\n";
    cout << "\t\t\t AVAILABILITY: " << availability << "\n";
    cout << "\t\t\t EXPIRY      : " << dateOfExpiry << "\n";
}

void Item::DisplayMenu() {          // NO 'override' here — only allowed in .h
    cout << "\t\t\t--- ITEM DETAILS ---\n";
    ShowItem();
}

void Item::modifyItem() {
    int choose;
    cout << "\n------ MODIFY -------\n";
    cout << "1) Name\n2) Category\n3) Price\n4) Quantity\n5) Date of Expiry\n";
    cout << "Enter choice: "; cin >> choose;
    switch (choose) {
        case 1: cout << "New name     : "; cin >> name;     break;
        case 2: cout << "New category : "; cin >> category; break;
        case 3:
            cout << "New price    : "; cin >> price;
            if (price < 0) throw invalid_argument("Price cannot be negative.");
            break;
        case 4:
            cout << "New quantity : "; cin >> quantity;
            if (quantity < 0) throw invalid_argument("Quantity cannot be negative.");
            availability = (quantity <= 0) ? "OutOfStock" : "InStock";
            break;
        case 5: cout << "New expiry   : "; cin >> dateOfExpiry; break;
        default: throw out_of_range("Invalid modify option. Choose 1 to 5.");
    }
}

void Item::saveToFile(ofstream& out) const {
    if (!out.is_open())
        throw runtime_error("Cannot write to inventory file.");
    out << id << "\n" << name << "\n" << category << "\n"
        << price << "\n" << quantity << "\n"
        << availability << "\n" << dateOfExpiry << "\n";
}

bool Item::loadFromFile(ifstream& in) {
    return static_cast<bool>(
        in >> id >> name >> category >> price >> quantity >> availability >> dateOfExpiry
    );
}
