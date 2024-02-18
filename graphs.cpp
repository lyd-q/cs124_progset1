#include "graphs.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>

using namespace std;

//functions to print (for testing)
//print adjacency list of graph
void print_graph (vector<vector<pair<int, float> > > adj) {
    cout << "Graph:" << endl;
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ")";
        }
        cout << endl;
    }
}

//print points vector
void print_points (vector<pair<float, float> > points) {
    cout << "Vertices list: " << endl;
    for (int i = 0; i < points.size(); i++) {
        cout << "(" << points[i].first << ", " << points[i].second << ")";
    }
    cout << endl;
}

// making first type graph (0-d)
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
            adj[i].push_back(make_pair(j, w)); 
		    adj[j].push_back(make_pair(i, w));
        }
    }
    return adj;
}


//make second type 2d-graph
vector<vector<pair<int, float> > > make_2d_graph(int n) {
    //for random number generation
    mt19937 rng1(time(nullptr));
    mt19937 rng2(time(nullptr));
    uniform_real_distribution<float> dist(0.0, 1.0);

    //make a vector of points (positions randomly generated)
    vector<pair<float, float> > points;
    for (int i = 0; i < n; i++) {
        float x = dist(rng1);
        float y = dist(rng2);
        points.push_back(make_pair(x, y));
    }
    print_points(points);
    //create adjacency list, vertex indexed in order from points vector
    vector<vector<pair<int, float> > > adj;
    adj.resize(n);
    
    for (int i = 0; i < n; i++){
        float x1 = points[i].first;
        float y1 = points[i].second;

        for (int j = i+1; j < n; j++) {
            //calculate edge weights using euclidean distance
            float x2 = points[j].first;
            float y2 = points[j].second;
            float w = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

            //add to adjacency list as a pair of (vertex index, edge weight)
            adj[i].push_back(make_pair(j, w)); 
		    adj[j].push_back(make_pair(i, w));
        }
    }
    return adj;
}





