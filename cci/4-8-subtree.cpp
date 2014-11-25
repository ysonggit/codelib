#include "binarytree.h"

using namespace std;

bool matchTree(Node * root1, Node * root2){
    if(root1 == NULL && root2 == NULL) return true;
    //  one is null but the other is not
    // (both null case is already excluded in last step)
    if(root1 == NULL || root2 == NULL) return false;

    if(root1->value != root2->value){
        return false;
    }
    return matchTree(root1->left, root2->left)
        && matchTree(root1->right, root2->right);
}

bool hasSubTree(Node * root1, Node * root2){
    bool result = false;
    if(root1 != NULL && root2!= NULL){
        if(root1->value == root2->value){
            result = matchTree(root1, root2);
        }
        if(!result){
            result = hasSubTree(root1->left, root2);
        }
        if(!result){
            result = hasSubTree(root1->right, root2);
        }
    }
    return result;
}

void test(const BinaryTree & tree1, const BinaryTree & tree2){
    if(hasSubTree(tree1.root, tree2.root)){
        cout<<"Tree 2 is a subtree of Tree 1\n";
    }else{
        cout<<"Tree 2 is not subtree of Tree 1\n";
    }
}

int main(){
    BinaryTree bt1, bt2, bt3;
    int foo[12] ={
	30, 20, 40, 10, 25, 50, 5, 15, 28, 41, 48, 60
    };
    for(int i : foo){
	bt1.insert(i);
    }
    bt1.printTree(1, 0);
    int goo[3] ={
        10, 5, 15
    };
    for(int j : goo){
        bt2.insert(j);
        bt3.insert(j);
    }
    bt2.printTree(1, 0);
    test(bt1, bt2);
    bt3.insert(25);
    test(bt1, bt3);
    return 0;
}
