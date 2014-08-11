#include <iostream>
#include <cmath>

using namespace std;

const int N = 8;
int position[N];

// if the k^th queen should be placed on i^th position of given row
bool is_safe(int queen_number, int row_position){
  for(int i=0; i< queen_number; i++){
    // get another queen's row_position
    int other_row_pos = position[i];
    
    // check if they are in the same column or diagonals
    if(other_row_pos == row_position)
      return false;

    if (other_row_pos == row_position - (queen_number - i))
      return false;

    if (other_row_pos == row_position + (queen_number - i))
      return false;
  }
  return true;
}

// recursively generate a tuple like [0 0 0 0 0 0], then [0 0 0 0 0 1], etc.
// finally the solution is saved in the array position, like
// [7 3 0 2 5 1 6 4] means the queens should be placed at 
// row[0]col[7]
// row[1]col[3]
// row[2]col[0]
// :
// :
// row[7]col[4] 
// input k means the k^th queen that should be placed
void solve(int k){
  static int s=0;
  if (k == N){
    // solution found
    cout<<" Solution #"<<++s<<" :\n-----------------------------\n";
    // for(int c=0; c<N; c++){
    //   cout<<position[c]<<" ";
    // }
    // cout<<endl;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        printf(position[i] == j? "|Q":"| ");
      }
      cout<<"|"<<endl;
    }
    cout<<"----------------------------"<<endl;
  }else{
    for(int i=0; i<N; i++){
      // before puting a queen
      if(is_safe(k, i)){
        position[k] = i;
        // place another queen
        solve(k+1);
      }
    }
  }
}


int main(){

  solve(0);

  return 0;
}



/*

int main(){
  char **grid;
  int rows = 8;
  int cols = 8;
  // dynamically allocate memory
  grid = new char *[rows];
  for(int i=0; i<rows; i++){
    grid[i] = new char [cols];
  }

  initialize_char_grid(grid, rows, cols);
  
  show_2d_grid(grid, rows, cols);


  // free memory
  for(int i=0; i<rows; i++){
    delete[] grid[i];
    grid[i] = NULL; // point the dangling ptr to null
  }
  delete [] grid;
  grid = NULL;
    
  return 0;
}
*/
