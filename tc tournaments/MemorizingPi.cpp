#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

/*
	all digits equal                   ("333" or "0000", but not "2233"): 1
    powers of 2, with no leading zeros ("512" or "4096", but not "0064"): 2
    consecutive ascending digits       ("012" or "5678", but not "1357"): 4
    consecutive descending digits      ("987" or "3210", but not "1098"): 5
    first and last digits equal        ("858" or "1761", but not "8882"): 7
    any two digits equal               ("655" or "0777", but not "9753"): 8
    all other groups                   ("832" or "2049"                ): 10
*/

map<string, int> cost;
int dp[2500];
int choice[2500];
string S;

int getCost(const string &w) {
	assert(w.size()==3 || w.size()==4);

	int &ret = cost[w];
	if (ret != 0)
		return ret;

	char c = w[0];
	bool ok = true;
	for (int i=1; i<(int)w.size(); ++i)
		if (w[i] != c) {
			ok = false;
			break;
		}

	if (ok)
		return ret = 1;

	istringstream is(w);
	int val;
	is >> val;

	if (w.size()==3 && (val==128 || val==256 || val==512) || w.size()==4 && (val==1024 || val==2048 || val==4096 || val==8192))
		return ret = 2;

	ok = true;
	for (int i=1; i<(int)w.size(); ++i)
		if (w[i] != w[i-1]+1) {
			ok = false;
			break;
		}
	if (ok)
		return ret = 4;

	ok = true;
	for (int i=1; i<(int)w.size(); ++i)
		if (w[i] != w[i-1]-1) {
			ok = false;
			break;
		}
	if (ok)
		return ret = 5;

	if (c == w[w.size()-1])
		return ret = 7;

	for (int i=0; i<(int)w.size(); ++i)
		for (int j=i+1; j<(int)w.size(); ++j)
			if (w[i] == w[j])
				return ret = 8;

	return ret = 10;
}
int go(int pos) {
	if (pos == (int)S.size())
		return 0;

	if (dp[pos] != -1)
		return dp[pos];

	int &ret = dp[pos];
	ret = 1000000000;

	int t = 0;
	for (int c=3; c<=4; ++c)
		if (pos+c<=(int)S.size() && (t = getCost(S.substr(pos, c))+go(pos+c)) < ret) {
			ret = t;
			choice[pos] = c;
		}

	return ret;
}
class MemorizingPi {
	public:
	vector <string> segmentation(vector <string> digits) {
		S.clear();
		for (int i=0; i<(int)digits.size(); ++i)
			S += digits[i];

		cost.clear();
		memset(dp, 0xff, sizeof dp);

		go(0);

		vector<string> sol;
		string one;
		bool first = 1;
		int pos = 0;
		while (pos < (int)S.size()) {
			const string &grp = S.substr(pos, choice[pos]);

			if ((int)one.size() + (int)grp.size() + !first > 100) {
				sol.push_back(one);
				one = grp;
				first = 0;
			} else {
				if (!first)
					one += ' ';
				first = 0;
				one += grp;
			}
			pos += choice[pos];
		}

		sol.push_back(one);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "2562222567" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"256 2222 567" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, segmentation(Arg0)); }
	void test_case_1() { string Arr0[] = { "2222",
  "2",
  "25",
  "555",
  "555" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"222 222 555 5555" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, segmentation(Arg0)); }
	void test_case_2() { string Arr0[] = { "31415926535897932384626433832795028841971693993751",
  "05820974944592307816406286208998628034825342117067",
  "98214808651328230664709384460955058223172535940812",
  "84811174502841027019385211055596446229489549303819",
  "64428810975665933446128475648233786783165271201909",
  "14564856692346034861045432664821339360726024914127",
  "37245870066063155881748815209209628292540917153643",
  "67892590360011330530548820466521384146951941511609" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3141 5926 535 8979 3238 4626 433 832 7950 2884 1971 6939 9375 1058 2097 4944 5923 0781 6406 2862", "0899 8628 0348 2534 2117 0679 8214 8086 5132 8230 6647 0938 4460 9550 5822 3172 5359 4081 2848 111", "7450 2841 0270 1938 5211 0555 9644 6229 4895 4930 3819 6442 8810 9756 6593 3446 128 475 6482 3378", "678 3165 2712 0190 914 5648 5669 234 6034 8610 454 3266 4821 3393 6072 6024 9141 2737 2458 7006 6063", "1558 8174 8815 2092 0962 8292 5409 1715 3643 678 9259 0360 0113 3053 054 8820 4665 2138 4146 9519", "4151 1609" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, segmentation(Arg0)); }
	void test_case_3() { string Arr0[] = { "111222333444555",
  "111222333444555",
  "111222333444555",
  "111222333444555",
  "1112223334445555",
  "111222333444555",
  "111222333444555",
  "111222333444555",
  "111222333444555",
  "11122233344445555" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"111 222 333 444 555 111 222 333 444 555 111 222 333 444 555 111 222 333 444 555 111 222 333 444 5555", "111 222 333 444 555 111 222 333 444 555 111 222 333 444 555 111 222 333 444 555 111 222 333 4444", "5555" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, segmentation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MemorizingPi ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
