#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() { //default constructor
  value = "?";
  left = NULL;
  right = NULL;
}

BinaryNode::~BinaryNode() { //destructor
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
