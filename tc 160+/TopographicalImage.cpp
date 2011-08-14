#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool inPeak[50][50];
vector<string> D;
int M, N;
const int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int go(int i, int j) {
	inPeak[i][j] = 1;

	int ret = 1;
	for (int d=0; d<8; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];

		if (r>=0 && r<M && c>=0 && c<N && !inPeak[r][c] && D[r][c]<=D[i][j])
			ret += go(r, c);
	}
	return ret;
}
class TopographicalImage {
	public:
	vector <int> calcPeakAreas(vector <string> topoData) {
		D = topoData;
		M = D.size();
		N = D[0].size();

		memset(inPeak, 0, sizeof inPeak);

		vector<int> sol;

		while (1) {
			int hi=-1, hj=-1;
			int h = 0;

			for (int i=0; i<M; ++i)
				for (int j=0; j<N; ++j)
					if (!inPeak[i][j])
						if (D[i][j] > h) {
							h = D[i][j];
							hi = i;
							hj = j;
						}

			if (hi == -1)
				return sol;

			sol.push_back(go(hi, hj));
		}

		return vector<int>();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"............",
"....i..i....",
"....i..i....",
".o..i..i..o.",
".o........o.",
"..oooooooo..",
"............"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 78,  3,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calcPeakAreas(Arg0)); }
	void test_case_1() { string Arr0[] = {
"............",
"....i..i....",
"....i..i....",
".S..i..i..Y.",
".M........E.",
"..ILEYSMIL..",
"............"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 69,  3,  2,  5,  3,  1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calcPeakAreas(Arg0)); }
	void test_case_2() { string Arr0[] = {
"zzzzzzzzzzzzz",
"z...........z",
"z...c.b.c...z",
"z....bab.b..z",
"z...c.b.c...z",
"z...........z",
"zzzzzzzzzzzzz"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 81,  6,  2,  1,  1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calcPeakAreas(Arg0)); }
	void test_case_3() { string Arr0[] = {"!"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calcPeakAreas(Arg0)); }
	void test_case_4() { string Arr0[] = {
"AAAAAAABBBBCCCDEFGHHIIJIIHGFEDDCCCBBBBBBBBBBAAAAAA",
"AAAAABBBBBCCDDEEFGHIJJJJIIHGFEDDCCCCCCCCCBBBBBAAAA",
"AAAABBBBCCCDDEEFGHIIJJJJJIHGFEDDDDDDDDDCCCCBBBBAAA",
"AAABBBBCCDDEEFFGHHIJJJJJJIHGFEEDDDDDEEDDDDCCBBBBAA",
"AABBBCCDDEEFFGGHHIIJJJJJIHHGFEEEEEEEFFFEEDDCCBBBAA",
"BBBBCCDDEFFGHHHIIIIJJJIIIHGFFEEEEFFGGGGGFEEDCCBBBA",
"BBBCCDEEFGHIIIJJJJIIIIIHHGGFFEEFFGGHHHHHGGFEDCCBBB",
"BBCCDEEGHIJJKKKKJJJIIHHGGFFEEEEFGGHIIJJIIHGFEDCCBB",
"CCCDEEFHIJKLMMMLKKJIHHGGFFEEEEFFGHIJJKKJJIHGFEDCBB",
"CDDEEFHIJLMNNNNMLKJIHGFFEEEDEEFFGIJKKLLLKJIHFEDCCB",
"DDEFFGIJLMNOPPONMLJIHGFEEDDDDEFGHIJKLMMMLKJIGFEDCB",
"EEFFGHIKMNOQQQPONLKIHFEEDDDDDEFGHIKLMMNMMLKIHGEDCC",
"FFGGHIJLMOPQRRQPNMKIGFEDDCCDDEFGHIKLMNNNNMLJIGFEDC",
"GHHHIJKLNOQRRRQPOMKIGFEDDCCDDEFGHIKLMNNNNMLKIHFEDC",
"HIIIJJKLNOPQRRQPNLKIGFEDDCCDDEFGHJKLMNOONNMKJHGFDC",
"IJJJJJKLMOPQQQPONLJHGFEDDDDDEEFGIJKLMNOONNMLJIGFED",
"JJJJJKKLMNOOPPONMKJHGFEDDDDEEFGHIJKLMNNONNMLJIGFED",
"JKKJJJKKLMMNNNNMLJIHFFEEEEEFGGHIJKLMMNNNNMMKJIGFED",
"KKKJJJJJKKLLMLLKJIHGFFEEEFFGHIJKKLMMNNNNNMLKJHGFED",
"JJJJIIIIIJJJKKJJIIHGFFFFFGHIJKLMMNNNNNNMMLKJIHGEDC",
"JJJIIHHHHHHIIIIIHHGGGGGGHIJKLMNOOOOONNMMLKJIHGFEDC",
"IIIHHGGGGGGGGHHHGGGGGGHIIJLMNOPQQQQPONMLKJIHGFEDDC",
"HHHGGFFFFFFFFFGGGGGGHHIJKMNOQRSSSSRQPNMLKIHGFFEDCC",
"GGGFFEEEEEEEEFFFGGGHIJKLMOPRSTUUUTSRPNMKJHGFFEDCCB",
"FFFEEEEDDDDEEEEFGGHIJKLNOQRTUVWWWVTRPNLJIHFEEDCCBB",
"EEEEDDDDDDDDEEEFGHIJKLNOQRTVWXYYXWUSPNLJHGFEDCCBBB",
"DDDDDDDDDDDEEEFFGHIKLNOQRTVWXYZYYWURPMKIGFEDCCBBBB",
"CDDDDDDEEEEEEFFGHIJKMOPRSUWXYZZZXWTROMJHGEDCCBBBBA",
"CCDDDEEEFFFFFGGHHJKLNOQRTVWXYZZYXVTQNLIGFEDCBBBAAA",
"CCDDEFFGGGGHHHHIIJKMNPQSTVWXYYYXVURPMKIGEDCBBBAAAA",
"CDDEFGGHIIIIIIIJJKLMOPQSTUVWWXWVUSQNLJHFECCBBBAAAA",
"CDEFGHIJKKKKKKKKKLMNOPQRSTUVVVUTSQOMJHGEDCBBBAAAAA",
"CDEGHIKLMMMMMMLLLMMNOPQRSSTTTTSRQOMKIGFDCCBBAAAAAA",
"DEFGIKLMNOOOONNMMMNNOPQQRRRRRRQPNMKIHFEDCBBBAAAAAA",
"DEGHJLMOPQQQPPOONNNOOPPPQQQPPONMLKIHFEDCBBBAAAAAAA",
"DEGIKMNPQRRRRQPOOOOOOOPPPOOONMLKJIHFEDCCBBAAAAAAAA",
"DFGIKMOQRSSSRRQPOOOOOOOOONMMLKJIHGFEDCCBBBAAAAAAAA",
"DFGIKMOQRSSSRRQPOOOOONNNMMLKJIIHGFEDCCBBBAAAAAAAAA",
"DEGIJLNPQRRRRQPOONNNNNMMLLKJIHGFEEDCCBBBAAAAAAAAAA",
"DEFHJKMOPQQQQPOONNMMMMLLKJIHGGFEDDCCBBBAAAAAAAAAAA",
"CDFGIJLMNOOOONNMMLLLLLKKJIHGFEEDCCCBBBAAAAAAAAAAAA",
"CDEFGIJKLMMMMMLLKKKKKJJIIHGFEDDCCBBBBAAAAAAAAAAAAA",
"CCDEFGHIJKKKKKJJJIIIIIHHGGFEDDCCBBBBAAAAAAAAAAAAAA",
"BCCDEFGHHIIIIIHHHHHHHGGGFFEDDCCBBBAAAAAAAAAAAAAAAA",
"BBCCDEEFFGGGGGGFFFFFFFFEEDDCCCBBBAAAAAAAAAAAAAAAAA",
"BBBCCDDEEEEEEEEEEEEEEEEDDDCCBBBBAAAAAAAAAAAAAAAAAA",
"ABBBCCCCDDDDDDDDDDDDDDDCCCCBBBBAAAAAAAAAAAAAAAAAAA",
"AABBBBBCCCCCCCCCCCCCCCCCCBBBBBAAAAAAAAAAAAAAAAAAAA",
"AAABBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAA",
"AAAAAABBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAA"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1918,  65,  483,  5,  5,  24 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, calcPeakAreas(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TopographicalImage ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
