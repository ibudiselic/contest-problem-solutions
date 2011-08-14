#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;
template<class T> string to_str(T x) {
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}
template<class T> int bitcount(T x) {
	int ret = 0;
	for (typeof(x) i=0; (1ull<<i)<=x; ++i)
		if (((1<<i) & x) != 0)
			++ret;
	return ret;
}
template<class T> inline bool get_bit(T x, int index) {
	return (x>>index) & 1;
}
template<class T> inline void set_bit(T &x, int index) {
	const T one = 1;
	x |= (one<<index);
}
template<class T> inline void flip_bit(T &x, int index) {
	const T one = 1;
	x ^= (one<<index);
}
template<class T> inline void reset_bit(T &x, int index) {
	const T one = 1;
	x &= ~(one<<index);
}
typedef pair<int, int> PII;
map<PII, int> m;
bool win[1u<<9];

int go(unsigned mask, unsigned cur) {
	if (mask == (1u<<9)-1)
		return 0;
	const PII t = make_pair(mask, cur);
	if (m.count(t))
		return m[t];

	for (int i=0; i<9; ++i)
		if (!get_bit(mask, i))
			if (win[cur|(1u<<i)] || !go(mask|(1u<<i), ~cur&mask))
				return m[t] = i+1;
	return 0;
}
class Fifteen {
	public:
	string outcome(vector <int> moves) {
		m.clear();

		for (unsigned mask=0; mask<(1u<<9); ++mask) {
			int sum = 0;
			if (bitcount(mask) == 3)
				for (int i=0; (1u<<i)<=mask; ++i)
					if (get_bit(mask, i))
						sum += i+1;
			win[mask] = sum==15;
			if (!win[mask])
				for (unsigned sub=0; sub<mask; ++sub)
					if (win[sub] && (mask&sub)==sub) {
						win[mask] = true;
						break;
					}
		}

		unsigned mask=0, cur=0;
		bool dealer = true;
		for (int i=0; i<(int)moves.size(); ++i) {
			set_bit(mask, moves[i]-1);
			if (!dealer)
				set_bit(cur, moves[i]-1);
			dealer = !dealer;
		}

		int t = go(mask, cur);
		if (t > 0)
			return "WIN " + to_str(t);
		else
			return "LOSE";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 5, 9, 6, 8, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 4"; verify_case(0, Arg1, outcome(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 8, 6, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(1, Arg1, outcome(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 4, 7, 6, 9, 8, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 1"; verify_case(2, Arg1, outcome(Arg0)); }
	void test_case_3() { int Arr0[] = {9, 2, 1, 6, 3, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 5"; verify_case(3, Arg1, outcome(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(4, Arg1, outcome(Arg0)); }
	void test_case_5() { int Arr0[] = {6, 3, 7, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 2"; verify_case(5, Arg1, outcome(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Fifteen ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
