#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int num[1000001], last[1000001];
class ContestWinner {
public:
    int getWinner(vector <int> events) {
        int winscore = 0;
        for (int i=0; i<(int)events.size(); ++i) {
            ++num[events[i]];
            winscore = max(winscore, num[events[i]]);
            last[events[i]] = i;
        }

        int winner = -1;
        for (int i=1; i<1000001; ++i) {
            if (num[i]==winscore && (winner==-1 || last[winner]>last[i])) {
                winner = i;
            }
        }
        return winner;
    }
};
