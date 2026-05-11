#pragma once
#include "inventory.h"
#include <stdexcept>


class admin {
   vector<Item> inventory;
   public:
    admin();
    void AdminMenu();
    private:
    void addItem();
    void deleteItem();
    void modifyItem();
    void showInventory() const;
};
