#include <string>
#include <iostream>

using namespace std;
// given 2 string s1, and s2,
// write a function bool isRotation(string s1, string s2)
// to check if the one string is a rotation of another
// e.g.
//    s1 = waterbottle
//    s2 = erbottlewat
// should return true 


// for a string s1 = xy, if it is rotated to be s2 = yx
// we always have s1s1 contains s2, namely, s2 is a substring of s1s1
// Great idea!
bool isRotation(string s1, string s2){
    // 1. repeats s1 
    string s1s1 = s1+s1;
    // 2. check is s2 is a substring of s1s1
    // string::npos = -1
    if(s1s1.find(s2) != string::npos){
	// indeed a substring
	return true;
    }
    return false;
}

void test(string s1, string s2){
    if(isRotation(s1, s2)){
	cout<<"string s2 : "<<s2 <<" is a rotation of s1 : "<<s1<<endl;
    }else{
	cout<<"string s2 : "<<s2 <<" is NOT rotation of s1 : "<<s1<<endl;
    }    
}

int main(){
    string s1("I am hungry");
    string s2("hungryI am ");
    string s3("hungry am I");
    test(s1, s2); //true
    test(s1, s3); //false
    return 0;
}
