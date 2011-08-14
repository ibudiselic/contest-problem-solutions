#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Cand {
	int votes, pos;
	Cand(int votes_=-1, int pos_=-1): votes(votes_), pos(pos_) {}
};
bool operator<(const Cand &a, const Cand &b) {
	if (a.votes != b.votes)
		return a.votes > b.votes;
	else
		return a.pos < b.pos;
}
class Election {
	public:
	int votesNeeded(vector <int> votes, vector <int> wishList) {
		vector<Cand> v;
		for (int i=0; i<(int)votes.size(); ++i)
			v.push_back(Cand(votes[i], i));
		sort(v.begin(), v.end());

		vector<bool> used(v.size(), 0);
		vector<Cand> target(v.size());
		for (int i=0; i<(int)wishList.size(); ++i)
			if (wishList[i] != -1) {
				used[i] = 1;
				target[wishList[i]] = Cand(votes[i], i);
			}
		int firstUnused = 0;
		int firstEmpty = 0;
		while (true) {
			while (firstUnused<(int)v.size() && used[v[firstUnused].pos])
				++firstUnused;
			if (firstUnused == (int)v.size())
				break;
			used[v[firstUnused].pos] = 1;
			// there must be an empty spot
			while (target[firstEmpty].votes != -1)
				++firstEmpty;
			target[firstEmpty] = v[firstUnused];
		}

		/*for (int i=0; i<(int)v.size(); ++i)
			cerr << v[i].votes << '(' << v[i].pos << ") ";
		cerr << '\n';
		for (int i=0; i<(int)wishList.size(); ++i)
			cerr << wishList[i] << '(' << i << ") ";
		cerr << '\n';
		for (int i=0; i<(int)target.size(); ++i)
			cerr << target[i].votes << '(' << target[i].pos << ") ";
		cerr << '\n';*/

		int sol = 0;
		for (int i=(int)target.size()-1; i>0; --i)
			if (target[i] < target[i-1]) {
				int add = (target[i].votes - target[i-1].votes) + (target[i].pos < target[i-1].pos);
				sol += add;
				target[i-1].votes += add;
			}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,8,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,0,-1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, votesNeeded(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10,20,30,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 31; verify_case(1, Arg2, votesNeeded(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 100, 40, 15, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 0, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, votesNeeded(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5052863,4419975,3556783,9490441,6166389,836297,
 4623556,4905465,117307,8071245,932463,9194925}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,2,0,-1,-1,8,9,4,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 53562445; verify_case(3, Arg2, votesNeeded(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Election ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
