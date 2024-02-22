#include "graphs.h"
#include <iostream>
#include "graphs.h"
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <chrono>


using namespace std;


vector<tuple<int, int, float> > make_graph(int n, int dim) {
    //for random number generation
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<float> dist(0.0, 1.0);

    //make vector of tuples
    vector<tuple<int, int, float> > edges;

    // making first type graph (0-d)
    if (dim == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                float weight = dist(rng);
                if (weight < 20 * pow(n, -1.0)){
                    tuple<int, int, float> e = make_tuple(i, j, weight);
                    edges.push_back(e);
                }
                
            }
        }
    }
    else if (dim == 2 || dim == 3 || dim == 4) {
        //make a vector of points (positions randomly generated)
        vector<vector<float> > points;
        for (int i = 0; i < n; i++) {
            vector<float> pt;
            for (int d = 0; d < dim; d++) {
                pt.push_back(dist(rng));
            }
            points.push_back(pt);
        }
        

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                //get euclidean distance
                float sum = 0;
                for (int d = 0; d < dim; d++) {
                    sum += pow(points[i][d] - points[j][d], 2);
                }
                float weight = sqrt(sum);

                if (dim == 2) {
                    if (weight < 4.0 * (pow(n, -0.5))){
                        tuple<int, int, float> e = make_tuple(i, j, weight);
                        edges.push_back(e);
                    }
                }

                else if (dim == 3) {
                    if (weight < 2.5 * (pow(n, -1.0 / 3.0))){
                        tuple<int, int, float> e = make_tuple(i, j, weight);
                        edges.push_back(e);
                    }
                }

                else if (dim == 4) {
                    if (weight < 2.0 * (pow(n, -1.0/4.0))){
                        tuple<int, int, float> e = make_tuple(i, j, weight);
                        edges.push_back(e);
                    }
                }
                
            }
        }
    }
    else {
        throw invalid_argument("Invalid dimension");
    }
    return edges;
}
