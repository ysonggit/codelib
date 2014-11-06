#include "linkedlist.h"

using namespace std;

// get list length
int listLength(ListNode * head){
    int length = 0;
    ListNode * cur = head;
    while(cur != NULL){
	cur=cur->next;
	length++;
    }
    return length;
}


void showList(ListNode * n ){
    ListNode *cur = n;
    while(cur != NULL){
	cout<<cur->data<<" -> ";
	cur = cur->next;
    }
    cout<<"NULL"<<endl;
}

//http://fisherlei.blogspot.com/2013/12/leetcode-sort-list-solution.html    
ListNode *mergeList(ListNode *lefthead, ListNode *righthead){
    if(lefthead == NULL && righthead == NULL) return NULL;
    if(lefthead == NULL) return righthead;
    if(righthead == NULL) return lefthead;
    // create a temp list node to lead the merge list
    // return mergedhead->next
    ListNode * mergedhead = new ListNode(0); 
    ListNode * cur = mergedhead;
    while(!lefthead || !righthead){
	if(!lefthead && !righthead){
	    // cout<<"sort "<<lefthead->data<<" "<<righthead->data<<endl;
	    if(lefthead->data <= righthead->data){
		cur->next = lefthead;
	    }else{
		cur->next = righthead;
	    }
	}else if(!lefthead){
	    cur->next = righthead;
	}else{
	    cur->next = lefthead;
	}
	cur = cur->next;
    }
    return mergedhead->next;
}

// merge sort list O(n log n) using O(1) space 
ListNode *sortList(ListNode *head) {  
    if(!head || !head->next) return head;
    showList(head);
    int length = listLength(head);
    ListNode * cur = head;
    for(int i=0; i<length/2; i++){
	if(cur->next != NULL){
	    cur = cur->next;
	}else{
	    cout<<"cur->val = "<<cur->data<<" next = null\n";
	    return NULL;
	}
    }
    ListNode *righthead = cur->next;
    cur->next = NULL; // trick: break the list
    ListNode *lefthead = head;
    //cout<<"length(right) = "<<listLength(righthead);
    //cout<<"\tlength(left) = "<<listLength(lefthead)<<endl;
    righthead = sortList(righthead);
    lefthead = sortList(lefthead);
    return mergeList(lefthead, righthead);
   
}


int main(){
    LinkedList mylist;
    for(int i=4; i>0; i--){
	mylist.append(i);
    }
    
    ListNode * n = sortList(mylist.root);
    showList(n);
    return 0;
}
