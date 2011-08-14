#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int D[50][50];
int inf = 0x3f3f3f3f;
int n;
long long K;
long long calc(int a, int b, long long len) {
    long long ret = 0;
    if (a < b) {
        swap(a, b);
    }

    for (long long i=0; i*a<=len; ++i) {
        ret += (len-i*a)/b + 1;
        if (ret > K) {
            return ret;
        }
    }

    return ret;
}

long long ways[5000000];
class ShortPaths {
	public:
	long long getPath(vector <string> graph, long long k, int start, int finish) {
		memset(D, 0x3f, sizeof D);
        n = graph.size();
        K = k;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (graph[i][j] != '0') {
                    D[i][j] = graph[i][j] - '0';
                }
            }
        }

        for (int z=0; z<n; ++z) {
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    D[i][j] = min(D[i][j], D[i][z] + D[z][j]);
                }
            }
        }

        if (D[start][finish] == inf) {
            return -1;
        }
        if (k == 1) {
            return D[start][finish];
        }

        vector<int> cyc;
        vector<bool> used(n, false);
        for (int i=0; i<n; ++i) {
            if (!used[i] && D[i][i]<inf && (D[start][i]+D[i][finish]==D[start][finish] || i==start || i==finish)) {
                for (int j=0; j<n; ++j) {
                    if (j==i || D[i][j]<inf && D[j][i]<inf) {
                        used[j] = 1;
                    }
                }
                cyc.push_back(D[i][i]);
            }
        }

        if (cyc.size() == 0) {
            return -1;
        }
        if (cyc.size() == 1) {
            return D[start][finish] + (k-1)*cyc[0];
        }
        if (cyc.size() == 2) {
            long long lo = 0;
            long long hi = 1000000000000LL;
            while (lo < hi) {
                long long mid = lo + (hi-lo)/2;
                long long cnt = calc(cyc[0], cyc[1], mid);
                if (cnt >= k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            return lo + D[start][finish];
        }

        memset(ways, 0, sizeof ways);
        long long len = D[start][finish];
        ways[len] = 1;
        for (int i=0; i<(int)cyc.size(); ++i) {
            for (int j=cyc[i]; j<5000000; ++j) {
                ways[j] += ways[j-cyc[i]];
            }
        }
        for (int i=0; i<5000000; ++i) {
            k -= ways[i];
            if (k <= 0) {
                return i;
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"0100",
"0020",
"0003",
"4000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; int Arg2 = 0; int Arg3 = 2; long long Arg4 = 3LL; verify_case(0, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {
"0100",
"0020",
"0003",
"4000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; int Arg2 = 0; int Arg3 = 2; long long Arg4 = 13LL; verify_case(1, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {
"011",
"000",
"000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; int Arg2 = 1; int Arg3 = 2; long long Arg4 = -1LL; verify_case(2, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {
"010000",
"001010",
"000101",
"000000",
"010000",
"001000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; int Arg2 = 0; int Arg3 = 3; long long Arg4 = 5LL; verify_case(3, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {
"010000",
"001010",
"000103",
"000000",
"010000",
"002000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 11LL; int Arg2 = 0; int Arg3 = 3; long long Arg4 = 14LL; verify_case(4, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {
"010000000",
"001002000",
"000100000",
"000010900",
"000000006",
"030000000",
"007000000",
"000040000",
"000000070"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5621LL; int Arg2 = 0; int Arg3 = 7; long long Arg4 = 363LL; verify_case(5, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { string Arr0[] = {
"09000000000000000000000002000000000000000000000000",
"00900000000000000000000000000000000000000000000000",
"00090000000000000000000000000000000000000000000000",
"00009000000000000000000000000000000000000000000000",
"00000900000000000000000000000000000000000000000000",
"00000090000000000000000000000000000000000000000000",
"00000009000000000000000000000000000000000000000000",
"00000000900000000000000000000000000000000000000000",
"00000000090000000000000000000000000000000000000000",
"00000000009000000000000000000000000000000000000000",
"00000000000900000000000000000000000000000000000000",
"00000000000090000000000000000000000000000000000000",
"00000000000009000000000000000000000000000000000000",
"00000000000000900000000000000000000000000000000000",
"00000000000000090000000000000000000000000000000000",
"00000000000000009000000000000000000000000000000000",
"00000000000000000900000000000000000000000000000000",
"00000000000000000090000000000000000000000000000000",
"00000000000000000009000000000000000000000000000000",
"00000000000000000000900000000000000000000000000000",
"00000000000000000000090000000000000000000000000000",
"00000000000000000000009000000000000000000000000000",
"00000000000000000000000900000000000000000000000000",
"00000000000000000000000090000000000000000000000000",
"40000000000000000000000000000000000000000000000000",
"00000000000000000000000000900000000000000000000000",
"00000000000000000000000000090000000000000000000000",
"00000000000000000000000000009000000000000000000000",
"00000000000000000000000000000900000000000000000000",
"00000000000000000000000000000090000000000000000000",
"00000000000000000000000000000009000000000000000000",
"00000000000000000000000000000000900000000000000000",
"00000000000000000000000000000000090000000000000000",
"00000000000000000000000000000000009000000000000000",
"00000000000000000000000000000000000900000000000000",
"00000000000000000000000000000000000090000000000000",
"00000000000000000000000000000000000009000000000000",
"00000000000000000000000000000000000000900000000000",
"00000000000000000000000000000000000000090000000000",
"00000000000000000000000000000000000000009000000000",
"00000000000000000000000000000000000000000900000000",
"00000000000000000000000000000000000000000090000000",
"00000000000000000000000000000000000000000009000000",
"00000000000000000000000000000000000000000000900000",
"00000000000000000000000000000000000000000000090000",
"00000000000000000000000000000000000000000000009000",
"00000000000000000000000000000000000000000000000900",
"00000000000000000000000000000000000000000000000090",
"00000000000000000000000000000000000000000000000009",
"00000000000000000000000004000000000000000000000000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10000000000LL; int Arg2 = 0; int Arg3 = 49; long long Arg4 = 31112618LL; verify_case(6, Arg4, getPath(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ShortPaths ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
