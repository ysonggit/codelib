#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iostream>

struct ListNode{
     ListNode(int d){
          data = d;
          next = NULL;
     }
     int data;
     ListNode* next;
};

struct LinkedList{
     LinkedList() {
          root = NULL;
     }
     ListNode * root;
     ListNode * at(int );
     void print();
     void append(int );
     // 2-1
     void removeDups();
     // 2-2
     ListNode * nthToLast(int );
     // 2-3
     void removeNode(ListNode * );
};

