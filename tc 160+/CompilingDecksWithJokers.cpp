#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class CompilingDecksWithJokers {
	public:
	int maxCompleteDecks(vector <int> cards, int jokers) {
		if (cards.size() == 1) {
			return cards[0] + jokers;
		}

		sort(cards.begin(), cards.end());
		int sol = 0;
		while (1) {
			int cnt = 1;
			for (int i=1; i<(int)cards.size() && cards[i]==cards[0]; ++i) {
				++cnt;
			}
			
			if (jokers < cnt) {
				return sol + cards[0];
			}

			if (cards[0] == 0) {
				return (cnt>1) ? sol : sol + min(jokers, cards[1]);
			}

			if (cnt == (int)cards.size()) {
				long long series = min(cards[0]/(cnt-1), jokers/cnt);
				sol += series*cnt;
				jokers -= series*cnt;

				return sol + (cards[0] - (cnt-1)*series);
			} if (cnt == 1) {
				int step = min(cards[1]-cards[0], jokers);
				jokers -= step;
				for (int i=1; i<(int)cards.size(); ++i) {
					cards[i] -= step;
				}
				sol += step;
				if (step == 0) {
					return sol + cards[0];
				}
			} else {
				long long series = min(cards[0]/(cnt-1), jokers/cnt);
				series = min(series, (long long)cards[cnt]-cards[0]);
				sol += series*cnt;
				jokers -= series*cnt;
				for (int i=0; i<cnt; ++i) {
					cards[i] -= series*(cnt-1);
				}
				for (int i=cnt; i<(int)cards.size(); ++i) {
					cards[i] -= series*cnt;
					assert(cards[i] >= 0);
				}
				if (series == 0) {
					return sol + cards[0];
				}
			}
		}
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 13; verify_case(0, Arg2, maxCompleteDecks(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(1, Arg2, maxCompleteDecks(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(2, Arg2, maxCompleteDecks(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(3, Arg2, maxCompleteDecks(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    CompilingDecksWithJokers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
