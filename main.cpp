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
    float weight = 0.0;
    // number of nodes?

    // how to refer to number of adjaceny matrix
    for (int u = 0; u < n; u++) {
        myuf.makeset(u);
    }

    //sort edges by weight?
    // custom sorting by third element in each pair
    sort(edges.begin(), edges.end(), [](tuple<int, int, float> &lhs, tuple<int, int, float> &rhs) {
        return get<2>(lhs) < get<2>(rhs);
    });

    for (int e = 0; e < edges.size(); e++) {
        int u = get<0>(edges[e]);
        int v = get<1>(edges[e]);
        if (myuf.find(u) != myuf.find(v)) {
            //insert edge into the tree
             tree.push_back({u, v}); 
             weight += get<2>(edges[e]);
             myuf.uni(u, v);
        }
    }
    return weight;   
}

int main(int argc, char** argv) {
    //get input 
    string
    cin >> flag >> numpoints >> numtrials >> dimension;
    int flag, numpoints, numtrials, dimension;

    vector<tuple<int, int, float> > g = make_graph(numpoints, dimension);

    //adj list version
    // vector<vector<pair<int, float> > > test_graph = make_graph(3, 2);
    // print_graph(test_graph);

    //edge version


    //test edge?
    vector<tuple<int, int, float> > edges;
    tuple<int, int, float> e1 = make_tuple(0, 1, 10.0);
    tuple<int, int, float> e2 = make_tuple(1, 2, 10.0);
    tuple<int, int, float> e3 = make_tuple(2, 3, 1.0);
    tuple<int, int, float> e4 = make_tuple(3, 4, 1.0);
    tuple<int, int, float> e5 = make_tuple(4, 0, 1.0);
    tuple<int, int, float> e6 = make_tuple(0, 2, 10.0);
    tuple<int, int, float> e7 = make_tuple(1, 4, 1.0);

    edges.push_back(e1);
    edges.push_back(e2);
    edges.push_back(e3);
    edges.push_back(e4);
    edges.push_back(e5);
    edges.push_back(e6);
    edges.push_back(e7);

    cout << kruz(edges) << endl;
    return kruz(edges);

}
