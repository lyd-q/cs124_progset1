#include "graphs.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>

// //compiling with gcc : g++-13 (name.cpp) -o name ??

using namespace std;

// making first graph (0-d)
vector<vector<pair<int, float> > > make_0d_graph(int n) {
    //for random number generation
    mt19937 rng(time(nullptr));
    uniform_real_distribution<float> dist(0.0, 1.0);

    vector<vector<pair<int, float> > > adj;
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            //get random edge weight
            float w = dist(rng);
            //make edges
            //j = edge destination, w = edge weight
            adj[i].push_back(make_pair(j,w)); 
		    adj[j].push_back(make_pair(i,w));
        }
    }
    return adj;
}

//print first 0d-graph
void print_0d (vector<vector<pair<int, float> > > adj) {
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ")";
        }
        cout << endl;
    }
}
