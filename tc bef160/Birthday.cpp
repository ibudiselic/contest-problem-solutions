#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

set<pair<int, int> > s;

class Birthday {
	public:
	string getNext(string date, vector <string>birthdays) {
		pair<int, int> cur;

		sscanf(date.c_str(), "%d/%d", &cur.first, &cur.second);
		s.clear();
		for (int i=0; i<(int)birthdays.size(); ++i) {
			pair<int, int> t;
			sscanf(birthdays[i].c_str(), "%d/%d", &t.first, &t.second);
			s.insert(t);
		}
		for (;;) {
			if (s.count(cur) != 0) {
				char buff[30];
				sprintf(buff, "%02d/%02d", cur.first, cur.second);
				return buff;
			}
			if (cur.second == 31) {
				++cur.first;
				cur.second = 0;
				if (cur.first == 13)
					cur.first = 1;
			} else
				++cur.second;
		}
		return "error";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "06/17"; string Arr1[] = {"02/17 Wernie", "10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(0, Arg2, getNext(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "06/17"; string Arr1[] = {"10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(1, Arg2, getNext(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "02/17"; string Arr1[] = {"02/17 Wernie", "10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "02/17"; verify_case(2, Arg2, getNext(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "12/24"; string Arr1[] = {"10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(3, Arg2, getNext(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "01/02"; string Arr1[] = {"02/17 Wernie",
 "10/12 Stefan",
 "02/17 MichaelJordan",
 "10/12 LucianoPavarotti",
 "05/18 WilhelmSteinitz"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "02/17"; verify_case(4, Arg2, getNext(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Birthday ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
