#include "linkedlist.h"

bool LinkedList::contains(int i){
    ListNode * tmp = root;
    while(tmp != NULL){
	if(tmp->data == i){
	    return true;
	}
	tmp = tmp->next;
    }
    return false;
}

// return the nth node in the list
ListNode * LinkedList::at(int n){
    ListNode * tmp = root;
    for(int i=1; i<n; i++){
	if(tmp->next != NULL){
	    tmp = tmp->next;
	}else{
	    std::cerr<<"List length < "<<n<<std::endl;
	    return NULL;
	}
    }
    return tmp;
}

int LinkedList::length(){
    ListNode * tmp = root;
    int count = 0;
    while(tmp!= NULL){
	count++;
	tmp = tmp->next;
    }
    return count;
}

void LinkedList::print(){
    if(root == NULL)
        return;

    ListNode * tmp = root;
    while(tmp->next != NULL){
        std::cout<<tmp->data<<" -> ";
        tmp = tmp->next;
    }
    std::cout<<tmp->data<<std::endl;
}

void LinkedList::reversePrint(){
    if(root==NULL){
	std::cout<<"0"<<std::endl;
	return;
    }
    std::stack<int> numstack; 
    ListNode *tmp = root;
    while(tmp != NULL){
	numstack.push(tmp->data);
	tmp = tmp->next;
    }
    while(!numstack.empty()){
	std::cout<<numstack.top();
	numstack.pop();
    }
    std::cout<<"\n";
}

void LinkedList::append(int d){
     ListNode * newnode = new ListNode(d);
     if(root == NULL){
          root = newnode;
          return;
     }
     // make a copy of root
     ListNode * tmp = root;
     while(tmp->next != NULL){
          tmp = tmp->next;
     }
     // tmp->next == NULL means now reaching the end node
     tmp->next = newnode;    
}

// using map to record the duplicates
// be sure to deal with memory (de)allocation
void LinkedList::removeDups(){
    if(root == NULL){
        // empty list
        return;
    }
    // key is the node.data
    // value is the frequency
    std:: map<int, int> cache; 
    // make a copy of root node
    ListNode* tmp = root;
    ListNode* pre = NULL;
    while(tmp != NULL){
        int cur_data = tmp->data;
        if(cache.find(cur_data) != cache.end()){
            // duplicates found, remove it
            pre->next = tmp->next;
        }else{
            cache[cur_data] = 1;
            pre = tmp;
        }
        tmp = tmp->next;
    }
}

// return the nth element to the list tail
ListNode *  LinkedList::nthToLast(int n){
    if(n<=0)
	return NULL;

    ListNode *p1= root;
    ListNode *p2= p1;
    // first move p2 n steps forward
    for(int i=0; i<n; i++){
	if(p2->next != NULL){
	    p2 = p2->next;
	}else{
	    std::cout<<"Already reach to the end of the list. (List length = "<<n<<")\n";
	    return root;
	}
    }
    // move both p1 and p2 until p2 reaches the end of the tail
    while(p2 != NULL){
	p2 = p2->next;
	p1 = p1->next;
    }
    return p1;
}

// assume the input is neither head nor tail node
void LinkedList::removeNode(ListNode * node){
    if (node == NULL)
	return ;

    if(node->next != NULL){
	 // copy next node data to override current node
	ListNode * next_node = node->next;
	node->data = next_node->data;
	node->next = next_node->next;
	// delete the original next node
	delete next_node;
	next_node = NULL;
    }
   
    
}
