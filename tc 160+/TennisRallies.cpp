#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int sol;
int n, allow;
vector<string> f;
string s;
class TennisRallies {
	public:
	void go(int x, int used) {
		if (x == n) {
			++sol;
			return;
		}

		int add = 0;
		s[x] = 'c';
		for (int i=0; i<(int)f.size(); ++i)
			if ((int)f[i].size() <= x+1)
				if (f[i] == s.substr(x+1-(int)f[i].size() ,f[i].size()))
					++add;
		if (used+add < allow)
			go(x+1, used+add);

		add = 0;
		s[x] = 'd';
		for (int i=0; i<(int)f.size(); ++i)
			if ((int)f[i].size() <= x+1)
				if (f[i] == s.substr(x+1-(int)f[i].size() ,f[i].size()))
					++add;
		if (used+add < allow)
			go(x+1, used+add);

		return;
	}


	int howMany(int numLength, vector <string> forbidden, int allowed) {
		sol = 0;
		n = numLength;
		f = forbidden;
		allow = allowed;
		s.resize(n);

	  go(0, 0);

	  return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"cc","dd"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; string Arr1[] = {"c"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"c"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 11; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 18; string Arr1[] = {"c","d"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 18; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 262144; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 18; string Arr1[] = {"c","cc","ccc","cccc","ccccc","cccccc","ccccccc",
 "cccccccc","ccccccccc","cccccccccc"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 262122; verify_case(5, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TennisRallies ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
