#include <iostream>

using namespace std;


// # ways of make changes of N cents =
//     # ways of make changes of N cents using 0 quarters +
//     # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  1 quarters +
//     # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  2 quarters +
//      .. 
//     # ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  N/25 quarters 
//  =  # ways of make changes of N cents using 0 quarters +
//     # ways of make changes of N-25 cents using 0 quarters +
//     # ways of make changes of N-50 cents using 0 quarters +
//     # ways of make changes of N-75 cents using 0 quarters +
//     ..
//     1 (ways of make changes of 0 (N - 25 x N/25) cents using 0 quarters)
int ways_makechanges(int N, int *coins, int index){
  int ways = 0;
  // length of coins is 4 ( only 4 kinds of coins)
  // 3 is from using length of coins - 1
  // when index reaches the last denom, return 1
  if (index >= 3) return 1; 
  // given total N cents, divide N by the value of each coin to decide how many subproblems are needed
  int coin_value = *(coins+index);
  int k = N/coin_value;
  for(int i=0; i<=k; i++){ // note: take care of <=
    int RemainingCents = N - coin_value*i;
    ways += ways_makechanges(RemainingCents, coins, index+1);
  }
  
  return ways;
}

void makechange(int n){
  int coins [] = {25, 10, 5, 1};
  int number = 0;
  if(n>=25){
    number = ways_makechanges(n, coins, 0);
  }else if(n < 25 && n>= 10){
    number = ways_makechanges(n, coins, 1);
  }else if(n < 10 && n>= 5){
    number = ways_makechanges(n, coins, 2);
  }else if(n < 5 && n>=1){
    number = ways_makechanges(n, coins, 3);
  }else{
    number = 0;
  }
  cout<<"There are "<<number<<" ways to make "<<n<<" cents using quarters, dimes, nickels and cents.\n";
}

int main(){
  makechange(1);
  makechange(5);
  makechange(10);
  makechange(25);
  return 0;
}
