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

struct Process {
	int i, indeg;
	Process(int i_, int indeg_): i(i_), indeg(indeg_) {}
};
bool operator<(const Process &a, const Process &b) {
	if (a.indeg != b.indeg)
		return a.indeg > b.indeg;
	else
		return a.i > b.i;
}

class ParallelProgramming {
	public:
	int minTime(vector <int> time, vector <string> prec) {
		priority_queue<Process> PQ;
		const int n = time.size();
		vector<int> in;

		for (int i=0; i<n; ++i) {
			int indeg = 0;
			for (int j=0; j<n; ++j)
				indeg += (prec[j][i]=='Y');
			PQ.push(Process(i, indeg));
			in.push_back(indeg);
		}

		vector<int> ts;
		while ((int)ts.size() < n) {
			const Process cur = PQ.top(); PQ.pop();
			if (cur.indeg > 0)
				return -1;
			ts.push_back(cur.i);
			for (int j=0; j<n; ++j)
				if (prec[cur.i][j] == 'Y') {
					--in[j];
					PQ.push(Process(j, in[j]));
				}
		}

		vector<int> best_time(n, 1000000000);
		for (int i=0; i<n; ++i) {
			int start = 0;
			for (int j=0; j<n; ++j)
				if (prec[j][ts[i]] == 'Y')
					start = max(start, best_time[j]);
			best_time[ts[i]] = start + time[ts[i]];
		}
		return *max_element(best_time.begin(), best_time.end());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {150,200,250}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 250; verify_case(0, Arg2, minTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {150,200,250}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "YNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 350; verify_case(1, Arg2, minTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {150,200,250}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NNY",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 600; verify_case(2, Arg2, minTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {150,200,250}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NNY",
 "YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, minTime(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {345,335,325,350,321,620}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNN",
 "NNYYYY",
 "YNNNNN",
 "NNYNYN",
 "NNNNNN",
 "NNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1355; verify_case(4, Arg2, minTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ParallelProgramming ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
