#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// define basic comparator for double type
bool fpeq(double A, double B) {
// This code is based on Bruce Dawson's "Comparing Floating Point Numbers" at
// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm.
    const double maxAbsoluteError = 0.0001;
    const double maxRelativeError = 0.0001;


    if (fabs(A - B) < maxAbsoluteError) { 
        return true;
    }

    double relativeError;
	
    if (fabs(B) > fabs(A)) {
        relativeError = fabs((A - B) / B);
    } else {
        relativeError = fabs((A - B) / A);
    }

    return (relativeError <= maxRelativeError);
}


double normalizeAngle(double t) {
	t = fmod(t, 2*M_PI);
	if(t < 0) t+= 2*M_PI;
	return t;
}


// define Polar type
struct Polar{
    Polar(){ radius = 0.0; angle = 0.0; id = 0; }
    Polar(double r, double a, int i): radius(r), angle(a), id(i) {}
    double radius;
    double angle;
    int id;
    bool operator <(const Polar & ) const;
    inline int getX(){
        return (int)round(radius * cos(angle));
    }
    inline int getY(){
        return (int)round(radius * sin(angle));
    }
};

ostream & operator<<(ostream &lhs, const Polar & p){
    lhs << "Polar angle = " << p.angle << ", radius = " << p.radius << endl;
    return lhs;
}

bool Polar::operator < (const Polar & other) const{
    // compare angle first 
    if(angle < other.angle){
        return true;
    }
    // if angle equal, compare radius
    if(fpeq(angle, other.angle)){
        if(radius < other.radius){
            return true;
        }
    }
    return false;
}

// define Cartesian Point type
struct Point{
    Point(){x = 0; y = 0; id = 0;}
    Point(int _x, int _y, int _i) : x(_x), y(_y), id(_i){}
    int x;
    int y;
    int id; 
    bool isValid();
    Polar toPolar();
   
};

ostream & operator << (ostream &lhs, const Point & p){
    lhs << p.x << " " << p.y <<endl;
    return lhs;
}

bool Point::isValid(){
    // exclude (0, 0)
    if(x==0 && y ==0 ){
        printf("Can not deal with origin point (0, 0)\n");
        return false;
    }
    // -100 <= x, y <= 100
    if(x>=-100 && x <=100 && y>=-100 && y<= 100){
        return true;
    }
    return false;
}

Polar Point::toPolar(){
    double r = hypot(x,y);
    double a = atan2(y,x);
    // now a is [-pi, pi]
    // normalize it to be [0, 2pi)
    double normalized_angle = normalizeAngle(a);
    if(fpeq(normalized_angle, 2*M_PI)){
        normalized_angle = 0.0;
    }
    return Polar(r, normalized_angle, id);
}

// given a vector of Polars
// output in form of point
// void outputResult(const vector<Polar> & vp){
//     for(Polar p: vp){
//         cout<<p.getX()<<" "<<p.getY()<<endl;
//     }
// }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    // 1. get user input and store data into a vector of Polars
    //  N
    //  x1 y1
    //  .
    //  .
    //  xn yn    
    int N;
    // reads the first line input and check range
    //scanf("%d", &N);
    cin>>N;
    if(N <1 || N>1001){
        printf("Too many inputs! Should be an integer in [1, 1000]\n");
        exit(1);
    }
    vector<Polar> all_polars;
    vector<Point> all_points;
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        Point p = Point(x, y, i);
        if(p.isValid()){
            all_points.push_back(p);
            Polar pl = p.toPolar();
            //cout<<pl;
            all_polars.push_back(pl);
        }else{
            printf("Point should be :  -100 <= x,y <=100\n");
            exit(1);
        }
    }
    //printf("=====================\n");
    // 2. Sort polars and output results
    std::sort(all_polars.begin(), all_polars.end());
    //outputResult(all_polars);
    for(int i=0; i<all_polars.size(); i++){
        int point_id = all_polars.at(i).id;
        cout<<all_points.at(point_id);
    }
    return 0;
}
