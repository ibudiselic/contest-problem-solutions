#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PartySeats {
	public:
	vector <string> seating(vector <string> ppl) {
		vector<string> boys, girls;

		for (int i=0; i<(int)ppl.size(); ++i)
			if (ppl[i].substr(ppl[i].find(' ')+1, string::npos) == "girl")
				girls.push_back(ppl[i].substr(0, ppl[i].find(' ')));
			else
				boys.push_back(ppl[i].substr(0, ppl[i].find(' ')));

		if (boys.size()!=girls.size() || boys.size()%2 != 0)
			return vector<string>();

		sort(boys.begin(), boys.end());
		sort(girls.begin(), girls.end());
		vector<string> sol;

		sol.push_back("HOST");
		const int n = (int)boys.size();
		for (int i=0; i<n; ++i)
			if (i%2==0)
				sol.push_back(girls[i/2]);
			else
				sol.push_back(boys[i/2]);
		sol.push_back("HOSTESS");
		for (int i=0; i<n; ++i)
			if (i%2==0)
				sol.push_back(boys[i/2 + n/2]);
			else
				sol.push_back(girls[i/2 + n/2]);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"BOB boy","SAM girl","DAVE boy","JO girl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "HOST",  "JO",  "BOB",  "HOSTESS",  "DAVE",  "SAM" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, seating(Arg0)); }
	void test_case_1() { string Arr0[] = {"JOHN boy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, seating(Arg0)); }
	void test_case_2() { string Arr0[] = {"JOHN boy","CARLA girl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, seating(Arg0)); }
	void test_case_3() { string Arr0[] = {"BOB boy","SUZIE girl","DAVE boy","JO girl",
"AL boy","BOB boy","CARLA girl","DEBBIE girl"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "HOST",  "CARLA",  "AL",  "DEBBIE",  "BOB",  "HOSTESS",  "BOB",  "JO",  "DAVE",  "SUZIE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, seating(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PartySeats ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
