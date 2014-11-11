//# intervals, greedy, graphs
//# => The obvious idea of representing the friendship with a graph doesn't work (we get the minimum energy broadcast problem - an NP-hard problem). Drawing a picture of the intervals helps. The idea is to pick the fewest intervals such that one of them is the source rabbit interval and all the intervals are connected and all the not selected intervals intersect at least one of the selected intervals. This can be done greedily by moving from left to right taking the interval that extends the most to the right while still sharing a point with all of the not taken intervals on the left or with the rightmost previously taken interval.
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

vector<int> process(const string &a, const string &b, const string &c, const string &d) {
    int n = a.size();
    vector<int> ret(n);
    for (int i=0; i<n; ++i) {
        ret[i] = (a[i]-'0')*1000
               + (b[i]-'0')*100
               + (c[i]-'0')*10
               + (d[i]-'0');
    }
    return ret;
}
inline string acc(const vector<string> &v) {
    return accumulate(begin(v), end(v), string());
}
vector<int> process(const vector<string> &a, const vector<string> &b, const vector<string> &c, const vector<string> &d) {
    return process(acc(a), acc(b), acc(c), acc(d));
}
class ShoutterDiv1 {
public:
    int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {
        vector<int> S = process(s1000, s100, s10, s1);
        vector<int> T = process(t1000, t100, t10, t1);
        int n = S.size();
        vector<pair<int, int>> v;
        for (int i=0; i<n; ++i) {
            v.push_back({S[i], T[i]});
        }
        sort(begin(v), end(v));
        const int INF = 1234567;
        int sol = 0;
        for (int take=0; take<n; ++take) {
            int cost = 0;
            int leftmost_end = INF;
            int extends_to = 0;
            int i = 0;
            bool have_take = 0;
            while (i<n && v[i].first<=leftmost_end) {
                if (!have_take && i==take) {
                    extends_to = v[take].second;
                    i = 0;
                    --cost;
                    have_take = true;
                    break;
                }
                leftmost_end = min(leftmost_end, v[i].second);
                extends_to = max(extends_to, v[i].second);
                ++i;
            }
            ++cost;
            while (i < n) {
                int rightmost = -INF;
                int start = i;
                while (i<n && v[i].first<=extends_to) {
                    if (!have_take && i==take) {
                        extends_to = max(extends_to, v[take].second);
                        i = start;
                        have_take = 1;
                        goto NEXT;
                    }
                    rightmost = max(rightmost, v[i].second);
                    ++i;
                }
                if (rightmost == -INF) {
                    return -1;
                }
                if (i == n) { // they all fit so we don't need to take any more
                    break;
                }
                ++cost;
                extends_to = max(extends_to, rightmost);
                NEXT: ;
            }
            sol += cost;
        }
        return sol;
    }
};
