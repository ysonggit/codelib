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
    return 0;
}
