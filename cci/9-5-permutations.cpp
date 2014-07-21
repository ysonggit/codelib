/*
A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation.
Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

Below are the permutations of string ABC.
ABC, ACB, BAC, BCA, CAB, CBA
 */
#include <stdio.h>

// swap values at two pointers
void swap(char* x, char* y){
  char temp = *x;
  *x = *y;
  *y = temp;
}

// inputs:
// 1. string 
// 2. starting index of string
// 3. ending index of string
void permutation(char* p_str, int i, int n){
  if(i == n){
    printf("%s\n", p_str);
  }
  else{
    for(int j = i; j<=n; j++){
      swap((p_str+i), (p_str+j));
      permutation(p_str, i+1, n);
      swap((p_str+i), (p_str+j)); 

    }
  }
}

int main(){
  char A[] = "abcd";
  permutation(A, 0, 3); 
  return 0;
}

