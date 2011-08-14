#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class CommunicableDisease {
	public:
	string findSource(vector <string> contact, string results) {
		int n = results.size();

		long long notCont = 0;
		long long cont = 0;

		for (int i=0; i<n; ++i)
			if (results[i] == 'C')
				cont |= (1LL<<i);
			else
				notCont |= (1LL<i);

		vector< vector<int> > out(n, vector<int> ());
		for (int i=0; i<n; ++i) {
			istringstream is(contact[i]);
			int x;
			while (is >> x)
				out[i].push_back(x);
		}
		vector<long long> contains(n, 0);
		for (int i=0; i<n; ++i)
			contains[i] |= (1LL<<i);

		for (int j=0; j<(int)out[0].size(); ++j) {
			vector<long long> next = contains;
			for (int i=0; i<n; ++i)
				next[out[i][j]] |= contains[i];

			contains.swap(next);
		}

		long long startNot = 0;
		string sol(n, 'I');
		for (int i=0; i<n; ++i)
			if (results[i] == 'N')
				for (int j=0; j<n; ++j)
					if (contains[i] & (1LL<<j)) {
						sol[j] = 'N';
						startNot |= (1LL << j);
					}

		if (cont && startNot==(1LL<<n)-1)
			return "INVALID";

		for (int i=0; i<n; ++i)
			if (results[i]=='C' && (cont & contains[i]) == (1LL<<i)) {
				if (sol[i] == 'N')
					return "INVALID";
				else
					sol[i] = 'C';
			}

		for (int i=0; i<n; ++i)
			if (results[i] == 'C') {
				long long m = contains[i] & ~startNot;
				if (m == 0)
					return "INVALID";

				if ((m & (m-1)) == 0)
					for (int j=0; j<n; ++j)
						if (m & (1LL<<j)) {
							if (sol[j] == 'N')
								return "INVALID";
							else
								sol[j] = 'C';
							break;
						}
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1", "2", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCN"; string Arg2 = "CNN"; verify_case(0, Arg2, findSource(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 7", "2 0", "3 1", "4 2", "5 3", "6 4", "7 5", "0 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCCNNNNN"; string Arg2 = "NCNNNNNN"; verify_case(1, Arg2, findSource(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1 7", "0 2", "3 1", "4 2", "5 3", "6 4", "7 5", "0 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCCNNNNC"; string Arg2 = "IINNNNNN"; verify_case(2, Arg2, findSource(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1 7 3", "0 2 5", "3 1 6", "4 2 7", "5 3 0", "6 4 1", "7 5 2", "0 6 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCCCCCCC"; string Arg2 = "IIIIIIII"; verify_case(3, Arg2, findSource(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"1", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CN"; string Arg2 = "INVALID"; verify_case(4, Arg2, findSource(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"0", "2", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CNN"; string Arg2 = "CNN"; verify_case(5, Arg2, findSource(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CommunicableDisease ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
