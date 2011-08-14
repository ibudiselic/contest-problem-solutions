#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/

struct Subject {
	bool has_the;
	string s;
	string the;
	Subject(): s(), the() { has_the = false; }
};
struct Verb {
	string s;
	string will;
	string tense;
	Verb(): s(), will(), tense() {}
};
struct Object {
	bool has_the;
	bool has_to;
	string the;
	string sto;
	string s;
	Object(): the(), sto(), s() { has_the = has_to = false; }
};

bool cmp_wo_case(const string &a, const string &b)
{
	for (int i=0; i<(int)a.length() && i<(int)b.length(); ++i)
		if (tolower(a[i])!=tolower(b[i])) return false;
	return true;
}
string get_syl(const string &s)
{
	string ret;
	int i;
	for (i=0; i<(int)s.length() && s[i]!='a' && s[i]!='A' && s[i]!='e' && s[i]!='E' && s[i]!='i' && s[i]!='I'
									&& s[i]!='o' && s[i]!='O' && s[i]!='u' && s[i]!='U'; ++i)
		ret += s[i];
	ret += s[i];
	return ret;
}
class TaglishTranslator {
    public:
    string translate(string sentence) {
        Subject sub;
        Verb vrb;
        Object obj;
        
        if (cmp_wo_case(sentence, "the") && 3<(int)sentence.size() && isspace(sentence[3])) {
        	sub.has_the = true;
        	sub.the = sentence.substr(0, 3);
        	sentence.erase(0, 4);
        }
        int i = 0;
        while (i<(int)sentence.length() && !isspace(sentence[i]))
        	sub.s += sentence[i++];
        sentence.erase(0, i+1);
       
        if (cmp_wo_case(sentence, "will") && 4<(int)sentence.size() && isspace(sentence[4])) {
        	vrb.tense = "future";
        	vrb.will = sentence.substr(0, 4);
        	sentence.erase(0, 5);
        }
        i = 0;
        while (i<(int)sentence.length() && !isspace(sentence[i]))
        	vrb.s += sentence[i++];
        sentence.erase(0, i+1);
        if (vrb.tense.length()==0)
        	if (vrb.s.length()>2 && cmp_wo_case(vrb.s.substr(vrb.s.length()-2, 2), "ed"))
        		vrb.tense = "past";
        	else vrb.tense = "present";
        
        if (sentence.length()) { /* has object */
        	if (cmp_wo_case(sentence, "to") && 2<(int)sentence.size() && isspace(sentence[2])) {
        		obj.has_to = true;
        		obj.sto = sentence.substr(0, 2);
        		sentence.erase(0, 3);
        	}
        	if (cmp_wo_case(sentence, "the") && 3<(int)sentence.size() && isspace(sentence[3])) {
        		obj.has_the = true;
        		obj.the = sentence.substr(0, 3);
        		sentence.erase(0, 4);
        	}
        	i = 0;
        	while (i<(int)sentence.length() && !isspace(sentence[i]))
        		obj.s += sentence[i++];
        	sentence.erase(0, i);
        	assert(sentence.length() == 0);
        }
        
        if (vrb.tense == "past") {
        	vrb.s.erase(vrb.s.length()-2, 2);
        	vrb.s = "nag"+vrb.s;
        }
        else if (vrb.tense == "present")
        	vrb.s = "nag"+get_syl(vrb.s)+vrb.s;
        else {
        	assert(vrb.tense == "future");
        	vrb.s = "mag"+get_syl(vrb.s)+vrb.s;
        }
        if (sub.has_the)
        	sub.s = "ang "+sub.s;
        else sub.s = "si "+sub.s;
        
        if (obj.s.length()) {
        	if (obj.has_to) {
        		if (obj.has_the) {
        			obj.s = "sa "+obj.s;
        		} else obj.s = "kay "+obj.s;
        	} else {
        		if (obj.has_the) {
        			obj.s = "ng "+obj.s;
        		} else obj.s = "ni "+obj.s;
        	}
        	sub.s += ' '+obj.s;
        }
        			
        return vrb.s + ' ' + sub.s;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "The fox jumps to the dog"; string Arg1 = "nagjujumps ang fox sa dog"; verify_case(0, Arg1, translate(Arg0)); }
	void test_case_1() { string Arg0 = "tomek codes"; string Arg1 = "nagcocodes si tomek"; verify_case(1, Arg1, translate(Arg0)); }
	void test_case_2() { string Arg0 = "tHe mAn plAyEd ThE pIAnO"; string Arg1 = "nagplAy ang mAn ng pIAnO"; verify_case(2, Arg1, translate(Arg0)); }
	void test_case_3() { string Arg0 = "Bob will Filed the taxes"; string Arg1 = "magFiFiled si Bob ng taxes"; verify_case(3, Arg1, translate(Arg0)); }
	void test_case_4() { string Arg0 = "Matthew walked to Mathew"; string Arg1 = "nagwalk si Matthew kay Mathew"; verify_case(4, Arg1, translate(Arg0)); }
	void test_case_5() { string Arg0 = "StrongBad kicked TheCheat"; string Arg1 = "nagkick si StrongBad ni TheCheat"; verify_case(5, Arg1, translate(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TaglishTranslator ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
