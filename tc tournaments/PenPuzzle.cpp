#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>
#include <queue>
#include <set>

using namespace std;

int M, N;
map<char, int> CV;
char IV[4];

int encode(const string &s) {
	int ret = 0;
	for (int i=0; i<(int)s.size(); ++i)
		ret = ret*4 + CV[s[i]];
	return ret;
}
string decode(int x) {
	string ret(M*N, ' ');
	for (int i=ret.size()-1; i>=0; --i) {
		ret[i] = IV[x%4];
		x /= 4;
	}
	return ret;
}
pair<string, int> rotate(string s, int blank, int level, bool ccw) {
	if (ccw) {
		const char c = s[level*N];
		for (int i=level*N; i<level*N+N-1; ++i)
			s[i] = s[i+1];
		s[level*N+N-1] = c;
	} else {
		const char c = s[level*N+N-1];
		for (int i=level*N+N-1; i>level*N; --i)
			s[i] = s[i-1];
		s[level*N] = c;
	}
	if (blank>=N*level && blank<=N*level+N-1)
		blank = (blank - N*level + N - (ccw - !ccw))%N + N*level;

	return make_pair(s, blank);
}
pair<string, int> up(string s, int blank) {
	assert(blank%N == 0); /* only call on normalized states */
	const int level = blank/N;
	if (level > 0) {
		const char c = s[blank];
		s[blank] = s[blank-N];
		s[blank-N] = c;
		return make_pair(s, blank-N);
	}
	return make_pair("", -1);
}
pair<string, int> down(string s, int blank) {
	assert(blank%N == 0); /* only call on normalized states */
	const int level = blank/N;
	if (level < M-1) {
		const char c = s[blank];
		s[blank] = s[blank+N];
		s[blank+N] = c;
		return make_pair(s, blank+N);
	}
	return make_pair("", -1);
}
bool done(const string &s) {
	for (int j=0; j<N; ++j)
		for (int i=1; i<M; ++i)
			if (s[(i-1)*N + j] != s[i*N + j])
				return false;
	return true;
}
pair<string, int> normalize(string s, int blank) {
	/* rotate blank to first column */
	while (blank%N != 0) {
		for (int i=0; i<M; ++i) {
			const pair<string, int> &t = rotate(s, blank, i, 0);
			s = t.first;
			blank = t.second;
		}
	}

	/* color symetry */
	vector<int> pos[4];
	for (int i=0; i<M*N; ++i)
		pos[CV[s[i]]].push_back(i);

	vector<int> order(4);
	for (int i=0; i<4; ++i)
		order[i] = i;

	for (int i=0; i<3; ++i)
		for (int j=i+1; j<4; ++j)
			if (pos[order[i]].size()==0 || (pos[order[j]].size()>0 && pos[order[i]][0]>pos[order[j]][0]))
				swap(order[i], order[j]);

	for (int i=0; i<4; ++i)
		for (int j=0; j<(int)pos[order[i]].size(); ++j)
			s[ pos[order[i]][j] ] = IV[i];

	return make_pair(s, blank);
}
int bfs(const pair<string, int> &p) {
	set< pair<int, int> > used;
	queue< pair<string, int> > q;

	used.insert(make_pair(encode(p.first), p.second));
	q.push(p);
	int cnt = 0;
	int sol = -1;
	while (!q.empty()) {
		if (cnt == 0) {
			cnt = q.size();
			++sol;
		}
		--cnt;
		const pair<string, int> t = q.front();
		q.pop();
		if (done(t.first))
			return sol;
		for (int level=0; level<M; ++level)
			for (int ccw=0; ccw<=1; ++ccw) {
				pair<string, int> x = rotate(t.first, t.second, level, ccw);
				x = normalize(x.first, x.second);
				const pair<int, int> tt = make_pair(encode(x.first), x.second);
				if (!used.count(tt)) {
					used.insert(tt);
					q.push(x);
				}
			}
		pair<string, int> x = up(t.first, t.second);
		if (x.second != -1) {
			const pair<int, int> tt = make_pair(encode(x.first), x.second);
			if (!used.count(tt)) {
				used.insert(tt);
				q.push(x);
			}
		}
		x = down(t.first, t.second);
		if (x.second != -1) {
			const pair<int, int> tt = make_pair(encode(x.first), x.second);
			if (!used.count(tt)) {
				used.insert(tt);
				q.push(x);
			}
		}
	}
	return 100000;
}
class PenPuzzle {
	public:
	int solve(vector <string> puzzle) {
		M = puzzle.size();
		N = puzzle[0].size();
		IV[0] = 'A'; IV[1] = 'B'; IV[2] = 'C'; IV[3] = 'D';
		for (int i=0; i<4; ++i)
			CV[IV[i]] = i;

		string s;
		for (int i=0; i<M; ++i)
			s += puzzle[i];

		int sol = 100000;
		/*cerr << s << '\n';*/
		for (int i=0; i<M*N; ++i) {
			/*cerr << i << '\n';
			const pair<string, int> t = normalize(s, i);
			cerr << t.first << ' ' << t.second << '\n';*/
			sol = min(sol, bfs(normalize(s, i)));
		}

		return (sol==10000 ? -1:sol);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC", "ABC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABC", "BCA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABA", "BCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"CBBC", "DCAB", "ADAD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PenPuzzle ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
