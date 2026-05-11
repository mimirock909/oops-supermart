#pragma once
#include "item.h"
#include "inventory.h"
#include <vector>
#include <stdexcept>
class cart{
    vector<Item> items;
    float total = 0.0f;
    public:
    	int AddToCart(Item item);
    	void DeleteFromCart();
	 	void ViewCart() const;
	 	void CheckOut() const;
};
