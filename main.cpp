#include "graphs.h"

#include <iostream>
#include<vector>
#include<string>
#include<random>

// //compiling with gcc : g++-13 (name.cpp) -o name ??

using namespace std;

struct heap {
	//fields 
	vector<int> arr;

    //constructor 
    heap(int n){
        arr.resize(n);
    }

    //methods 

    //maxheapify
    void max_heapify(int node){
        int largest = 0;
        int l = (node)*2;
        int r = (node)*2 + 1;

        // HOW TO CHECK IF L EXISTS?
        if (arr[l-1] > arr[node-1] && arr.size() >= l){
            largest = l;
        }
        else{
            largest = node;
        }

        if (arr.size() > r && arr[r-1] > arr[largest- 1]){
            largest = r;
        }

        // RECUIRSIVE CALL? ALSO SWAP?
        if (largest != node){
            // i am swapping 
            int temp = 0;
            temp = arr[node-1];
            arr[node-1] = arr[largest - 1];
            arr[largest-1] = temp;

            max_heapify(largest);
        }
    }

    //buildheap

    // why are we giving it an array here? okay so am i assigning the arr 
    //to be the result of this build/
    // how to call max_heapify on array?  
    void build(vector<int> A){
        arr = A;
        for(int i = floor(A.size()/2) - 1; i >= 0; i--){
            max_heapify(i);
        }
    }

    // peek
    int peek(){
        return arr[0];
    }

    //extract max 
    // same thing here, how am i calling heapify on itself?
    int extract_max(){
        int max = arr[0];
        arr[0] = arr[arr.size()];
        arr.resize(arr.size()-1);
        max_heapify(1); // im calling it on the root node number

    }

    // insert
    void insert(int v){
        arr.resize(arr.size()+1);
        arr[arr.size()] = v;
        int N = arr.size();
        while (N != 1 && arr[floor(N/2)-1] < arr[N-1]){
            int p =floor(N/2)-1;
            int temp = arr[p];
            arr[p] = arr[N-1];
            arr[N-1] = temp;
            N = p;
        }
    }
};

int main()
{   
    //get input 
    int flag, numpoints, numtrials, dimension;
    cin >> flag >> numpoints >> numtrials >> dimension;

    vector<vector<pair<int, float> > > test_graph = make_4d_graph(3);
    print_graph(test_graph);
    return 0;
}
