#include "binarytree.h"

using namespace std;

// g++ -std=c++0x 4-7-common_ancestor.cpp binarytree.cpp
// returns true if p is descendant of root
bool inTree(Node * root, Node *p){
    if (root == NULL || p==NULL) return false;
    if (root == p ) return true; //base case
    return inTree(root->left, p) || inTree(root->right, p);
}


// from leetcode.com
// traverse from bottom to top
// once we reach a node which matches one of the two nodes,
// pass it up to its parent.
// The parent would then test its left and right subtree
// if each contain one of the two nodes. (p & q must be on two sides of the ancestor)
// If yes, then the parent must be the CA and we pass its parent up to the root.
// If not, we pass the lower node which contains either one of the two nodes (if the left or right subtree contains either p or q), or NULL (if both the left and right subtree does not contain either p or q) up.
// NOTE, this function works only if the tree contains root, p and q 
Node * commonAncestor(Node * root, Node * p, Node * q){
    if(root == NULL) return NULL;
    if(!inTree(root, p) || !inTree(root, q)) return NULL;
    if(p == root || q == root) return root;
    // check if p & q are on the same sides of root
    // root is not null,
    Node *in_left_subtree = commonAncestor(root->left, p, q);
    Node *in_right_subtree = commonAncestor(root->right, p, q);
    if(in_left_subtree && in_right_subtree) return root;
    return  in_left_subtree ? in_left_subtree : in_right_subtree;    
    
}

void test(Node *root, Node *p, Node *q){
    if(p && q){
	cout<<"Common Ancestor of Node ("<<p->value<<") & Node ("<<q->value<<") = ";
    }else{
	cout<<"Null nodes given, exit\n";
	return ;
    }
       
    Node *ca =  commonAncestor(root, p, q);
    if(ca != NULL){
	cout<<"("<<ca->value<<")\n";
    }else{
	cout<<"()\n";
    }
}

int main(){
    BinaryTree bt;
    Node * n1 = new Node(3);
    Node * n2 = new Node(1);
    Node * n3 = new Node(5);
    Node * n4 = new Node(8);
    Node * n5 = new Node(0);
    Node * n6 = new Node(4);
    bt.root = n1;
    bt.root->left = n3;
    bt.root->right = n5;
    n3->left = n4;
    n5->right = n2;
    n5->left = n6;
    /*
         __3__
	/     \
       5      _0_
      /      /   \
      8      4    1
    */
    bt.printTree(1, 0);
    test(n1, n2, n6);
    test(n1, n4, n6);
    test(n1, n2, n3);
    test(n1, n3, n4);
    test(n1, n1, n2);
    test(n1, n3, n3);
    
    Node * n7 = new Node(7);
    test(n1, n2, n7);
    test(NULL, NULL, NULL);
    return 0;
}
