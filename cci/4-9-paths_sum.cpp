#include "binarytree.h"
#include <vector>

using namespace std;

void printPath(const vector<int> & path, int start_idx, int end_idx){
    for(int j=start_idx; j<=end_idx; j++){
        cout<<path.at(j)<<" ";
    }
    cout<<endl;
}

// find path start from any node and ends at any node
void findPaths(int sum, Node * n, vector<int> & path, int level){
    if(n ==  NULL) return ;
    // insert current node to path
    path[level] = n->value;
    int _sum = 0;
    for(int i= level; i>=0; i--){
        _sum += path[i];
        if(sum == _sum){
            // print path
            printPath(path, i, level);
        }
    }
    findPaths(sum, n->left, path, level+1);
    findPaths(sum, n->right, path, level+1);
}

// only can find path from root to leaf
void findPath(int sum, Node * n, vector<int>& path, int cur_sum){
    if(n == NULL) return; // make sure n is not null
    cur_sum += n->value; 
    path.push_back(n->value);
    bool is_leaf = (n->left==NULL) && (n->right==NULL);
    if(is_leaf && sum == cur_sum){
        // print this path
        for(int i : path){
            cout<<i<<" - ";
        }
        cout<<endl;
    }
    // keep on searching child node if not leaf
    if(n->left != NULL){
        findPath(sum, n->left, path, cur_sum);
    }
    if(n->right != NULL){
        findPath(sum, n->right, path, cur_sum);
    }
    // remove current node before returning to parent node
    cur_sum -= n->value;
    path.pop_back();
}

int main(){
    BinaryTree bt;
    int foo[12] ={
	30, 20, 40, 10, 25, 50, 5, 15, 28, 41, 48, 60
    };
    for(int i : foo){
	bt.insert(i);
    }
    bt.printTree(1, 0);
    int depth = bt.treeHeight();
    vector<int> path(depth);
    findPaths(45, bt.root, path, 0);
    vector<int> path2;
    findPath(65, bt.root, path2, 0);
    return 0;
}
