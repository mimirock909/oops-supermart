#include "inventory.h"
#include <fstream>
#include <stdexcept>
using namespace std;

const string INVENTORY_FILE = "inventory.txt";
// Read every item stored in INVENTORY_FILE into a vector
vector<Item> loadInventory() {
    vector<Item> inv;
    ifstream fin(INVENTORY_FILE);
    if (!fin.is_open()) return inv;   // file doesn't exist yet  that's fine
    Item tmp;
    while (tmp.loadFromFile(fin))
        inv.push_back(tmp);
    fin.close();
    return inv;
}

// Overwrite INVENTORY_FILE with the current vector contents
void saveInventory(const vector<Item>& inv) {
    ofstream fout(INVENTORY_FILE.c_str(), ios::trunc);
    if (!fout.is_open())
        throw runtime_error("Failed to open '" + INVENTORY_FILE + "' for saving. Check disk permissions.");
    for (int i = 0; i < (int)inv.size(); i++)
        inv[i].saveToFile(fout);
    fout.close();
}
