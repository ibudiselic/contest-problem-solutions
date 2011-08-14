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
class TravellingByTrain {
	public:
	string earliestArrival(vector <string> timeTable) {
		int curTime = 9*60;

		for (int i=0; i<(int)timeTable.size(); ++i) {
			vector<string> t = cutUp(timeTable[i], " ");
			int nextTime = curTime;
			for (int j=0; j<(int)t.size(); ++j) {
				int h, m, H, M;
				sscanf(t[j].c_str(), "%d:%d-%d:%d", &h, &m, &H, &M);
				m += h*60;
				M += H*60;

				while (m < curTime) {
					m += 24*60;
					M += 24*60;
				}

				if (m >= M)
					M += 24*60;

				if (j == 0)
					nextTime = M;
				else
					nextTime = min(nextTime, M);
			}
			curTime = nextTime;
		}

		int d = curTime/(24*60);
		curTime -= d*24*60;
		char buff[100];
		sprintf(buff, "%02d:%02d, day %d", curTime/60, curTime%60, d+1);

		return string(buff);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10:00-13:00 12:00-15:00","11:00-16:00 14:00-19:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "19:00, day 1"; verify_case(0, Arg1, earliestArrival(Arg0)); }
	void test_case_1() { string Arr0[] = {"09:00-13:57","13:56-17:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "17:00, day 2"; verify_case(1, Arg1, earliestArrival(Arg0)); }
	void test_case_2() { string Arr0[] = {"10:00-08:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "08:00, day 2"; verify_case(2, Arg1, earliestArrival(Arg0)); }
	void test_case_3() { string Arr0[] = {"09:10-11:00 09:05-10:05","10:10-12:00 11:00-11:05","17:00-08:00","09:00-08:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "08:00, day 3"; verify_case(3, Arg1, earliestArrival(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TravellingByTrain ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
