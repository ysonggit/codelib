#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
    list<int> mylist {1, 2, 3, 4, 5};
    for(int i : mylist){
	cout<<i<<" ";
    }
    cout<<endl;

    vector<int> myvec (mylist.begin(), mylist.end());
    for(int j : myvec){
	cout<<j<<" ";
    }
    cout<<endl;

    for(int i=0; i<myvec.size(); i++){
	for(int j=i+1; j<myvec.size(); j++){
	    cout<<" pair composed by two elements in myvec : "<<myvec.at(i)<<", "<<myvec.at(j)<<endl;
	}
    }
    return 0;
}
