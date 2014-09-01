#include <iostream>
#include <cstring>

using namespace std;

// given a string (represented by char array) replace whitespaces with %20
// that is, if the string contains N whitespaces and lenght is M, the new string length
// will be M + 2*N
// O(n) algorithm :
//  - replace whitespace from backend to front using two indices, front_idx & back_idx
//  - front_idx moves first, 
//  - back_idx moves after front_idx moves
//  - if front_idx meets a whitespace, it moves 1 step, and then insert %20, then back_idx moves 3 steps
void replaceWhitespace(char str[]){
    int pre_str_length = strlen(str) + 1;
    int whitespaces_num = 0;
    // count the number of whitespaces in the original string
    for (int i=0; i<pre_str_length; i++){
	if(str[i] == ' '){
	    whitespaces_num++;
	}
    }
    if (whitespaces_num == 0){
	// no whitespace at all, directly return without doing anything
	cout<<str<<endl;
	return ;
    }
    // create a new char array
    int new_str_length  = pre_str_length + 2 * whitespaces_num;
    char new_str[new_str_length];
    new_str[new_str_length-1] = '\0'; // do not forget this ending char
    
    int front_idx = pre_str_length - 2; // be careful here, this is the position of last non-\0 char in original string
    int back_idx = new_str_length - 2; // this is the position of last non-\0 char in the new string
    for (int i=0; i<pre_str_length-1; i++){
	if(str[front_idx] !=' '){
	    // not a whitespace, copy char to new string and then move both indices
	    new_str[back_idx] = str[front_idx];
	    back_idx--;
	}else{
	    // meets a whitespace, move front_idx 1 position ahead
	    // fill %20 in the new string then mvoe back_idx 3 position ahead
	    new_str[back_idx-2] = '%';
	    new_str[back_idx-1] ='2';
	    new_str[back_idx] = '0';
	    back_idx -=3;
	}
	front_idx--;
    }
    cout<<new_str<<endl;
}

int main(){
    char s1[] = "hello world";
    cout<<"Basic Knowledge of Char Array\n-------------------------------\n";
    cout<<"char s1[] = "<<s1<<endl;
    cout<<"sizeof(s1) = "<<sizeof(s1)<<endl;
    cout<<"sizeof(s1[0]) = "<<sizeof(s1[0]) <<endl;
    cout<<"The length of char array s1 = sizeof(s1)/sizeof(s1[0]) = strlen(s1) + 1 = "<<strlen(s1) + 1<<endl;
    cout<<"_______________________________"<<endl;
    cout<<"Test Replace Whitespace Function\n-------------------------------\n";
    replaceWhitespace(s1);
    char s2[] ="helloworldhello";
    char s3[] ="         ";
    replaceWhitespace(s2);
    replaceWhitespace(s3);
    return 0;
}
