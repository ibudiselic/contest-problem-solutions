#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MnemonicMemory {
	public:
	string getPhrase(string number, vector <string> dictionary) {
		vector< vector<string> > w(10, vector<string>());
		for (int i=0; i<(int)dictionary.size(); ++i)
			w[dictionary[i].size()].push_back(dictionary[i]);

		for (int i=1; i<10; ++i) {
			sort(w[i].begin(), w[i].end());
			reverse(w[i].begin(), w[i].end());
		}

		string sol;
		for (int i=0; i<(int)number.size(); ++i) {
			sol += ' ' + w[number[i]-'0'].back();
			w[number[i]-'0'].pop_back();
		}

		return sol.substr(1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "25735"; string Arr1[] = {"is", "there", "anybody", "out", "there"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "is there anybody out there"; verify_case(0, Arg2, getPhrase(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "31415926"; string Arr1[] = {"may", "i", "have", "a", "large", "container", "of", "coffee"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "may a have i large container of coffee"; verify_case(1, Arg2, getPhrase(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1212"; string Arr1[] = {"a", "aa", "a", "aa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a aa a aa"; verify_case(2, Arg2, getPhrase(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "11111111122"; string Arr1[] = {"a", "b", "d", "c", "a", "e", "f", "z", "zz", "za", "az", "e"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a a b c d e e f z az za"; verify_case(3, Arg2, getPhrase(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "2222"; string Arr1[] = {"ab", "cd", "ef", "a", "b", "ab"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ab ab cd ef"; verify_case(4, Arg2, getPhrase(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MnemonicMemory ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
