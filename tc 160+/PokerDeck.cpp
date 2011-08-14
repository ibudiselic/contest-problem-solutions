#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <map>
#include <utility>

using namespace std;

#define DBG(X) cerr << (#X) << ' ' << (X)
#define DBG_NL(X) cerr << (#X) << ' ' << (X) << '\n'
#define DBG_A(A, I) cerr << (#A) << '[' << (I) << "] " << (A[(I)])
#define DBG_A_NL(A, I) cerr << (#A) << '[' << (I) << "] " << (A[(I)]) << '\n'

int face[13];
int suit[4];
int have[4][13];
int nCards;
string suits = "CHSD";
string faceCards = "JQKA";

void update(const string &t) {
	int s = suits.find(t[t.size()-1]);
	int f = (t.size()==3 ? 8 : isdigit(t[0]) ? t[0]-'0'-2 : 9+(int)faceCards.find(t[0]));
	++suit[s];
	++face[f];
	++have[s][f];
	++nCards;
}
struct Hand {
	long long cnt;
	string name;
	Hand(long long cnt_, const string &name_): cnt(cnt_), name(name_) {}
};
bool operator<(const Hand &a, const Hand &b) {
	if (a.cnt != b.cnt)
		return a.cnt < b.cnt;
	return a.name < b.name;
}
map< pair<int, int>, long long > C;
long long choose(int n, int k) {
	if (n < k)
		return 0;
	long long &ret = C[make_pair(n, k)];
	if (ret != 0)
		return ret;

	ret = 1;
	for (int i=0; i<k; ++i)
		ret *= (n-i);
	for (int i=k; i>1; --i)
		ret /= i;

	return ret;
}
class PokerDeck {
	public:
	vector <string> getRanking(vector <string> decks) {
		memset(face, 0, sizeof face);
		memset(suit, 0, sizeof suit);
		memset(have, 0, sizeof have);
		nCards = 0;

		for (int i=0; i<(int)decks.size(); ++i) {
			istringstream is(decks[i]);
			string w;
			while (is >> w)
				update(w);
		}

		/*for (int i=0; i<13; ++i)
			DBG_A_NL(face, i);
		for (int i=0; i<4; ++i)
			DBG_A_NL(suit, i);*/

		long long ok5 = 0;
		for (int f=0; f<13; ++f)
			ok5 += choose(face[f], 5);
		DBG_NL(ok5);

		long long royalFlush = 0;
		for (int s=0; s<4; ++s) {
			long long add = 1;
			for (int f=8; f<13; ++f)
				add *= have[s][f];
			royalFlush += add;
		}
		DBG_NL(royalFlush);

		long long straightFlush = 0;
		for (int s=0; s<4; ++s) {
			long long add = (have[s][0]*have[s][1]*have[s][2]*have[s][3]*have[s][12]);
			for (int start=0; start<8; ++start) {
				long long ways = 1;
				for (int i=0; i<5; ++i)
					ways *= have[s][start+i];
				add += ways;
			}
			straightFlush += add;
		}
		DBG_NL(straightFlush);

		long long straight = -straightFlush-royalFlush;
		straight += (face[12]*face[0]*face[1]*face[2]*face[3]);
		for (int i=0; i<9; ++i) {
			long long add = 1;
			for (int j=0; j<5; ++j)
				add *= face[i+j];
			straight += add;
		}
		DBG_NL(straight);

		long long flush = -straightFlush-royalFlush;
		for (int s=0; s<4; ++s)
			for (int f=0; f<13; ++f)
				flush -= choose(have[s][f], 5);
		for (int s=0; s<4; ++s)
			flush += choose(suit[s], 5);
		DBG_NL(flush);

		long long fullHouse = 0;
		for (int s=0; s<4; ++s)
			for (int i=0; i<13; ++i)
				for (int j=i+1; j<13; ++j)
					fullHouse -= choose(have[s][i], 2)*choose(have[s][j], 3) + choose(have[s][i], 3)*choose(have[s][j], 2);
		for (int i=0; i<13; ++i)
			for (int j=i+1; j<13; ++j)
				fullHouse += choose(face[i], 2)*choose(face[j], 3) + choose(face[i], 3)*choose(face[j], 2);
		DBG_NL(fullHouse);

		long long ok4 = 0;
		for (int s=0; s<4; ++s)
			for (int f=0; f<13; ++f)
				ok4 -= choose(have[s][f], 4)*(suit[s]-have[s][f]);
		for (int f=0; f<13; ++f)
			ok4 += choose(face[f], 4)*(nCards-face[f]);
		DBG_NL(ok4);

		long long ok3 = 0;
		for (int s=0; s<4; ++s)
			for (int f=0; f<13; ++f) {
				long long t = 0;
				for (int i=0; i<13; ++i)
					if (i != f)
						for (int j=i+1; j<13; ++j)
							if (j != f)
								t += have[s][i]*have[s][j];
				ok3 -= choose(have[s][f], 3)*t;
			}
		for (int f=0; f<13; ++f) {
			long long t = 0;
			for (int i=0; i<13; ++i)
				if (i != f)
					for (int j=i+1; j<13; ++j)
						if (j != f)
							t += face[i]*face[j];
			ok3 += choose(face[f], 3)*t;
		}
		DBG_NL(ok3);

		long long pair2 = 0;
		for (int s=0; s<4; ++s)
			for (int i=0; i<13; ++i)
				for (int j=i+1; j<13; ++j)
					pair2 -= choose(have[s][i], 2)*choose(have[s][j], 2)*(suit[s]-have[s][i]-have[s][j]);
		for (int i=0; i<13; ++i)
			for (int j=i+1; j<13; ++j)
				for (int k=0; k<13; ++k)
					if (k!=i && k!=j)
						pair2 += choose(face[i], 2)*choose(face[j], 2)*face[k];
		DBG_NL(pair2);

		long long pair = 0;
		for (int s=0; s<4; ++s)
			for (int f=0; f<13; ++f) {
				long long t = 0;
				for (int i=0; i<13; ++i)
					if (i != f)
						for (int j=i+1; j<13; ++j)
							if (j != f)
								for (int k=j+1; k<13; ++k)
									if (k != f)
										t += have[s][i]*have[s][j]*have[s][k];
			pair -= choose(have[s][f], 2)*t;
		}
		for (int f=0; f<13; ++f) {
			long long t = 0;
			for (int i=0; i<13; ++i)
				if (i != f)
					for (int j=i+1; j<13; ++j)
						if (j != f)
							for (int k=j+1; k<13; ++k)
								if (k != f)
									t += face[i]*face[j]*face[k];
			pair += choose(face[f], 2)*t;
		}
		DBG_NL(pair);

		vector<Hand> v;
		v.push_back(Hand(ok5, "FIVE OF A KIND"));
		v.push_back(Hand(ok4, "FOUR OF A KIND"));
		v.push_back(Hand(ok3, "THREE OF A KIND"));
		v.push_back(Hand(pair, "ONE PAIR"));
		v.push_back(Hand(pair2, "TWO PAIR"));
		v.push_back(Hand(fullHouse, "FULL HOUSE"));
		v.push_back(Hand(straight, "STRAIGHT"));
		v.push_back(Hand(flush, "FLUSH"));
		v.push_back(Hand(royalFlush, "ROYAL FLUSH"));
		v.push_back(Hand(straightFlush, "STRAIGHT FLUSH"));
		v.push_back(Hand(choose(nCards, 5)-ok5-ok4-ok3-pair-pair2-fullHouse-straight-flush-royalFlush-straightFlush, "NOTHING"));

		sort(v.begin(), v.end());

		vector<string> sol;
		for (int i=0; i<(int)v.size(); ++i)
			if (v[i].cnt > 0)
				sol.push_back(v[i].name);

		for (int i=0; i<(int)v.size(); ++i)
			cerr << v[i].name << ' ' << double(v[i].cnt)/choose(nCards, 5)*100 << '\n';

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"AC 2C 3C 4C 5C 6C 7C 8C 9C 10C JC QC KC",
 "AD 2D 3D 4D 5D 6D 7D 8D 9D 10D JD QD KD",
 "AH 2H 3H 4H 5H 6H 7H 8H 9H 10H JH QH KH",
 "AS 2S 3S 4S 5S 6S 7S 8S 9S 10S JS QS KS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ROYAL FLUSH", "STRAIGHT FLUSH", "FOUR OF A KIND", "FULL HOUSE", "FLUSH", "STRAIGHT", "THREE OF A KIND", "TWO PAIR", "ONE PAIR", "NOTHING" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getRanking(Arg0)); }
	void test_case_1() { string Arr0[] = {"AS 2C 3C 4C 5C 7D 7H 8C 8D 8H 10S JS QS KS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"FLUSH", "FULL HOUSE", "ROYAL FLUSH", "STRAIGHT", "TWO PAIR", "THREE OF A KIND", "ONE PAIR", "NOTHING" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getRanking(Arg0)); }
	void test_case_2() { string Arr0[] = {"AS AS AS AS AS AS AS AS AS AS AS",
 "AS AS AS AS AS AS AS AS AS AS AS",
 "AS AS AS AS AS AS AS AS AS AS AS",
 "2C 4C 6C 8C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NOTHING", "ONE PAIR", "THREE OF A KIND", "FOUR OF A KIND", "FIVE OF A KIND" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getRanking(Arg0)); }
	void test_case_3() { string Arr0[] = {"QC QH QD 6S 6H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"FULL HOUSE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getRanking(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PokerDeck ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
