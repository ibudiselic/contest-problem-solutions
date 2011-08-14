#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}

class Salary {
	public:
	int howMuch(vector <string> arrival, vector <string> departure, int wage) {
		int sec = 0;
		int a = 18*3600;
		int b = 6*3600;

		for (vector<string>::size_type i=0; i<arrival.size(); ++i) {
			vector<int> t = tokenize<int>(arrival[i], ":");
			int t1 = t[0]*3600+t[1]*60+t[2];
			t = tokenize<int>(departure[i], ":");
			int t2 = t[0]*3600+t[1]*60+t[2];
			if (t2 > a) {
				sec += 3*(t2 - max(a, t1));
				t2 = a;
			}
			if (t1 < b) {
				sec += 3*(min(t2, b) - t1);
				t1 = b;
			}
			if (t2 > t1)
				sec += 2*(t2-t1);
		}
		return (int)((long long)sec*wage/7200);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"08:00:00","13:00:00","19:27:32"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"12:00:00","17:00:00","20:48:10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 10015; verify_case(0, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"01:05:47","16:48:12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"09:27:30","21:17:59"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2000; int Arg3 = 33920; verify_case(1, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"00:00:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"23:59:59"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; int Arg3 = 299995; verify_case(2, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"10:00:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"18:00:00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; int Arg3 = 80000; verify_case(3, Arg3, howMuch(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"22:19:46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"23:12:46"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5320; int Arg3 = 7049; verify_case(4, Arg3, howMuch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Salary ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
