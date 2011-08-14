#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class OperationsArrangement {
	public:
	string arrange(string sequence) {
		string sol(sequence.size()*2, ' ');
		int l;
		bool nula = sequence[0]=='0';
		sol[0] = sequence[0];
		l = sequence[0];
		for (int i=1; i<(int)sequence.size(); ++i) {
			sol[2*i] = sequence[i];
			if (sol[2*i-1] != ' ') continue;
			if (sequence[i] == '0') {
				sol[2*i-1] = '*';
				sol[2*i+1] = '*';
				l = '0';
				nula = true;
			} else if (sequence[i] == '1') {
				sol[2*i-1] = '*';
			} else if (sequence[i]=='2' && (l=='0' || l=='1' || l=='2')) {
				sol[2*i-1] = '*';
				l = (l-'0')*2 + '0';
			} else if (l=='0' || l=='1') {
				sol[2*i-1] = '*';
				l = (l=='0' ? '0':sequence[i]);
			} else {
				sol[2*i-1] = '+';
				l = sequence[i];
			}
		}
		if (nula)
			for (int i=0; i<(int)sequence.size(); ++i)
				sol[2*i+1] = '*';
		return sol.substr(0, sol.size()-1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "222"; string Arg1 = "2*2+2"; verify_case(0, Arg1, arrange(Arg0)); }
	void test_case_1() { string Arg0 = "322"; string Arg1 = "3+2*2"; verify_case(1, Arg1, arrange(Arg0)); }
	void test_case_2() { string Arg0 = "307"; string Arg1 = "3*0*7"; verify_case(2, Arg1, arrange(Arg0)); }
	void test_case_3() { string Arg0 = "391118571"; string Arg1 = "3+9*1*1*1+8+5+7*1"; verify_case(3, Arg1, arrange(Arg0)); }
	void test_case_4() { string Arg0 = "111221911212"; string Arg1 = "1*1*1*2*2*1+9*1*1+2*1*2"; verify_case(4, Arg1, arrange(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OperationsArrangement ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
