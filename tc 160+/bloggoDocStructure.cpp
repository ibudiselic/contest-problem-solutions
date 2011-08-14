#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Doc {
	string tag;
	vector<Doc> v;
	void ispisi(int level=0) {
		const string indent(level, ' ');
		cerr << indent << tag << '\n';
		for (int i=0; i<(int)v.size(); ++i)
			v[i].ispisi(level+2);
	}
	Doc(const string &tag_): tag(tag_) {}
};
Doc create(const string &s) {
	string::size_type i = s.find('<');
	assert(i != string::npos);

	string::size_type j = i+1;
	while (s[j] != '>')
		++j;

	const string &tag = s.substr(i+1, j-i-1);

	string::size_type k = s.size()-1;
	while (s[k] != '<')
		--k;

	/*cerr << tag << '\n';
	cerr << s << '\n';*/
	assert(s.size()-k-2>=tag.size() && tag==s.substr(k+2, tag.size()));

	Doc ret(tag);

	const string::size_type lim = k;
	for (++i; i<lim; ++i) {
		if (s[i] == '<') {
			j = i+1;
			while (s[j] != '>')
				++j;
			const string &t = s.substr(i+1, j-i-1);

			int tagCnt = 1;
			k = j+1;
			while (tagCnt > 0) {
				if (s[k] == '<') {
					string::size_type l = k+1;
					while (s[l] != '>')
						++l;
					const string &tt = s.substr(k+1, l-k-1);
					if (tt == t)
						++tagCnt;
					else if (tt[0]=='/' && tt.substr(1)==t)
						--tagCnt;
					k = l+1;
				} else {
					++k;
				}
			}
			ret.v.push_back(create(s.substr(i, k-i)));
			i = k-1;
		}
	}

	return ret;
}

Doc create(const vector<string> &d) {
	string s;
	for (int i=0; i<(int)d.size(); ++i)
		s += d[i];

	return create(s);
}
int getSize(const Doc &a) {
	int ret = 1;
	for (int i=0; i<(int)a.v.size(); ++i)
		ret += getSize(a.v[i]);

	return ret;
}
int intree(const Doc &a, const Doc &b) {
	assert(a.tag == b.tag);

	int ret = 0;
	int i = 0;
	int j = 0;

	while (i<(int)a.v.size() && j<(int)b.v.size()) {
		if (a.v[i].tag == b.v[j].tag) {
			const int add = intree(a.v[i], b.v[j]);
			if (add == -1) {
				ret += getSize(b.v[j]);
			} else {
				ret += add;
				++i;
			}
		} else {
			ret += getSize(b.v[j]);
		}
		++j;
	}

	if (i < (int)a.v.size())
		return -1;

	while (j < (int)b.v.size())
		ret += getSize(b.v[j++]);

	return ret;
}
class bloggoDocStructure {
	public:
	string compare(vector <string> docA, vector <string> docB) {
		Doc A = create(docA);
		Doc B = create(docB);

		int diff = intree(A, B);
		if (diff == 0)
			return "equivalent";
		if (diff > 0) {
			ostringstream os;
			os << "intree " << diff;
			return os.str();
		}

		diff = intree(B, A);
		if (diff == -1)
			return "incompatible";

		ostringstream os;
		os << "outtree " << diff;
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"<html> <h1>Snapping Turtles</h1> <ul> <li> <h2>",
 "Common Snapping Turtle (<i>Chelydra serpentina</i>",
 ") </h2> <p> With its dark coloring, sinuous neck,",
 "and swift lunging motion, Chelydra serpentina is a",
 "n adept hunter. </p><p> The snapping turtle rarely",
 "basks. </p><p> Snapping turtle populations are jeo",
 "pardized by automobile traffic.   </",
 "p>    </li> <li> <h2> Alligator Snapping Turtle (",
 "<i>Macroclemys temminckii</i>) </h2> <p> Like the",
 " common snapping turtle, the alligator snapping ",
 "turtle has a massive head.</p><p>This is the lar",
 "gest freshwater turtle. A tubular pink append",
 "age grows from its mouth.</p>   <",
 "/li> </ul> </html>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {" <html> turtles <h1> snapping </h1> <ul> <li> <h2",
 "> common <i> chelydra serpentina </i> </h2> <p>",
 "hunter </p> (adept?) <p> rarely basks </p> (hmm)",
 "<p> jeopardized by traffic </p></li>",
 "<li> often confused with... <h2> alligator snapp",
 "ing turtle <i>macroclemys temminckii</i> </h2>",
 "<p> massive head </p> big! <p>",
 "largest freshwater turtle. pink wormlike thing <",
 "/p></li></ul></html>  "}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "equivalent"; verify_case(0, Arg2, compare(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {" <html> turtles <h1> snapping </h1> <ul> <li> <h2",
 "> common <i> chelydra serpentina </i> </h2> <p>",
 "hunter </p> (adept?) <p> rarely basks </p> (hmm)",
 "<p> jeopardized by traffic </p></li>",
 "<li> often confused with... <h2> alligator snapp",
 "ing turtle <i>macroclemys temminckii</i> </h2>",
 "<p> massive head </p> big! <p>",
 "largest freshwater turtle. pink wormlike thing <",
 "/p></li></ul></html>  "}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"<html><h1></h1><ul><li><h2><i></i></h2><p></p><p>",
 "</p><p></p></li><li><h2><i></i></h2><p></p><p></p",
 "></li></ul></html>"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "equivalent"; verify_case(1, Arg2, compare(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"<html><h1></h1><ul><li><h2><i></i></h2><p></p><p>",
 "</p><p></p></li><li><h2><i></i></h2><p></p><p></p",
 "></li></ul></html>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {" <html> snapping turtles <ul> <li> common ",
 "snapping turtle, chelydra serpentina <p>",
 "hunter </p> <p> rarely basks </p> ",
 "<p> jeopardized by traffic </p></li>",
 "<li> often confused with... <h2> alligator snapp",
 "ing turtle <i>macroclemys temminckii</i> </h2>",
 "<p> massive head; largest freshwater turtle;",
 "pink wormlike appendage lures fish </p>",
 "</li></ul></html>  "}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "outtree 4"; verify_case(2, Arg2, compare(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"<html><h1></h1><ul><li><h2><i></i></h2><p></p><p>",
 "</p><p></p></li><li><h2><i></i></h2><p></p><p></p",
 "></li></ul></html>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {" <html> turtles <h1> snapping </h1> <ul> <li> <h2",
 "> common <i> chelydra serpentina </i> </h2> <p>",
 "hunter </p> <p> rarely basks <h3>",
 "<i>almost</i> <b>never</b> </h3> </p>",
 "<p> jeopardized by traffic </p></li>",
 "<li> often confused with... <h2> alligator snapp",
 "ing turtle <i>macroclemys temminckii</i> </h2>",
 "<p> massive head </p> big! <p>",
 "largest freshwater turtle. </p> <p> <b>pink</b>",
 " <b>wormlike</b> lure in mouth </p> <p> imposing",
 "sight on land or water </p> </li></ul></html>  "}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "intree 7"; verify_case(3, Arg2, compare(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"<html><h1></h1><ul><li><h2><i></i></h2><p></p><p>",
 "</p><p></p></li><li><h2><i></i></h2><p></p><p></p",
 "></li></ul></html>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"<html><ul><li><h2><i></i></h2><p></p><p>",
 "</p><p></p></li><li><h2><i></i></h2><p></p><p></p",
 "></li></ul><h1></h1></html>"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "incompatible"; verify_case(4, Arg2, compare(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"<html></html>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"<html><html><html></html><html></html><ul>",
 "</ul><ol></ol></html></html>"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "intree 5"; verify_case(5, Arg2, compare(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"<html><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><b></b></html>"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"<html><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p><p></p>",
 "<p></p><p></p><p></p><p></p><p></p><p></p></html>"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "incompatible"; verify_case(6, Arg2, compare(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    bloggoDocStructure ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
