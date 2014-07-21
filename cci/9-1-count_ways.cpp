#include <iostream>

using namespace std;

// input : number of steps
// output : # of ways to finish the step
// for example: n= 3 steps, count_of ways include: 1,1,1; 1,2; 2,1; 3;
// assume the n is not very large so that the result will not be overflowed
int count_stepways(int n){
  // base cases
  if (n < 0){
    return 0;
  }
  if(n ==0 ){
    return 1;
  }
  int counts = count_stepways(n-1) + count_stepways(n-2) + count_stepways(n-3);
  return counts; 
}


int main(){
  cout<<"Test 1: n= 3"<<endl;
  cout<<count_stepways(3)<<" ways"<<endl;

  cout<<"Test 2: n= 6"<<endl;
  cout<<count_stepways(6)<<" ways"<<endl;
  return 0;
}
