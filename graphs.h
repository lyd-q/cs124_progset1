#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include<vector>
#include<string>
#include<random>

using namespace std;

vector<vector<pair<int, float> > > make_0d_graph(int n);
void print_0d (vector<vector<pair<int, float> > > adj);

#endif