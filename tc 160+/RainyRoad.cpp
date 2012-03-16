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

class RainyRoad {
public:
    string isReachable(vector <string> road) {
        for (int i=0; i<(int)road[0].size(); ++i) {
            if (road[0][i]=='W' && road[1][i]=='W') {
                return "NO";
            }
        }
        return "YES";
    }
};
