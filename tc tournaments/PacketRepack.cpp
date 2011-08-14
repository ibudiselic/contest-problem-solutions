#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Data {
	Data() {
		memset(d, 0, sizeof d);
	}
	void set_b(int pos, bool val) {
		d[pos/32] |= (val << (31-pos%32));
	}
	bool get_b(int pos) const {
		return (d[pos/32] & (1<<(31-pos%32))) != 0;
	}
	void set_w(int start, int len, int w) {
		for (int i=0; i<len; ++i)
			set_b(start + len-1 - i, (w&(1<<i))!=0);
	}
	int get_w(int start, int len) const {
		int w = 0;
		for (int i=0; i<len; ++i)
			w = w*2 + get_b(start+i);

		return w;
	}
	void ispis() {
		for (int i=0; i<320; ++i)
			cerr << get_b(i);
		cerr << '\n';
	}
	private:
	int d[10];
};
class PacketRepack {
	public:
	vector <int> output(vector <int> input, int b, int num_fields, int field_size) {
		Data A;
		for (int i=(int)input.size()-1; i>=0; --i)
			A.set_w(((int)input.size()-1-i)*b, b, input[i]);

		int fieldStart = input.size()*b - num_fields*field_size;

		Data B;
		for (int i=0; i<num_fields; ++i)
			B.set_w(input.size()*b - (i+1)*field_size, field_size, A.get_w(fieldStart + i*field_size, field_size));

		vector<int> sol;
		for (int i=0; i<(int)input.size(); ++i)
			sol.push_back(B.get_w(input.size()*b - (i+1)*b, b));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = { 22, 37, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 4; int Arg3 = 4; int Arr4[] = {19, 22, 6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, output(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { 1, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; int Arg2 = 10; int Arg3 = 1; int Arr4[] = {512, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, output(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 1, 0, 0, 0 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 31; int Arg3 = 1; int Arr4[] = {0, 0, 0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, output(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = { 15834, 2483, 19423 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = 8; int Arg3 = 6; int Arr4[] = {53074, 60455, 27516 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, output(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PacketRepack ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
