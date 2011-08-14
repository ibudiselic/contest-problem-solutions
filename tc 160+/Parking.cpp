#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <utility>

using namespace std;

const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
bool done[50][50];
int ind[50][50];
vector<string> P;
int M, N;
int nPark;
int nCar;
int dist[100][100];
int match[100];
int rmatch[100];
bool used[100];
set<int> allDists;

void bfs(int i, int j, int carInd) {
	memset(done, 0, sizeof done);
	queue< pair<int, int> > Q;
	Q.push(make_pair(i, j));
	done[i][j] = 0;
	int t = 0;
	int cur = -1;

	while (!Q.empty()) {
		if (t == 0) {
			t = Q.size();
			++cur;
		}
		--t;
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();

		for (int d=0; d<4; ++d) {
			const int r = i + di[d];
			const int c = j + dj[d];
			if (r>=0 && r<M && c>=0 && c<N && !done[r][c] && P[r][c]!='X') {
				if (P[r][c] == 'P') {
					dist[carInd][ind[r][c]] = cur+1;
					allDists.insert(cur+1);
				}
				done[r][c] = 1;
				Q.push(make_pair(r, c));
			}
		}
	}
}

bool getPath(int i, int maxDist) {
	used[i] = 1;
	for (int j=0; j<nPark; ++j)
		if (rmatch[j]==-1 && dist[i][j]<=maxDist) {
			match[i] = j;
			rmatch[j] = i;
			return true;
		} else if (rmatch[j]!=-1 && dist[i][j]<=maxDist && !used[rmatch[j]]) {
			if (getPath(rmatch[j], maxDist)) {
				match[i] = j;
				rmatch[j] = i;
				return true;
			}
		}
	return false;
}
bool canMatch(int maxDist) {
	if (nCar > nPark)
		return false;

	memset(match, 0xff, sizeof match);
	memset(rmatch, 0xff, sizeof rmatch);

	for (int i=0; i<nCar; ++i)
		for (int j=0; j<nPark; ++j)
			if (rmatch[j]==-1 && dist[i][j]<=maxDist) {
				match[i] = j;
				rmatch[j] = i;
				break;
			}

	for (int i=0; i<nCar; ++i)
		if (match[i] == -1) {
			memset(used, 0, sizeof used);
			if (!getPath(i, maxDist))
				return false;
		}

	return true;
}
class Parking {
	public:
	int minTime(vector <string> park) {
		memset(ind, 0xff, sizeof ind);
		P = park;
		M = P.size();
		N = P[0].size();

		nPark = 0;
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (P[i][j] == 'P')
					ind[i][j] = nPark++;

		memset(dist, 0x3f, sizeof dist);
		allDists.clear();

		nCar = 0;
		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				if (P[i][j] == 'C')
					bfs(i, j, nCar++);

		vector<int> v(allDists.begin(), allDists.end());
		int lo = 0;
		int hi = (int)v.size()-1;

		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			if (canMatch(v[mid]))
				hi = mid;
			else
				lo = mid+1;
		}

		return canMatch(v[lo]) ? v[lo] : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"C.....P",
 "C.....P",
 "C.....P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"C.X.....",
 "..X..X..",
 "..X..X..",
 ".....X.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXXXXXXXXX",
 "X......XPPX",
 "XC...P.XPPX",
 "X......X..X",
 "X....C....X",
 "XXXXXXXXXXX"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { string Arr0[] = {".C.",
 "...",
 "C.C",
 "X.X",
 "PPP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"CCCCC",
 ".....",
 "PXPXP"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minTime(Arg0)); }
	void test_case_5() { string Arr0[] = {"..X..",
 "C.X.P",
 "..X.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Parking ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
