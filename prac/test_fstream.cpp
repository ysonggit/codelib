#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string filename = string("cache/")+string("hello.txt");
    ofstream outf (filename.c_str());
    outf<<"hello\n";
    outf.close();
    return 0;
}
