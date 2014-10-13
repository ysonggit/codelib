#include "linkedlist.h"

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

