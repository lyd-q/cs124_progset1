#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>


//compiling with gcc : g++-13 (name.cpp) -o name ??
//random number generation
Mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<float> distribution(0.0, 1.0);
//distribution(rng) gives random number from 0 to 1


using namespace std;

int main()
{   
    cout << "Hello World" << std::endl;
    return 0;

    ./randmst 0 numpoints numtrials dimension
}
