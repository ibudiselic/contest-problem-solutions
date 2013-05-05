#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long cost[5];
long long P[50];
long long have[5];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> P[i];
    }
    for (int i=0; i<5; ++i) {
        cin >> cost[i];
    }

    long long points = 0;
    for (int i=0; i<n; ++i) {
        points += P[i];
        for (int j=4; j>=0; --j) {
            if (points >= cost[j]) {
                have[j] += points/cost[j];
                points %= cost[j];
            }
        }
    }
    
    for (int i=0; i<5; ++i) {
        if (i > 0) cout << ' ';
        cout << have[i];
    }
    cout << '\n' << points << '\n';

    return 0;
} 
