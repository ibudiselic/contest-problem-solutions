#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class VoteRigging {
	public:
	int minimumVotes(vector <int> votes) {
		if (votes.size() == 1) {
			return 0;
		}
		int sol = 0;
		while (1) {
			int x = max_element(votes.begin(), votes.end()) - votes.begin();
			if (x == 0) {
				return sol + (votes[0] == *max_element(votes.begin()+1, votes.end()));
			}
			--votes[x];
			++votes[0];
			++sol;
		}
		
		return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumVotes(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 10, 10, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimumVotes(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimumVotes(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 10, 7, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimumVotes(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    VoteRigging ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
