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

vector<int> req;
vector<int> res;
vector<int> cur;

int goal = (1<<('X'-'A'));

class QuantumAlchemy {
	public:
	int minSteps(string initial, vector <string> reactions) {
		req.clear();
		res.clear();

		int have = 0;
		cur.assign(26, 0);
		for (int i=0; i<(int)initial.size(); ++i) {
			have |= (1<<(initial[i]-'A'));
			++cur[initial[i]-'A'];
		}

		for (int i=0; i<(int)reactions.size(); ++i) {
			int r = 0;
			int j=0;
			while (reactions[i][j] != '-')
				r |= (1<<(reactions[i][j++]-'A'));
			req.push_back(r);
			res.push_back(reactions[i][j+2]-'A');
		}

		if (have & goal)
			return 0;

		queue<int> Q;
		int cnt = initial.size();
		Q.push('X'-'A');

		int sol = 0;

		while (!Q.empty()) {
			//cerr << char(Q.front()+'A') << '\n';
			if (cnt < 2 || Q.size()>50)
				return -1;

			int x = Q.front();
			Q.pop();

			++sol;

			for (int i=0; i<(int)res.size(); ++i)
				if (res[i] == x) {
					//cerr << reactions[i] << '\n';
					for (int j=0; (1<<j)<=req[i]; ++j)
						if (req[i] & (1<<j)) {
							//cerr << "*" << char(j+'A') << '\n';
							if (cur[j] == 0) {
								Q.push(j);
							} else {
								--cnt;
								--cur[j];
							}
						}

					goto NEXT;
				}

			return -1;

			NEXT: ;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDE"; string Arr1[] = {"ABC->F", "FE->X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AABBB"; string Arr1[] = {"BZ->Y", "ZY->X", "AB->Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAABB"; string Arr1[] = {"BZ->Y", "ZY->X", "AB->Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAXB"; string Arr1[] = {"BZ->Y", "ZY->X", "AB->Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWYZABCDEFGHIJKLMNOPQRSTUVWYZ"; string Arr1[] = {"ABCE->Z", "RTYUIO->P", "QWER->T", "MN->B"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, minSteps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QuantumAlchemy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
