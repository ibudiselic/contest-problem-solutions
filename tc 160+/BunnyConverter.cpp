#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool used[500001];
class BunnyConverter {
	public:
	int getMinimum(int n, int z, int start, int goal) {
        if (start == goal) {
            return 0;
        }
		long long zzz = (long long)z*z*z;
        vector< vector<int> > Y(n, vector<int>());
        for (long long i=1; i<=n; ++i) {
            Y[i*i%n].push_back(i);
        }
        memset(used, 0, sizeof used);
        
        queue<int> Q;
        Q.push(start);
        int sol = 0;
        int layer_sz = 0;
        while (!Q.empty()) {
            if (layer_sz == 0) {
                layer_sz = Q.size();
                ++sol;
            }
            --layer_sz;
            start = Q.front();
            Q.pop();
            long long index = -zzz-start;
            index += (-index+n-1)/n*n;
            for (int i=0; i<(int)Y[index].size(); ++i) {
                const int y = Y[index][i];
                if (y == goal) {
                    return sol;
                } else if (!used[y]) {
                    used[y] = true;
                    Q.push(y);
                }
            }
        }
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 5; int Arg3 = 3; int Arg4 = 1; verify_case(0, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 5; int Arg3 = 1; int Arg4 = 2; verify_case(1, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = -1; verify_case(2, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 7; int Arg2 = 7; int Arg3 = 7; int Arg4 = 0; verify_case(3, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 499979; int Arg1 = 499979; int Arg2 = 499976; int Arg3 = 3; int Arg4 = 249988; verify_case(4, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BunnyConverter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
