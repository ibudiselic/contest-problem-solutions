#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}
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
template<class T> string bits(T x, int len=-1) {
	string ret;
	const T one = 1;
	for (typeof(x) i=0; (one<<i)<=x; ++i)
		if (((one<<i) & x) != 0)
			ret += '1';
		else ret += '0';
	if (len!=-1 && len>(int)ret.size())
		ret += string(len-ret.size(), '0');
	reverse(ret.begin(), ret.end());
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
class Clue {
	public:

	vector <string> whodunit(vector <string> cards, vector <string> guesses) {
		unsigned p[3] = {0};
		unsigned sol = 0;
		const unsigned clear = 0x1fffff;
		const unsigned lim = (1u<<12);

		vector<string> c;
		for (int i=1; i<=6; ++i)
			c.push_back("S"+to_str(i));
		for (int i=1; i<=6; ++i)
			c.push_back("W"+to_str(i));
		for (int i=1; i<=9; ++i)
			c.push_back("L"+to_str(i));

		map<string, int> index;
		for (int i=0; i<(int)c.size(); ++i)
			index[c[i]] = i;

		for (int i=0; i<(int)cards.size(); ++i) {
			const int t = index[cards[i]];
			set_bit(p[0], t);
		}
		vector<int> guesser, replyer;
		vector<unsigned> guess;
		vector<string> reply;

		for (int i=0; i<(int)guesses.size(); ++i) {
			vector<int> t = tokenize<int>(guesses[i].substr(0, 9));
			guesser.push_back(t[0]);
			replyer.push_back(t[4]);
			reply.push_back(guesses[i].substr(10));

			unsigned g = 0;
			set_bit(g, index["S"+to_str(t[1])]);
			set_bit(g, index["L"+to_str(t[2])]);
			set_bit(g, index["W"+to_str(t[3])]);
			guess.push_back(g);
		}

		unsigned secret = 0;
		for (int i=0; i<6; reset_bit(secret, i), ++i) {
			if (get_bit(p[0], i)) continue;
			set_bit(secret, i);
			for (int j=6; j<12; reset_bit(secret, j), ++j) {
				if (get_bit(p[0], j)) continue;
				set_bit(secret, j);
					for (int k=12; k<21; reset_bit(secret, k), ++k) {
						if (get_bit(p[0], k)) continue;
						set_bit(secret, k);

						assert((secret&p[0]) == 0);
						assert(bitcount(secret) == 3);
						vector<int> avail;
						for (int x=0; x<(int)c.size(); ++x)
							if (!get_bit(p[0], x) && !get_bit(secret, x))
								avail.push_back(x);
						assert(avail.size() == 12);
						for (unsigned mask=1; mask<lim; ++mask) {
							if (bitcount(mask) != 6) continue;
							p[1] = 0;
							for (int x=0; (1u<<x)<=mask; ++x)
								if (get_bit(mask, x))
									set_bit(p[1], avail[x]);
							assert(bitcount(p[1]) == 6);
							p[2] = ~(p[0]|p[1]|secret) & clear;
							assert(bitcount(p[2]) == 6);
							assert((p[0]|p[1]|p[2]|secret) == clear);

							bool good = true;
							for (int x=0; x<(int)guesses.size(); ++x) {
								if (replyer[x] == 0) {
									unsigned tt = 0;
									for (int y=0; y<3; ++y)
										if (y!=guesser[x]-1)
											tt |= p[y];
									if ((tt & guess[x]) != 0) {
										good = false;
										goto kraj;
									}
								} else if ((guesser[x]+1)%3 == replyer[x]-1 && (p[guesser[x]%3] & guess[x]) != 0) {
									good = false;
									goto kraj;
								}
								if (replyer[x]!=0 && (p[replyer[x]-1] & guess[x])==0) {
									good = false;
									goto kraj;
								}
								if (reply[x]!="N0" && !get_bit(p[replyer[x]-1], index[reply[x]])) {
									good = false;
									goto kraj;
								}
							}
							kraj:
							if (good)
								sol |= secret;
						}
					}
				}
			}

		vector<string> ret;
		for (int i=0; (1u<<i)<=sol; ++i)
			if (get_bit(sol, i))
				ret.push_back(c[i]);

		sort(ret.begin(), ret.end());
		return ret;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"S1","S2","S4","S3","S5","W5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 1 1 1 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "S6",  "W1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, whodunit(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"L3","S2","S4","S3","S5","W5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 1 1 1 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "L2",  "L4",  "L5",  "L6",  "L7",  "L8",  "L9",  "S1",  "S6",  "W1",  "W2",  "W3",  "W4",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, whodunit(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"W4","W1","L5","L9","S3","L2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 3 8 4 1 W4",
 "1 3 8 3 3 W3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L8",  "S1",  "S2",  "S4",  "S5",  "S6",  "W2",  "W5",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, whodunit(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"W4","W1","L5","L9","S3","L2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 3 5 4 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "L3",  "L4",  "L6",  "L7",  "L8",  "S1",  "S2",  "S4",  "S5",  "S6",  "W2",  "W3",  "W5",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, whodunit(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"W4","W1","L5","L9","S3","L2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L1",  "L3",  "L4",  "L6",  "L7",  "L8",  "S1",  "S2",  "S4",  "S5",  "S6",  "W2",  "W3",  "W5",  "W6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, whodunit(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"L5","L7","L8","S5","W5","W6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 6 1 6 3 N0",
 "3 6 5 4 1 L5",
 "1 6 1 3 2 W3",
 "2 3 5 1 3 N0",
 "3 5 7 1 1 S5",
 "1 6 1 1 3 L1",
 "2 1 2 5 3 N0",
 "3 4 6 5 1 W5",
 "1 3 3 4 2 W4",
 "2 6 4 1 3 N0",
 "3 4 3 6 1 W6",
 "1 4 6 1 2 S4",
 "2 2 5 6 3 N0",
 "3 6 7 4 1 L7",
 "1 6 4 1 3 L4",
 "2 6 5 1 1 L5",
 "3 4 3 1 2 N0",
 "1 6 2 1 3 L2",
 "2 6 3 1 0 N0",
 "3 6 3 1 0 N0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "L3",  "S6",  "W1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, whodunit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Clue ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
