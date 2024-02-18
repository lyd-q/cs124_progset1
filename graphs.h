#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include<vector>
#include<string>
#include<random>

using namespace std;

void print_graph (vector<vector<pair<int, float> > > adj);
void print_points (vector<pair<int, float> > points);

vector<vector<pair<int, float> > > make_0d_graph(int n);
vector<vector<pair<int, float> > > make_2d_graph(int n);


#endif