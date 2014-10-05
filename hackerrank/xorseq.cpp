#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
using namespace std;

/*
  array[] -- array of n elements
  data[] -- temp array to store current combination
  start & end -- starting and ending indices in pt_idx
  idx --  current index in data
  r -- size of a combination 

  return a combination of points indices (size of K)
 */
struct Comb{
    vector<unsigned int > indices;
  
};

ostream & operator << (ostream &lhs, const Comb & cb){
    // lhs << " Combination (indices) : " << endl;
    for(unsigned int i : cb.indices){
        lhs << i << " ";
    }
    lhs <<endl;
    return lhs;
}

unsigned int getXor(Comb comb){
    unsigned int result = comb.indices[0];
    for(int i=1; i<comb.indices.size(); i++){
        result = result ^ (comb.indices[i]);
    }

    return result;
}

bool inSet(vector<Comb> combs, Comb cb){
    for(Comb c: combs){
       if(c.indices.size()== cb.indices.size()){
           sort(c.indices.begin(), c.indices.end());
           sort(cb.indices.begin(), cb.indices.end());
           unsigned int c_ints [c.indices.size()];
           for(int i=0; i<c.indices.size();i++){
               c_ints[i] = c.indices.at(i);
           }
           if(equal(cb.indices.begin(), cb.indices.end(), c_ints))
               return true;
        }
    }
    return false;
}

void combination(unsigned int * array,  unsigned int data[], int start, int end, int idx, int r, vector<Comb> & allcombs){
    if(idx == r){
        // reach the base case: one combination
        Comb cb;
        for(int j=0; j<r; j++){
            // all point indices are in data[]
            //cout<<data[j]<<" ";
            cb.indices.push_back(data[j]);
        }
        //cout<<endl;
        if(!inSet(allcombs, cb)){
            allcombs.push_back(cb);
            // cout<<cb;
        }
    }

    for(int i=start; i<=end && end-i+1 >= r-idx; i++){
        data[idx] = array[i];
        combination(array, data, i+1, end, idx+1, r, allcombs);
    }
}

void getAllCombinations(unsigned int * array, int n, int r, vector<Comb> & allcombs){
    unsigned int  data[r];
    combination(array, data, 0, n-1, 0, r, allcombs);
}
 

int main() {

    int N;
    cin>>N;
    if(N<0 || N>100000){
        return 0;
    }

    unsigned int * array = new unsigned int  [N];
    
    for(int i=0; i<N; i++){
        unsigned int  A;
        cin>>A;
        if(A < 0 || A >= UINT_MAX)
            return 0;

        array[i] = A;
        
    }
    vector<Comb> allcombs;
    for(int i=1; i<=N; i++){
        getAllCombinations(array, N, i, allcombs);
    }

    int n = allcombs.size();
    map<unsigned int , int> num_freq;
    for(int i=0; i<n; i++){
        Comb cb = allcombs[i];
        unsigned int  res = getXor(cb);
        if(num_freq.find(res) == num_freq.end()){
            num_freq[res] = 1;
        }else{
            num_freq[res] ++;
        }
    }

    // iterate all counts, find the minimum nuber that shows most frequently
    int  max_count = 0;
    unsigned int   min_num = UINT_MAX;
    unsigned int   num_most_freq;
    set<unsigned int > multi_most_freq;
    for(auto iter = num_freq.begin(); iter!= num_freq.end(); ++iter){
        if(iter->second > max_count ){
            max_count = iter->second;
            num_most_freq = iter->first;
        }
    }
    multi_most_freq.insert(num_most_freq);
    for(auto iter = num_freq.begin(); iter!= num_freq.end(); ++iter){
        if(iter->second == max_count && multi_most_freq.find(num_most_freq) == multi_most_freq.end() ){
            multi_most_freq.insert(iter->first);
        }
    }
    if(multi_most_freq.size()>1){
        vector<unsigned int> myvec (multi_most_freq.begin(), multi_most_freq.end());
        sort(myvec.begin(), myvec.end());
        num_most_freq = myvec[0];
    }
        
    
    cout<<num_most_freq<<" "<<max_count<<endl;
    return 0;
}
