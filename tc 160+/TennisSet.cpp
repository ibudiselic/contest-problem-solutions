#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TennisSet {
	public:
	string firstSet(vector <string> p) {
		string P;
		for (int i=0; i<(int)p.size(); ++i)
			P += p[i];

		int games[2] = {0};
		int points[2] = {0};
		int server = 0;
		for (int i=0; i<(int)P.size(); ++i) {
			points[server] += P[i]=='S';
			points[!server] += P[i]=='R';
			if (points[server]>=4 && points[server]>=points[!server]+2) {
				++games[server];
				goto end;
			} else if (points[!server]>=4 && points[!server]>=points[server]+2) {
				++games[!server];
				goto end;
			}
			continue;
			end:
			if (games[server]>=6 && games[server]>=games[!server]+2
				||
				games[!server]>=6 && games[!server]>=games[server]+2) {
					ostringstream os;
					os << games[0];
					os << '-';
					os << games[1];
					return os.str();
				}

			points[server] = points[!server] = 0;
			server = !server;
		}

		ostringstream os;
		os << games[0] << '-' << games[1];
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SSSSSSSSSSSSSSS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2-1"; verify_case(0, Arg1, firstSet(Arg0)); }
	void test_case_1() { string Arr0[] = {"SS","SRSS","RRRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2-0"; verify_case(1, Arg1, firstSet(Arg0)); }
	void test_case_2() { string Arr0[] = {"SSSSRRRRSSSSRR","RRSSSSRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR","R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "6-0"; verify_case(2, Arg1, firstSet(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TennisSet ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
