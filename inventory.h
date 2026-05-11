#pragma once
#include "item.h"
#include <vector>
#include <string>
extern const string INVENTORY_FILE;
vector<Item> loadInventory();
void saveInventory(const vector<Item>& inv);
