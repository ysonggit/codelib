#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {
    if(n==0 || n==1) return n;
    int count = 1;
    for(int i=1; i<n; i++){
	if(A[i-1] != A[i]){
	    cout<<"A["<<count<<"]=A["<<i<<"]="<<A[i]<<endl;
	    A[count] = A[i];
	    count++;
	}
    }   
    return count;
}

int main(){
    int A[5] = {
	1, 1, 2, 2, 3
    };
    removeDuplicates(A, 5);
    
    return 0;
}
