#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int bid[11], ask[11], spreadSum[11];
int cntChange[11], d[11];

string toStr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
string frac(int a, int b) {
	string ret = ".";
	a *= 10;
	ret += char((a/b)+'0');
	a = a%b * 10;
	ret += char((a/b)+'0');
	a = a%b * 10;

	if (a/b >= 5) {
		if (ret[2] == '9') {
			ret[2] = '0';
			++ret[1];
		} else {
			++ret[2];
		}
	}

	return ret;
}
string calcAvg(int x) {
	int whole = 0;

	int a = spreadSum[x];
	int b = d[x];

	whole = a/b;
	a -= whole*b;

	return toStr(whole) + frac(a, b);
}
string makeData(int x) {
	ostringstream os;
	os << x << ' ' << cntChange[x] << ' ';

	if (spreadSum[x] == 0)
		os << "0.00";
	else
		os << calcAvg(x);

	return os.str();
}
class StockQuotes {
	public:
	vector <string> report(vector <string> quotes) {
		memset(bid, 0xff, sizeof bid);
		memset(ask, 0xff, sizeof ask);
		memset(cntChange, 0, sizeof cntChange);
		memset(spreadSum, 0, sizeof spreadSum);
		memset(d, 0, sizeof d);

		int diff = -1;
		int mm=-1, MM=-1;
		for (int i=0; i<(int)quotes.size(); ++i) {
			int x, b, a;
			sscanf(quotes[i].c_str(), "%d %d %d", &x, &b, &a);
			bid[x] = b;
			ask[x] = a;
			++cntChange[x];
			spreadSum[x] += ask[x]-bid[x];
			++d[x];

			int m = 1234567890;
			int M = 0;
			for (int j=0; j<10; ++j)
				if (bid[j] != -1) {
					M = max(M, bid[j]);
					m = min(m, ask[j]);
				}
			if (m!=mm || M!=MM) {
				mm = m; MM = M;
				++cntChange[10];
				diff = m-M;
				spreadSum[10] += diff;
				++d[10];
			}
		}

		vector<string> sol;

		for (int i=0; i<10; ++i)
			if (cntChange[i] > 0)
				sol.push_back(makeData(i));

		sol.push_back(makeData(10));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 10 14",
 "1 9 16",
 "2 11 15",
 "0 11 13",
 "1 10 15",
 "2 12 14",
 "0 9 15",
 "2 8 20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 3 4.00", "1 2 6.00", "2 3 6.00", "10 6 2.83" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, report(Arg0)); }
	void test_case_1() { string Arr0[] = {"8 931 944",
 "8 926 946",
 "8 926 951",
 "8 928 953",
 "8 929 954"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"8 5 21.60", "10 5 21.60" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, report(Arg0)); }
	void test_case_2() { string Arr0[] = {"2 711 730",
 "5 716 729",
 "7 711 734",
 "0 718 731",
 "5 713 731",
 "1 713 730"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 13.00", "1 1 17.00", "2 1 19.00", "5 2 15.50", "7 1 23.00", "10 4 13.75" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, report(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StockQuotes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
