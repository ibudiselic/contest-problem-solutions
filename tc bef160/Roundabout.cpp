#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define ALLFULL (!N.empty() && !E.empty() && !S.empty() && !W.empty())
#define ALLEMPTY (N.empty() && E.empty() && S.empty() && W.empty())
class Roundabout {
	public:
	int clearUpTime(string n, string e, string s, string w) {
		queue<char> N, E, S, W;
		vector<char> rotor(4, '0');
		char a[] = { 'N', 'E', 'S', 'W' };
		int t;
		int end = 0;

		for (int i=end; i<(int)n.size(); ++i)
			if (n[i]!='-')
				end = i+1;
		for (int i=end; i<(int)e.size(); ++i)
			if (e[i]!='-')
				end = i+1;
		for (int i=end; i<(int)s.size(); ++i)
			if (s[i]!='-')
				end = i+1;
		for (int i=end; i<(int)w.size(); ++i)
			if (w[i]!='-')
				end = i+1;

		for (t=0; ; ++t) {
			bool done = true;
			for (int i=0; i<4; ++i)
				if (rotor[i] != '0') {
					done = false;
					break;
				}
			if (t>=end && ALLEMPTY && done) break;
			if (t < (int)n.size()) if (n[t] != '-') N.push(n[t]);
			if (t < (int)e.size()) if (e[t] != '-') E.push(e[t]);
			if (t < (int)s.size()) if (s[t] != '-') S.push(s[t]);
			if (t < (int)w.size()) if (w[t] != '-') W.push(w[t]);

			vector<bool> can(4, true);
			for (int i=0; i<4; ++i)
				if (rotor[i] == a[i]) {
					rotor[i] = '0';
					can[(i==0) ? 3:(i-1)] = false;
				}

			char t = rotor[0];
			for (int i=0; i<3; ++i)
				rotor[i] = rotor[i+1];
			rotor[3] = t;

			for (int i=0; i<4; ++i)
				can[i] = can[i] && (rotor[i]=='0');

			if (!N.empty() && (E.empty() || ALLFULL) && can[0]) {
				rotor[0] = N.front();
				N.pop();
				can[3] = false;
			}
			if (!W.empty() && N.empty() && can[3]) {
				rotor[3] = W.front();
				W.pop();
				can[2] = false;
			}
			if (!S.empty() && W.empty() && can[2]) {
				rotor[2] = S.front();
				S.pop();
				can[1] = false;
			}
			if (!E.empty() && S.empty() && can[1]) {
				rotor[1] = E.front();
				E.pop();
			}
		}
		return t;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "--"; string Arg1 = "--"; string Arg2 = "WE"; string Arg3 = "-S"; int Arg4 = 6; verify_case(0, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "WWW"; string Arg1 = "NNN"; string Arg2 = "---"; string Arg3 = "---"; int Arg4 = 9; verify_case(1, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "SSS"; string Arg1 = "WW-"; string Arg2 = "N"; string Arg3 = "S------"; int Arg4 = 13; verify_case(2, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "SSS-"; string Arg1 = "--W---W"; string Arg2 = "WE"; string Arg3 = "-S"; int Arg4 = 14; verify_case(3, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "E"; string Arg1 = "-N"; string Arg2 = "W"; string Arg3 = "-S"; int Arg4 = 5; verify_case(4, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arg0 = ""; string Arg1 = ""; string Arg2 = ""; string Arg3 = ""; int Arg4 = 0; verify_case(5, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { string Arg0 = "W"; string Arg1 = ""; string Arg2 = "--E"; string Arg3 = ""; int Arg4 = 6; verify_case(6, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { string Arg0 = "ES"; string Arg1 = "N"; string Arg2 = "E"; string Arg3 = ""; int Arg4 = 9; verify_case(7, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_8() { string Arg0 = "E"; string Arg1 = "SN"; string Arg2 = "-N"; string Arg3 = "S-E"; int Arg4 = 12; verify_case(8, Arg4, clearUpTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Roundabout ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
