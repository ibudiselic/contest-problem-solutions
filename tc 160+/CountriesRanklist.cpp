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

int ranking(vector<int> score, int ind) {
	int x = score[ind];
	sort(score.begin(), score.end());
	reverse(score.begin(), score.end());

	for (int i=0; i<(int)score.size(); ++i)
		if (score[i] == x)
			return i+1;
	return -1;
}
int best(const vector<int> &cnt, vector<int> score, int ind, int M) {
	for (int i=0; i<(int)score.size(); ++i)
		score[i] += (4-cnt[i]) * (i==ind ? M : 0);

	return ranking(score, ind);
}
int worst(const vector<int> &cnt, vector<int> score, int ind, int M) {
	for (int i=0; i<(int)score.size(); ++i)
		score[i] += (4-cnt[i]) * (i!=ind ? M : 0);

	return ranking(score, ind);
}
string toStr(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
class CountriesRanklist {
	public:
	vector <string> findPlaces(vector <string> knownPoints) {
		map<string, int> ind;
		vector<int> cnt, score;
		int m = 1234567890;
		for (int i=0; i<(int)knownPoints.size(); ++i) {
			istringstream is(knownPoints[i]);
			string c, n;
			int x;
			is >> c >> n >> x;

			m = min(m, x);
			if (ind.count(c) == 0) {
				ind[c] = cnt.size();
				cnt.push_back(0);
				score.push_back(0);
			}

			++cnt[ind[c]];
			score[ind[c]] += x;
		}

		m = max(m-1, 0);
		vector<string> sol;
		for (map<string, int>::const_iterator it=ind.begin(); it!=ind.end(); ++it)
			sol.push_back(it->first + ' ' + toStr(best(cnt, score, it->second, m)) + ' ' + toStr(worst(cnt, score, it->second, m)));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Poland Krzysztof 101", "Ukraine Evgeni 30", "Ukraine Ivan 24"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Poland 1 1", "Ukraine 2 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findPlaces(Arg0)); }
	void test_case_1() { string Arr0[] = {"Poland Krzysztof 100", "CzechRep Martin 30", "CzechRep Jirka 25"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CzechRep 1 2", "Poland 1 2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findPlaces(Arg0)); }
	void test_case_2() { string Arr0[] = {"Slovakia Marian 270", "Hungary Istvan 24", "Poland Krzysztof 100",
 "Hungary Gyula 30", "Germany Tobias 27", "Germany Juergen 27"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Germany 2 4", "Hungary 2 4", "Poland 2 2", "Slovakia 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findPlaces(Arg0)); }
	void test_case_3() { string Arr0[] = {"usa Jack 14", "USA Jim 10", "USA Jim 10", "USA Jim 10",
 "USA Jim 10", "usa Jack 14", "usa Jack 14", "Zimbabwe Jack 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"USA 2 2", "Zimbabwe 3 3", "usa 1 1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findPlaces(Arg0)); }
	void test_case_4() { string Arr0[] = {"A a 9", "A b 9", "A c 9", "A d 9",
 "B e 9", "B f 9", "B g 8", "B h 8",
 "C i 9", "C j 9", "C k 9", "C l 7",
 "D m 1", "D n 1", "D o 1", "D p 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A 1 1", "B 2 2", "C 2 2", "D 4 4" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, findPlaces(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CountriesRanklist ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
