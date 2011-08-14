#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

class DequeSort {
	public:
	int minDeques(vector <int> data) {
		vector< pair<int, int> > v;
		v.push_back(make_pair(data[0], data[0]));

		for (int i=1; i<(int)data.size(); ++i) {
			bool done = false;
			for (int j=0; j<(int)v.size(); ++j) {
				int l = v[j].first;
				int r = v[j].second;
				if (data[i]>l && data[i]<r)
					continue;
				l = min(l, data[i]);
				r = max(r, data[i]);
				bool ok = true;
				for (int k=i+1; k<(int)data.size(); ++k)
					if (data[k]>l && data[k]<r) {
						ok = false;
						break;
					}
				if (ok) {
					v[j].first = l;
					v[j].second = r;
					done = true;
					break;
				}
			}
			if (!done)
				v.push_back(make_pair(data[i], data[i]));
		}

		return v.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {50, 45, 55, 60, 65,
 40, 70, 35, 30, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minDeques(Arg0)); }
	void test_case_1() { int Arr0[] = {3, 6, 0, 9, 5, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minDeques(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 2, 1, 4, 3, 6, 5, 8, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, minDeques(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DequeSort ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
