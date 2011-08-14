#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
struct Card {
	int suite, val;
	Card(char s, char v) {
		switch (s) {
			case 'C': suite = 0; break;
			case 'D': suite = 1; break;
			case 'H': suite = 2; break;
			case 'S': suite = 3; break;
		}
		switch (v) {
			case '1': case '2': case '3': case '4': case '5': case '6':
			case '7': case '8': case '9':
				val = v-'1'; break;
			case 'T': val = 9; break;
			case 'J': val = 10; break;
			case 'Q': val = 11; break;
			case 'K': val = 12; break;
			case 'A': val = 13; break;
		}
	}
	string print() const {
		ostringstream os;
		switch (suite) {
			case 0: os << 'C'; break;
			case 1: os << 'D'; break;
			case 2: os << 'H'; break;
			case 3: os << 'S'; break;
		}
		if (val < 9)
			os << char(val + '1');
		else
			switch (val) {
				case 9: os << 'T'; break;
				case 10: os << 'J'; break;
				case 11: os << 'Q'; break;
				case 12: os << 'K'; break;
				case 13: os << 'A'; break;
			}
		return os.str();
	}
};
bool operator<(const Card &a, const Card &b) {
	if (a.suite != b.suite)
		return a.suite < b.suite;
	else
		return a.val < b.val;
}
class BridgeSort {
	public:
	string sortedHand(string hand) {
		vector<Card> A;
		for (int i=0; i<(int)hand.size(); i += 2)
			A.push_back(Card(hand[i], hand[i+1]));

		sort(A.begin(), A.end());
		string sol;
		for (int i=0; i<(int)A.size(); ++i)
			sol += A[i].print();

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "HAH2H3C4D5ST" ; string Arg1 = "C4D5H2H3HAST"; verify_case(0, Arg1, sortedHand(Arg0)); }
	void test_case_1() { string Arg0 = "H3SAHA"; string Arg1 = "H3HASA"; verify_case(1, Arg1, sortedHand(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BridgeSort ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
