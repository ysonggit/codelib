#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_array(const int* arr, const int arr_size){ 
  for(int i=0; i<arr_size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
// input: given array of integers 
// output array of ints in which each number is replaced 
//        with a number presented on the right side of it (in the given array)
//        such that the number is the Least Greater than the element

/* naive method: */  
void replace_with_least_greater_number(const int* input, const int arr_size, int* output){
  
  for(int index = arr_size-1; index >=0 ; index--){
    int current_number = *(input+index);
    int replaced_number = -1;
    int sub_arr_size = arr_size-1 - index;
     
    vector<int> sorted_elements;
    for(int j=0; j< sub_arr_size; j++){
      int number_from_tail = *(input + (arr_size-1) - j );
      if (number_from_tail > current_number){
        sorted_elements.push_back(number_from_tail);
      }
    }
    
    if(sorted_elements.size() > 0){
      sort(sorted_elements.begin(), sorted_elements.end()); 
      replaced_number = sorted_elements.front();
    }
    
    *(output+index) = replaced_number;
    // cout<<replaced_number<<endl;
  } 
}

/* BST method: O(log n) */
struct Node{
  int value;
  Node* left;
  Node* right;
};

class BSTree{
public:
  Node* root;
  BSTree() {
    root = NULL;
  }
  Node* insert(int );
  void print_tree();
  void print(Node*, int);
  
};

Node* BSTree::insert(int num){
  Node* n = new Node;
  n->value = num;
  n->left = NULL;
  n->right = NULL;
  Node* pre = NULL;

  if (root == NULL){ //an empty tree yet
    root = n;
  
  }else{
    Node* current = root; // a copy of root node
    Node* parent = NULL;

    while (current){ // keep on go through the tree
      parent = current;
      if(n->value > current->value){
        current = current->right;
      }else{
        current = current->left;
        if (pre == NULL || pre->value > parent->value){
          pre = parent;  // update the least greater inorder predecessor
        }
      }
    
    }
    // now reach a leaf position, the new node should be inserted as a child of parent
    if(n->value > parent->value){
      parent->right = n;
    }else{
      parent->left = n;
    }
  }
  return pre;
  
}

void BSTree::print(Node* n, int offset){  
  offset++;
  if(n->right != NULL){
    print(n->right, offset);
  }
  for(int i=0; i<=offset; i++){
    cout<<"\t";
  }
  cout<<n->value<<endl;
  if(n->left !=NULL){
    print(n->left, offset);
  }
}

void BSTree::print_tree(){
  print(root, 0);
}


int main(){
  const int input[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
  // output should be array of {18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1}
  const int arraysize = sizeof(input) / sizeof(input[0]);
  print_array(input, arraysize);
 
  // test naive method
  int output[arraysize];
  replace_with_least_greater_number(input, arraysize, output);
  print_array(output, arraysize);

  // test BST method
  int output2[arraysize];
  BSTree tree;
  for(int i= arraysize-1; i>=0; i--){
    Node* least_greater_predecessor = tree.insert(input[i]);
    if (least_greater_predecessor == NULL){
      output2[i] = -1;
    }else{
      output2[i] = least_greater_predecessor->value;
    }
  }
  
  //tree.print_tree();
  print_array(output2, arraysize);
  return 0;
}
