#include <iostream>
#include "linkedlist.h"

// this solution assumes x is contained in the list
LinkedList partitionList(LinkedList l, int x){
    // 1. create two lists
    LinkedList list1;
    LinkedList list2;
    if(l.contains(x)){
	list2.append(x);
    }
    // 2. copy original list root
    ListNode * tmp  = l.root;
    // 3. iterate the original list, seperate it
    int count = 0;
    while(tmp != NULL){
	int cur_val = tmp->data;
	if(cur_val >= x){
	    if(count==0 && cur_val == x){
		// if list does not contain x
                // this one will never be true
		count++;
	    }else{
		list2.append(cur_val);
	    }
	}else{
	    list1.append(cur_val);
	}
	tmp = tmp->next;
    }
    //  4. merge the two lists: list1->list2
    ListNode * tmp2 = list2.root;
    while(tmp2 != NULL){
	list1.append(tmp2->data);
	tmp2 = tmp2->next;
    }
    return list1;
}


int main(){
    LinkedList mylist;
    for(int i=20; i>0; i--){
	if(i!=10)
	    mylist.append(i);
    }
    LinkedList newlist = partitionList(mylist, 12);
    newlist.print();

    LinkedList newnewlist = partitionList(newlist, 10);
    newnewlist.print();
    
    return 0;
}
