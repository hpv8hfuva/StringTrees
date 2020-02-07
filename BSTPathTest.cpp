#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main() {
  BinarySearchTree bst;
  while (cin.good()) {
    string instr, word;
    cin >> instr;
    cin >> word;
    if (instr == "I") { // I is inserts 
      bst.insert(word);
    } else if (instr == "R") { // R is remove
      bst.remove(word);
    } else if (instr == "L") { // L is lookup (find path)
      cout << "BST path: " << bst.pathTo(word) << endl;
    }
  }
  cout << "BST numNodes: " << bst.numNodes() << endl;
}
