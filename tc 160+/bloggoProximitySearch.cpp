#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <set>

using namespace std;

struct Query {
	string w;
	int n;
	Query *left, *right;
	void ispisi() {
		if (w.size() > 0) {
			cerr << w;
		} else if (left!=NULL && right!=NULL) {
			left->ispisi();
			cerr << " +" << n << " ";
			right->ispisi();
		}
	}
	Query(): left(NULL), right(NULL) {}
	~Query() {
		delete left;
		delete right;
	}
};

string toLow(string s) {
	for (int i=0; i<(int)s.size(); ++i)
		s[i] = tolower(s[i]);

	return s;
}
void make(Query *q, const string &s) {
	if (s[0] != '(') {
		q->w = s;
		q->n = 0;
	} else {
		int bc = 0;
		for (int i=1; i<(int)s.size(); ++i) {
			bc += (s[i]=='(');
			bc -= (s[i]==')');
			if (s[i]=='+' && bc==0) {
				int t = 0;
				int j = i+1;
				while (isdigit(s[j]))
					t = t*10 + s[j++]-'0';
				q->n = t;
				q->left = new Query();
				make(q->left, s.substr(1, i-2));
				q->right = new Query();
				make(q->right, s.substr(j+1, s.size()-1-(j+1)));
				goto DONE;
			}
		}
		DONE:;
	}
}
struct match {
	int a, b;
	int docInd;
	int aStart, bEnd;
	match(int a_, int b_, int docInd_, int aStart_, int bEnd_): a(a_), b(b_), docInd(docInd_), aStart(aStart_), bEnd(bEnd_) {}
};
bool operator<(const match &a, const match &b) {
	if (a.b-a.a != b.b-b.a)
		return a.b-a.a < b.b-b.a;
	else if (a.docInd != b.docInd)
		return a.docInd < b.docInd;
	else
		return a.a < b.a;
}

// So if b<c or d<a, we must have (c-b)<=n+1 or (a-d)<=n+1
vector<int> wStart, wEnd;
vector<string> w;
set<match> pass_;

bool test(const match &x, const match &y, int n) {
	if (x.a<=y.a && y.a<=x.b || y.a<=x.a && x.a<=y.b)
		return true;

	if (x.b < y.a)
		return (y.a-x.b) <= n+1;
	else
		return (x.a-y.b) <= n+1;
}
match merge(match x, const match &y) {
	if (y.a < x.a) {
		x.a = y.a;
		x.aStart = y.aStart;
	}
	if (y.b > x.b) {
		x.b = y.b;
		x.bEnd = y.bEnd;
	}

	return x;
}
set<match> makeMatches(const Query &q, int docInd, bool top=0) {
	set<match> ret;
	if (q.w.size() > 0) {
		for (int i=0; i<(int)w.size(); ++i)
			if (w[i] == q.w)
				ret.insert(match(i, i, docInd, wStart[i], wEnd[i]));
	} else {
		assert(q.left!=NULL && q.right!=NULL);

		const set<match> L = makeMatches(*(q.left), docInd);
		const set<match> R = makeMatches(*(q.right), docInd);

		for (set<match>::const_iterator it1=L.begin(); it1!=L.end(); ++it1)
			for (set<match>::const_iterator it2=R.begin(); it2!=R.end(); ++it2)
				if (test(*it1, *it2, q.n))
					ret.insert(merge(*it1, *it2));
	}
	if (ret.size() > 10) {
		int i = 0;
		for (set<match>::const_iterator it=ret.begin(); i<=10; ++i, ++it)
			if (i == 10) {
				ret.erase(it, ret.end());
				break;
			}
	}
	if (top)
		pass_.insert(ret.begin(), ret.end());

	return ret;
}
void go(const string &doc, const Query &q, int docInd) {
	w.clear();
	wStart.clear();
	wEnd.clear();

	bool inWord = false;
	int start = 0;
	for (int i=0; i<(int)doc.size(); ++i)
		if (inWord) {
			if (!isalpha(doc[i])) {
				w.push_back(toLow(doc.substr(start, i-start)));
				wStart.push_back(start);
				wEnd.push_back(i);
				inWord = 0;
			}
		} else {
			if (isalpha(doc[i])) {
				inWord = 1;
				start = i;
			}
		}
	if (inWord) {
		w.push_back(toLow(doc.substr(start)));
		wStart.push_back(start);
		wEnd.push_back(doc.size());
	}

	makeMatches(q, docInd, 1);
}

class bloggoProximitySearch {
	public:
	vector <string> findPassages(vector <string> documents, string query) {
		query = toLow(query);

		Query q;
		make(&q, query);

		pass_.clear();
		for (int i=0; i<(int)documents.size(); ++i)
			go(documents[i], q, i);

		vector<match> pass(pass_.begin(), pass_.end());

		vector<string> sol;
		for (int i=0; i<min(10, (int)pass.size()); ++i) {
			ostringstream os;
			os << pass[i].docInd << ' ' << pass[i].aStart << " [" << documents[pass[i].docInd].substr(pass[i].aStart, pass[i].bEnd-pass[i].aStart) << ']';

			sol.push_back(os.str());
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,",
  "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining",
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,",
 "for the people, shall not perish from the earth."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(can +000 we)"; string Arr2[] = { "0 22 [we can]",  "1 0 [we can]",  "1 25 [we can]" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findPassages(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,",
  "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining",
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,",
 "for the people, shall not perish from the earth."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "this"; string Arr2[] = { "1 43 [this]",  "15 34 [this]",  "17 0 [this]" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findPassages(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,",
  "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining",
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,",
 "for the people, shall not perish from the earth."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "((the +099 people) +999 by)"; string Arr2[] = { "17 19 [the people, by]",  "17 23 [people, by the]",  "17 31 [by the people]",  "17 19 [the people, by the people]" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findPassages(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"But in a larger sense we can not dedicate --",
 "we can not consecrate -- we can not hallow this",
 "ground. The brave men, living and dead, who",
 "struggled, here, have consecrated it far above",
 "our poor power to add or detract. The world will",
 "little note, nor long remember, what we say here,",
  "but can never forget what they did here. It is",
 "for us, the living, rather to be dedicated here",
 "to the unfinished work which they have, thus",
 "far, so nobly carried on. It is rather for us",
 "to be here dedicated to the great task remaining",
 "before us -- that from these honored dead we take",
 "increased devotion to that cause for which they",
 "here gave the last full measure of devotion --",
 "that we here highly resolve that these dead",
 "shall not have died in vain; that this nation",
 "shall have a new birth of freedom; and that",
 "this government of the people, by the people,",
 "for the people, shall not perish from the earth."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "((TO +20 (tO +20 tO)) +20 ((TO +20 tO) +20 To))"; string Arr2[] = { "4 15 [to]",  "7 27 [to]",  "8 0 [to]",  "10 0 [to]",  "10 21 [to]",  "12 19 [to]",  "10 0 [to be here dedicated to]" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findPassages(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"c B b B A C b b A C A a c a B A b C c b b b b A a ",
 "b A A C c c B c A c c C b c B C B A a B b a b c A ",
 "a C C B A b A a A c A B b b a A A C a B C A A b C ",
 "C A a a c a A B C a c B c B b A c B A A c b b B b ",
 "a A a A b C A b c a B B a c B A a c a b c b C b C ",
 "c C A a C C A c A c b a b A b A c C A C b C C B c ",
 "a B C B c A b C c c a a c a c A A c a A B c c A c ",
 "A C A C c a b C C C c A a b a b b C C a A C b a c ",
 "C A B c a A B b b c b C b B C c A b A B A c b B a ",
 "c b a B a C B C c A c b B c C A A C c C a B C a a ",
 "A C C A a C C B a c C a C a c A A A C c A a B a A ",
 "a b c B C C A b b a c c b B A B b A b b b b a a b ",
 "C B c C B b c c a C B C b B B a C B B a A B B c c ",
 "a B B B B A c c C a b b A c B A A b B B B c C c B ",
 "c A B C b B b c a a C b b c b c b a B A c c A a A ",
 "a B A B c c b C A A b b A a A B b C A A B b c b C ",
 "b b b A A c a c a c a B A B b a a A c B b B B A b ",
 "c a b B a b A c C B b B b c A A C c b C B a c c c ",
 "C A A C b C C A a c B c b B C A c B a c c B c b c ",
 "b A A B b B b b b A C b a b A C b B C A c c A B A ",
 "b a c b B a B B B a a a A C a a A A A A A B a c a ",
 "c a A C c A c b a a C B b c c B C B c b a c C B B ",
 "a b A c B b b B B C c b c B A a a b C b a C b c b ",
 "c b b b a a A b b b b c B b b c c a a c a C A a b ",
 "C B b b A A A b B c b C a c C a B A A C C c C b C ",
 "B C a a B A a B c B a C c B A B b c B a b B B b C ",
 "a A a C C b A C a C b b A a B C C C C A c C c C b ",
 "a c a a A a c C b B b c A c B b A A A B a C c c c ",
 "A c B b c C c a b b C B b c B b b A C c B b a b b ",
 "c a c A A B C C b C b C c C c C c b b a A C c C a ",
 "A b a A b B B C c C c c a b C a C a b c c A A B c ",
 "c C a b A a b A C C a C A a B C c a C b c b B C C ",
 "B C C B b B C A c a C B c a B b c B A A a a a b C ",
 "b a a A A B b b a b A b b a b c A B B c C a a A C ",
 "a c a C A b a A C c a C c b b A A B a C B a A C B ",
 "B A B B a a c c a c b A c c c B C A A B a b B B B ",
 "C c B c A c b C b a c b a c C A c A a c b a b c c ",
 "B C b c c A C A b A B c c c B A C b b C c C a a b ",
 "C a b b C a C B a B C b c C C c b b c A b B B b a ",
 "a B A b a A C C B C B A B a b a a c a c b b b B a ",
 "c b c B A C C c A B a b B a A A C b A C b C a a c ",
 "b b a b a A c c A c A A A a A b c a C C b a A C a ",
 "a B b A b C c c a A b A c A B A b B a B a b A c A ",
 "c B b b C b c c c a B C c c c a b a c B B a C c A ",
 "C A a b c C c b a B A c A C C c B A C b A C c b c ",
 "a c A a b C b C A C A A a c B c a B A B B b A c a ",
 "B c C B a B C C B a a B A b b c b b A c A B b A a ",
 "c c c a C A B a c b c a B c b a C B a B A a b c A ",
 "B c b a C B c A A b a a c c c A c B C B B C b b a ",
 "C a C c a c c c b a C C B C a B a C A b a C a c B "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "(a +3 (b +2 (a +6 (((b +1 c) +3 a) +0 c))))"; string Arr2[] = { "0 6 [B A C]",  "0 8 [A C b]",  "0 14 [b A C]",  "0 24 [c a B]",  "0 30 [A b C]",  "1 12 [B c A]",  "1 30 [C B A]",  "1 42 [a b c]",  "1 44 [b c A]",  "2 4 [C B A]" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findPassages(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    bloggoProximitySearch ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
