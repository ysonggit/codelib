#include <iostream>
#include "linkedlist.h"
using namespace std;

int main(){
    LinkedList mylist;
    for(int i=0; i<20; i++){
	mylist.append(i);
    }

    ListNode * n1 = mylist.nthToLast(1);
    cout<<n1->data<<endl;
    ListNode * n2 = mylist.nthToLast(20);
    cout<<n2->data<<endl;
    return 0;
}
