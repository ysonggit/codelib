#include "binarytree.h"
#include <stdlib.h> // abs

using namespace std;

int getHeight(Node * n){
    if(n == NULL){
	return 0;
    }
    return std::max(getHeight(n->left), getHeight(n->right))+1;
}


bool isBalanced(Node * n){
    if(n == NULL) return true;
    
    int height_diff = getHeight(n->left) - getHeight(n->right);
    if(abs(height_diff)>1){
	return false;
    }
    return true;
}

int main(){
    BinaryTree bt;
    int foo[12] ={
	30, 20, 40, 10, 25, 50, 5, 15, 28, 41, 48, 49
    };
    for(int i : foo){
	bt.insert(i);
    }
    //cout<<"Tree height = "<<bt.treeHeight()<<endl;
    bt.printTree(1, 0); // level = 1, indentSpace = 0
    if(isBalanced(bt.root)){
	cout<< "Tree is balanced "<<endl;
    }else{
	cout<< "Tree is unbalanced "<<endl;
    }
    
    return 0;
}
