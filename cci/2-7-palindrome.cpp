#include <iostream>
#include "linkedlist.h"
#include <stack>
using namespace std;

bool isPalindrome(LinkedList l){
    if(l.root == NULL){
	return false;
    }
    ListNode * p1 = l.root;
    ListNode * p2 = p1;

    // p2 moves forward 2 steps each time
    // p1 moves forward 1 step each time
    int count = 0;
    while(p2 != NULL){
	p1 = p1->next;
	p2 = (p2->next);
	count++;
	if(p2 != NULL){
	    count++;
	    p2 = p2->next;
	}else{
	    break;
	}
    }
    // now p1 points to the middle of the list
    // count == list size
    // push the first half of list into stack
    stack<int> firsthalf;
    ListNode *  tmp = l.root;
    for(int i=0; i<count/2; i++){
	firsthalf.push(tmp->data);
	tmp = tmp->next;
    }
    if(true){
	cout<<"First half stack contains "<<firsthalf.size()<<" numbers\n";
	cout<<"Second half of list starts from p1->data = "<<p1->data<<endl;
    }
    
    ListNode * tmp2 = p1;
    while(!firsthalf.empty() && tmp2 != NULL){
	if(firsthalf.top() == tmp2->data){
	    tmp2 = tmp2->next;
	    firsthalf.pop();
	}else{
	    return false;
	}
    }
    return true;
}


int main(){
    LinkedList mylist1;
    for(int i=0; i<=3; i++){
	mylist1.append(i);
    }
    for(int j=2; j>=0; j--){
	mylist1.append(j);
    }
    cout<<"List: ";
    mylist1.print();
    if(isPalindrome(mylist1))
	cout<<"is Palindrome\n";
    else
	cout<<"is NOT Palindrome\n";

    LinkedList mylist2;
    for(int i=0; i<=3; i++){
	mylist2.append(i);
    }
    for(int j=3; j>=0; j--){
	mylist2.append(j);
    }
    cout<<"List: ";
    mylist2.print();
    if(isPalindrome(mylist2))
	cout<<"is Palindrome\n";
    else
	cout<<"is NOT Palindrome\n";
    
    
    return 0;
}
