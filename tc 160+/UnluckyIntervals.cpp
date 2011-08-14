#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <set>
#include <queue>
#include <functional>

using namespace std;

long long calc(int x, const vector<int> &v) {
    int i = lower_bound(v.begin(), v.end(), x) - v.begin();
    long long lo, hi;
    if (i == 0) {
        lo = 0;
    } else {
        lo = v[i-1];
    }
    if (i == (int)v.size()) {
        hi = 1000LL * v.back();
    } else {
        hi = v[i];
    }
    
    return max(0LL, (x-lo)*(hi-x)-1);
}
class UnluckyIntervals {
	public:
	vector <int> getLuckiest(vector <int> luckySet, int n) {
	    set<int> done;
        
        priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > PQ;
        
        sort(luckySet.begin(), luckySet.end());
        for (int i=0; i<(int)luckySet.size(); ++i) {
            done.insert(luckySet[i]);
            PQ.push(make_pair(0, luckySet[i]));
        }
        for (int i=1; i<=n; ++i) {
            if (!done.insert(i).second) {
                break;
            }
            PQ.push(make_pair(calc(i, luckySet), i));
        }
        for (int i=0; i<(int)luckySet.size(); ++i) {
            for (int j=1; j<=n; ++j) {
                if (luckySet[i]-j<=0 || !done.insert(luckySet[i]-j).second) {
                    break;
                }
                PQ.push(make_pair(calc(luckySet[i]-j, luckySet), luckySet[i]-j));
            }
            for (int j=1; j<=n; ++j) {
                if (!done.insert(luckySet[i]+j).second) {
                    break;
                }
                PQ.push(make_pair(calc(luckySet[i]+j, luckySet), luckySet[i]+j));
            }
        }
        
        vector<int> sol;
        while (n--) {
            sol.push_back(PQ.top().second);
            PQ.pop();
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {3, 1, 2, 4, 5, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 11, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {5, 11, 18, 1, 4, 6, 10, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {7, 13, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {7, 13, 18, 14, 17, 8, 12, 1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000, 1004, 4000, 4003, 5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arr2[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getLuckiest(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    UnluckyIntervals ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
