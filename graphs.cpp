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
void print_2d_points (vector<pair<float, float> > points) {
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
    print_2d_points(points);
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


//make 3d-graph
vector<vector<pair<int, float> > > make_3d_graph(int n) {
    //for random number generation
    mt19937 rng1(time(nullptr));
    mt19937 rng2(time(nullptr));
    mt19937 rng3(time(nullptr));
    uniform_real_distribution<float> dist(0.0, 1.0);

    //make a vector of points (positions randomly generated)
    vector<vector<float>> points;
    for (int i = 0; i < n; i++) {
        float x = dist(rng1);
        float y = dist(rng2);
        float z = dist(rng3);
        vector<float> pt{x, y, z};
        points.push_back(pt);
    }
    //create adjacency list, vertex indexed in order from points vector
    vector<vector<pair<int, float> > > adj;
    adj.resize(n);
    
    for (int i = 0; i < n; i++){
        float x1 = points[i][0];
        float y1 = points[i][1];
        float z1 = points[i][2];

        for (int j = i+1; j < n; j++) {
            //calculate edge weights using euclidean distance
            float x2 = points[j][0];
            float y2 = points[j][1];
            float z2 = points[j][2];
            float w = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + + pow(z2 - z1, 2));

            //add to adjacency list as a pair of (vertex index, edge weight)
            adj[i].push_back(make_pair(j, w)); 
		    adj[j].push_back(make_pair(i, w));
        }
    }
    return adj;
}

//make 4d-graph
vector<vector<pair<int, float> > > make_4d_graph(int n) {
    //for random number generation
    mt19937 rng0(time(nullptr));
    mt19937 rng1(time(nullptr));
    mt19937 rng2(time(nullptr));
    mt19937 rng3(time(nullptr));
    uniform_real_distribution<float> dist(0.0, 1.0);

    //make a vector of points (positions randomly generated)
    vector<vector<float>> points;
    for (int i = 0; i < n; i++) {
        float w = dist(rng0);
        float x = dist(rng1);
        float y = dist(rng2);
        float z = dist(rng3);
        vector<float> pt{w, x, y, z};
        points.push_back(pt);
    }
    //create adjacency list, vertex indexed in order from points vector
    vector<vector<pair<int, float> > > adj;
    adj.resize(n);
    
    for (int i = 0; i < n; i++){
        float w1 = points[i][0];
        float x1 = points[i][1];
        float y1 = points[i][2];
        float z1 = points[i][3];

        for (int j = i+1; j < n; j++) {
            //calculate edge weights using euclidean distance
            float w2 = points[j][0];
            float x2 = points[j][1];
            float y2 = points[j][2];
            float z2 = points[j][3];
            float weight = sqrt(pow(w2 - w1, 2) + pow(x2 - x1, 2) + pow(y2 - y1, 2) + + pow(z2 - z1, 2));

            //add to adjacency list as a pair of (vertex index, edge weight)
            adj[i].push_back(make_pair(j, weight)); 
		    adj[j].push_back(make_pair(i, weight));
        }
    }
    return adj;
}



