#include "graphs.h"
#include <iostream>
#include<vector>
#include<string>
#include<random>
#include<algorithm>
#include <iomanip>
#include <stdexcept>

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

float kruz(vector<tuple<int, int, float> > edges, int numpoints) {
    // kruskal's algorithm   
    // float max = 0;
    // number of nodes?
    int n = edges.size();
    ufind myuf(n);
    vector<pair<int, int> > tree(0);
    float weight = 0.0;


    // how to refer to number of adjaceny matrix
    for (int u = 0; u < n; u++) {
        myuf.makeset(u);
    }

    //sort edges by weight
    // custom sorting by third element in each pair
    sort(edges.begin(), edges.end(), [](tuple<int, int, float> &lhs, tuple<int, int, float> &rhs) {
        return get<2>(lhs) < get<2>(rhs);
    });

    int mst_edge_count = 0;
    for (int e = 0; e < edges.size(); e++) {
        int u = get<0>(edges[e]);
        int v = get<1>(edges[e]);
        if (myuf.find(u) != myuf.find(v)) {
            //insert edge into the tree
            tree.push_back({u, v}); 
            weight += get<2>(edges[e]);
            mst_edge_count++;

            //for edge pruning function generation
            //get the max edge weight
            //  if(get<2>(edges[e]) > max){
            //     max = get<2>(edges[e]);
            //  }

            myuf.uni(u, v);
        }
    }
    
    if (mst_edge_count != numpoints-1) {
        cout << "MST has less than n-1 edges: " << mst_edge_count << endl;
    }
    return weight;   
    // return max;
}

int main(int argc, char** argv) {
    int numpoints = stoi(argv[2]);
    int numtrials = stoi(argv[3]);
    int dimension = stoi(argv[4]);
    
    float sum = 0;
    for (int i = 0; i < numtrials; i++) {
        //generate graph
        vector<tuple<int, int, float> > graph = make_graph(numpoints, dimension);

        //run kruskals
        float mst_weight = kruz(graph, numpoints);
        sum += mst_weight;
        //cout << "Trial " << i+1 << ": " << mst_weight << endl;
    }
    float numtrials_float = float(numtrials);
    float avg = sum / numtrials_float;
    //cout << "Average: " << avg << endl;

    cout << avg << " " << numpoints << " " << numtrials << " " << dimension << endl;

}