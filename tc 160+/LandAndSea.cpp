#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <exception>

using namespace std;

const int di[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
const int dj[] = { 0, 1, 0, -1, -1, 1, 1, -1 };

int m, n;
bool outside[50][50];
bool done[50][50];
vector<string> G;
vector< vector<int> > islandMap;

void flood(int i, int j, int comp) {
	islandMap[i][j] = comp;

	for (int d=0; d<8; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];
		if (r>=0 && r<m && c>=0 && c<n && G[r][c]=='x' && islandMap[r][c]==-1)
			flood(r, c, comp);
	}
}
bool isEdge(int i, int j) {
	return i==0 || j==0 || i==m-1 || j==n-1;
}
bool canOut(int i, int j) {
	if (outside[i][j])
		return 1;
	if (isEdge(i, j))
		return 1;

	queue< pair<int, int> > Q;
	Q.push(make_pair(i, j));
	memset(done, 0, sizeof done);
	done[i][j] = 1;

	while (!Q.empty()) {
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();

		for (int d=0; d<4; ++d) {
			const int r = i + di[d];
			const int c = j + dj[d];
			if (G[r][c]=='.' && !done[r][c]) {
				if (outside[r][c] || isEdge(r, c))
					return 1;
				done[r][c] = 1;
				Q.push(make_pair(r, c));
			}
		}
	}

	return false;
}
void expand(int i, int j, int comp) {
	outside[i][j] = 1;
	for (int d=0; d<4; ++d) {
		const int r = i + di[d];
		const int c = j + dj[d];

		if (r>=0 && r<m && c>=0 && c<n && !outside[r][c] && islandMap[r][c]!=comp)
			expand(r, c, comp);
	}
}
class LandAndSea {
	public:
	vector <int> howManyIslands(vector <string> seaMap) {
		G = seaMap;
		m = G.size();
		n = G[0].size();
		islandMap.assign(m, vector<int> (n, -1));

		int cnt = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (G[i][j]=='x' && islandMap[i][j]==-1)
					flood(i, j, cnt++);

		vector< vector<int> > contains(cnt, vector<int> ());

		for (int comp=0; comp<cnt; ++comp) {
			memset(outside, 0, sizeof outside);
			for (int i=0; i<m; ++i) {
				int j=0;
				while (j<n && islandMap[i][j]!=comp)
					outside[i][j++] = 1;
				if (j < n) {
					j = n-1;
					while (islandMap[i][j] != comp)
						outside[i][j--] = 1;
				}
			}
			for (int j=0; j<n; ++j) {
				int i = 0;
				while (i<m && islandMap[i][j]!=comp)
					outside[i++][j] = 1;
				if (i < m) {
					i = m-1;
					while (islandMap[i][j] != comp)
						outside[i--][j] = 1;
				}
			}
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (outside[i][j])
						expand(i, j, comp);

			vector<bool> isInside(cnt, 1);
			isInside[comp] = 0;

			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (islandMap[i][j]!=-1 && islandMap[i][j]!=comp)
						isInside[islandMap[i][j]] = isInside[islandMap[i][j]] && !canOut(i, j);

			for (int i=0; i<cnt; ++i)
				if (isInside[i])
					contains[comp].push_back(i);
		}

		vector<int> level(cnt, 0);
		while (1) {
			for (int comp=0; comp<cnt; ++comp)
				for (int i=0; i<(int)contains[comp].size(); ++i)
					if (level[comp] < level[contains[comp][i]]+1) {
						level[comp] = level[contains[comp][i]]+1;
						goto REPEAT;
					}
			break;
			REPEAT: ;
		}

		int k = cnt>0 ? *max_element(level.begin(), level.end()) : -1;
		vector<int> sol(k+1, 0);

		for (int i=0; i<cnt; ++i)
			++sol[level[i]];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, howManyIslands(Arg0)); }
	void test_case_1() { string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, howManyIslands(Arg0)); }
	void test_case_2() { string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx",
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, howManyIslands(Arg0)); }
	void test_case_3() { string Arr0[] = {
"..",
".."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, howManyIslands(Arg0)); }
	void test_case_4() { string Arr0[] = {
"............",
".......xxxx.",
"..xxx.x...x.",
"..x..x..x.x.",
"..x.x.x...x.",
"..xx...xxx.."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, howManyIslands(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    LandAndSea ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
