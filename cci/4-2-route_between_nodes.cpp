#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp> // tie
#include <boost/graph/graphviz.hpp>

// g++ -std=c++0x 4-2-route_between_nodes.cpp -I /usr/share/boost
// dot -Tpng graph.dot -o graph.png

using namespace std;
using namespace boost;

typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;
typedef graph_traits<Graph>::vertex_iterator vertex_iter;
typedef graph_traits<Graph>::edge_iterator edge_iter;
typedef graph_traits<Graph>::adjacency_iterator adj_iter;

int main(){
    Graph g(6);
    // add edges
    add_edge(1,2,g);
    add_edge(1,5,g);
    add_edge(2,3,g);
    add_edge(2,0,g);
    add_edge(3,4,g);
    add_edge(4,3,g);
    add_edge(3,5,g);
    // use vertex iterator
    // to get all vertices
    // vrange has two iters, points to 1st and last vertices
    pair<vertex_iter, vertex_iter> vrange = vertices(g);
    for(vertex_iter it = vrange.first; it != vrange.second; ++it){
        cout<<*it<<" "<<endl;
    }
    pair<edge_iter, edge_iter> erange = edges(g);
    for(edge_iter it = erange.first; it != erange.second; ++it){
        cout<<"("<<source(*it, g)<<") -> ("<<target(*it, g)<<")"<<endl;
    }
    vertex_iter vi, vi_end;
    adj_iter ai, ai_end;
    //property_map<Graph, vertex_index_t>::type index_map = get(vertex_index, g);
    for(tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi){
        tie(ai, ai_end) = adjacent_vertices(*vi, g);
        cout<<"("<<*vi<<")";
        if(ai == ai_end){
            cout<< " has no children \n";
        }else{
            cout<< " is the parent of :";
        }
        for(; ai !=ai_end; ++ai){
            cout<<"("<<(*ai)<<")";
            if(boost::next(ai) != ai_end){
                cout<<", ";
            }
        }
        cout<<endl;
    }
 
    //write
    // boost::dynamic_properties dp;
    // dp.property("node_id", get(boost::vertex_index, g));
    ofstream dotfile("graph.dot");
    write_graphviz(dotfile, g);
    return 0;
}
