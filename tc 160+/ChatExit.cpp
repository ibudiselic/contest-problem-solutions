#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ChatExit {
	public:
	vector <int> leaveOrder(vector <string> numSeen) {
		int n = numSeen.size();
		vector<int> done(n, 0);
		vector<int> sol;

		vector< vector<int> > v(n, vector<int>(n, 0));
		for (int i=0; i<n; ++i) {
			istringstream is(numSeen[i]);
			for (int j=0; j<n; ++j)
				is >> v[i][j];
		}

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				v[i][i] = max(v[i][i], v[j][i]);

		for (int k=0; k<n; ++k) {
			vector<int> best(n, 123456);
			for (int i=0; i<n; ++i)
				if (!done[i])
					for (int j=0; j<n; ++j)
						best[j] = min(best[j], v[i][j]);

			for (int i=0; i<n; ++i)
				if (!done[i]) {
					bool ok = true;
					for (int j=0; j<n; ++j)
						if (best[j]!=v[i][j]) {
							ok = false;
							break;
						}
					if (ok) {
						done[i] = 1;
						sol.push_back(i);
						break;
					}
				}
		}

		if (sol.size() < n)
			return vector<int> ();
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"0 1 1",
"2 0 0",
"3 1 0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, leaveOrder(Arg0)); }
	void test_case_1() { string Arr0[] = {
"0 1 1",
"4 0 0",
"3 1 0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, leaveOrder(Arg0)); }
	void test_case_2() { string Arr0[] = {
"0 100 100 100 100 100",
"100 0 100 100 100 100",
"100 100 0 100 100 100",
"100 100 100 0 100 100",
"100 100 100 100 0 100",
"100 100 100 100 100 0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, leaveOrder(Arg0)); }
	void test_case_3() { string Arr0[] = {
"0 1 0 0",
"1 0 0 0",
"0 0 0 0",
"0 0 0 0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, leaveOrder(Arg0)); }
	void test_case_4() { string Arr0[] = {
"0 0 0 0 0",
"0 0 0 0 0",
"0 0 0 0 0",
"0 0 0 0 0",
"0 0 0 0 0"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, leaveOrder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChatExit ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
