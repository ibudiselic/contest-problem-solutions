#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class UnderscoreJustification {
	public:
	string justifyLine(vector <string> words, int width) {
		int sz = 0;
		for (int i=0; i<(int)words.size(); ++i) {
			sz += words[i].size();
		}

		int empty = width - sz;
		int x = empty/((int)words.size()-1);

		int sz_y = empty - x*((int)words.size()-1);
		int sz_x = (int)words.size()-1 - sz_y;

		string sol = words[0];
		for (int i=1; i<(int)words.size(); ++i) {
			if (words[i][0]<='Z' && sz_x>0 || sz_y==0) {
				sol += string(x, '_') + words[i];
				--sz_x;
			} else {
				sol += string(x+1, '_') + words[i];
				--sz_y;
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arg2 = "A___quick__brown__fox__jumps__over__the__lazy__dog"; verify_case(0, Arg2, justifyLine(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; string Arg2 = "Alpha_Beta_Gamma__Delta__Epsilon"; verify_case(1, Arg2, justifyLine(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"Hello", "world", "John", "said"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 29; string Arg2 = "Hello____world___John____said"; verify_case(2, Arg2, justifyLine(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    UnderscoreJustification ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
