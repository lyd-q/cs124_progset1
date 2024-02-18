#include <iostream>
//#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<random>


//compiling with gcc : g++-13 (name.cpp) -o name ??
//random number generation

//distribution(rng) gives random number from 0 to 1


using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int rand_weight () {
    uniform_real_distribution<float> dist(0.0, 1.0);
    return dist(rng);
}


// making first graph (0-d)
vector<vector<pair<int, float> > > make_0d_graph(int n) {
    vector<vector<pair<int, float> > > adj; 
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            //get random edge weight
            float w = rand_weight();
            //make edges
            //j = edge destination, w = edge weight
            adj[i].push_back(make_pair(j,w)); 
		    adj[j].push_back(make_pair(i,w));
        }
    }
    return adj;
}

int main()
{   
    vector<vector<pair<int, float> > > test_graph = make_0d_graph(4);

    // vector<vector<pair<int, float> > > test_graph;
    // test_graph = make_0d_graph(4);
    
    cout << (test_graph[0][0]); 
    cout << "Hello World" << std::endl;
    return 0;
    // terminal input format: ./randmst 0 numpoints numtrials dimension
}
