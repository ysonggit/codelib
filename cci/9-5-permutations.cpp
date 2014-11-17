/*
A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation.
Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

Below are the permutations of string ABC.
ABC, ACB, BAC, BCA, CAB, CBA
 */
#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

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


// leetcode problem
/*  if pass the last position in given number aray
        store number and return
    else
        for each bit in the array
            if is marked used, 
                go to next bit
            else 
                place this bit in current position
                mark it used
                recursive call this func to permute rest bits 
                mark it un-used
    */
void generatePermutation(vector<int> &num, int n, vector<int> & sol, vector<vector<int> >& allpermus, vector<bool> & visited){
    if(n == num.size()){
	allpermus.push_back(sol);
	return;
    }
    for(int i=0; i< num.size(); i++){
	if(visited[i] == false){
	    visited[i] = true;
	    sol.push_back(num[i]);
	    generatePermutation(num, n+1, sol, allpermus, visited);
	    visited[i] = false;
	    sol.pop_back();
	}
    }
}
    
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > results;
    vector<int> sol;
    vector<bool> visited(num.size());
    for(bool v : visited){
	v = false;
    }
    generatePermutation(num, 0, sol, results, visited);
    return results;
}

void printAllPermutations(const vector<vector<int> > & all){
    for(vector<int> pm : all){
	for(int i : pm ){
	    std::cout<<i<<", ";
	}
	std::cout<<std::endl;
    }
}

int main(){
  char A[] = "abcd";
  permutation(A, 0, 3); 
  vector<int> B({1,2,3});
  vector<vector<int> > allpermus = permute(B);
  printAllPermutations(allpermus);
  vector<int> C({0,1});
  vector<vector<int> > allpermus2 = permute(C);
  printAllPermutations(allpermus2);
  return 0;
}

