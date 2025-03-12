#ifndef HASH_H
#define HASH_H

#include <bits/stdc++.h>
using namespace std;

class HashMapTable {
  int table_size;
  list<int> *table;

public:
  HashMapTable(int ts);
  int hashFunction(int key) { return (key % table_size); }

  void insertElement(int key);
  void deleteElement(int key);
  void displayHashTable();
};

#endif // HASH_H