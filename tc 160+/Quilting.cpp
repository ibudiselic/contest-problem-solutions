#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Color {
	int orig, cnt;
	int susjed;
	char c;
	Color(int o, int cn, int s, char sym): orig(o), cnt(cn), susjed(s), c(sym) {}
};
bool operator<(const Color& a, const Color&b) {
	if (a.susjed != b.susjed)
		return (a.susjed < b.susjed);
	else if (a.cnt != b.cnt)
		return (a.cnt < b.cnt);
	else
		return (a.orig < b.orig);
}

int dx[] = { -1, 0, 1, 0 };
int dy[] = {  0,-1, 0, 1 };

char board[400][400];
class Quilting {
	public:
	string lastPatch(int length, int width, vector <string> colorList) {
		memset(board, 0, sizeof board);
		int n = length*width;
		int dir = 0;
		int x, y;

		vector<Color> clist;
		for (int i=0; i<(int)colorList.size(); ++i)
			clist.push_back(Color(i, 0, 0, i+'a'));

		x = y = 200;
		while (n--) {
			sort(clist.begin(), clist.end());
			if (n == 0)
				return colorList[clist[0].orig];
			const Color t = clist[0];
			board[x][y] = t.c;
			++clist[0].cnt;
			x += dx[dir];
			y += dy[dir];
			if (board[x+dx[(dir+1)%4]][y+dy[(dir+1)%4]] == 0)
				dir = (dir+1)%4;
			for (int k=0; k<(int)clist.size(); ++k)
				clist[k].susjed = 0;
			for (int i=-1; i<=1; ++i)
				for (int j=-1; j<=1; ++j)
					if (abs(i)+abs(j)!=0 && board[x+i][y+j]!=0) {
						const char tt = board[x+i][y+j];
						for (int k=0; k<(int)clist.size(); ++k)
							if (tt == clist[k].c) {
								++clist[k].susjed;
								break;
							}
					}
		}
		return "error";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; string Arr2[] = {"RED","BLUE","TAN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "TAN"; verify_case(0, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; string Arr2[] = {"E","D","C","B","A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "E"; verify_case(1, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"A","B","C","D"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "C"; verify_case(2, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"RED","BLUE","YELLOW"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "RED"; verify_case(3, Arg3, lastPatch(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 10; string Arr2[] = {"X","Y","Z"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Z"; verify_case(4, Arg3, lastPatch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Quilting ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
