#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int barPos(const string &s) {
	return s.size()/2 - 1 + (s.size() & 1);
}
void trim(string &s) {
	int i = (int)s.size()-1;

	while (i>=0 && s[i]==' ')
		--i;

	s = s.substr(0, i+1);
}
class Histogram {
	public:
	vector <string> draw(vector <string> title, vector <int> value) {
		int dist = 0;
		for (int i=0; i<(int)title.size()-1; ++i) {
			const int i1 = barPos(title[i]);
			const int i2 = barPos(title[i+1]);

			int minRoom = (int)title[i].size()-i1-1 + 1 + i2;

			dist = max(dist, minRoom);
		}

		vector<string> sol;
		ostringstream os;
		for (int i=0; i<(int)title.size()-1; ++i) {
			os << title[i];

			const int i1 = barPos(title[i]);
			const int i2 = barPos(title[i+1]);

			int minRoom = (int)title[i].size()-i1-1 + 1 + i2;

			int cntSpace = dist-minRoom+1;

			os << string(cntSpace, ' ');
		}
		os << title.back();

		sol.push_back(os.str());

		int cntRows = *max_element(value.begin(), value.end());

		for (int level=1; level<=cntRows; ++level) {
			bool inWord = 0;
			int titleInd = -1;
			int titlePos = 0;
			int titleBarPos = 0;

			sol.push_back(string());
			for (int i=0; i<(int)sol[0].size(); ++i) {
				if (sol[0][i]==' ') {
					if (inWord) {
						inWord = 0;
					}
					sol.back() += ' ';
				} else {
					if (!inWord) {
						inWord = 1;
						++titleInd;
						titlePos = 0;
						titleBarPos = barPos(title[titleInd]);
					} else {
						++titlePos;
					}

					if (titlePos==titleBarPos && value[titleInd]>=level)
						sol.back() += 'X';
					else
						sol.back() += ' ';
				}
			}
		}

		for (int i=0; i<(int)sol.size(); ++i)
			trim(sol[i]);

		reverse(sol.begin(), sol.end());

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"EAST","NORTH","SOUTH","WEST","INTERNATIONAL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1,4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "                               X",  "                               X",  "           X                   X",  " X         X         X         X         X",  "EAST     NORTH     SOUTH      WEST INTERNATIONAL" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, draw(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A","B","C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "X   X",  "X X X",  "A B C" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, draw(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"VERYLARGE", "XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "    X",  "    X",  "    X",  "    X",  "    X",  "    X",  "    X",  "    X",  "    X",  "    X     X",  "VERYLARGE XX" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, draw(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Histogram ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
