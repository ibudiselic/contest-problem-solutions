#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int a[5][76];
int match[5][5];
const int MISS = 2000;
class Bingo {
	public:
	string winner(vector <string> card, vector <string> calls) {
		card.erase(card.begin());
		for (int i=0; i<5; ++i)
			for (int j=0; j<76; ++j)
				a[i][j] = -1;
		for (int i=0; i<5; ++i)
			for (int j=0; j<5; ++j)
				match[i][j] = MISS;
		match[2][2] = 1000;
		{
			const int nesto = card[2].find("F");
			card[2][nesto] = '0';
		}
		map<char, int> ind;
		ind['B'] = 0; ind['I'] = 1; ind['N'] = 2; ind['G'] = 3; ind['O'] = 4;
		for (int i=0; i<5; ++i) {
			istringstream is(card[i]);
			for (int j=0; j<5; ++j) {
				int x;
				is >> x;
				a[j][x] = i;
			}
		}
		for (int i=0; i<(int)calls.size()-1; ++i) {
			istringstream is(calls[i]);
			char c;
			int x;
			is >> c >> x;
			const int t = ind[c];
			if (a[t][x] != -1)
				match[a[t][x]][t] = i;
		}
		int bestlast = MISS;
		int bestfirst = MISS;
		vector<int> seq;
		for (int i=0; i<5; ++i) {
			bool ok = true;
			int last = -1;
			int first = MISS;
			vector<int> cur;
			for (int j=0; j<5; ++j) {
				if (match[i][j] == MISS) {
					ok = false;
					break;
				}
				cur.push_back(match[i][j]);
				if (match[i][j] != 1000)
					last = max(last, match[i][j]);
				first = min(first, match[i][j]);
			}
			if (ok)
				if (last<bestlast || last==bestlast && first<bestfirst) {
					seq = cur;
					bestlast = last;
					bestfirst = first;
				}
		}
		for (int i=0; i<5; ++i) {
			bool ok = true;
			int last = -1;
			int first = MISS;
			vector<int> cur;
			for (int j=0; j<5; ++j) {
				if (match[j][i] == MISS) {
					ok = false;
					break;
				}
				cur.push_back(match[j][i]);
				if (match[j][i] != 1000)
					last = max(last, match[j][i]);
				first = min(first, match[j][i]);
			}
			if (ok)
				if (last<bestlast || last==bestlast && first<bestfirst){
					seq = cur;
					bestlast = last;
					bestfirst = first;
				}
		}
		bool ok = true;
		int last = -1;
		int first = MISS;
		vector<int> cur;
		for (int i=0; i<5; ++i) {
			if (match[i][i] == MISS) {
				ok = false;
				break;
			}
			cur.push_back(match[i][i]);
			if (match[i][i] != 1000)
				last = max(last, match[i][i]);
			first = min(first, match[i][i]);
		}
		if (ok)
			if (last<bestlast || last==bestlast && first<bestfirst) {
				seq = cur;
				bestlast = last;
				bestfirst = first;
			}

		ok = true;
		last = -1;
		first = MISS;
		cur.clear();
		for (int i=0; i<5; ++i) {
			if (match[i][4-i] == MISS) {
				ok = false;
				break;
			}
			cur.push_back(match[i][4-i]);
			if (match[i][4-i] != 1000)
				last = max(last, match[i][4-i]);
			first = min(first, match[i][4-i]);
		}
		if (ok)
			if (last<bestlast || last==bestlast && first<bestfirst){
				seq = cur;
				bestlast = last;
				bestfirst = first;
			}

		if (bestfirst == MISS)
			return "YOU LOSE";
		else {
			sort(seq.begin(), seq.end());
			string sol;
			for (int i=0; i<5; ++i) {
				if (seq[i]==1000) continue;
				if (i > 0) sol += ',';
				sol += calls[seq[i]];
			}
			return sol;
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B12","B3","I16","N40","B2","O70","B1","B9","O71","B4","B7","B11","O68","BINGO"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "B12,B3,B1,B9,B4"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"B12","B3","I16","N40","B2","O70","B1","B9","BINGO"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YOU LOSE"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "  B  I  N  G  O",
  " 12 22 33 55 66",
  "  9 23 34 52 72",
  "  1 24  F 59 71",
  "  4 16 40 48 61",
  "  3 18 41 49 63"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"O63","G48","I23","B9","B1","B4","B3","B7","B12","G49","BINGO"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "O63,G48,I23,B12"; verify_case(2, Arg2, winner(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Bingo ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
