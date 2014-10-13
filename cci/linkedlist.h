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
     void print();
     void append(int );
     void removeDups();
};

