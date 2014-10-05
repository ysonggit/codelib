#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// define Cartesian Point type
// assume coordinates are integers
struct Point{
    Point(){x = 0; y = 0;}
    Point(int _x, int _y) : x(_x), y(_y){}
    int x;
    int y;
    bool isValid();
   
    bool operator == (const Point & p) const{
        return (x == p.x && y == p.y);
    }
    
};


ostream & operator << (ostream &lhs, const Point & p){
    lhs << p.x << " " << p.y <<endl;
    return lhs;
}

bool Point::isValid(){
    // 0 <= x, y <= 100000
    if(x>=0 && x <=10000 && y>=0 && y<= 100000){
        return true;
    }
    return false;
}

struct Rectangle{
    Rectangle(){
        
    }
    Rectangle(Point _ll, Point _ur) : ll(_ll), ur(_ur){
        
    }
    Point ll;
    Point ur;
    bool contains(Point ) const;
   
};

bool Rectangle::contains(Point p) const{
    return (ll.x <= p.x) && (p.x <= ur.x) && (ll.y <= p.y) && (p.y <= ur.y);
}

bool operator == (Rectangle r1, Rectangle r2){
    return (r1.ll==r2.ll && r1.ur == r2.ur);
}

ostream & operator<<(ostream& lhs, const Rectangle &rhs) {
	lhs << '[' << rhs.ll << rhs.ur << ']';
	return lhs;
}

typedef vector<vector<int> > AllKPoints;

void showPointsIdx(vector<int> points_idx){
    for(int p_idx : points_idx){
        cout<<p_idx<<", ";
    }
    cout<<endl;
}

/*
  pt_idx[] -- array of points indices
  data[] -- temp array to store current combination
  start & end -- starting and ending indices in pt_idx
  idx --  current index in data
  r -- size of a combination 

  return a combination of points indices (size of K)
 */
void combination(int pt_idx[], int data[], int start, int end, int idx, int r, AllKPoints & allkpts){
    if(idx == r){
        // reach the base case: one combination
        vector<int> kpts;
        for(int j=0; j<r; j++){
            // all point indices are in data[]
            //cout<<data[j]<<" ";
            kpts.push_back(data[j]);
        }
        //cout<<endl;
        allkpts.push_back(kpts);
    }

    for(int i=start; i<=end && end-i+1 >= r-idx; i++){
        data[idx] = pt_idx[i];
        combination(pt_idx, data, i+1, end, idx+1, r, allkpts);
    }
}

void getAllCombinationsOfKPoints(int pt_idx[], int n, int r, AllKPoints & allkpts){
    int data[r];
    combination(pt_idx, data, 0, n-1, 0, r, allkpts);
}


Rectangle getMaxRectangle(vector<Point> points){
    if (points.size()==1){
        return Rectangle(points[0], points[0]);
    }
    
    if (points.size()>=2){
        vector<int> allx, ally;
        for(Point p : points){
            allx.push_back(p.x);
            ally.push_back(p.y);
        }
        sort(allx.begin(), allx.end());
        sort(ally.begin(), ally.end());
        int maxx = allx.back();
        int minx = allx.front();
        int maxy = ally.back();
        int miny = ally.front();
        Point _ll = Point(minx, miny);
        Point _ur = Point(maxx, maxy);
        return Rectangle(_ll, _ur);
    }

    return Rectangle();
}


Rectangle getMaxRectangle(vector<int> pt_idx, vector<Point> all_points){
    vector<Point> points;
    for(int idx : pt_idx){
        points.push_back(all_points[idx]);
    }
    
    return getMaxRectangle(points);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K;
    // reads the first line input and check range
    cin>>N>>K;
    if(N <1 || N>1001 || K<0 || K>N){
        //printf("Illegal Inputs! N should be an integer in [1, 1000]; K should be an integer in [0, N]\n");
        //exit(0);
        return 0;
    }
    if(K==0 || K==N){
        cout<<0<<endl;
        return 0;
    }
    vector<Point> points;
    int pt_idx[N];
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        pt_idx[i] = i;
        Point p = Point(x, y);
        if(p.isValid())
            points.push_back(p);
        else{
            //cout<<"invalid point "<<endl;
            //exit(0);
            return 0;
        }
        //cout<<i<<" pushed point ("<<x<<", "<<y<<")"<<endl;
    }
    Rectangle rect_all = getMaxRectangle(points);

    // brute force method
    // find all possible K bindings among N points
    AllKPoints allkpts;
    getAllCombinationsOfKPoints(pt_idx, N, K, allkpts);
    
    // find the max rectangle composed by the rest N-K points
    // if the rectangle == rect_all, return false
    // otherwise true
    int max_ways = allkpts.size();
    // cout<<"Max ways : "<<max_ways<<endl;
    unsigned long int actual_ways = max_ways;
    for(int i=0; i<max_ways; i++){
        vector<int> rest_idx;
        vector<int> kpts_idx = allkpts.at(i);
        for(int j=0; j<N; j++){
            bool is_rest = true;
            for(int kid : kpts_idx ){
                if(pt_idx[j] == kid)
                    is_rest = false;
            }
            if(is_rest){
                rest_idx.push_back(pt_idx[j]);
            }
        }
        // so far rest_idx contains N-K indices of points
        // find the max rectangle among these points
        Rectangle rect_rest = getMaxRectangle(rest_idx, points);
        if(rect_rest == rect_all){
            actual_ways --;
            //showPointsIdx(kpts_idx);
            //cout<<rect_rest<<endl;
        }
    }

    // print result : remainder divided by 1000000007
    cout<<actual_ways% 1000000007<<endl;
    
    return 0;
}
