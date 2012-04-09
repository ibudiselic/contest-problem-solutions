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
#include <cmath>

using namespace std;

int M;
struct T {
    int day, win, gain;
    T(int day_, int win_, int gain_): day(day_), win(win_), gain(gain_) {}
};
bool operator<(const T &a, const T &b) {
    if (a.day != b.day) {
        return a.day < b.day;
    } else if (a.win != b.win) {
        return a.win < b.win;
    } else {
        return a.gain < b.gain;
    }
}
vector<T> A;

bool done[52][100001];
double dp[52][100001];
double go(int at, int prev) {
    if (done[at][prev]) {
        return dp[at][prev];
    }
    done[at][prev] = 1;
    double &ret = dp[at][prev];
    if (at==(int)A.size() || A[at-1].day+prev<=A[at].day) {
        ret = prev;
    } else {
        int cur = prev - A[at].day + A[at-1].day;
        ret = go(at+1, cur);
        ret = max(ret, A[at].win/100.0*go(at+1, min(M, cur + A[at].gain)));
        ret += A[at].day - A[at-1].day;
    }
    return ret;
}
class MagicalGirl {
public:
    double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain) {
        ::M = M;
        A.clear();
        for (int i=0; i<(int)day.size(); ++i) {
            A.push_back(T(day[i], win[i], gain[i]));
        }
        A.push_back(T(0, 100, 0));
        sort(A.begin(), A.end());
        memset(done, 0, sizeof done);
        return go(1, M);
    }
};
