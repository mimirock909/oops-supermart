#pragma once
#include <vector>
#include <string>
using namespace std;
// T must have a getID() method that returns an Int.
// Works for any container of objects with an ID  currently used with
// vector<Item> in admin and customer, but reusable for any future type.
//
// Returns a pointer to the found element, or nullptr if not found.
// Using a pointer return allows the caller to modify the item in-place
// (e.g. admin modifying quantity) without making a copy.
//
// Usage:
//   Item* found = searchByID(inventory, 3);
//   if (found) found->ShowItem();
template <typename T>
T* searchByID(vector<T>& vec, int id) {
    for (int i = 0; i < (int)vec.size(); i++) {
        if (vec[i].getID() == id)
            return &vec[i];
    }
    return nullptr;   // not found
}

// T must have a getName() method returning string.
// Used in customer browse and cart deletion.
template <typename T>
T* searchByName(vector<T>& vec, const string& name) {
    for (int i = 0; i < (int)vec.size(); i++) {
        if (vec[i].getName() == name)
            return &vec[i];
    }
    return nullptr;
}
