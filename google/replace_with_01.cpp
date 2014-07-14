/* http://www.careercup.com/question?id=5192571630387200

  Given a string (for example: "a?bc?def?g"), write a program to generate all the possible strings by replacing ? with 0 and 1. 
Example: 
Input : a?b?c? 
Output: a0b0c0, a0b0c1, a0b1c0, a0b1c1, a1b0c0, a1b0c1, a1b1c0, a1b1c1.
 */

#include <stdlib.h>
#include <iostream>

using namespace std;

void print_char(char buffer[],  int length){
  for(int i=0; i< length; i++){
    cout<<buffer[i];
  }
  cout<<endl;
}

bool replace(char buffer[], int idx, char c, int length){
  bool not_base_case; 
  int pos = idx;
  while (pos < length){
    if (buffer[pos] == '?'){
      break;
    }
    pos++;
  }
    
  if (pos < length){
    buffer[pos] = c;
    if(replace( buffer, pos+1, '0', length)){
      replace( buffer, pos+1, '1', length);
    }
    buffer[pos] = '?';
    not_base_case= true;
  }else{
    // base case: all question marks are replaced with 0 or 1
    not_base_case = false;
    print_char(buffer, length);
  }
  // keep on recursion if not all the question marks are replaced
  return not_base_case;
}

void replace_questionmark(char buffer[], int length){
  if(replace(buffer, 0, '0', length)){
    replace(buffer, 0, '1', length);
  }
}

int main(){
  char c1[] = "a?b?c?";
  char c2[] = "";
  char c3[] = "???";
  
  int l1 = strlen(c1); //sizeof(c1)/sizeof(c1[0]);
  replace_questionmark(c1, l1);
 
  int l2 = strlen(c2);
  replace_questionmark(c2, l2);
  
  int l3 = strlen(c3);
  replace_questionmark(c3, l3);
  
  return 0;
}
