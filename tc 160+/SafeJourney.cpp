#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}

int hx, hy, wx, wy;
int maxX, maxY;
vector< vector<int> > board;
vector< vector<bool> > done;
int bfs() {
	done.assign(maxY, vector<bool> (maxX, false));
	deque< pair<int, int> > Q;
	int t = 0;
	int sol = -1;

	int i = hy;
	int j = hx;

	const int ti = wy;
	const int tj = wx;

	Q.push_back(make_pair(i, j));

	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++sol;
		}
		--t;

		i = Q.front().first;
		j = Q.front().second;
		Q.pop_front();
		if (done[i][j])
			continue;

		done[i][j] = true;
		if (i==ti && j==tj)
			return sol;

		for (int di=-1; di<=1; ++di)
			for (int dj=-1; dj<=1; ++dj)
				if (abs(di) + abs(dj) == 1) {
					const int r = i + di;
					const int c = j + dj;
					if (r>=0 && r<maxY && c>=0 && c<maxX) {
						if (done[r][c] || board[r][c]>1)
							continue;

						if (board[r][c] == 0) {
							Q.push_front(make_pair(r, c));
							++t;
						} else {
							Q.push_back(make_pair(r, c));
						}
					}
				}
	}

	return -1;
}

class SafeJourney {
	public:
	int fewestRoadCrossings(int width, int length, vector <string> horizontal, vector <string> vertical, string home, string work) {
		set<int> X, Y;

		for (int i=0; i<(int)horizontal.size(); ++i) {
			vector<string> t = cutUp(horizontal[i], ",");
			for (int j=0; j<(int)t.size(); ++j) {
				int y, x1, x2;
				sscanf(t[j].c_str(), "%d %d %d", &y, &x1, &x2);
				Y.insert(y);
				X.insert(x1);
				X.insert(x2);
			}
		}
		for (int i=0; i<(int)vertical.size(); ++i) {
			vector<string> t = cutUp(vertical[i], ",");
			for (int j=0; j<(int)t.size(); ++j) {
				int x, y1, y2;
				sscanf(t[j].c_str(), "%d %d %d", &x, &y1, &y2);
				X.insert(x);
				Y.insert(y1);
				Y.insert(y2);
			}
		}

		sscanf(home.c_str(), "%d %d", &hx, &hy);
		X.insert(hx);
		Y.insert(hy);

		sscanf(work.c_str(), "%d %d", &wx, &wy);
		X.insert(wx);
		Y.insert(wy);

		X.insert(0);
		X.insert(width);
		Y.insert(0);
		Y.insert(length);

		map<int, int> mX;
		int translate = 0;
		for (set<int>::const_iterator it=X.begin(); it!=X.end(); ++it) {
			mX[*it] = translate;
			translate += 2;
		}
		maxX = translate - 1;

		map<int, int> mY;
		translate = 0;
		for (set<int>::const_iterator it=Y.begin(); it!=Y.end(); ++it) {
			mY[*it] = translate;
			translate += 2;
		}
		maxY = translate - 1;

		hx = mX[hx];
		hy = mY[hy];
		wx = mX[wx];
		wy = mY[wy];

		board.assign(maxY, vector<int> (maxX, 0));

		for (int i=0; i<(int)horizontal.size(); ++i) {
			vector<string> t = cutUp(horizontal[i], ",");
			for (int j=0; j<(int)t.size(); ++j) {
				int y, x1, x2;
				sscanf(t[j].c_str(), "%d %d %d", &y, &x1, &x2);
				y = mY[y];
				x1 = mX[x1];
				x2 = mX[x2];

				for (int c=x1; c<=x2; ++c)
					++board[y][c];
			}
		}
		for (int i=0; i<(int)vertical.size(); ++i) {
			vector<string> t = cutUp(vertical[i], ",");
			for (int j=0; j<(int)t.size(); ++j) {
				int x, y1, y2;
				sscanf(t[j].c_str(), "%d %d %d", &x, &y1, &y2);
				x = mX[x];
				y1 = mY[y1];
				y2 = mY[y2];

				for (int r=y1; r<=y2; ++r)
					++board[r][x];
			}
		}

		return bfs();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; string Arr2[] = { "2 0 6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "2 2 4", "4 0 2" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "1 3"; string Arg5 = "5 1"; int Arg6 = 2; verify_case(0, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 4; string Arr2[] = { "2 0 6" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "2 0 2", "4 2 4" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "1 3"; string Arg5 = "5 1"; int Arg6 = 1; verify_case(1, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 5; string Arr2[] = { "4 1 3,1 1 3" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "2 1 4" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "1 2"; string Arg5 = "3 3"; int Arg6 = 0; verify_case(2, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 8; string Arr2[] = { "2 0 7", "4 0 7", "5 2 4,5 5 6", "6 0 4,6 5 7", "7 1 3" }
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "2 2 5", "3 0 6", "4 0 7", "5 0 5" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "1 3"; string Arg5 = "6 1"; int Arg6 = 4; verify_case(3, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 5; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "3 0 2", "3 2 5" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "2 4"; string Arg5 = "4 1"; int Arg6 = 1; verify_case(4, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 100; string Arr2[] = { "10 0 100,20 0 100,30 0 100,40 0 100,50 0 100",
  "60 0 100,70 0 100,80 0 100,90 0 100" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "10 0 100,20 0 100,30 0 100,40 0 100,50 0 100",
  "60 0 100,70 0 100,80 0 100,90 0 100" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "15 6"; string Arg5 = "93 95"; int Arg6 = 17; verify_case(5, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_6() { int Arg0 = 13; int Arg1 = 9; string Arr2[] = { "7 0 5,6 0 5,4 4 8,4 9 13,3 4 13,2 4 8,3 1 3" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "1 1 3,3 0 3,4 2 7,5 2 7,7 5 9,8 5 9,8 0 1,9 1 3", "10 1 3" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "2 8"; string Arg5 = "2 1"; int Arg6 = 1; verify_case(6, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_7() { int Arg0 = 15; int Arg1 = 8; string Arr2[] = { "1 9 14", "4 0 2", "6 2 3", "6 9 12", "7 0 2", "7 7 14" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "3 0 7", "4 1 8", "7 0 7", "9 1 6", "12 4 6", "14 1 6" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "10 4"; string Arg5 = "1 2"; int Arg6 = 0; verify_case(7, Arg6, fewestRoadCrossings(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SafeJourney ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
