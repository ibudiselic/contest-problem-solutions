#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/* spaces will be 0, 'A'-'Z' will be 1-26, 'a'-'z' will be 27-52, '0'-'9' will be 53-62, and 63 will be used for any space after the message */
int getVal(char c) {
	if (c == ' ')
		return 0;
	else if (c>='A' && c<='Z')
		return c-'A'+1;
	else if (c>='a' && c<='z')
		return c-'a'+27;
	else if (c>='0' && c<='9')
		return c-'0'+53;
	else
		return -1;
}
int parseInt(const string &s) {
	assert(s.size() == 3);
	int ret = 0;
	for (int i=0; i<3; ++i)
		ret = ret*10 + (s[i]-'0');
	return ret;
}
string toStr(int x) {
	string ret(3, 0);
	for (int i=2; i>=0; --i) {
		ret[i] = x%10 + '0';
		x /= 10;
	}

	assert(x == 0);
	return ret;
}
int cover(int code, int val, int offset) {
	offset *= 2;

	return ((code&0xFC) | ((val>>offset)&3));
}
class ImageSteganography {
	public:
	vector <string> encode(vector <string> image, string message) {
		string s;
		for (int i=0; i<(int)image.size(); ++i)
			s += image[i];

		int pos = 0;
		string res;
		for (int i=0; i<(int)message.size(); ++i) {
			int val = getVal(message[i]);
			for (int j=0; j<3; ++j) {
				int code = parseInt(s.substr(pos, 3));
				res += toStr(cover(code, val, j));
				pos += 3;
			}
		}

		while (pos < (int)s.size()) {
			res += toStr(cover(parseInt(s.substr(pos, 3)), 3, 0));
			pos += 3;
		}

		vector<string> sol;
		pos = 0;
		for (int i=0; i<(int)image.size(); ++i) {
			sol.push_back(res.substr(pos, image[i].size()));
			pos += image[i].size();
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"255123212001201222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "hi"; string Arr2[] = { "254120214003200222" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, encode(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"255123212","001201222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "hi"; string Arr2[] = { "254120214",  "003200222" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, encode(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"123234213001023213123145",
 "222111121101213198009",
 "121122123124125",
 "132212093039",
 "213110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 =  "Hello 1"; string Arr2[] = { "120234212003023213122145",  "222110121102213198010",  "120120120126125",  "135215095039",  "215111" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, encode(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ImageSteganography ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
