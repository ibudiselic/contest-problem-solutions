#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class TeXLeX {
	public:
	bool is_hex(int c) {
		return isdigit(c) || c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f';
	}
	vector<int> solve(const vector<int> &s) {
		vector<int> sol;
		for (int i=0; i<(int)s.size()-1; ++i)
			sol.push_back(s[i]);
		return sol;
	}
	void dodaj(vector<int> &a, const vector<int> &b, int i) {
		for (; i<(int)b.size()-1; ++i)
			a.push_back(b[i]);
	}
	vector <int> getTokens(string inputt) {
		map<int, int> hex;
		for (int i=0; i<10; ++i)
			hex[i+'0'] = i;
		hex['a'] = 10;
		hex['b'] = 11;
		hex['c'] = 12;
		hex['d'] = 13;
		hex['e'] = 14;
		hex['f'] = 15;
		vector<int> input(inputt.begin(), inputt.end());
		input.push_back(10000);

		bool done = false;
		while (!done) {
			done = true;
			vector<int> s;
			for (int i=0; i<(int)input.size()-1; ++i) {
				if (input[i] == '^') {
					if (input[i+1] == '^') {
						if (i+3<(int)input.size()-1 && is_hex(input[i+2]) && is_hex(input[i+3])) {
							s.push_back(hex[input[i+2]]*16 + hex[input[i+3]]);
							done = false;
							dodaj(s, input, i+4);
							input = s;
							goto kraj;
						} else if (i+2 < (int)input.size()-1) {
							if (input[i+2] > 63) {
								s.push_back(input[i+2]-64);
							} else {
								s.push_back(input[i+2]+64);
							}
							dodaj(s, input, i+3);
							done = false;
							goto kraj;
						} else {
							s.push_back('^');
						}
					} else {
						s.push_back('^');
					}
				} else {
					s.push_back(input[i]);
				}
			}
			input = s;
			kraj:
			input.push_back(10000);
		}
		return solve(input);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aAbB cd"; int Arr1[] = { 97,  65,  98,  66,  32,  99,  100 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getTokens(Arg0)); }
	void test_case_1() { string Arg0 = "^^ ^^5e"; int Arr1[] = { 96,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getTokens(Arg0)); }
	void test_case_2() { string Arg0 = "^^"; int Arr1[] = { 94,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getTokens(Arg0)); }
	void test_case_3() { string Arg0 = "^^^5e5e"; int Arr1[] = { 30,  53,  101,  53,  101 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getTokens(Arg0)); }
	void test_case_4() { string Arg0 = "^^5e^5e^5e^5e^ abASFs&*^@%#"; int Arr1[] = { 96,  97,  98,  65,  83,  70,  115,  38,  42,  94,  64,  37,  35 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getTokens(Arg0)); }
	void test_case_5() { string Arg0 = "^^5E ^^40"; int Arr1[] = { 117,  69,  32,  64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getTokens(Arg0)); }
	void test_case_6() { string Arg0 = "^^`2^^^^OC^^c^^xJ^^Dq9GQpe^^)^^i_&_Q<^^@>|AL8^^d^^"; int Arr1[] = { 32,  50,  30,  94,  79,  67,  35,  56,  74,  4,  113,  57,  71,  81,  112,  101,  105,  41,  95,  38,  95,  81,  60,  0,  62,  124,  65,  76,  56,  36,  94,  94 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getTokens(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TeXLeX ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
