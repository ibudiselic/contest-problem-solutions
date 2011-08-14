#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int can[11][100];
vector<int> v[11][100];
int go(int p, int carry, int n) {
    int &ret = can[p][carry];
    if (ret != -1) {
        return ret;
    }

    if (carry == n) {
        return ret = 1;
    }

    for (int cnt=1; cnt*4 + carry <= n; ++cnt) {
        bool found = false;
        for (int n4=cnt; n4>=0 && carry+n4*4+(cnt-n4)*7 <= n; --n4) {
            int n7 = cnt - n4;
            int np = p + 1;
            int sum = carry + n4*4 + n7*7;
            if (sum%10 != n%10) {
                continue;
            }
            int ncarry = sum / 10;
            int nn = n / 10;

            if (!go(np, ncarry, nn)) {
                continue;
            }
            vector<int> t = v[np][ncarry];
            if (cnt < (int)t.size()) {
                continue;
            }

            reverse(t.begin(), t.end());
            while (cnt > (int)t.size()) {
                t.push_back(0);
            }
            reverse(t.begin(), t.end());
            for (int i=0; i<n4; ++i) {
                t[i] = t[i]*10 + 4;
            }
            for (int i=n4; i<cnt; ++i) {
                t[i] = t[i]*10 + 7;
            }

            if (found) {
                if (t < v[p][carry]) {
                    v[p][carry] = t;
                }
            } else {
                found = true;
                v[p][carry] = t;
            }
        }
        if (found) {
            return (ret = 1);
        }
    }

    return (ret = 0);
}

class TheLuckySum {
	public:
	vector <int> sum(int n) {
        for (int i=0; i<11; ++i) {
            for (int j=0; j<100; ++j) {
                v[i][j].clear();
            }
        }

        memset(can, 0xff, sizeof can);
        
        go(0, 0, n);
        return v[0][0];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 11; int Arr1[] = {4, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sum(Arg0)); }
	void test_case_1() { int Arg0 = 12; int Arr1[] = {4, 4, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sum(Arg0)); }
	void test_case_2() { int Arg0 = 13; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sum(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {4, 4, 4, 44, 44 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sum(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheLuckySum ___test; 
    ___test.run_test(-1);
    } 
// END CUT HERE
