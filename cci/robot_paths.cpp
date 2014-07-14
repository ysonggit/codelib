#include <iostream>
#include <list>
#include <vector>

using namespace std;


struct Point{
  Point(int _x, int _y, bool _b) : x(_x), y(_y), accessiable(_b){}
  int x;
  int y;
  bool accessiable; // True if it is in Cfree ; False if it is obstacle
};

struct Gridmap{
  Gridmap(vector<Point> _pts) : map_pts(_pts) {}
  vector<Point> map_pts;
  bool point_free(int x, int y);
};

bool  Gridmap::point_free(int x, int y){
  vector<Point>::iterator iter = map_pts.begin();
  bool is_free = false;
  for(; iter != map_pts.end(); ++iter ){
    if((*iter).x == x && (*iter).y == y ){
      is_free = (*iter).accessiable;
    }
  }
  return is_free;
}

// x and y are index of M's row and column 
// check the range of x and y before passing the values to func
// assume point(0, 0) is always obstale-free
bool getPath(int x, int y, list<Point>& path, Gridmap env){
  // base case
  // path.push_front(p);
  if(x == 0 && y == 0){
    Point p = Point(x, y, true);
    path.push_back(p);
    return true; // path found
  }
  
  bool path_exits = false;
  if( x > 0 && env.point_free(x-1, y)){
    // then try to search left of current point
    path_exits = getPath(x-1, y, path, env);
  }
  if ( !path_exits && y >0 && env.point_free(x, y-1)){
    // add condition "!path_exits" because if the algorithm intends to find the path from left first, if left way is blocked, then try to change direction to up
    // then try to search up of current point
    path_exits = getPath(x, y-1, path, env);
  }
  
  if (path_exits){
     Point p = Point(x, y, true);
     path.push_back(p);
  }

  return path_exits;
}


int main(){
 
  vector<Point> pts;
  for (int x = 0; x< 6; x++){
    for(int y= 0; y< 6; y++){
      if( x != y+1)
        pts.push_back(Point(x, y, true));
      else
        pts.push_back(Point(x, y, false));
    }
  }
  Gridmap env = Gridmap(pts);
  list<Point> a_path;
  if(getPath(5, 5, a_path, env)){
    for(list<Point>::iterator it = a_path.begin(); it!= a_path.end(); ++it){
      cout<<"("<<(*it).x<<", "<<(*it).y<<") --> ";
    }
    cout<<"END"<<endl;
  } else{
    cout<<"There is no path found!"<<endl;
  }
  return 0;
}
