#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


// the parentheses is represented by a string :(())() is stored as
// "("  "("  ")"  ")"  "(" ")"
// insert a pair of "(" ")" into the vector
string insertParentheses(string ps, int index_of_left_paren){
  size_t len_to_left_paren = index_of_left_paren+1;
  string prefix = ps.substr(0, len_to_left_paren);
  string postfix = ps.substr(index_of_left_paren+1); // to the end
  return prefix+string("()")+postfix;
}


// recursively generate parentheses:
// if n= 1, return ()
// if n = 2
// return ()(), (())
// if n= 3
// return ()()() ()(()) (())() ((()))
set<string> getNPairsParentheses(int n){
  set<string> n_parens;
  //base case
  if(n == 0){
    n_parens.insert("");
    return n_parens;
  }else if (n==1){
    n_parens.insert(string("()") );
    return n_parens;
  }else{
    // solution of f(n) is based on solution of f(n-1)
    set<string> n_1_parens = getNPairsParentheses(n-1);
    for(auto s : n_1_parens){
      // for each parentheses, iterate it and finds the index of left "("
      for(int i = 0; i< s.length(); i++){
        if(s.compare(i,1, "(") ==0 ){ // they are equal
          string newstr = insertParentheses(s, i);
          if(n_parens.find(newstr) == n_parens.end()){
            n_parens.insert(newstr);
          }
        }
        string newstr2 = s+string("()");
        if (n_parens.find(newstr2) == n_parens.end()){
          n_parens.insert(newstr2);
        }
      }
    }
  

  }
  return n_parens;
}


int main(){
  // string ps = "(())()";
  cout<<" ========= test Parentheses function  ============ "<<endl;
  // cout<<insertParentheses(ps, 1)<<endl;
  // cout<<insertParentheses(ps, 4)<<endl;
  set<string> nps=  getNPairsParentheses(3);
  for(auto s : nps){
    cout<<s<<""<<endl;
  }
  return 0;
}
