#include "linkedlist.h"
#include <iostream>

using namespace std;

ListNode * loopBeginning(const LinkedList & l){
    // 1. Create two pointers, fast and slow
    ListNode * fast = l.root;
    ListNode * slow = fast;
    bool acyclic = false;
    // 2. Move fast forward 2 steps each times,
    //    move slow forward 1 step each time
    while (fast != NULL && fast->next != NULL){
	// note for a loop list, this is always true
	fast = (fast->next)->next;
	slow = slow->next;
	if(slow == fast){
            acyclic = true;
	    // 3. When they collide, reset slow to the list head
	    slow = l.root;
	    break;
	}
    }
    if(!acyclic) return NULL;
    // 4. Move slow and fast forward 1 step each time
    // return the new collide point
    while(fast!= slow){
	fast = fast->next;
	slow = slow->next;
    }
    return slow;
}

int main(){
    LinkedList looplist;
    for(int i=0; i<20; i++){
	looplist.append(i);
	// let the tail node point to a middle node
    }
    ListNode * tail = looplist.at(20);
    tail->next = looplist.at(10);
    ListNode * loopstart = loopBeginning(looplist);
    cout<<"Loop Beginning Node.data = "<<loopstart->data<<endl;

    LinkedList nonlooplist;
    for(int i=1; i<3; i++){
        nonlooplist.append(i);
    }
    if(loopBeginning(nonlooplist) == NULL){
        cout<<"It is a nonloop list"<<endl;        
    }
    return 0;
}
