#include "linkedlist.h"

using namespace std;

ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL) return head;
    ListNode * fakehead = new ListNode(-1);
    fakehead->next = head;
    ListNode * pre = fakehead;
    ListNode * cur = head;
    while(cur != NULL){
        while(cur->next != NULL && (pre->next)->data == (cur->next)->data){
            // duplicate numbers
            cur = (cur->next);
        }
        
        pre = cur;
        cur = cur->next;
    }
    return fakehead->next;
}

void printList(ListNode * head){
    ListNode * cur = head;
    while(cur != NULL){
        cout<<cur->data<<" - ";
        cur=cur->next;
    }
    cout<<endl;
}

int main(){
    LinkedList mylist;
    for(int i=0; i<4; i++)
        mylist.append(1);

    for(int i=2; i<4; i++)
        mylist.append(i);

    mylist.print();

    ListNode * listhead = deleteDuplicates(mylist.root);
    printList(listhead);
    return 0;
}
