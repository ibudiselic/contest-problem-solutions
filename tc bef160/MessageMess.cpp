#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class MessageMess {
	public:
	string restore(vector <string> dict, string msg) {
		int a[50];

		for (int i=0; i<50; ++i)
			a[i] = -1;

		for (int i=0; i<(int)msg.size(); ++i) {
			bool ok = true;
			for (int j=0; j<(int)dict.size(); ++j)
				if ((int)dict[j].size()==i+1 && dict[j]==msg.substr(0, i+1))
					if (a[i] != -1) {
						a[i] = -2;
						ok = false;
						break;
					} else
						a[i] = j;

			for (int j=0; ok && j<i; ++j)
				if (a[j] != -1) {
					for (int k=0; k<(int)dict.size(); ++k)
						if ((int)dict[k].size()==i-j && dict[k]==msg.substr(j+1, i-j)) {
							if (a[i]!=-1 || a[j]==-2) {
								a[i] = -2;
								ok = false;
								break;
							} else
								a[i] = k;
						}
				}
		}
		if (a[msg.size()-1] == -1)
			return "IMPOSSIBLE!";
		else if (a[msg.size()-1] == -2)
			return "AMBIGUOUS!";
		else {
			string sol;
			int pos = msg.size()-1;
			while (pos >= 0) {
				sol = dict[a[pos]]+' '+sol;
				pos -= dict[a[pos]].size();
			}
			return sol.substr(0, sol.size()-1);
		}
		return "error";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"HI", "YOU", "SAY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "HIYOUSAYHI"; string Arg2 = "HI YOU SAY HI"; verify_case(0, Arg2, restore(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABC", "BCD", "CD", "ABCB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCBCD"; string Arg2 = "AMBIGUOUS!"; verify_case(1, Arg2, restore(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"IMPOSS", "SIBLE", "S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; string Arg2 = "IMPOSSIBLE!"; verify_case(2, Arg2, restore(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"IMPOSS", "SIBLE", "S", "IMPOSSIBLE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; string Arg2 = "IMPOSSIBLE"; verify_case(3, Arg2, restore(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MessageMess ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
