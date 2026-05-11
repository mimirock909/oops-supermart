#pragma once
#include <string>
using namespace std;
class cart;
class product {
protected:
    int    id;
    string name;
    string category;
    float  price;
    int    quantity;
    string availability;
    string dateOfExpiry;

    friend class cart;          // cart can access protected members directly
    virtual void DisplayMenu() = 0;
};
