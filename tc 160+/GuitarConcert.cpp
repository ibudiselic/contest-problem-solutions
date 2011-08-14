#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bc[1<<10];
void make_cand(int m, const vector<string> &G, vector<string> &res) {
	for (int i=0; i<(int)G.size(); ++i)
		if (m & (1<<i))
			res.push_back(G[i]);
	sort(res.begin(), res.end());
}
int get_bc(long long x) {
	int ret = 0;
	while (x > 0) {
		++ret;
		x &= (x-1);
	}
	return ret;
}
class GuitarConcert {
	public:
	vector <string> buyGuitars(vector <string> G, vector <string> S) {
		vector<string> sol(50, string(50, 'z'));
		int scover = -1;

		int n = G.size();
		vector<long long> m(n, 0);

		for (int i=0; i<n; ++i)
			for (int j=0; j<(int)S[i].size(); ++j)
				if (S[i][j] == 'Y')
					m[i] |= (1LL<<j);

		bc[0] = 0;
		for (int M=1; M<(1<<n); ++M)
			bc[M] = bc[M>>1] + (M&1);

		for (int M=0; M<(1<<n); ++M) {
			long long cover = 0;
			for (int i=0; i<n; ++i)
				if (M & (1<<i))
					cover |= m[i];
			cover = get_bc(cover);

			vector<string> t;
			if (cover>scover || cover==scover && (bc[M]<(int)sol.size() || bc[M]==(int)sol.size() && (make_cand(M, G, t), t)<sol)) {
				scover = cover;
				t.clear();
				make_cand(M, G, t);
				sol = t;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"GIBSON","FENDER", "TAYLOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNYYN", "NNNYY", "YYYYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"TAYLOR" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"GIBSON", "CRAFTER", "FENDER", "TAYLOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYNN", "NNNYY", "YYNNY", "YNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CRAFTER", "GIBSON" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AB", "AA", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN", "YN", "NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"FENDER", "GIBSON", "CRAFTER", "EPIPHONE", "BCRICH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYNNYNN", "YYYNYNN", "NNNNNYY", "NNYNNNN", "NNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"BCRICH", "CRAFTER", "GIBSON" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, buyGuitars(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GIBSON","FENDER"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, buyGuitars(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GuitarConcert ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
