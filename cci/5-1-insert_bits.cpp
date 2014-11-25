// solution 4-2 is not complete yet
#include <bitset>
#include <iostream>

using namespace std;

// assume i and j are properly given
int insertBits(int M, int N, int i, int j){
    // 1. clear bits of N from bit j to bit i (right->left)
    for(int k=i; k<=j; k++){
        int mask = ~(1<<k);
        N = N & mask;
    }
    // 2. shift M right for i bits
    int M_shift = M << i;
    // 3. merge M_shift with N
    return M_shift | N;
}

int main(){
    bitset<12> N2;
    N2[11] = 1;
    bitset<5> M2;
    M2[4] = 1;
    M2[0] = 1;
    M2[1] = 1;
    cout<<"N = "<<N2<<" M = "<<M2<<endl;
    //cout<<N2.to_ulong()<<endl;
    int N = N2.to_ulong();
    int M = M2.to_ulong();
    int R = insertBits(M, N, 2, 6);
    bitset<12> R2(R);
    cout<<"Result = "<<R2<<endl;
    return 0;
}
