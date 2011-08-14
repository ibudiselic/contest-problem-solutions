#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct Team {
	char name;
	vector<int> places;
	int score() const {
		if (places.size() < 5)
			return 1000000000;
		else
			return accumulate(places.begin(), places.begin()+5, 0);
	}
};
bool operator<(const Team &a, const Team &b) {
	const int x = a.score();
	const int y = b.score();

	if (x != y) {
		return x < y;
	} else if (a.places.size()>5 || b.places.size()>5) {
		if (a.places.size()>5 && b.places.size()==5)
			return true;
		else if (a.places.size()==5 && b.places.size()>5)
			return false;
		else
			return a.places[5]<b.places[5];
	} else
		return a.name < b.name;
}

class CrossCountry {
	public:
	string scoreMeet(int numTeams, string finishOrder) {
		vector<Team> a;
		for (int i=0; i<numTeams; ++i) {
			Team t;
			t.name = 'A'+i;
			for (int j=0; j<(int)finishOrder.size(); ++j)
				if (finishOrder[j]-'A' == i)
					t.places.push_back(j+1);
			a.push_back(t);
		}

		sort(a.begin(), a.end());
		string sol;
		for (int i=0; i<(int)a.size() && a[i].score()!=1000000000; ++i)
			sol += a[i].name;

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 = "AABBABBABBA"; string Arg2 = "AB"; verify_case(0, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "CCCBBBBBAAACC"; string Arg2 = "BC"; verify_case(1, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arg1 = "ABDCBADBDCCDBCDBCAAAC"; string Arg2 = "BDCA"; verify_case(2, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arg1 = "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG"; string Arg2 = "BCDAHEG"; verify_case(3, Arg2, scoreMeet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; string Arg1 = "BABCAABABAB"; string Arg2 = "AB"; verify_case(4, Arg2, scoreMeet(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CrossCountry ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
