#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include<vector>
#include<string>
#include<random>

using namespace std;

// void print_graph (vector<vector<pair<int, float> > > adj);
// void print_2d_points (vector<pair<float, float> > points);
// void print_2d_points (vector<vector<float> > points);
// void print_2d_points (vector<vector<float> > points);


vector<vector<pair<int, float> > > make_0d_graph(int n);
vector<vector<pair<int, float> > > make__graph(int n);
vector<vector<pair<int, float> > > make_3d_graph(int n);
vector<vector<pair<int, float> > > make_4d_graph(int n);


#endif