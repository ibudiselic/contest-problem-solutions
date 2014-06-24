//# rooms, room assignments, probability, expectation
//# => Fairly tricky and there are several cases to consider, but otherwise straightforward.
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
#include <sstream>

using namespace std;

class EllysRoomAssignmentsDiv1 {
public:
    double getAverage(vector <string> ratings) {
        string s = accumulate(begin(ratings), end(ratings), string());
        istringstream is(s);
        vector<int> v;
        copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(v));
        int elly = v[0];
        sort(begin(v), end(v));
        elly = (end(v) - lower_bound(begin(v), end(v), elly)) - 1;
        reverse(begin(v), end(v));

        int n = v.size();
        int R = (n+19)/20;
        int large_rooms = n%R;
        int small_rooms = R - large_rooms;
        double sol = 0.0;
        if (elly >= n/R*R) { // large room
            long long sum = accumulate(begin(v), begin(v)+n/R*R, 0ll);
            sol = (double(sum)/R + v[elly])/(n/R+1);
        } else { // small room or large room
            long long elly_group_sum = accumulate(begin(v)+elly/R*R, begin(v)+elly/R*R+R, 0ll);
            long long sum1 = accumulate(begin(v), begin(v)+n/R*R, 0ll) - elly_group_sum;
            long long sum2 = accumulate(begin(v)+n/R*R, end(v), 0ll);
            if (large_rooms > 0) {
                double large = double(sum1)/R + double(sum2)/large_rooms;
                double small = double(sum1)/R;
                sol = (small+v[elly])*small_rooms/R/(n/R) + (large+v[elly])*large_rooms/R/(n/R+1);
            } else {
                sol = (double(sum1)/R + v[elly]) / (n/R);
            }
        }

        return sol;
    }
};
