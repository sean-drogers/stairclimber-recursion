/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Sean Rogers
 * Date        : 10/4/25
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    vector< vector<int> > ways;

    // Base case: the only way to climb 0 stairs
    if(num_stairs == 0) {
        return {{}};
    }

    // Steps of 1, 2, or 3
    for(int step = 1; step <= 3; ++step) {
        if(num_stairs - step >= 0){
            vector<vector<int>> sub_ways = get_ways(num_stairs - step);  //creates a sublist to store more ways
            for(vector<int> way : sub_ways){
                way.insert(way.begin(), step);    // insert step at the beginning
                ways.push_back(way);    // add the new way to the list
            }
        }
    }
    return ways;
    
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.

    // Find maxwidth to right align numbers
     int width = to_string(ways.size()).length();

    // Find the number of stairs
    int num_stairs = 0;
    for (int step : ways[0]) {
        num_stairs += step;
    }

    if(ways.size() == 1){   //Print out top statement
        cout << "1 way to climb 1 stair." << endl;
    } else {
        cout << ways.size() << " ways to climb " << num_stairs << " stairs." << endl;
    }


    int count = 0;    // Keep track of when you hit end of inner vector
    for(unsigned int i = 0; i < ways.size(); i++){  // Iterate the outter vector for number of ways
        cout << setw(width) << i+1 << ". [";
        for(unsigned int k = 0; k < ways[i].size(); k++){ // Iterate the inner vector for ways
            count = count + ways[i][k];
            if(count == num_stairs){   // Once you hit inner vector dont put another comma
                cout << ways[i][k];
            } else {
            cout << ways[i][k] << ", ";   
            }
        }
        cout << "]" << endl;
        count = 0;   // Finish the line of ways to step
    }
    
}

int main(int argc, char * const argv[]) {
    /*
    Case 1: No input arguments
    Print usage message.
    $ ./stairclimber
    Usage: ./stairclimber <number of stairs>
    Case 2: Too many input arguments
    Print usage message.
    $ ./stairclimber 3 4 5
    Usage: ./stairclimber <number of stairs>
    Case 3: Bad input
    $ ./stairclimber Howdy
    Error: Number of stairs must be a positive integer.
    Case 4: Bad input
    $ ./stairclimber 0
    Error: Number of stairs must be a positive integer.
    */

    if(argc != 2) {
        cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
        return 1;
    }
    
    string arg = argv[1];
    for(char c : arg){
        if(!isdigit(c)){
            cerr << "Error: Number of stairs must be a positive integer." << endl;
            return 1;
        }
    }

    if(arg == "0"){
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }

    /*
    Case 5: Valid
    $ ./stairclimber 1
    1 way to climb 1 stair.
    1. [1]
    */

    int num_stairs = 0;
    for(char c: arg) {
        num_stairs = num_stairs * 10 + (c - '0');
    }

    vector<vector<int>> ways = get_ways(num_stairs);
    display_ways(ways);

}
