#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Box{
public:
    Box(int w, int h, int d) : width(w), height(h), depth(d){
	
    }
    // assume all parameters are of integer type
    // if they are required to be double type, take care of comparison operator
    int width;
    int height;
    int depth;
    // box1 can be placed under box2 only when box1 > box2
    bool operator>(const Box& another) const{
	if (width> another.width && height > another.height && depth > another.depth){
	    return true;
	}	    
	return false;
    }
    bool operator<(const Box& another) const{
	if (width < another.width && height < another.height && depth < another.depth){
	    return true;
	}	    
	return false;
    }
 
};
ostream& operator<<(std::ostream& os, const Box& b){
    os<<"Box ["<<b.width<<", "<<b.height<<", "<<b.depth<<"]"<<endl;
    return os;
}

int getHeight(const vector<Box>& boxstack){
    int stackheight = 0;
    for(auto i=boxstack.begin(); i!=boxstack.end(); ++i){
	stackheight += (*i).height;
    }
    return stackheight;
}


// naive method of CCI book, the input bottom is supposed to be the largest box in given boxes
vector<Box> createStack(const vector<Box>& allboxes, Box bottom){
    int max_height = 0;
    vector<Box> max_stack;
    for(auto i = allboxes.begin(); i!=allboxes.end(); ++i){
	if(bottom > (*i) ){
	    // (*i) can be placed above bottom
	    vector<Box> new_stack = createStack(allboxes, (*i));
	    int new_height = getHeight(new_stack);
	    if(new_height > max_height){
		max_height = new_height;
		max_stack = new_stack;
	    }
	}
    }
    // base case
    // insert bottom box to the max_stack
    max_stack.push_back(bottom);
    return max_stack;
}

// optimized method with DP
vector<Box> createStackDP(const vector<Box>& allboxes, Box bottom,  map<Box, vector<Box> >& cachedboxstack){
    int max_height = 0;
    vector<Box> max_stack;
    for(auto it=allboxes.begin(); it!=allboxes.end(); ++it){
	int new_height;
	vector<Box> new_stack;
	if(cachedboxstack.find(*it) == cachedboxstack.end()){
	    if(bottom > (*it)){
		new_stack = createStackDP(allboxes, *it, cachedboxstack);
		cachedboxstack.insert(map<Box, vector<Box> >::value_type(*it, new_stack));
	    }
	}else{
	    new_stack = (cachedboxstack.find(*it))->second;
	}
	new_height = getHeight(new_stack);
	if(new_height > max_height){
	    max_height = new_height;
	    max_stack = new_stack;
	}
    }
    max_stack.push_back(bottom);
    return max_stack;
}

int getMaxStackHeight(vector<Box> allboxes){
    int max_height = 0;
    vector<Box> max_stack;
    // sort boxes from small to big
    sort(allboxes.begin(), allboxes.end());
    max_stack.push_back(allboxes.front());
    for(auto it=allboxes.begin()+1; it!=allboxes.end(); ++it){
	cout<<(*it);
	if((*it) > max_stack.back() ){
	    // if current box is exactly smaller then the top box of max_stack
	    // it can be placed above, so add it to the max_stack
	    cout<<"on stack bottom, push "<<(*it);
	    max_stack.push_back(*it);
	}
    }
    return getHeight(max_stack);
}

int main(){
    vector<Box> allboxes;
    Box b1 = Box(1,1,1);
    Box b2 = Box(2,2,2);
    Box b3 = Box(3,3,3);
    Box b4 = Box(4,4,4);
    Box b5 = Box(3,2,1);
    Box b6 = Box(2,2,2);
    Box b7 = Box(1,2,1);
    allboxes.push_back(b1);
    allboxes.push_back(b2);
    allboxes.push_back(b3);
    allboxes.push_back(b4);
    allboxes.push_back(b5);
    allboxes.push_back(b6);
    allboxes.push_back(b7);
    vector<Box> boxstack = createStack(allboxes, b4); // b4 is the biggest box
    cout<<"Maximum Stack Height : "<<getHeight(boxstack)<<endl;
    cout<<"\n-----------------------"<<endl;
    cout<<"Max Stack Height : "<<getMaxStackHeight(allboxes)<<endl;
    map<Box, vector<Box> > cachedboxstack;
    vector<Box> bs = createStackDP(allboxes, b4, cachedboxstack);
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"Max stack height (DP version)"<<getHeight(bs)<<endl;
    
    return 0;
}
