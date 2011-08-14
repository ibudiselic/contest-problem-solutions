#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <map>
#include <numeric>

using namespace std;

int v1[1<<16], p1[1<<16];
class CollectingPostmarks {
	public:
	int amountOfMoney(vector <int> prices, vector <int> have, vector <int> values, int K) {
        if (K == 0) {
            return 0;
        }
        if (accumulate(values.begin(), values.end(), 0) < K) {
            return -1;
        }

		int start_money = 0;
        for (int i=0; i<(int)have.size(); ++i) {
            start_money += prices[have[i]];
        }

        if (prices.size() == 1) {
            return prices[0] - start_money;
        }
           
        int n = prices.size()/2;
        for (int m=0; m<(1<<n); ++m) {
            v1[m] = 0;
            p1[m] = 0;
            for (int i=0; i<n; ++i) {
                if (m & (1<<i)) {
                    v1[m] += values[i];
                    p1[m] += prices[i];
                }
            }
        }

        map<int, int> v2p;
        int n2 = (int)prices.size() - n;
        for (int m=0; m<(1<<n2); ++m) {
            int p = 0;
            int v = 0;
            for (int i=0; i<n2; ++i) {
                if (m & (1<<i)) {
                    p += prices[n+i];
                    v += values[n+i];
                }
            }
            int &t = v2p[v];
            if (t==0 || p<t) {
                t = p;
            }
        }

        vector<int> v2, p2;
        v2.reserve(v2p.size());
        p2.reserve(v2p.size());
        for (map<int, int>::const_iterator it=v2p.begin(); it!=v2p.end(); ++it) {
            v2.push_back(it->first);
            p2.push_back(it->second);
        }

        int t = p2.back();
        for (int i=(int)v2.size()-2; i>=0; --i) {
            p2[i] = min(p2[i], t);
            t = min(t, p2[i]);
        }

        int need_money = 1234567890;
        for (int m=0; m<(1<<n); ++m) {
            int need_val = K - v1[m];
            if (K < 0) {
                need_money = min(need_money, p1[m]);
            } else {
                int i = lower_bound(v2.begin(), v2.end(), need_val) - v2.begin();
                if (i < (int)v2.size()) {
                    need_money = min(need_money, p1[m] + p2[i]);
                }
            }
        }

        return max(need_money - start_money, 0);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,21}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; int Arg4 = 15; verify_case(0, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {9,18,7,6,18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,27,10,10,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 67; int Arg4 = 22; verify_case(1, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {14,14,12,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {19,23,20,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {43,33,14,31,42,37,17,42,40,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {116,71,38,77,87,106,48,107,91,41}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 811; int Arg4 = -1; verify_case(3, Arg4, amountOfMoney(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CollectingPostmarks ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
