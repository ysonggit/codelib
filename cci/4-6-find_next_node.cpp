#include "binarytree.h"
#include <vector>

using namespace std;
// recursively find the leftmost child node
Node * leftMostChild(Node * n){
    if(n==NULL) return NULL;
    if(n!=NULL && n->left == NULL) return n;
    return leftMostChild(n->left);
}

// if n has a right subtree
//    return leftmost child of the right subtree
// else
//    while n is a right child of n's parent
//          n = n.parent
//    return n.parent
Node * inOrderSuccessor(Node * n){
    if (n==NULL ) return NULL;
    // make a copy of node n
    Node *tmp = n;
    Node * tmp_parent = tmp->parent;
    if(n->right !=NULL){
	return leftMostChild(n->right);
    }else{
	while(tmp_parent != NULL && tmp == tmp_parent->right){
	    // if tmp is a right child of its parent
	    // then traverse the tree up
	    tmp = tmp_parent;
	    tmp_parent = tmp->parent;
	}
    }
    // null if root has no right subtree
    // or reach the rightmost node
    return tmp_parent; 
}

void getAllNodes(vector<Node*> & v, Node * n){
    if(n != NULL){
	v.push_back(n);
	getAllNodes(v, n->left);
	getAllNodes(v, n->right);
    }
}

void test(const BinaryTree & bst){
    vector<Node*> allnodes;
    getAllNodes(allnodes, bst.root);
    for(Node* n : allnodes){
	cout<<"In-order successor of ("<<n->value<<") -> ";
	Node * s = inOrderSuccessor(n);
	if(s!=NULL)
	    cout<<"("<<s->value<<")\n";
	else
	    cout<<"()\n";
    }
    
}

int main(){
    int foo[8] ={
	20, 30, 10, 5, 15, 17, 7, 3
    };
    BinaryTree bst;
    for(int i : foo){
	bst.insert(i);
    }
    bst.printTree(1, 0);
    cout<<"In-order print nodes :\n";
    bst.inOrder(bst.root);
    cout<<endl;
    cout<<"Leftmost node of root is: \n";
    cout<<leftMostChild(bst.root)->value<<endl;
    // test inOrderSuccessor() using every tree node
    test(bst);
    return 0;
}
