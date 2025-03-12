#include "HASH.h"
#include <bits/stdc++.h>

HashMapTable::HashMapTable(int ts)
{
  this->table_size = ts;
  table = new list<int>[table_size];
}
// insert function to push the keys in hash table
void HashMapTable::insertElement(int key)
{
  int index = hashFunction(key);
  table[index].push_back(key);
}
// delete function to delete the element from the hash table
void HashMapTable::deleteElement(int key)
{
  int index = hashFunction(key);
  // finding the key at the computed index
  list<int>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++)
  {
    if (*i == key)
      break;
    if (i != table[index].end())
      table[index].erase(i);
  }
}

void HashMapTable::displayHashTable()
{
  for (int i = 0; i < table_size; i++)
  {
    cout << i;
    // traversing at the recent/ current index
    for (auto j : table[i])
      cout << " ==> " << j;
    cout << endl;
  }
}
