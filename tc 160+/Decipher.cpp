#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

struct Letter {
	char c;
	int f;
	Letter(char c_, int f_): c(c_), f(f_) {}
};
bool operator<(const Letter &a, const Letter &b) {
	if (a.f != b.f)
		return a.f > b.f;
	return a.c < b.c;
}
class Decipher {
	public:
	vector <string> decipher(vector <string> encoded, string frequencyOrder) {
		map<char, int> M;
		for (int i=0; i<(int)encoded.size(); ++i)
			for (int j=0; j<(int)encoded[i].size(); ++j)
				if (encoded[i][j] != ' ' )
					++M[encoded[i][j]];

		vector<Letter> v;
		for (map<char, int>::const_iterator it=M.begin(); it!=M.end(); ++it)
			v.push_back(Letter(it->first, it->second));

		sort(v.begin(), v.end());

		map<char, char> T;
		for (int i=0; i<(int)v.size(); ++i)
			T[v[i].c] = frequencyOrder[i];

		for (int i=0; i<(int)encoded.size(); ++i)
			for (int j=0; j<(int)encoded[i].size(); ++j)
				if (encoded[i][j] != ' ')
					encoded[i][j] = T[encoded[i][j]];

		return encoded;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "ABBBCC" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "XYZ"; string Arr2[] = {"ZXXXYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, decipher(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "RZLW" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CEFD"; string Arr2[] = {"EDCF" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, decipher(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "XX YYY Z YYY XX",
  "WWWWWZWWWWW" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ETMQ"; string Arr2[] = {"MM TTT Q TTT MM", "EEEEEQEEEEE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, decipher(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { " X ",
  "",
  " ",
  "  ",
  "   " }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "B"; string Arr2[] = {" B ", "", " ", "  ", "   " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, decipher(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "RAZVLHAR KNW CNR",
  "HEA HNFMNSAR NFAK" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "EORTPNFHSCDIWG"; string Arr2[] = {"REGISTER NOW FOR", "THE TOPCODER OPEN" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, decipher(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Decipher ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
