#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CircleGame {
	public:
	int cardsLeft(string deck) {
		vector<int> a;
		char s[] = " A23456789TJQK";

		for (int i=0; i<(int)deck.size(); ++i)
			for (int j=0; j<13; ++j)
				if (deck[i]==s[j]) {
					a.push_back(j);
					break;
				}
		int sol = (int)a.size();
		int n = sol;

		for (int x=0; x<25; ++x) {
			vector<int> b;
			for (int i=0; i<n; ++i) {
				if (a[i]+a[(i+1)%n]==13) {
					sol -= 2;
					a[i] = a[(i+1)%n] = 0;
				} else if (a[i]+a[(i-1+n)%n]==13) {
					sol -=2;
					a[i] = a[(i-1+n)%n] = 0;
				}
				if (a[i])
					b.push_back(a[i]);
			}
			a = b;
			n = (int)a.size();
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "KKKKKKKKKK"; int Arg1 = 0; verify_case(0, Arg1, cardsLeft(Arg0)); }
	void test_case_1() { string Arg0 = "KKKKKAQT23"; int Arg1 = 1; verify_case(1, Arg1, cardsLeft(Arg0)); }
	void test_case_2() { string Arg0 = "KKKKATQ23J"; int Arg1 = 6; verify_case(2, Arg1, cardsLeft(Arg0)); }
	void test_case_3() { string Arg0 = "AT68482AK6875QJ5K9573Q"; int Arg1 = 4; verify_case(3, Arg1, cardsLeft(Arg0)); }
	void test_case_4() { string Arg0 = "AQK262362TKKAQ6262437892KTTJA332"; int Arg1 = 24; verify_case(4, Arg1, cardsLeft(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CircleGame ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
