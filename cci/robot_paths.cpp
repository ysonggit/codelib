#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;


struct Point{
  Point() {}
  Point(int _x, int _y, bool _b) : x(_x), y(_y), accessiable(_b){}
  int x;
  int y;
  bool accessiable; // True if it is in Cfree ; False if it is obstacle
  bool operator<(Point other) const{
    return (x < other.x && y < other.y);
  }
};



struct Gridmap{
  Gridmap(vector<Point> _pts) : map_pts(_pts) {}
  vector<Point> map_pts;
  bool point_free(int x, int y);
  Point get_point(int x, int y);
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

Point Gridmap::get_point(int x, int y){
  for(vector<Point>::iterator iter = map_pts.begin(); iter!=map_pts.end(); ++iter){
    if((*iter).x == x && (*iter).y == y){
      return (*iter);
    }
  }
  cerr<<"Error! Gridmap::get_point(). No such point with coordinate ("<<x<<", "<<y<<") exits in the map"<<endl;
  return Point();
}

// x and y are index of M's row and column 
// check the range of x and y before passing the values to func
// assume point(0, 0) is always obstale-free
bool getPath(int x, int y, list<Point>& path, Gridmap env){
  // base case
  // path.push_front(p);
  if(x == 0 && y == 0){
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
  // obstacle-free waypoint found, add to path
  if (path_exits){
     Point p = Point(x, y, true);
     path.push_back(p);
  }
  return path_exits;
}

bool getPath(Point p, list<Point>& path, Gridmap env, set<Point>& cache){
  // ultimate step reached
  if(p.x == 0 && p.y == 0){
    return true; // path found
  }
  if(cache.find(p) != cache.end()){
    // this point is already visited 
    return p.accessiable;
  }
  // for the points not visited yet, do as above
  bool path_exits = false;
  if( p.x > 0 && env.point_free(p.x-1, p.y)){
    path_exits = getPath(env.get_point(p.x-1, p.y), path, env, cache);
  }
  if(!path_exits && p.y>0 && env.point_free(p.x, p.y-1)){
    path_exits = getPath(env.get_point(p.x, p.y-1), path, env, cache);
  }
  if(path_exits){
    path.push_back(p);
  }
  cache.insert(p);
  return path_exits;  
}

int main(){
 
  vector<Point> pts;
  for (int x = 0; x< 6; x++){
    for(int y= 0; y< 6; y++){
      pts.push_back(Point(x, y, true));
    }
  }
  // set some of points "off limits"
  // Point(0,0) and Point(5,5) are always accessiable
  pts.at(5).accessiable = false;
  pts.at(8).accessiable = false;
  pts.at(9).accessiable = false;
  pts.at(15).accessiable = false;
  pts.at(25).accessiable = false;
  pts.at(26).accessiable = false;
  pts.at(27).accessiable = false;
  pts.at(28).accessiable = false;
  
  Gridmap env = Gridmap(pts);
  // test the first function 
  list<Point> a_path;
  if(getPath(5, 5, a_path, env)){
    for(list<Point>::iterator it = a_path.begin(); it!= a_path.end(); ++it){
      cout<<"("<<(*it).x<<", "<<(*it).y<<") --> ";
    }
    cout<<"END"<<endl;
  } else{
    cout<<"There is no path found!"<<endl;
  }
  // test the second function 
  list<Point> b_path;
  set<Point> cache;
  if(getPath(Point(5,5, true), b_path, env, cache)){
    for(list<Point>::iterator it = b_path.begin(); it!= b_path.end(); ++it){
      cout<<"("<<(*it).x<<", "<<(*it).y<<") --> ";
    }
    cout<<"END"<<endl;
  }else{
    cout<<"There is no path found!"<<endl;
  }
  return 0;
}
