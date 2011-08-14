#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TaxiBusiness {
	public:
	vector <int> place(vector <string> town) {
		int m = town.size();
		int n = town[0].size();

		vector<int> r, c;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (town[i][j] == 'T') {
					r.push_back(i);
					c.push_back(j);
				}

		vector< vector<int> > oldDist(m, vector<int>(n, 123456789));
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (town[i][j] == '-')
					for (int k=0; k<(int)r.size(); ++k)
						oldDist[i][j] = min(oldDist[i][j], abs(r[k]-i)+abs(c[k]-j));

		vector<int> sol(2, 0);
		int cnt = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (town[i][j] == '-') {
					int cur = 0;
					for (int y=0; y<m; ++y)
						for (int x=0; x<n; ++x)
							if (town[y][x] == '-')
								cur += (abs(y-i)+abs(x-j) < oldDist[y][x]);
					if (cur > cnt) {
						cnt = cur;
						sol[0] = i;
						sol[1] = j;
					}
				}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"T--X","-X--","--X-","X--T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, place(Arg0)); }
	void test_case_1() { string Arr0[] = {"---","-T-","---"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, place(Arg0)); }
	void test_case_2() { string Arr0[] = {"TXT","TTT","T-T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, place(Arg0)); }
	void test_case_3() { string Arr0[] = {"-XXX","-XTX","-XXX","----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, place(Arg0)); }
	void test_case_4() { string Arr0[] = {"XXX-","----","-XXX","----","XXX-","----","-XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, place(Arg0)); }
	void test_case_5() { string Arr0[] = {"XXXXXXXXXXXXXXXXXXXX","-------------------T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 18 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, place(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TaxiBusiness ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
