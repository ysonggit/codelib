#include <iostream>
#include <algorithm> // max min
#include <queue>
#include <deque> // iterator
#include <memory>
#include <iomanip> // setw
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

struct Node{
     Node(int d) {
	  value = d;
	  left = NULL;
	  right = NULL;
	  parent = NULL;
     }
     int value;
     Node * left;
     Node * right;
     Node * parent;
};

class BinaryTree{
public:
     BinaryTree(){
	  root = NULL;
     }
     Node * root;
     void insert(int );
     void insert(Node * , Node *);
     int height(Node *);
     int treeHeight();
     // http://leetcode.com/2010/09/printing-binary-tree-in-level-order.html
     void printLevelOrder();
     // http://leetcode.com/2010/09/how-to-pretty-print-binary-tree.html
     string toStr(int );
     void printBranches(int, int ,int, int, const deque<Node*> &);
     void printNodes(int, int ,int, int, const deque<Node*> &);
     void printLeaves(int ,int, int, const deque<Node*> &);
     void printTree(int , int);
     // traverse left tree
     // visit root
     // traverse right tree
     void inOrder(Node *);
     // visit the root
     // traverse left tree
     // traverse right tree
     void preOrder(Node *);
     // traverse left tree
     // traverse righ tree
     // visit root
     void postOrder(Node *);
     //void delete(Node * );
};
