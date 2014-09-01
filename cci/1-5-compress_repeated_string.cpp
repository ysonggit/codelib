#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

// given a string aabcccdddd determine the repeatation and
// compress to a2bc3d4
// it the compressed lenght is not shorter than the original length,
// then should return the original one

void compressRepeatedString(char str[]){
    cout<<"Original String : "<<str<<endl;
    int pre_str_length = strlen(str) + 1; // the last one is char \0
    if (pre_str_length <= 1){
	// empty string
	cout<<"Empty string!"<<endl;
	return ;
    }
    if (pre_str_length == 2){
	// only one char in the string (the last one is \0)
	cout<<str<<endl;
	return ;
    }

    map<char, int> charsMap; // map a single char with its repeatation times
        
    char last_char = str[0];
    int cur_char_repeats = 1;
    charsMap.insert(map<char, int>::value_type(str[0], 1));
    for(int i=1; i<pre_str_length-1; i++){
	char cur_char = str[i];

	if(charsMap.find(cur_char) != charsMap.end() ){
	    // current char is aleady in the map, then update the corresponding repeatation times
	    int last_times = charsMap[cur_char];
	    last_times++;
	    charsMap[cur_char] = last_times;
	}else{
	    charsMap.insert(map<char, int>::value_type(cur_char, 1));
	}
		    
    }
    int new_str_length = charsMap.size()*2;
  
    if(new_str_length >= strlen(str)){
	// no better than original 
	cout<<str<<endl;
	return ;
    }else{
	string new_str;
	for(auto iter = charsMap.begin(); iter != charsMap.end(); ++iter){
	    // directly use string(iter->first) will cause a compiling error:
	    // invalid conversion from 'const char*' to 'char'
	    // in C++, char with " " and ' ' are different
	    // http://stackoverflow.com/questions/22072846/problems-with-invalid-conversion-from-const-char-to-char-fpermissive
	    // convert char to string safely
	    stringstream sschar, ssint;
	    sschar<<iter->first;
	    ssint<<iter->second;
	    new_str += sschar.str()+ssint.str();
	}	
	cout<<new_str<<endl;
    }
   
}


int main(){
    char s1[] = "aabcccdddde";
    compressRepeatedString(s1);
    
    char s2[] = "aaaaa";
    compressRepeatedString(s2);
    
    char s3[] = "";
    compressRepeatedString(s3);
    char s4[] = "aabb"; //should return aabb
    compressRepeatedString(s4);
    return 0;
}
