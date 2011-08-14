#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class AirlinerSeats {
	public:
	vector <string> mostAisleSeats(int width, int seats) {
		int maxIsle = width - seats;

		string s;

		while (maxIsle*2 > seats) {
			s += '.';
			--maxIsle;
		}
		if (s.size() && (width-(int)s.size()) % 3 == 1)
			s += 'S';

		while (maxIsle && (int)s.size() < width) {
			--maxIsle;
			s += "S.S";
		}

		s += string(max(0, width-(int)s.size()), 'S');

		s = s.substr(0, width);
		if (s.size()>1 && s[s.size()-1]=='.')
			swap(s[s.size()-1], s[s.size()-2]);

		vector<string> sol;
		if ((int)s.size() <= 50) {
			sol.push_back(s);
		} else if ((int)s.size() <= 100) {
			sol.push_back(s.substr(0, 50));
			sol.push_back(s.substr(50));
		} else {
			sol.push_back(s.substr(0, 50));
			sol.push_back(s.substr(s.size()-50));
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 3; string Arr2[] = {"..SS.S" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, mostAisleSeats(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 4; string Arr2[] = {"S.SS.S" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, mostAisleSeats(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 10; string Arr2[] = {"S.SS.SSSSSSS" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, mostAisleSeats(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 7; string Arr2[] = {".SS.SS.SS.S" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, mostAisleSeats(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 52; int Arg1 = 52; string Arr2[] = {"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS", "SS" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, mostAisleSeats(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 200; int Arg1 = 2; string Arr2[] = {"..................................................", "...............................................S.S" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, mostAisleSeats(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AirlinerSeats ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
