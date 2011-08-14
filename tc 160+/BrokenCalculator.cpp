#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int basicDist[1000];
int dist[1000];
void init(int cur, const vector<int> &keys, int cost) {
	if (cost == 4)
		return;
	for (int i=0; i<(int)keys.size(); ++i) {
		const int t = cur*10 + keys[i];
		if (t != 0) {
			basicDist[t] = min(basicDist[t], cost);
			init(t, keys, cost+1);
		}
	}
}
class BrokenCalculator {
	public:
	int fewestKeys(vector <int> keys, string operators, int target) {
		memset(basicDist, 0x3f, sizeof basicDist);
		init(0, keys, 1);

		memcpy(dist, basicDist, sizeof dist);

		bool add=false, sub=false, div=false, mul=false;
		for (int i=0; i<(int)operators.size(); ++i)
			switch(operators[i]) {
				case '+': add=true; break;
				case '-': sub=true; break;
				case '*': mul=true; break;
				case '/': div=true; break;
			}

		bool change = true;
		while (change) {
			change = false;
			if (add)
				for (int i=1; i<1000; ++i)
					if (dist[i] < 1000000)
						for (int j=1; i+j<1000; ++j) {
							const int t = dist[i]+basicDist[j]+1;
							if (t < dist[i+j]) {
								change = 1;
								dist[i+j] = t;
							}
						}
			if (sub)
				for (int i=1; i<1000; ++i)
					if (dist[i] < 1000000)
						for (int j=1; j<=i; ++j) {
							const int t = dist[i]+basicDist[j]+1;
							if (t < dist[i-j]) {
								change = 1;
								dist[i-j] = t;
							}
						}
			if (mul)
				for (int i=1; i<1000; ++i)
					if (dist[i] < 1000000)
						for (int j=1; i*j<1000; ++j) {
							const int t = dist[i]+basicDist[j]+1;
							if (t < dist[i*j]) {
								change = 1;
								dist[i*j] = t;
							}
						}
			if (div)
				for (int i=1; i<1000; ++i)
					if (dist[i] < 1000000)
						for (int j=1; j<1000 && i/j<1000; ++j) {
							const int t = dist[i]+basicDist[j]+1;
							if (t < dist[i/j]) {
								change = 1;
								dist[i/j] = t;
							}
						}
		}

		if (dist[target]<10000000 || basicDist[target]<10000000)
			return min(dist[target]+1, basicDist[target]);

		return -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 5; int Arg3 = 4; verify_case(0, Arg3, fewestKeys(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+-*/"; int Arg2 = 5; int Arg3 = -1; verify_case(1, Arg3, fewestKeys(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "/-+*"; int Arg2 = 124; int Arg3 = 3; verify_case(2, Arg3, fewestKeys(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+-*/"; int Arg2 = 875; int Arg3 = 8; verify_case(3, Arg3, fewestKeys(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BrokenCalculator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
