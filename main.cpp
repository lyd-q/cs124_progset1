#include "graphs.h"
#include <iostream>
#include<vector>
#include<string>
#include<random>
#include<algorithm>

// //compiling with gcc : g++-13 (name.cpp) -o name ??

using namespace std;
struct ufind {
    //fields 
    vector<pair<int, int> > arr;

    //constructors (rank, parent)
    ufind() {
        arr = vector<pair<int, int> >();
    }

    ufind(int n){
        arr.resize(n);
    }

    // methods 
    void makeset(int x) {
        arr[x].first = 0;
        arr[x].second = x;
    }

    int find(int x){
        if (arr[x].second == x){
            return x;
        }
        arr[x].second = find(arr[x].second);
        return arr[x].second;
    }

    int link(int x, int y) {
        if (arr[x].first > arr[y].first){
            return link(y, x);
        }
        else if (arr[x].first == arr[y].first){
            arr[y].first += 1;
        }
        arr[x].second = y;
        return y;
    }

    void uni(int x, int y) {
        link(find(x), find(y));
    }
    
    int get_rank(int x) {
        return arr[x].first;
    }
};

int kruz(vector<tuple<int, int, float> > edges) {
    // kruskal's algorithm    
    int n = edges.size();
    ufind myuf(n);
    vector<pair<int, int> > tree(0);
    int weight = 0;
    // number of nodes?

    // how to refer to number of adjaceny matrix
    for (int u = 0; u < n; u++) {
        myuf.makeset(u);
    }

    //sort edges by weight?
    // custom sorting by third element in each pair
    sort(edges.begin(), edges.end(), [](vector<int> &lhs, vector<int> &rhs) {
        return lhs[2] < rhs[2];
    });

    for (int e = 0; e < edges.size(); e++) {
        int u = edges[e][0];
        int v = edges[e][1];
        if (myuf.find(u) != myuf.find(v)) {
            //insert edge into the tree
             tree.push_back({u, v}); 
             weight += edges[e][2];
             myuf.uni(u, v);
        }
    }
    return weight;   
}

int main(int argc, char** argv) {
    //get input 
    int flag, numpoints, numtrials, dimension;
    cin >> flag >> numpoints >> numtrials >> dimension;

    //adj list version
    // vector<vector<pair<int, float> > > test_graph = make_graph(3, 2);
    // print_graph(test_graph);

    //edge version


    //test edge?
    vector<tuple<int, int, float> > edges;
    vector<int> e1;
    e1.push_back(0);
    e1.push_back(1);
    e1.push_back(10.0);



    vector<int> e2;
    e2.push_back(1);
    e2.push_back(2);
    e2.push_back(10.0);


    vector<int> e3;
    e3.push_back(2);
    e3.push_back(3);
    e3.push_back(1.0);

    vector<int> e4;
    e4.push_back(3);
    e4.push_back(4);
    e4.push_back(1.0);

    vector<int> e5;
    e5.push_back(4);
    e5.push_back(0);
    e5.push_back(1.0);

    vector<int> e6;
    e6.push_back(0);
    e6.push_back(2);
    e6.push_back(10.0);

    vector<int> e7;
    e7.push_back(1);
    e7.push_back(4);
    e7.push_back(1.0);

    edges.push_back(e1);
    edges.push_back(e2);
    edges.push_back(e3);
    edges.push_back(e4);
    edges.push_back(e5);
    edges.push_back(e6);
    edges.push_back(e7);

    return kruz(edges);

}
