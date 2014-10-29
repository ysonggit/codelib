#include "binarytree.h"

using namespace std;

// build a BST with minimal height
void minimalBST(int arr[], int start_idx, int end_idx, BinaryTree & bst){
    if(start_idx > end_idx) return;

    int mid_idx = (start_idx + end_idx)/2;
    bst.insert(arr[mid_idx]);
    minimalBST(arr, start_idx, mid_idx - 1, bst);
    minimalBST(arr, mid_idx+1, end_idx, bst);
}

int main(){
    BinaryTree bst;
    int sorted_arr[10] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    minimalBST(sorted_arr, 0, 9, bst);
    bst.printTree(1, 0);
    return 0;
}
