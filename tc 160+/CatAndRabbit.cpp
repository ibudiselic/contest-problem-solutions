#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class CatAndRabbit {
public:
    string getWinner(string tiles) {
        int n = tiles.size();
        int k = count(tiles.begin(), tiles.end(), '#');
        if (k==0 || k==n) {
            return "Rabbit";
        }
        int nim = 0;
        for (int i=0; i<n; ++i) {
            if (tiles[i] == '.') {
                int j = i+1;
                while (j<n && tiles[j]=='.') {
                    ++j;
                }
                nim ^= j - i;
                i = j-1;
            }
        }

        return nim==0 ? "Rabbit" : "Cat";
    }
};
