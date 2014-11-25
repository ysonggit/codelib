#include <iostream>
#include <string>

using namespace std;

void printDoubleInBinary(double num){
    cout<<num;
    string bin_str;
    bin_str.append("0.");
    while(num>0){
        if(bin_str.length()>33){
            cout<<"ERROR"<<endl;
            return ;
        }
        double r = num * 2;
        if(r>=1){
            bin_str.append("1");
            num = r - 1;
        }else{
            bin_str.append("0");
            num = r;
        }
    }
    cout<<" = "<<bin_str<<endl;
}

int main(){
    double d = 0.72;
    printDoubleInBinary(d);
    double e = 0.75;
    printDoubleInBinary(e);
    double f = 0.125;
    printDoubleInBinary(f);
    return 0;
}
