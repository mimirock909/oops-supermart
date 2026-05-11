#pragma once
#include "product.h"
#include <fstream>
#include <stdexcept>
class Item : public product {
public:
    Item();
    void  setQuantity(int qty);
    int    getID()           const;
    string getName()         const;
    string getCategory()     const;
    float  getPrice()        const;
    int    getQuantity()     const;
    string getAvailability() const;
    string getExpiry()       const;
    void AdminAddItem();
    void ShowItem() const;
    void DisplayMenu() override;
    void modifyItem();
    void saveToFile(ofstream& out) const;
    bool loadFromFile(ifstream& in);
	};
