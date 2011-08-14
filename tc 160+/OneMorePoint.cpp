#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int N;
int maxX, maxY;
vector<int> X1, Y1, X2, Y2;
vector< vector<int> > A;
inline bool valid(int i, int j) {
	if (i<0 || j<0 || i>=maxY || j>=maxX)
		return false;
	return true;
}
bool test(int i, int j, int di, int dj) {
	while (valid(i, j)) {
		if (A[i][j])
			return true;
		i += di;
		j += dj;
	}
	return false;
}
class OneMorePoint {
	public:
	string interiorPoint(vector <string> rectangles) {
		N = rectangles.size();
		X1.assign(N, 0);
		Y1.assign(N, 0);
		X2.assign(N, 0);
		Y2.assign(N, 0);

		set<int> sX, sY;
		for (int i=0; i<(int)rectangles.size(); ++i) {
			sscanf(rectangles[i].c_str(), "%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
			sX.insert(X1[i]);
			sY.insert(Y1[i]);
			sX.insert(X2[i]);
			sY.insert(Y2[i]);
		}

		map<int, int> mX, mY;
		int t = 0;
		for (set<int>::const_iterator it=sX.begin(); it!=sX.end(); ++it, t+=2)
			mX[*it] = t;
		maxX = t;

		t = 0;
		for (set<int>::const_iterator it=sY.begin(); it!=sY.end(); ++it, t+=2)
			mY[*it] = t;
		maxY = t;

		for (int i=0; i<N; ++i) {
			X1[i] = mX[X1[i]];
			Y1[i] = mY[Y1[i]];
			X2[i] = mX[X2[i]];
			Y2[i] = mY[Y2[i]];
		}

		A.assign(maxY, vector<int> (maxX, 0));
		for (int i=0; i<N; ++i)
			for (int r=Y1[i]; r<Y2[i]; ++r)
				for (int c=X1[i]; c<X2[i]; ++c)
					A[r][c] = 1;

		for (int i=1; i<maxY; i+=2)
			for (int j=1; j<maxX; j+=2)
				if (A[i][j] == 0) {
					for (int di=-1; di<=1; ++di)
						for (int dj=-1; dj<=1; ++dj)
							if (abs(di) + abs(dj) == 1)
								if (!test(i, j, di, dj))
									goto fail;
					return "YES";
					fail: ;
				}

		return "NO";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"5068 5408 5521 5409", "6283 9537 6284 9538", "1376 106 4470 8056", "8273 8541 8274 8542", "3208 843 3209 8364", "3799 4306 3800 4307", "6622 1069 6623 1070", "49 3345 8667 5859", "2310 7632 7666 7633", "5068 8453 5069 8454", "277 3715 9779 8640", "9426 9593 9427 9594", "5235 8142 7263 8287", "4267 1033 8698 3632", "2250 8195 9659 8269", "1160 9822 4138 9823", "5869 8203 9867 8204", "5579 649 8353 650", "8419 6687 8420 9451", "6632 1900 6633 7569", "6239 5914 6240 7878", "5358 5940 5359 9338", "5569 5554 5570 6405", "6024 6740 8625 9534"}/*{"0 0 2 1", "2 0 3 2", "1 2 3 3", "0 1 1 3"}*/; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, interiorPoint(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 0 2 1", "2 0 3 2", "1 2 3 3", "0 1 1 3", "1 1 2 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, interiorPoint(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 0 2 1", "3 0 4 2", "2 3 4 4", "0 2 1 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, interiorPoint(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 0 100 1", "100 1 200 2", "0 0 1 100", "50 50 51 51"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, interiorPoint(Arg0)); }
	void test_case_4() { string Arr0[] = {"1 1 1000 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, interiorPoint(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    OneMorePoint ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
