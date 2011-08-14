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

int key[27] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

string M, S;
vector<string> D;
int dp[2501];
inline int get_key(char c) {
	return key[c-'a'];
}
int check(int start, int len) {
	int ret = 0;
	for (int i=0; i<(int)D.size(); ++i) {
		if (len > (int)D[i].size()) {
			continue;
		}
		if (S.substr(start, len) == D[i].substr(0, len)) {
			return ret;
		}
		bool is_prefix = true;
		for (int j=0; j<len; ++j) {
			if (get_key(S[start+j]) != get_key(D[i][j])) {
				is_prefix = false;
				break;
			}
		}
		if (is_prefix) {
			++ret;
		}
	}

	return 123456789;
}
int go(int pos) {
	if (pos == (int)S.size()) {
		return -1;
	}
	int &ret = dp[pos];
	if (ret != -1) {
		return ret;
	}

	ret = 123456789;
	for (int i=0; pos+i<(int)S.size(); ++i) {
		ret = min(ret, 1 + (i+1) + check(pos, i+1) + go(pos+i+1));
	}

	return ret;
}
class JohnnysPhone {
	public:
	int minimizePushes(vector <string> dictionary, string message) {
		M = message;
		D.clear();
		D.push_back(string(1000, 'z'+1));
		string s;
		for (int i=0; i<(int)dictionary.size(); ++i) {
			s += dictionary[i];
		}
		istringstream is(s);
		string t;
		while (is >> t) {
			D.push_back(t);
		}

		int sol = 0;
		if (M == string(M.size(), ' ')) {
			return M.size();
		}
		for (int i=(int)M.size()-1; i>=0; --i) {
			if (M[i] == ' ') {
				++sol;
			}
		}

		istringstream is2(M);
		while (is2 >> S) {
			memset(dp, 0xff, sizeof dp);
			sol += go(0);
			if (sol >= 123456789) {
				return -1;
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "age messagd messagd message" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "message"; int Arg2 = 8; verify_case(0, Arg2, minimizePushes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "b a c d" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abcd  dcba "; int Arg2 = 23; verify_case(1, Arg2, minimizePushes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "a b c" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "d"; int Arg2 = -1; verify_case(2, Arg2, minimizePushes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "gajdkwifpcks iclfabc" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "gajf"; int Arg2 = -1; verify_case(3, Arg2, minimizePushes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a ", "aa ", "aaa ", "aaaa ", "ab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ab"; int Arg2 = 5; verify_case(4, Arg2, minimizePushes(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = { "aaa ", "bbb ", "ccc" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ccc"; int Arg2 = 5; verify_case(5, Arg2, minimizePushes(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    JohnnysPhone ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
