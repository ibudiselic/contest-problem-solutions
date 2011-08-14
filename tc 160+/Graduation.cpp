#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <queue>

using namespace std;

vector< vector<int> > G;
vector<int> matching;

void bfs(int pos) {
	vector<int> parent(G.size(), -1);

	parent[pos] = -2;
	queue<int> q;

	q.push(pos);

	bool found = 0;
	while (!q.empty()) {
		pos = q.front();
		q.pop();

		if (pos >= 127) {
			if (matching[pos] == -1) {
				found = 1;
				break;
			} else {
				if (parent[matching[pos]] == -1) {
					parent[matching[pos]] = pos;
					q.push(matching[pos]);
				}
				continue;
			}
		}

		for (int i=0; i<(int)G[pos].size(); ++i)
			if (parent[G[pos][i]] == -1) {
				parent[G[pos][i]] = pos;
				q.push(G[pos][i]);
			}
	}

	if (found) {
		while (1) {
			//cerr << pos << ' ' << char(parent[pos]) << ' ';
			matching[pos] = parent[pos];
			matching[parent[pos]] = pos;

			if (parent[parent[pos]] == -2)
				break;
			pos = parent[parent[pos]];
		}
	}
}

class Graduation {
	public:
	string moreClasses(string classesTaken, vector <string> requirements) {
		G.assign(127, vector<int> ());

		for (int i=0; i<(int)requirements.size(); ++i) {
			int cnt = 0;
			int j = 0;
			while (isdigit(requirements[i][j]))
				cnt = cnt*10 + requirements[i][j++]-'0';

			if (cnt > (int)requirements[i].size()-j)
				return "0";

			while (cnt--) {
				G.push_back(vector<int> ());
				for (int k=j; k<(int)requirements[i].size(); ++k) {
					G[requirements[i][k]].push_back(G.size()-1);
					G.back().push_back(requirements[i][k]);
				}
			}
		}

		for (int i=0; i<(int)G.size(); ++i)
			if (G[i].size() > 0)
				sort(G[i].begin(), G[i].end());

		vector<bool> hadBefore(127, 0);
		matching.assign(G.size(), -1);

		sort(classesTaken.begin(), classesTaken.end());

		for (int i=0; i<(int)classesTaken.size(); ++i) {
			hadBefore[classesTaken[i]] = 1;
			if (matching[classesTaken[i]] == -1) {
				//cerr << classesTaken[i] << " :: ";
				bfs(classesTaken[i]);
				//cerr << '\n';
			}
		}

		for (int i=33; i<127; ++i)
			if (matching[i] == -1) {
				//cerr << char(i) << " :: ";
				bfs(i);
				//cerr << '\n';
			}

		for (int i=127; i<(int)G.size(); ++i)
			if (matching[i] == -1)
				return "0";

		string sol;
		for (int i=33; i<127; ++i)
			if (matching[i]!=-1 && matching[matching[i]]==i && !hadBefore[i])
				sol += char(i);

		return sol;
	}



// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arr1[] = {"2ABC","2CDE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "BCD"; verify_case(0, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+/NAMT"; string Arr1[] = {"3NAMT","2+/","1M"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(1, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "A"; string Arr1[] = {"100%*Klju"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "0"; verify_case(2, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ""; string Arr1[] = {"5ABCDE","1BCDE,"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ",ABCDE"; verify_case(3, Arg2, moreClasses(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "CDH"; string Arr1[] = {"2AP", "3CDEF", "1CDEFH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AEP"; verify_case(4, Arg2, moreClasses(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Graduation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
