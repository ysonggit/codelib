#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode * next;
  ListNode(int x) : val(x), next(NULL) {}
};

int getLength(ListNode *head){
  if(head == NULL) return 0;
  int l = 0;
  while(head != NULL){
    l++;
    head = head->next;
  }
  return l;
}
    
int sumTwoNodes(ListNode * n1, ListNode * n2, int & carry){
  if(n1 == NULL && n2 == NULL) return carry;
  int d1=0, d2=0;
  if(n1 == NULL && n2 != NULL){
    d2 = n2->val;
  }  
  if(n1!=NULL && n2 == NULL){
    d1 = n1->val;
  }
  if(n1!= NULL && n2!=NULL) {
    d1 = n1->val;
    d2 = n2->val;
  }
  int sum = (d1 + d2 + carry);
  carry = sum /10;
  return sum%10;
}
    
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  // 1. get length of two lists
  int len1 = getLength(l1);
  int len2 = getLength(l2);
  // 2. align two lists (numbers)
  int N = max(len1, len2);
       
  int carry = 0;
  ListNode * fakehead = new ListNode(-1);
  ListNode * cur = fakehead;
  for(int i=0; i<N; i++){
    int cur_digit = sumTwoNodes(l1, l2, carry);
    l1 = (l1 == NULL)? NULL : l1->next;
    l2 = (l2 == NULL)? NULL : l2->next;
    cur->next = new ListNode(cur_digit);
    cur = cur->next;
  }
  if(carry==1){
    ListNode * tail = new ListNode(1);
    cur->next = tail;
  }
  return fakehead->next;
}

int main(){
  ListNode * l1 = new ListNode(5);
  ListNode * l2 = new ListNode(5);
  ListNode * sum = addTwoNumbers(l1, l2);
  while(sum != NULL){
    cout<<sum->val<<"-";
    sum = sum->next;
  }
  cout<<endl;
  return 0;
}
