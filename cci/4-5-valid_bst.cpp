#include "binarytree.h"
#include <climits>

using namespace std;

// recursively evaluate each sub-tree
bool validBST(Node * n, int local_min, int local_max){
    if(n==NULL) return true;
    int curr_value = n->value;
    if(curr_value >= local_min
       && curr_value < local_max
       && validBST(n->left, local_min, curr_value)
       && validBST(n->right, curr_value, local_max)){
	return true;
    }
    return false;
}



int main(){
    BinaryTree bt;
    int foo[12] ={
	30, 20, 40, 10, 25, 50, 5, 15, 28, 41, 48, 60
    };
    for(int i : foo){
	bt.insert(i);
    }
    int local_min = INT_MIN;
    int local_max = INT_MAX;
    if(validBST(bt.root, local_min, local_max)){
	cout<<"Tree is valid BST\n";
    }else{
	cout<<"Not valid BST\n";
    }

    return 0;
}
