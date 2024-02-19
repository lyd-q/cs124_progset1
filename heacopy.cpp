// #include <iostream>
// #include<vector>
// #include <math.h>       /* floor */
// using namespace std;

// struct heap {
// 	//fields 
// 	vector<int> arr;

//     //constructor 
//     heap(int n){
//         arr.resize(n);
//     }

//     //methods 

//     //maxheapify
//     void max_heapify(int node){
//         int largest = 0;
//         int l = (node)*2;
//         int r = (node)*2 + 1;

//         // HOW TO CHECK IF L EXISTS?
//         if (arr[l-1] > arr[node-1] && arr.size() >= l){
//             largest = l;
//         }
//         else{
//             largest = node;
//         }

//         if (arr.size() > r && arr[r-1] > arr[largest- 1]){
//             largest = r;
//         }

//         // RECUIRSIVE CALL? ALSO SWAP?
//         if (largest != node){
//             // i am swapping 
//             int temp = 0;
//             temp = arr[node-1];
//             arr[node-1] = arr[largest - 1];
//             arr[largest-1] = temp;

//             max_heapify(largest);
//         }
//     }

//     //buildheap

//     // why are we giving it an array here? okay so am i assigning the arr 
//     //to be the result of this build/
//     // how to call max_heapify on array?  
//     void build(vector<int> A){
//         arr = A;
//         for(int i = floor(A.size()/2) - 1; i >= 0; i--){
//             max_heapify(i);
//         }
//     }

//     // peek
//     int peek(){
//         return arr[0];
//     }

//     //extract max 
//     // same thing here, how am i calling heapify on itself?
//     int extract_max(){
//         int max = arr[0];
//         arr[0] = arr[arr.size()];
//         arr.resize(arr.size()-1);
//         max_heapify(1); // im calling it on the root node number

//     }

//     // insert
//     void insert(int v){
//         arr.resize(arr.size()+1);
//         arr[arr.size()] = v;
//         int N = arr.size();
//         while (N != 1 && arr[floor(N/2)-1] < arr[N-1]){
//             int p =floor(N/2)-1;
//             int temp = arr[p];
//             arr[p] = arr[N-1];
//             arr[N-1] = temp;
//             N = p;
//         }
//     }
// };

// // to run prim, should i write a function? or like what
// int n = stoi(argv[1]);

// //PRIM
// heap my_heap;
// vector<float> dist(n, 1e9);
// vector<bool> vis(n, false);
// dist[0] = 0;
// my_heap.add(0,0)


// // dijkstra
//     heap min_heap;
//     vector<float> dist(n, 1e9);
//     vector<bool> vis(n, false);
//     dist[0] = 0;
//     min_heap.add(0, 0);

//     // do dijkstra things
//     while (! min_heap.empty()) {
//         int u = min_heap.pop_min();
//         // continue skips to the next iteration of the loop
//         if (vis[u]) continue;
//         vis[u] = true;
//         // enhanced for loop: loops over each object the given container
//         // type doesn't have to be provided: use auto if you're too lazy to write out pair<int, float>
//         for (auto p : adj[u]) {
//             // use first and second to unpack the fields in the pair
//             int v = p.first;
//             float w = p.second;
//             if (dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;
//                 min_heap.add(v, dist[v]);
//             }
//         }
//     }

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

int main(int argc, char** argv) {
    //get input 
    int flag, numpoints, numtrials, dimension;
    cin >> flag >> numpoints >> numtrials >> dimension;

    ufind test(10);
    test.makeset(1);
    test.makeset(2);
    test.makeset(3);
    test.makeset(4);
    test.uni(3, 4);


    cout << test.find(3);

}