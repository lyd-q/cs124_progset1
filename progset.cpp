#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>

mt19937 rng(chrono::stead_clock::now().time_since_epoch().count());
// if you're testing change seed to constant so you can replicate rng(0)
uniform_real_distribution<float> distribution(0,0, 1.0)
//calling distribution(rng) gives random float 0 to 1

//compiling with gcc : g++-13 (name.cpp) -o name ??

using namespace std;

int main()
{   
    // << points in direction that information is flowing
    cout << "Hello World" << endl;
    return 0;

    ./randmst 0 numpoints numtrials dimension
}
