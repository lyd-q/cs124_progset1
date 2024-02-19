#include "graphs.h"

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <stdexcept>


using namespace std;


vector<vector<pair<int, float> > > make_graph(int n, int dim) {
    //for random number generation
    mt19937 rng(time(nullptr));
    uniform_real_distribution<float> dist(0.0, 1.0);

    vector<vector<pair<int, float> > > adj;
    adj.resize(n);

    // making first type graph (0-d)
    if (dim == 0) {
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
    }
    else if (dim == 2 || dim == 3 || dim == 4) {
        //make a vector of points (positions randomly generated)
        vector<vector<float>> points;
        for (int i = 0; i < n; i++) {
            vector<float> pt;
            for (int d = 0; d < dim; d++) {
                pt.push_back(dist(rng));
            }
            points.push_back(pt);
        }
        //create edge list for the graph, vector version
        //vector <vector<int, int, float> > edges;

        // //create adjacency list, vertex indexed in order from points vector
        // vector<vector<pair<int, float> > > adj;
        // adj.resize(n);
        
        //make vector of tuples
        vector <tuple<int, int, float> > edges;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                //get euclidean distance
                float sum = 0;
                for (int d = 0; d < dim; d++) {
                    sum += pow(points[i][d] - points[j][d], 2);
                }
                float weight = sqrt(sum);
                // //add to adjacency list as a pair of (vertex index, edge weight)
                // adj[i].push_back(make_pair(j, weight)); 
                // adj[j].push_back(make_pair(i, weight));

                tuple<int, int, float> e = make_tuple(i, j, weight);
                edges.push_back(e);
            }
        }
    }
    else {
        throw invalid_argument("Invalid dimension");
    }
    return adj;
}