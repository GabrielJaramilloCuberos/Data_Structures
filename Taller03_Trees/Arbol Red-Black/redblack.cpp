//j

/**
 * Implementacion modular de Salomon Avila
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */
   #include <bits/stdc++.h>
   #include "rbtree.h"
   using namespace std;

   // Driver Code
   int main()
   {
       RBTree tree;
    
       tree.insert(11);
       tree.insert(19);
       tree.insert(7);
       tree.insert(14);
       tree.insert(17);
       tree.insert(31);
       tree.insert(26);
       tree.insert(45);
       tree.insert(70);
       
       cout << "Inoder Traversal of Created Tree\n";
       tree.inorder();
       cout<<"\n";
    
    
       return 0;
   }