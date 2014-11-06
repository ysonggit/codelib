#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> row, newrow;
    if(rowIndex < 0 ) return row;
    row.push_back(1); // row_0
    if(rowIndex == 0) return row;
    for(int i=1; i<=rowIndex; i++){
	newrow.clear();
	for(int j=0; j<i+1; j++){
	    if(j==0 || j==rowIndex) {
		newrow.push_back(1);
	    }else{
		// newrow[i] = row[i] + row[i-1]   
		newrow.push_back(row[j] + row[j-1]);        
	    }
	}
	// reset row
	row.clear();
	copy(newrow.begin(), newrow.end(), back_inserter(row));
	if(true){
	    for(int i : row){
		cout<<i<<" ";
	    }
	    cout<<endl;
	}
    }
        
    return row;
}

vector<int> getRow2(int rowIndex){
    vector<int> row;
    if(rowIndex<0) return row;
    row.resize(rowIndex+1);
    row[0] = 1;
    if(rowIndex == 0) return row; 
    for(int r = 1; r<=rowIndex; r++){
	for(int i=rowIndex; i>=0; i--){
	    if(i==0 || i==rowIndex){
		row[i] = 1;
	    }else{
		row[i] = row[i]+ row[i-1];
	    }
	}
    }
    return row;
}

int main(){
    vector<int> row = getRow(4);
    cout<<"----result------\n";
    for(int i : row){
	cout<<i<<" ";
    }
    cout<<endl;

    vector<int> row2 = getRow2(4);
    cout<<"----result 2------\n";
    for(int i : row2){
	cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
