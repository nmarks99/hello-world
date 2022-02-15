#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ABOUT_LENGTH 200
int max_of_four(int a, int b, int c, int d);



struct Point {
    // Point has fields for the x and y coordinates
    float x;
    float y; 
};

// compute centroid in continuous units 
Point compute_centroid( vector<Point> coll){
    const int N = coll.size(); // number of Points 

    float sumx = 0; // sum of x coordinates
    float sumy = 0; // sum of y coordinates
    for (int i = 0; i < N; i++) {
        // sum up all the x coords, and y coords
        sumx += coll[i].x; 
        sumy += coll[i].y;
    }

    // Compute the centroid and return it as a Point type
    Point centroid;
    centroid.x = sumx/N;
    centroid.y = sumy/N;    

    return centroid;
}


int main(void) {

    vector<Point> coll;
    for (int i = 0; i < 10; i++) {
        Point temp_point;
        temp_point.x = i;
        temp_point.y = i*2;
        coll.push_back(temp_point);
    }
    
    for (int i = 0; i < coll.size(); i++)
    {
        cout << coll[i].x << " ";
    }
    cout << "\n";
    for (int i = 0; i < coll.size(); i++)
    {
        cout << coll[i].y << " ";
    }
    cout << "\n";


    
    Point centroid = compute_centroid(coll);

    cout << centroid.x << " " << centroid.y << "\n"; 
    
  

    // centroid = sum of all point coordinates divided by number of points

    return 0;
}













void update(int *a, int *b){
    int a_old = *a;
    int b_old = *b;
    *a = a_old + b_old;
    *b = abs(a_old - b_old);
}

int max_of_four(int a, int b, int c, int d) { 
    vector<int> nums = {a,b,c,d};
    int biggest = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] > biggest) { 
            biggest = nums[i];
        }
    }
    return biggest;
}


// Reverse a vector
/*
std::vector<int> a = {1,2,3,4};
std::reverse(a.begin(), a.end());
for (size_t i = 0; i < a.size(); i++)
{
    cout << a[i];
}
*/

// int N;
// cin >> N;
// vector<int> arr;

// int i = 0;
// int val;
// while(i < N){    
//     cin >> val;
//     arr.push_back(val);
//     i++;
// }
// for(int i = arr.size() -1 ; i >= 0 ; i--) {
//     cout << arr[i] << "\n";
// }



// getline stuff
/*
char name[MAX_NAME_LENGTH], address[MAX_ADDRESS_LENGTH],
about[MAX_ABOUT_LENGTH];

cout << "Enter name: ";
cin.getline (name, MAX_NAME_LENGTH);

cout << "Enter address: ";
cin.getline (address, MAX_ADDRESS_LENGTH);

cout << "Enter about yourself (press ENTER to complete): ";
cin.getline (about, MAX_ABOUT_LENGTH, '\n');	//# is a delimiter 

cout << "\nEntered details are:\n";
cout << "Name: " << name << endl;
cout << "Address: " << address << endl;
cout << "About: " << about << endl;
*/