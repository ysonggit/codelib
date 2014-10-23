#include "binarytree.h"

void BinaryTree::insert(int d){
    // make it binary search tree
    Node * newnode = new Node(d);
    if(root == NULL){
	root = newnode;
	return ;
    }
    insert(newnode, root);
}

// recursively insert 
void BinaryTree::insert(Node * newnode, Node * n){
    if(newnode->value <= n->value){
	if(n->left == NULL){
	    newnode->parent = n; 
	    n->left = newnode;	    
	    return ;
	}else{
	    insert(newnode, n->left);
	}
    }else{
	// newnode value is greater than or equal to n's value
	if(n->right == NULL){
	    newnode->parent = n;
	    n->right = newnode;
	    return ;
	}else{
	    insert(newnode, n->right);
	}
    }
}

int BinaryTree::height(Node * n){
    if(n==NULL) return 0;
    return max(height(n->left), height(n->right))+1;
}

int BinaryTree::treeHeight(){
    return height(root);
}

void BinaryTree::printLevelOrder(){
    if(root==NULL) return;
    // BFS
    queue<Node*> nodes_queue;
    int nodes_curr_level = 1;
    int nodes_next_level = 0;
 
    nodes_queue.push(root);
    while(!nodes_queue.empty()){
	Node* current_node = nodes_queue.front();
	nodes_queue.pop();
	nodes_curr_level--;
	if(current_node != NULL){
	    cout<<current_node->value<<" ";
	    nodes_queue.push(current_node->left);
	    nodes_queue.push(current_node->right);
	    nodes_next_level += 2;
	}
	if(nodes_curr_level == 0){
	    cout<<endl;
	    // move to next level 
	    nodes_curr_level = nodes_next_level;
	    nodes_next_level = 0;
	}
    } 
}

string BinaryTree::toStr(int val){
    ostringstream ss;
    ss << val;
    return ss.str();
}

void BinaryTree::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*> & nodes_queue){
    deque<Node*>::const_iterator iter = nodes_queue.begin();
    for(int i=0; i< nodesInThisLevel/2; i++){
	cout<<((i==0)? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
	cout<<setw(2*branchLen+2) << ""<<((*iter++) ? "\\" : " ");
    }
    cout<<endl;
}

void BinaryTree::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*> & nodes_queue){
    deque<Node*>::const_iterator iter = nodes_queue.begin();
    for(int i=0; i<nodesInThisLevel; i++, iter++){
	Node * curr_node = *iter;
	cout<<((i==0) ? setw(startLen):setw(nodeSpaceLen)) <<""<<((curr_node && curr_node->left)? setfill('_'): setfill(' '));
	cout<<setw(branchLen+2)<<((curr_node) ? toStr(curr_node->value) : "" );
	cout<<((curr_node && curr_node->right) ? setfill('_') : setfill(' ')) << setw(branchLen)<<""<<setfill(' ');
    }
    cout<<endl;   
}

void BinaryTree::printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*> & nodes_queue){
    //cout<<"print leaves: "<<nodesInThisLevel<<" leaf nodes "<<endl;
    deque<Node*>::const_iterator iter = nodes_queue.begin();
    for(int i= 0; i< nodesInThisLevel; i++, iter++){
	Node * curr_node = *iter;
	cout<< ((i==0) ? setw(indentSpace+2) : setw(2*level+2))<<(curr_node ? toStr(curr_node->value) : ""); 
    }
    cout<<endl;
}

void BinaryTree::printTree(int level, int indentSpace){
    if(root == NULL) return;
    int H = treeHeight();
    int nodesInThisLevel = 1;
    // branchLen = 2* (2^H - 1) - (3 - level) * (2^(H-1))
    int branchLen = 2*((int)pow(2, H)-1) - (3-level) *(int)pow(2, H-1);
    // distance between left neighbor node's right arm and right neighbor node's left arm
    // nodeSpaceLen = 2 + (level+1)  * 2^H
    int nodeSpaceLen = 2 + (level + 1) * (int)pow(2, H);
    // starting space to the first node to print of each level (for the left most node of each level only)
    int startLen = branchLen + (3-level) + indentSpace;
    // BFS the tree
    deque<Node*> nodes_queue;
    nodes_queue.push_back(root);
    // use for loop to print levels excluding the bottom leaf level
    for(int r = 1; r < H; r++){ 
	printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodes_queue);
	branchLen = branchLen/2 - 1;
	nodeSpaceLen = nodeSpaceLen/2 + 1;
	startLen = branchLen + (3-level) + indentSpace;
	printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodes_queue);
	for(int i=0; i< nodesInThisLevel; i++){
	    Node * curr_node = nodes_queue.front();
	    nodes_queue.pop_front();
	    if(curr_node){
		nodes_queue.push_back(curr_node->left);
		nodes_queue.push_back(curr_node->right);
	    }else{
		// push NULL as place holder 
		nodes_queue.push_back(NULL);
		nodes_queue.push_back(NULL);
	    }
	}
	nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodes_queue);
    printLeaves(indentSpace, level, nodesInThisLevel, nodes_queue);
}

void BinaryTree::inOrder(Node * n){
    if(n==NULL) return ;
    inOrder(n->left);
    cout<<n->value<<" ";
    inOrder(n->right);
}

void BinaryTree::preOrder(Node *n ){
    if(n==NULL) return ;
    cout<<n->value<<" ";
    preOrder(n->left);
    preOrder(n->right);
}

void BinaryTree::postOrder(Node *n){
    if(n==NULL) return ;
    postOrder(n->right);
    postOrder(n->left);
    cout<<n->value<<" ";
}

// recursively delete
//void BinaryTree::delete(Node * n){
    // if(n != NULL){
    // 	delete(n->left);
    // 	delete(n->right);	
    // }
//}
