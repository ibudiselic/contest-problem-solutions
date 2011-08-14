#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct S {
	int ind;
	string s;
	S(int ind_, const string &s_): ind(ind_), s(s_) {}
};
bool is_vow(char c) {
	return string("aeiou").find(c) != string::npos;
}
vector< vector<string> > sorted, unsorted;
bool operator<(const S &a, const S &b) {
    const vector<string> &aa = sorted[a.ind];
	const vector<string> &bb = sorted[b.ind];
	if (aa != bb) {
		return aa < bb;
	}
	const vector<string> &aaa = unsorted[a.ind];
	const vector<string> &bbb = unsorted[b.ind];
	return aaa < bbb;
}
vector<string> decomp(const string &s) {
	int p = 0;
	vector<string> ret;
	while (p < (int)s.size()) {
		string t;
		while (!is_vow(s[p])) {
			t += s[p];
			++p;
		}
		while (p<(int)s.size() && is_vow(s[p])) {
			t += s[p];
			++p;
		}
		ret.push_back(t);
	}
	return ret;
}


class SyllableSorting {
	public:
	vector <string> sortWords(vector <string> words) {
		sorted.clear();
		unsorted.clear();
		vector<S> v;
		for (int i=0; i<(int)words.size(); ++i) {
			v.push_back(S(i, words[i]));
			unsorted.push_back(decomp(words[i]));
			sorted.push_back(unsorted.back());
			sort(sorted.back().begin(), sorted.back().end());
		}

		sort(v.begin(), v.end());

		vector<string> sol;
		for (int i=0; i<(int)v.size(); ++i) {
			sol.push_back(v[i].s);
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"xiaoxiao", "yamagawa", "gawayama"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"gawayama", "yamagawa", "xiaoxiao" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortWords(Arg0)); }
	void test_case_1() { string Arr0[] = {"bcedba", "dbabce", "zyuxxo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bcedba", "dbabce", "zyuxxo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortWords(Arg0)); }
	void test_case_2() { string Arr0[] = {"hgnibqqaxeiuteuuvksi", "jxbuzui", "zrotyqeruiydozui",
 "ywuuzkto", "lmopbookoagyco", "vredfvavvexliu"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"hgnibqqaxeiuteuuvksi", "vredfvavvexliu", "lmopbookoagyco", "jxbuzui", "zrotyqeruiydozui", "ywuuzkto" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortWords(Arg0)); }
	void test_case_3() { string Arr0[] = {"crazgo", "cwsoygiokiuo", "yueoseeu", "tuadiojvugeoe",
 "naumxditui", "sgukkelyoi", "nrohjuasoia", "mgabmo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"mgabmo", "crazgo", "cwsoygiokiuo", "tuadiojvugeoe", "nrohjuasoia", "sgukkelyoi", "naumxditui", "yueoseeu" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortWords(Arg0)); }
	void test_case_4() { string Arr0[] = {"wheewjuguoi", "coutcu", "hqivaa", "sgiibgwi", "ypaqpki",
 "bgyikouapae", "wqakeu", "skolfo", "pzesaa", "ypivhi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"sgiibgwi", "bgyikouapae", "coutcu", "wheewjuguoi", "hqivaa", "wqakeu", "skolfo", "pzesaa", "ypaqpki", "ypivhi" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sortWords(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SyllableSorting ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
