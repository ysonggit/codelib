#include <iostream>
#include "linkedlist.h"

using namespace std;

int main(){
    LinkedList mylist;
    for(int i=0; i<10; i++){
	mylist.append(i);
    }
    ListNode * to_remove = mylist.at(3);
    mylist.removeNode(to_remove);
    mylist.print();
    return 0;
}
