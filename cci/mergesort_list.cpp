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
/*
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
    }*/
ListNode * mergeSort(ListNode * left, ListNode * right){
    if(left== NULL) return right;
    if(right==NULL) return left;
    ListNode * mergeHead = NULL;
    if(left->data <= right->data){
	mergeHead = left;
	mergeHead->next = mergeSort(left->next, right);
    }else{
	mergeHead = right;
	mergeHead->next = mergeSort(left, right->next);
    }
    return mergeHead;
}

// split list then merge two heads
ListNode * merge(ListNode * head){
    if(head == NULL || head->next == NULL) return head;
    ListNode * first = head;
    /*
    ListNode * second = head->next;
    while(second != NULL && second->next != NULL){
	first = first->next;
	second = first->next->next;
	}*/
    ListNode *second = head;
    while(second!= NULL && second->next != NULL){
	first = first->next;
	second= second->next->next;
    }
    second = first->next;
    // break the list
    first->next = NULL;
    // cout<<"Right : ";
    // showList(second);
    return mergeSort(merge(head), merge(second));
}

// merge sort list O(n log n) using O(1) space leetcode version
/*
ListNode *sortList(ListNode *head) {  
    if(!head || !head->next) return head;
    return  merge(head);
}
*/
ListNode *sortList(ListNode *head) {  
    // Get length first  
    ListNode* p = head;  
    int len = 0;  
    while (p != NULL)  
    {  
	p = p->next;  
	len++;  
    }  
    ListNode* fakehead = new ListNode(-1);  
    fakehead->next = head;       
    for (int interval = 1; interval <= len; interval = interval * 2)  
    {  
	ListNode* pre = fakehead;  
	ListNode* slow = fakehead->next, *fast = fakehead->next;  
	while (fast != NULL || slow != NULL)  
	{  
	    int i = 0;  
	    while (i< interval && fast != NULL)  
	    {  
		fast = fast->next; //move fast pointer ahead 'interval' steps  
		i++;  
	    }  
	    //merge two lists, each has 'interval' length  
	    int fvisit = 0, svisit = 0;  
	    while (fvisit < interval && svisit<interval && fast != NULL && slow != NULL) {  
		if (fast->data < slow->data)  
		{  
		    pre->next = fast;  
		    pre = fast;  
		    fast = fast->next;  
		    fvisit++;  
		}  
		else  
		{  
		    pre->next = slow;  
		    pre = slow;  
		    slow = slow->next;  
		    svisit++;  
		}  
	    }  
	    while (fvisit < interval && fast != NULL)  
	    {  
		pre->next = fast;  
		pre = fast;  
		fast = fast->next;  
		fvisit++;  
	    }  
	    while (svisit < interval && slow != NULL)  
	    {  
		pre->next = slow;  
		pre = slow;  
		slow = slow->next;  
		svisit++;  
	    }  
	    pre->next = fast;  
	    slow = fast;  
	}  
    }  
    ListNode* newhead = fakehead->next;  
    delete fakehead;  
    return newhead;  
}  

int main(){
    ListNode * head = new ListNode(4);
    ListNode * n1 = new ListNode(3);
    ListNode * n2 = new ListNode(2);
    ListNode * n3 = new ListNode(1);
    ListNode * n4 = new ListNode(1);
    ListNode * n5 = new ListNode(2);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode * n = sortList(head);
    showList(n);
    return 0;
}
