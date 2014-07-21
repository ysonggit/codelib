#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<vector<T> > getAllSubsets(vector<T> given_set, int index){
  vector<vector<T> > subsets;
  // base case
  if( index < 0){
    // add empty set
    vector<T> emptyset;
    subsets.push_back(emptyset);
    return subsets;
  }else{
    // make sure index and index + 1  not out of range here
    T element = given_set.at(index);
    // add this element to each subset and return
    subsets = getAllSubsets(given_set, index-1);
    vector<vector<T> > new_subsets;
    for(int k= 0 ; k<subsets.size(); k++){
      vector<T> cur_set = subsets.at(k);
      vector<T> new_set;
      new_set.assign(cur_set.begin(), cur_set.end());
      new_set.push_back(element);
      new_subsets.push_back(new_set);
      
    }
    for(int j=0; j<new_subsets.size(); j++){
      subsets.push_back(new_subsets.at(j));
    }
    
  }
  
  return subsets;
}

template<class T>
void showSet(vector<T> a_set){
  cout<<"{ ";
  for(int i=0; i<a_set.size(); i++){
    cout<<a_set.at(i)<<" ";
  }
  cout<<"}";
}

template<class T>
void showPowerset(vector<vector<T> > p_set){
  cout<<"{ ";
  for(int i=0; i<p_set.size(); i++){
    showSet(p_set.at(i));
    cout<<"  ";
  }
  cout<<"}"<<endl;
}

int main(){
  vector<char> charset;
  charset.push_back('a');
  charset.push_back('b');
  charset.push_back('c');
  showSet(charset);
  cout<<" ===================== "<<endl;
  vector<vector<char> > allcharsubsets=  getAllSubsets(charset, 2);
  showPowerset(allcharsubsets);
  return 0;
}
