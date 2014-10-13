#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

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
     void append(int );
     void removeDups();
};

