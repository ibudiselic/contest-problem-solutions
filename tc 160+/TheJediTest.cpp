//# dp, proof, analysis, floors
//# => attempt to understand when it's optimal to move guys up a floor (locally)
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
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

class TheJediTest {
public:
    int minimumSupervisors(vector <int> students, int K) {
        int n = students.size();
        int sol = 0;
        int slots = 0; // number of "free" slots on the previous level
        for (int i=0; i<n; ++i) {
            if (slots <= students[i]) { // it's then optimal to fill the free slots
                students[i] -= slots;
                sol += (students[i]+K-1)/K;
                slots = (K-students[i]%K)%K;
            } else {
                // now we know that the free slots can't be filled so we move (K-slots)%K guys to i
                students[i] += (K-slots)%K; // now the total is <=K so it's optimal that they all stay
                assert(students[i] <= K);
                --sol; // remove one jedi from i-1 (we overcharged there)
                if (i+1 < n) { // now we're basically stuck with these "fractional" guys at i as they can't move up anymore
                    // so we're forced to put a jedi at i, so we'll try to fill up the level from the next level if possible
                    int take = min(students[i+1], (K-students[i]%K)%K);
                    students[i+1] -= take;
                    students[i] += take;
                }
                sol += (students[i]+K-1)/K;
                slots = 0; // no free slots as the level i+1 has been "drained" already
            }
        }
        return sol;
    }
};
