#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// assume it is case sensitive, and do not consider any whitespace

bool IsPermutation(string s1, string s2){
    if(s1.size() == 0 && s2.size() == 0)
	return true;

    // 1. remove whitespaces in two strings
    auto end_pos_1 = std::remove(s1.begin(), s1.end(), ' ');
    s1.erase(end_pos_1, s1.end());
    auto end_pos_2 = std::remove(s2.begin(), s2.end(), ' ');
    s2.erase(end_pos_2, s2.end());

    // 2. Sort characters in two given strings
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    if(s1.compare(s2) != 0){
	return false;
    }
    return true;
}

void test(string s1, string s2){
    if(IsPermutation(s1, s2)){
	cout<<s1<<" IS A PERMUTATION OF "<<s2<<endl;
    }else{
	cout<<s1<<" IS NOT A PERMUTATION OF "<<s2<<endl;
    }
}

int main(){
    string s1 ("this is a dog");
    string s2 ("thisadogis");
    string s3 ("godasithis ");
    string s4 (" this is a god");
    string s5 ("");
    string s6 ("");
    string s7 ("i like dogs");
    test(s1, s2);
    test(s2, s3);
    test(s3, s4);
    test(s4, s7);
    test(s5, s6);
    return 0;
}
