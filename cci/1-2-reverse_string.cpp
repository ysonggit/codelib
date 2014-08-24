#include <iostream>
#include <stdio.h>
#include <cstring> // for strlen

using namespace std;

void swapChars(char* a, char *b){
    char  tmp = *a;
    *a = *b;
    *b = tmp;
}

// given a null-terminated string *char
// return reversed string in form of *char
void reverse(char *str){
    // skip null pointer
    if (str== 0){
	return;
    }
    // skip empty string
    if(*str == 0 ){
	return;
    }
    char* end = str+strlen(str) - 1; // the last non-null character
    while(str < end){
	swapChars(str, end);
	str++;
	end--;
    }
}

void printChars(char *str){
    for(int i=0; i<strlen(str); i++){
	cout<<*(str+i);
    }
    cout<<endl;
}

int main(){
    char a1[]= "this is a message";
    reverse(a1);
    printChars(a1);
    char a2[] ="";
    reverse (a2);
    printChars(a2);
    return 0;
}
