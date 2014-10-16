#include <iostream>
#include <algorithm> // std::max
#include "linkedlist.h"

using namespace std;

struct BitSum{
    BitSum(){
	carry = 0;
	sum = 0;
    }
    int carry;
    int sum;
};

// given a list contains 7-1-6 = number 617
// append N=3 zeros to make it 7-1-6-0-0-0 = 000617
void padListWithZeros(LinkedList & l, int N){
    ListNode * tmp = l.root;
    for(int i=0; i<N; i++){
	l.append(0);
    }
}

void addNodes(ListNode * n1, ListNode * n2, BitSum & result){
    int sum = (n1->data + n2->data) + result.carry;
   
    if(false){
	cout<<n1->data<<"+"<<n2->data<<"+"<<result.carry<<endl;
    }
    result.sum = sum % 10;
    result.carry = (sum >= 10) ? 1 : 0;
    if(false){
	cout<<"sum = "<<result.sum<<endl;
	cout<<"carry = "<<result.carry<<endl;
    }
}

// this idea can be used to solve big number addition
// positive numbers only 
LinkedList addLists(LinkedList list1, LinkedList list2){
    cout<<"\n ";
    list1.reversePrint();
    cout<<"+";
    list2.reversePrint();
    cout<<"=";
    int l1 = list1.length();
    int l2 = list2.length();
    int l = max(l1, l2);
    if(l1 < l){
	padListWithZeros(list1, l-l1);
    }
    if(l2 < l){
	padListWithZeros(list2, l-l2);
    }
    LinkedList sum_list;
    // now list1 and list2 have the same length
    if(l == 0){
	return sum_list;
    }
    BitSum bs;
    for(int i=1; i<=l; i++){
	addNodes(list1.at(i), list2.at(i), bs);
	sum_list.append(bs.sum);
    }
    if(bs.carry > 0){
	sum_list.append(1);
    }
    return sum_list;    
}

int main(){
    LinkedList a;
    LinkedList b;
    addLists(a,b).reversePrint();
    a.append(7);
    a.append(1);
    a.append(6);
    
    b.append(2);
    b.append(9);
    b.append(5);
    LinkedList c = addLists(a, b);
    c.reversePrint();

    LinkedList d;
    d.append(9);
    d.append(9);
    d.append(8);
    d.append(3);
    LinkedList e = addLists(d, b);
    e.reversePrint();
    LinkedList f;
    for(int i=9; i>0; i--){
	f.append(i);
	f.append(i);
	f.append(i);
    }
    LinkedList g;
    for(int j=0; j<10; j++){
	g.append(j);
	g.append(j);
	g.append(j);
	g.append(j);
    }
    LinkedList h = addLists(f, g);
    h.reversePrint();
    
    return 0;
}

