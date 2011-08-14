#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void setBits(int &x, int pattern, int offset) {
	x |= (pattern << offset);
}
/*
convert(int character):
  if character <= 0x7F:
    output(character)
  else if character <= 0x7FF:
    output(0xC0 + getbits(character, 6, 5))
    output(0x80 + getbits(character, 0, 6))
  else if character <= 0xFFFF:
    output(0xE0 + getbits(character, 12, 4))
    output(0x80 + getbits(character, 6, 6))
    output(0x80 + getbits(character, 0, 6))
  else if character <= 0x10FFFF:
    output(0xF0 + getbits(character, 18, 3))
    output(0x80 + getbits(character, 12, 6))
    output(0x80 + getbits(character, 6, 6))
    output(0x80 + getbits(character, 0, 6))
  else:
    abort - character is out of range
*/
class UTF8Decode {
	public:
	vector <int> decodeString(vector <int> bytes) {
		int x = 0;
		int byte = 1;
		int need = 0;

		vector<int> sol;
		for (int i=0; i<(int)bytes.size(); ++i) {
			if (byte == 1) {
				if (bytes[i] <= 0x7F) {
					sol.push_back(bytes[i]);
				} else if (bytes[i] < 0xE0) {
					int t = bytes[i] - 0xC0;
					if ((bytes[i]&0xC0)!=0xC0 || t >= (1<<5) || t<2)
						continue;
					setBits(x, t, 6);
					need = 2;
					byte = 2;
				} else if (bytes[i] < 0xF0) {
					int t = bytes[i] - 0xE0;
					if ((bytes[i]&0xE0)!=0xE0 || t >= (1<<4))
						continue;
					setBits(x, t, 12);
					need = 3;
					byte = 2;
				} else {
					int t = bytes[i] - 0xF0;
					if ((bytes[i]&0xF0)!=0xF0 || t>4)
						continue;
					setBits(x, t, 18);
					need = 4;
					byte = 2;
				}
			} else {
				int t = bytes[i] - 0x80;
				if ((bytes[i]&0x80)!=0x80 || t>=(1<<6))
					continue;
				if (need==3 && byte==2 && (x==0 && t<32))
					continue;
				if (need==4 && byte==2 && (x==0 && t<16 || (x>>20) && t>=16))
					continue;
				setBits(x, t, (need-byte)*6);
				++byte;
				if (byte > need) {
					byte = 1;
					sol.push_back(x);
					x = 0;
				}
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {10,
 207, 168,
 226, 156, 144,
 240, 152, 154, 160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 1000, 10000, 100000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, decodeString(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 255,
 207, 17, 168, 193,
 226, 156, 144,
 240, 143, 152, 154, 160,
 240, 152, 154}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 1000, 10000, 100000 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, decodeString(Arg0)); }
	void test_case_2() { int Arr0[] = {191, 192, 193, 245, 255, 128, 129, 130, 189, 190, 191, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, decodeString(Arg0)); }
	void test_case_3() { int Arr0[] = {76, 95, 228, 250, 1, 100, 167, 59, 165, 27, 87, 32, 49, 22, 100, 236, 1,
 111, 209, 100, 155, 35, 156, 47, 135, 56, 114, 131, 32, 73, 24, 104, 92,
 221, 107, 12, 222, 60, 24, 113, 130, 217, 180, 144, 106, 136, 137, 234, 24, 173}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {76, 95, 18917, 27, 87, 32, 49, 22, 100, 50908, 47, 56, 114, 32, 73, 24, 104, 92, 1858, 1652, 106 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, decodeString(Arg0)); }
	void test_case_4() { int Arr0[] = {240, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, decodeString(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UTF8Decode ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
