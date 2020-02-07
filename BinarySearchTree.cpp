//Hunter Vaccaro
//hpv8hf
//10/15/2019
//BinarySearchTree.cpp
#include "BinarySearchTree.h"
#include <string>
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() { root = NULL; } //default constructor

BinarySearchTree::~BinarySearchTree() { //destructor
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
  root = insert(x,root);
}

// with the root, finds the position for x in the tree and places it there
BinaryNode* BinarySearchTree::insert(const string& x, BinaryNode*& root) {
  if(find(x,root)){
    //if x exists, do nothing
  }
  else {
    BinaryNode* temp = new BinaryNode(); //creates dummy node for x
    temp -> value = x;
    if(root == NULL){ 
      return temp; //no root = dummy node is the root
    }
    else if(root->value < x) { 
      if(root->right == NULL){ // if right is empty, assign roots right to x
	root->right = temp;
	return root;
      }
      insert(x, root->right); // move right
    }
    else {
      if(root -> left == NULL){ // if left is empty, assign roots left to x
	root->left = temp;
	return root;
      }
      insert(x, root->left); //move left
    }
  }
  return root; 
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
  return pathTo(x, root);
}

// using the root, prints out the path to get to x
string BinarySearchTree::pathTo(const string& x, BinaryNode* root) const {
  if(root == NULL){ //no path 
    return "";
  }
  else if(!find(x,root)){ //x isnt in root == no path
    return "";
  }
  else if(root->value > x){ // displays roots value and moves left 
    return ""+root->value+" "+pathTo(x,root->left);
  }
  else if(root->value < x){ // displays roots value and moves right
    return ""+root->value+" "+pathTo(x,root->right);
  }
  else { //displays x
    return ""+root->value;
  }
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
  return find(x,root);
}

// using the root, checks to see if x is in the root
bool BinarySearchTree::find(const string& x, BinaryNode* root) const {
  if(root == NULL){ //no root == no x
    return false;
  }
  else if(root->value == x){ // return true if found on root
    return true;
  }
  else { //move left and right 
    return (find(x,root->left) || find(x,root->right));
  }
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  return numNodes(root);
}

// using the root, returns the number of nodes in the tree.
int BinarySearchTree::numNodes(BinaryNode* root) const {
  if(root == NULL){ //no root == 0
    return 0;
  }
  else { // move left and right while adding one for root
    return 1 + numNodes(root->left) + numNodes(root->right);
  }
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void BinarySearchTree::printTree() { printTree(root, NULL, false); }
