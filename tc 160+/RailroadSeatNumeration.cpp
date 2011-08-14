#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string to_str(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
bool inter(int x) {
	int comp = x/10;
	int seat = x%10;
	return comp>=1 && comp<=9 && (seat==1 || seat==3 || seat==4 || seat==6);
}
bool dom(int x) {
	return x>=1 && x<=9*4;
}
int f(int x) {
	int comp = (x-1)/4 + 1;
	int seat = (x-1)%4;
	static const int v[] = { 1, 3, 4, 6 };
	return comp*10 + v[seat];
}
string d2i(vector<int> v) {
	string ret;
	for (int i=0; i<(int)v.size(); ++i)
		if (!dom(v[i]))
			return "";
	for (int i=0; i<(int)v.size(); ++i)
		v[i] = f(v[i]);
	for (int i=0; i<(int)v.size(); ++i) {
		if (i)
			ret += ' ';
		ret += to_str(v[i]);
	}
	return ret;
}
string i2i(const vector<int> &v) {
	string ret;
	for (int i=0; i<(int)v.size(); ++i)
		if (!inter(v[i]))
			return "";
	for (int i=0; i<(int)v.size(); ++i) {
		if (i)
			ret += ' ';
		ret += to_str(v[i]);
	}
	return ret;
}
class RailroadSeatNumeration {
	public:
	string getInternational(vector <int> tickets) {
		string s = d2i(tickets);
		string t = i2i(tickets);

		if (s=="" && t=="")
			return "BAD DATA";
		if (s!="" && t!="")
			return "AMBIGUOUS";
		return (s=="" ? t : s);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "11"; verify_case(0, Arg1, getInternational(Arg0)); }
	void test_case_1() { int Arr0[] = {11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUOUS"; verify_case(1, Arg1, getInternational(Arg0)); }
	void test_case_2() { int Arr0[] = {45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BAD DATA"; verify_case(2, Arg1, getInternational(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 7, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "21 24 23"; verify_case(3, Arg1, getInternational(Arg0)); }
	void test_case_4() { int Arr0[] = {21, 24, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUOUS"; verify_case(4, Arg1, getInternational(Arg0)); }
	void test_case_5() { int Arr0[] = {8, 28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "26 76"; verify_case(5, Arg1, getInternational(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RailroadSeatNumeration ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
