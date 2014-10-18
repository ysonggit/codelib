#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/filesystem.hpp>
#include <boost/iterator/filter_iterator.hpp>
namespace fs = boost::filesystem;

// g++ -std=c++0x test_boostfilesys.cpp -lboost_system -lboost_filesystem

int main(){
    fs::path p("./");
    fs::directory_iterator dir_first(p), dir_last;

    auto pred = [](const fs::directory_entry& p){
        return fs::is_regular_file(p);
    };
    int num =  std::distance(boost::make_filter_iterator(pred, dir_first, dir_last),
			     boost::make_filter_iterator(pred, dir_last, dir_last));
    std::cout <<num <<std::endl;
    return 0;
}
