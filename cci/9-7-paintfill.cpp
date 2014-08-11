#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

//If don't specify values for enum constants, the values start at zero and increase by one with each move down the list
enum FillColor{
  black, red, green, yellow, blue, magenta, cyan, white
};

template<class T>
void show_in_color(int color_name,  T sth){
  string color_prefix = "\033[1;3";
  string color_postfix = "\033[0m";
  stringstream ss;
  ss<<color_name;
  cout<<color_prefix<<ss.str()<<"m"<<sth<<color_postfix;
}

template<class T>
void show_2d_array(T **array, int rows, int cols){
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      show_in_color(array[i][j], 0);
    }
    cout<<endl;
  }
  cout<<endl;
}


bool keep_painting(FillColor **array, int rows, int cols, int row, int col, FillColor old_color, FillColor new_color){
  // index out of range, stop painting and return false
  if (row< 0 || col <0){
    return false;
  }
  if (row >= rows || col >= cols){
    return false;
  }
  if(array[row][col] == old_color){
    // need keep on painting with new_color
    array[row][col] = new_color;
    //search around of current "pixel"
    keep_painting(array, rows, cols, row, col+1, old_color, new_color);
    keep_painting(array, rows, cols, row, col-1, old_color, new_color);
    keep_painting(array, rows, cols, row+1, col, old_color, new_color);
    keep_painting(array, rows, cols, row-1, col, old_color, new_color);
  }
  return true;
}

void paint_fill(FillColor **array, int rows, int cols, int r, int c, FillColor new_color){
  if(array[r][c] == new_color) {
    return;
  }
  FillColor old_color = array[r][c];
  keep_painting(array, rows, cols, r, c, old_color, new_color);

}


int main(){
  FillColor **screen;
  int rows =10; 
  int cols =20;

  // allocate memory
  screen = new FillColor *[rows];
  for(int i=0; i<rows; i++){
    screen[i] = new FillColor[cols];
  }
  
  // initialize each element
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(i>4 && j>8){
        screen[i][j] = red;
        //show_in_color(red, 0);
      }else{
        screen[i][j] = blue;
        //show_in_color(blue, 0);
      }
    }
  }
  
  show_2d_array(screen, rows, cols);
  
  cout<<"===========test paint fill============\n";
  paint_fill(screen, rows, cols, 6, 10, green);

  show_2d_array(screen, rows, cols);
  
  // deallocate 2d array memory
  for(int i=0; i<rows; i++){
    delete [] screen[i];
    screen[i] = NULL;
  }
  delete [] screen;
  screen = NULL;

  return 0;
}
