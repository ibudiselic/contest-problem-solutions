#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> tokenize_to_string(const string &s, const char delim=' ') {
	vector<string> ret;

	string t;
	for (string::size_type i=0; i<s.size(); ++i) {
		if (s[i]==delim) {
			ret.push_back(t);
			t.clear();
		} else {
			t += s[i];
		}
	}
	ret.push_back(t);

	return ret;
}
struct Player {
	string handle;
	double p[3];
	double ch;
	double score() const {
		return p[0]+p[1]+p[2]+ch;
	}
	string make_string() const {
		char buf[10];
		sprintf(buf, "%.2f", score());
		return handle+' '+string(buf);
	}
	Player(const string &s): handle(s) {
		p[0] = p[1] = p[2] = ch = 0;
	}
};

bool operator<(const Player &a, const Player &b) {
	const double x = a.score();
	const double y = b.score();

	if (x != y)
		return x > y;
	else return a.handle < b.handle;
}
class RoomSummary {
	public:
	vector <string> generate(vector <string> problems, vector <string> handles, vector <string> submissions, vector <string> challenges, vector <string> failed) {
		map<string, int> prob, hand;

		vector<Player> a;
		for (int i=0; i<(int)problems.size(); ++i)
			prob[problems[i]] = i;
		for (int i=0; i<(int)handles.size(); ++i) {
			hand[handles[i]] = i;
			a.push_back(Player(handles[i]));
		}

		for (int i=0; i<(int)submissions.size(); ++i) {
			char p[16], h[11];
			double score = 0.0;
			sscanf(submissions[i].c_str(), "%s %s %lf", h, p, &score);
			a[hand[h]].p[prob[p]] = score;
		}

		for (int i=0; i<(int)challenges.size(); ++i) {
			vector<string> t = tokenize_to_string(challenges[i]);
			if (t[3] == "successful") {
				a[hand[t[0]]].ch += 50.0;
				a[hand[t[1]]].p[prob[t[2]]] = 0;
			} else {
				a[hand[t[0]]].ch -= 50.0;
			}
		}
		for (int i=0; i<(int)failed.size(); ++i) {
			vector<string> t = tokenize_to_string(failed[i]);
			a[hand[t[0]]].p[prob[t[1]]] = 0;
		}
		sort(a.begin(), a.end());
		vector<string> sol;
		for (int i=0; i<(int)a.size(); ++i)
			sol.push_back(a[i].make_string());

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "EasyP", "MediumP", "HardP" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Andrea", "Billy", "Chris", "eddy", "David", "Feliza" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "Andrea EasyP 220.31",
  "Billy EasyP 213.24",
  "Chris EasyP 194.24",
  "Chris EasyP 75.00",
  "Andrea MediumP 472.23",
  "Billy MediumP 428.34",
  "Andrea HardP 823.60" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "Chris Andrea EasyP unsuccessful",
  "Chris Billy EasyP unsuccessful",
  "Billy Andrea HardP successful" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "Billy MediumP" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { "Andrea 692.54",  "Billy 263.24",  "David 0.00",  "Feliza 0.00",  "eddy 0.00",  "Chris -25.00" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(0, Arg5, generate(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = { "EasyP", "MediumP", "HardP" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Andrea", "Billy", "Chris" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "Billy EasyP 240.31",
  "Billy MediumP 425.23",
  "Chris HardP 831.42",
  "Andrea EasyP 89.12" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "Andrea Billy EasyP unsuccessful",
  "Andrea Chris HardP unsuccessful" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { "Chris 831.42",  "Billy 665.54",  "Andrea -10.88" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(1, Arg5, generate(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = { "250pointer", "500pointer", "1000pointer" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "Andrea", "Billy", "Chrissy", "Chris" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "Billy 250pointer 244.32",
  "Andrea 250pointer 241.42",
  "Andrea 500pointer 432.39",
  "Billy 500pointer 372.40",
  "Billy 250pointer 100.42" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "Billy Andrea 250pointer unsuccessful",
  "Andrea Billy 500pointer successful",
  "Billy Andrea 500pointer unsuccessful" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { "Andrea 723.81",  "Billy 0.42",  "Chris 0.00",  "Chrissy 0.00" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); verify_case(2, Arg5, generate(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RoomSummary ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
