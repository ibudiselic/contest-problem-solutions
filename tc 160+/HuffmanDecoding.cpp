#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class HuffmanDecoding {
	public:
	string decode(string archive, vector <string> dictionary) {
		string sol;
		for (int i=0; i<(int)archive.size(); ) {
			for (int j=0; j<(int)dictionary.size(); ++j)
				if (archive.substr(i, dictionary[j].size()) == dictionary[j]) {
					sol += 'A'+j;
					i += dictionary[j].size();
					break;
				}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "101101"; string Arr1[] = {"00","10","01","11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BDC"; verify_case(0, Arg2, decode(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "10111010"; string Arr1[] = {"0","111","10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "CBAC"; verify_case(1, Arg2, decode(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0001001100100111001"; string Arr1[] = {"1","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BBBABBAABBABBAAABBA"; verify_case(2, Arg2, decode(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "111011011000100110"; string Arr1[] = {"010","00","0110","0111","11","100","101"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "EGGFAC"; verify_case(3, Arg2, decode(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "001101100101100110111101011001011001010"; string Arr1[] = {"110","011","10","0011","00011","111","00010","0010","010","0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "DBHABBACAIAIC"; verify_case(4, Arg2, decode(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    HuffmanDecoding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
