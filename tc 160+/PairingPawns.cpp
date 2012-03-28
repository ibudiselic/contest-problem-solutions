#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PairingPawns {
public:
    int savedPawnCount(vector <int> start) {
        int n = start.size();
        for (int i=n-1; i>=1; --i) {
            start[i-1] += start[i]/2;
        }
        return start[0];
    }
};
