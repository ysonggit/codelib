#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isValidGroup(vector<char> & line){
    map<char, int> cache;
    for(char c : line){
	if(c!='.'){
	    if(cache.find(c)==cache.end()){
		cache[c] = 1;
	    }else{
		return false;   
	    }
	}
    } 
    return true;
}

bool isValidSudoku(vector<vector<char> > &board) {
    if(board.size() !=9 || board[0].size()!=9 ) return false;
    // check each row
    for(vector<char> row : board){
	if(!isValidGroup(row)) return false;
    }
    // check each column
    for(int i=0; i<9; i++){
	// create column
	vector<char> col;
	for(int c=0; c<9; c++){
	    col.push_back(board[c][i]);
	}
	if(!isValidGroup(col)){
	    return false;
	}
    }
    // check each sub-grid
    for(int g=0; g<9; g++){
	// create grid
	vector<char> grid(9);
	for(int k=3*g/3; k<3*g/3 +3; k++){ // row idx
	    for(int j=3*g%3; j < 3*g%3 + 3; j++){//col idx
		grid.push_back(board[k][j]);
	    }
	}
	if(!isValidGroup(grid)){
	    return false;
	}
    }
    return true;
}

bool test(vector<vector<char> > &board){
    if(isValidSudoku(board)){
	cout<<"valid\n";
    }else{
	cout<<"false\n";
    }
    
}

int main(){
    char board[9][9] ={
	{".87654321"},
	{"9........"},
	{"8........"},
	{"7........"},
	{"6........"},
	{"5........"},
	{"4........"},
	{"3........"},
	{"2........"}
    };
    vector<vector<char> > sudoku;
    for(int i=0; i<9; i++){
	sudoku[i].assign(board[i], 9);
    }
    test(sudoku);
    
    return 0;
}
