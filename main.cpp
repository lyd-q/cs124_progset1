#include "graphs.h"

#include <iostream>
#include<vector>
#include<string>
#include<random>

// //compiling with gcc : g++-13 (name.cpp) -o name ??

using namespace std;

int main()
{   
    //get input 
    int flag, numpoints, numtrials, dimension;
    cin >> flag >> numpoints >> numtrials >> dimension;

    vector<vector<pair<int, float> > > test_graph = make_4d_graph(3);
    print_graph(test_graph);
    return 0;
}
