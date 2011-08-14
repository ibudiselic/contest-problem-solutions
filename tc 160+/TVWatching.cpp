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

int dp[1441][1440];
int parse12hTime(const string &s) {
	int h, m;
	string mod;
	char c;
	istringstream is(s);
	is >> h >> c >> m >> mod;

	if (h == 12)
		h = 0;
	if (mod == "PM")
		h += 12;

	return h*60 + m;
}
vector<int> startTime, endTime;
int go(int firstTaken, int start) {
	if (start >= 1440)
		return 0;
	if (dp[firstTaken][start] != -1)
		return dp[firstTaken][start];

	dp[firstTaken][start] = 0;
	for (int i=0; i<(int)startTime.size(); ++i)
		if (startTime[i]>=start && (endTime[i]<=1440 || endTime[i]%1440<=firstTaken))
			dp[firstTaken][start] = max(dp[firstTaken][start], endTime[i]-startTime[i] + go(min(firstTaken, startTime[i]), endTime[i]));

	return dp[firstTaken][start];
}
class TVWatching {
	public:
	int mostMinutes(vector <string> programs) {
		startTime.clear();
		endTime.clear();

		for (int i=0; i<(int)programs.size(); ++i) {
			vector<string> t = cutUp(programs[i], " - ");
			startTime.push_back(parseTime(t[0]));
			endTime.push_back(parse12hTime(t[1]));
			if (endTime.back() <= startTime.back())
				endTime.back() += 24*60;
		}

		memset(dp, 0xff, sizeof dp);

		return go(1440, 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"09:00AM - 12:00PM", "02:00PM - 07:00PM", "09:00PM - 02:00AM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 780; verify_case(0, Arg1, mostMinutes(Arg0)); }
	void test_case_1() { string Arr0[] = {"01:15PM - 11:20PM", "08:00AM - 04:13PM", "03:12PM - 12:06AM", "02:00PM - 02:01PM" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 605; verify_case(1, Arg1, mostMinutes(Arg0)); }
	void test_case_2() { string Arr0[] = {"12:34PM - 12:34PM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1440; verify_case(2, Arg1, mostMinutes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TVWatching ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
