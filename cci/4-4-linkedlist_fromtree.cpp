#include "binarytree.h"
#include <map>
#include <list>

using namespace std;

map<int, list<Node*> > createLevelLinkedlist(const BinaryTree & bst){
    map<int, list<Node*> > level_lists;
    if (bst.root != NULL){
	int nodes_level = 1;
	list<Node*> curr_level_list;
	curr_level_list.push_back(bst.root);
	// for each node in current_level list, visit its children
	while(curr_level_list.size()>0){
	    // add previous level
	    level_lists[nodes_level] = curr_level_list;
	    list<Node*> parent_level_list = curr_level_list;
	    // clear curr_level_list
	    curr_level_list.clear();
	    nodes_level++;
	    for(Node* parent_node : parent_level_list){
		Node * left_child = parent_node->left;
		Node * right_child = parent_node->right;
		if(left_child != NULL){
		    curr_level_list.push_back(left_child);
		}
		if(right_child != NULL){
		    curr_level_list.push_back(right_child);
		}
	    }
	}
    }
    return level_lists;
}

int main(){
    BinaryTree bt;
    int foo[12] ={
	30, 20, 40, 10, 25, 50, 5, 15, 28, 41, 48, 60
    };
    for(int i : foo){
	bt.insert(i);
    }
    bt.printTree(1, 0);
    map<int, list<Node*> > level_lists = createLevelLinkedlist(bt);
    for(auto iter = level_lists.begin(); iter != level_lists.end(); ++iter){
	cout<<"Level "<<iter->first<<" "<<endl;
	list<Node*> l = iter->second;
	for(Node* n : l){
	    cout<<n->value<<" ->  ";
	}
	cout<<"END\n";
    }
    return 0;
}
