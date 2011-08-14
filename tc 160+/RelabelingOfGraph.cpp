#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

class RelabelingOfGraph {
	public:
	vector <int> renumberVertices(vector <string> G) {
		int n = G.size();
		vector<int> deg;
		priority_queue< pair<int, int> > PQ;
		for (int i=0; i<n; ++i) {
			deg.push_back(count(G[i].begin(), G[i].end(), '1'));
			PQ.push(make_pair(-deg.back(), i));
		}

		vector<int> sol(n, -1);
		for (int i=n-1; i>=0; --i) {
			int d, j;
			do {
				assert(PQ.size() > 0);
				d = -PQ.top().first;
				if (d != 0)
					return vector<int> ();
				j = PQ.top().second;
				PQ.pop();
			} while (sol[j] != -1);

			sol[j] = i;
			for (int k=0; k<n; ++k)
				if (G[k][j] == '1') {
					--deg[k];
					PQ.push(make_pair(-deg[k], k));
				}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0100", "0010", "0001", "0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, renumberVertices(Arg0)); }
	void test_case_1() { string Arr0[] = {"010", "001", "100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, renumberVertices(Arg0)); }
	void test_case_2() { string Arr0[] = {"00001", "00010", "00000", "00001", "00100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 4, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, renumberVertices(Arg0)); }
	void test_case_3() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, renumberVertices(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RelabelingOfGraph ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
