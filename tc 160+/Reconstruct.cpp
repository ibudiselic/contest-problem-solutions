#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> x, y, z;
int dist[20][20];

inline int sqr(int x) { return x*x; }
bool go(int pos) {
	if (pos == (int)x.size())
		return true;

	for (int i=(pos==1 ? 0:-31); i<32; ++i) {
		for (int old=0; old<pos; ++old)
			if (sqr(x[old]-i) > dist[old][pos])
				goto NEXT_I;
		x[pos] = i;
		for (int j=(pos==1 ? 0:-31); j<32; ++j) {
			for (int old=0; old<pos; ++old)
				if (sqr(x[old]-i)+sqr(y[old]-j) > dist[old][pos])
					goto NEXT_J;
			y[pos] = j;
			for (int k=(pos==1 ? 0:-31); k<32; ++k) {
				for (int old=0; old<pos; ++old)
					if (sqr(x[old]-i)+sqr(y[old]-j)+sqr(z[old]-k) != dist[old][pos])
						goto NEXT_K;

				z[pos] = k;
				if (go(pos+1))
					return true;
				NEXT_K:;
			}
			NEXT_J:;
		}
		NEXT_I:;
	}

	return false;
}
class Reconstruct {
	public:
	vector <string> findPoints(vector <string> dists) {
		if (dists.size() == 1)
			return vector<string> (1, string("0 0 0"));

		x.assign(dists.size(), 0);
		y.assign(dists.size(), 0);
		z.assign(dists.size(), 0);

		for (int i=0; i<(int)dists.size(); ++i) {
			istringstream is(dists[i]);
			for (int j=0; j<(int)dists.size(); ++j)
				is >> dist[i][j];
		}

		if (!go(1))
			return vector<string>();

		vector<string> sol;
		for (int i=0; i<(int)x.size(); ++i) {
			ostringstream os;
			os << x[i] << ' ' << y[i] << ' ' << z[i];
			sol.push_back(os.str());
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 1","1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0 0 0",  "0 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findPoints(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 2 2","2 0 2","2 2 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0 0 0",  "0 1 1",  "-1 0 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findPoints(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 33 25","33 0 84","25 84 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0 0 0",  "1 4 4",  "3 -4 0" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findPoints(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 15","15 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findPoints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Reconstruct ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
