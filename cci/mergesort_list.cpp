#include "linkedlist.h"

using namespace std;

void showList(ListNode * n ){
    ListNode *cur = n;
    while(cur != NULL){
	cout<<cur->data<<" -> ";
	cur = cur->next;
    }
    cout<<"NULL"<<endl;
}

//http://fisherlei.blogspot.com/2013/12/leetcode-sort-list-solution.html    
ListNode *mergeSort(ListNode *lefthead, ListNode *righthead){
    if(lefthead == NULL && righthead == NULL) return NULL;
    if(lefthead == NULL) return righthead;
    if(righthead == NULL) return lefthead;
    // create a temp list node to lead the merge list
    // return mergedhead->next
    ListNode * mergedhead = new ListNode(0); 
    ListNode * cur = mergedhead;
    while(lefthead != NULL || righthead != NULL){
	if(lefthead != NULL && righthead != NULL){
	    if(lefthead->data <= righthead->data){
		cur->next = lefthead;
		lefthead = lefthead->next;
	    }else{
		cur->next = righthead;
		righthead = righthead->next;
	    }
	}else if(lefthead != NULL ){
	    cur->next = lefthead;
	    lefthead = lefthead->next;
	}else{
	    cur->next = righthead;
	    righthead = righthead->next;
	}
	cur = cur->next;
    }
    return mergedhead->next;
}
// split list then merge two heads
ListNode * merge(ListNode * head){
    if(head == NULL || head->next == NULL) return head;
    ListNode * first = head;
    ListNode * second = head->next;
    while(second != NULL && second->next != NULL){
	first = first->next;
	second = first->next->next;
    }
    second = first->next;
    // break the list
    first->next = NULL;
    return mergeSort(merge(head), merge(second));
}

// merge sort list O(n log n) using O(1) space 
ListNode *sortList(ListNode *head) {  
    if(!head || !head->next) return head;
    return  merge(head);
    cout<<"------------------------\n";
    
}


int main(){
    ListNode * head = new ListNode(4);
    ListNode * n1 = new ListNode(3);
    ListNode * n2 = new ListNode(2);
    ListNode * n3 = new ListNode(1);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    ListNode * n = sortList(head);
    showList(n);
    return 0;
}
