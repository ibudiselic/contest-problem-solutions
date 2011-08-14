#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

vector<string> date;

int dateVal(int day, int month) {
	if (month > 12)
		return -1;
	return month*32 + day;
}
class DateFormat {
	public:
	string fromEuropeanToUs(vector <string> dateList) {
		string s;
		for (int i=0; i<(int)dateList.size(); ++i)
			s += dateList[i];

		date = cutUp(s);

		int cur = 0;
		for (int i=0; i<(int)date.size(); ++i) {
			int a, b;
			sscanf(date[i].c_str(), "%d/%d", &a, &b);
			if (a > 12) {
				int mnth = b;
				int day = a;
				if (dateVal(day, mnth) <= cur)
					return "";
				cur = dateVal(day, mnth);
				char buff[8];
				sprintf(buff, "%02d/%02d", mnth, day);
				date[i] = string(buff);
			} else if (b > 12) {
				int mnth = a;
				int day = b;
				if (dateVal(day, mnth) <= cur)
					return "";
				cur = dateVal(day, mnth);
			} else {
				char buff[8];
				sprintf(buff, "%02d/%02d", b, a);
				string inverted(buff);

				int valOrig = dateVal(b, a);
				int valInv = dateVal(a, b);

				if (inverted < date[i]) {
					if (valInv > cur) {
						date[i] = inverted;
						cur = valInv;
					} else if (valOrig > cur) {
						cur = valOrig;
					} else {
						return "";
					}
				} else {
					if (valOrig > cur) {
						cur = valOrig;
					} else if (valInv > cur) {
						date[i] = inverted;
						cur = valInv;
					} else {
						return "";
					}
				}
			}
		}

		string sol;
		for (int i=0; i<(int)date.size(); ++i)
			sol += ' ' + date[i];

		return sol.substr(1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"16/01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "01/16"; verify_case(0, Arg1, fromEuropeanToUs(Arg0)); }
	void test_case_1() { string Arr0[] = {"02/01 08/02 08/02 21/09 06/11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "01/02 02/08 08/02 09/21 11/06"; verify_case(1, Arg1, fromEuropeanToUs(Arg0)); }
	void test_case_2() { string Arr0[] = {"08/02 08/02 03/04"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, fromEuropeanToUs(Arg0)); }
	void test_case_3() { string Arr0[] = {"2", "9/02", " 08/", "03 01/08"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "02/29 03/08 08/01"; verify_case(3, Arg1, fromEuropeanToUs(Arg0)); }
	void test_case_4() { string Arr0[] = {"17/01 05/05 03/07 07/24 23/09 09/30 01/11 11/11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "01/17 05/05 07/03 07/24 09/23 09/30 11/01 11/11"; verify_case(4, Arg1, fromEuropeanToUs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DateFormat ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
