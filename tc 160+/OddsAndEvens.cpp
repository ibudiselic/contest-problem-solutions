#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N;
int S[2], P[2];
bool test(unsigned mask) {
	int s[2], p[2];
	memset(s, 0, sizeof s);
	memset(p, 0, sizeof p);

	for (int i=0; i<N-1; ++i)
		for (int j=i+1; j<N; ++j) {
			int a = ((mask&(1<<i)) != 0);
			int b = ((mask&(1<<j)) != 0);
			/*cerr << i << ' ' << j << '\n';
			cerr << a << ' ' << b << '\n';*/
			++s[(a+b)%2];
			++p[a*b];
		}

	/*cerr << "test " << mask << ":: " << s[0] << ' ' << s[1] << ' ' << p[0] << ' ' << p[1] << '\n';*/
	return s[0]==S[0] && s[1]==S[1] && p[0]==P[0] && p[1]==P[1];
}

int bc(unsigned x) {
	int ret = 0;
	while (x > 0) {
		++ret;
		x &= (x-1);
	}

	return ret;
}
string makeSolution(unsigned mask) {
	int odd = bc(mask);
	int even = N-odd;

	ostringstream os;
	os << "EVEN " << even << " ODD " << odd;
	return os.str();
}
class OddsAndEvens {
	public:
	string find(vector <string> sums, vector <string> products) {
		for (N=2; N*(N-1)/2!=(int)sums.size(); ++N)
			;

		memset(S, 0, sizeof S);
		memset(P, 0, sizeof P);

		for (int i=0; i<(int)sums.size(); ++i) {
			++S[sums[i]=="ODD"];
			++P[products[i]=="ODD"];
		}
		/*cerr << S[0] << ' ' << S[1] << ' ' << P[0] << ' ' << P[1] << '\n';*/

		for (unsigned mask=0; mask<(1u<<N); ++mask)
			if (test(mask))
				return makeSolution(mask);

		return "IMPOSSIBLE";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"EVEN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ODD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "EVEN 0 ODD 2"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ODD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ODD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"EVEN","EVEN","EVEN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EVEN","EVEN","EVEN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "EVEN 3 ODD 0"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"EVEN","ODD","ODD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ODD","EVEN","EVEN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "EVEN 1 ODD 2"; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ODD","EVEN","ODD","EVEN","ODD","EVEN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ODD","EVEN","EVEN","EVEN","ODD","ODD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "EVEN 1 ODD 3"; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OddsAndEvens ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
