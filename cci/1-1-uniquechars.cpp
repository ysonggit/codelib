#include <iostream>
#include <vector>
#include <string>

using namespace std;

// function input : a given string
// output: boolean value:
//         true if the given string is composed of all unique ASCII characters
//         otherwise, false

// you know, ASCII set contains 256 characters
// Each character in a string is already ascii

// the question is similar to :
// given a set of numbers, determine whether there exists duplicated numbers
bool hasAllUniqueChars(string s){
    if(s.length()==0){
	cout<<"EMPTY STRING GIVEN!"<<endl;
	return true;
    }
    if(s.length()>256){
	return false;
    }
	    
    vector<int> ascii(256); // initially containing 256 zeros
    // let each place in ascii represent the times that character shows up in given string
    // for example, ascii[97] = 3, means character "a" appears for 3 times in the string
    // iterate every characters in the string
    for(int c : s){
	//cout<<c<<" ";
	// c is the character in string
	ascii[c]++;	
    }
    for(int i=0; i<ascii.size(); i++){
	if(ascii[i] > 1){
	    return false;
	}
    }
    return true;
}

void test(string s){
    if(hasAllUniqueChars(s)){
	cout<<"given string contains all unique ascii characters."<<endl;
    }else{
	cout<<"given string contains duplicated ascii characters."<<endl;
    }
}

int main(){
    string s1 = "abcdfeghijklmnopqrstuvwxyz";
    test(s1);
    string s2 ="aaaaaacccccddddd";
    test(s2);
    string s3 ="";
    test(s3);
    string s4 ="  "; // double spaces
    test(s4);
    string s5 =" "; // single space
    test(s5);
    return 0;
}
