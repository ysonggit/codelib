#include "linkedlist.h"

using namespace std;

// Compile: g++ 2-1-remove_duplicates.cpp linkedlist.cpp 

int main(){
    LinkedList mylist;
    for(int i=0; i<10; i++)
        mylist.append(i);

    for(int i=0; i<10; i++)
        mylist.append(i);

    mylist.print();

    mylist.removeDups();
    mylist.print();
    return 0;
}
