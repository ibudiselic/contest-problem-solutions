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

int pos[256];
class TypingDistance {
public:
    int minDistance(string keyboard, string word) {
        for (int i=0; i<(int)keyboard.size(); ++i) {
            pos[keyboard[i]] = i;
        }
        int sol = 0;
        for (int i=1; i<(int)word.size(); ++i) {
            sol += abs(pos[word[i]] - pos[word[i-1]]);
        }
        return sol;
    }
};
