#include "graphs.h"

#include <iostream>
#include<vector>
#include<string>
#include<random>

// //compiling with gcc : g++-13 (name.cpp) -o name ??

using namespace std;

int main()
{   
    vector<vector<pair<int, float> > > test_graph = make_0d_graph(6);
    print_0d(test_graph);
    return 0;
}
