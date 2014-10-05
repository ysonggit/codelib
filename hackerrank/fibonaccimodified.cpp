#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool checkInput(int a, int b, int n){
    if(a >=0 && a<=2 && b >=0 && b<=2 && n >=3 && n <=20){
        return true;
    }
    return false;
}


unsigned long long int fibonacciModified(int a, int b, int n){
    int result[2] = {a, b};
    if (n <2)
	return result[n];

    int sum = 0;
    int f_n_1 = a;
    int f_n_2 = b;
    for(int i=2; i<=n; i++){
	sum = f_n_1 * f_n_1 + f_n_2;
	f_n_2 = f_n_1;
	f_n_1 = sum;
    }
    return sum;
}

int main(){
    int a, b, N;
    cin>>a>>b>>N;
    if(checkInput(a, b, N)){
        cout<<fibonacciModified(a, b, N)<<endl;
    }else{
        cout<<"Check input range: 0 <= A,B <=2; 3<=N<=20."<<endl;
        exit(1);
    }
    
    return 0;
}
