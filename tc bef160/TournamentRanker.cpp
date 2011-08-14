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

struct player {
	string name;
	string lost;
	int n;
};
map<string, player> memo;
bool operator<(const player &a, const player &b)
{
	if (a.n!=b.n)
		return a.n > b.n;
	return memo[a.lost]<memo[b.lost];
}
class TournamentRanker {
    public:
    vector <string> rankTeams(vector <string> names, vector <string> lostTo) {
        
 		memo.clear();
 		
        for (int i=0; i<(int)names.size(); ++i) {
        	int n=0;
        	player &a = memo[names[i]];
        	for (int j=0; j<(int)lostTo.size(); ++j)
        		if (names[i]==lostTo[j]) {
        			++n;
        			memo[names[j]].lost = names[i];
        		}
        	a.name = names[i];
        	a.n = n;
        }
       	vector<player> tmp;
       	for (map<string, player>::const_iterator i=memo.begin(); i!=memo.end(); ++i)
       	    tmp.push_back(i->second);
       	for (vector<player>::iterator i=tmp.begin(); i!=tmp.end(); ++i)
       		for (vector<player>::iterator j=i+1; j!=tmp.end(); ++j)
       			if (*j < *i) {
       				player a = *i;
       				*i = *j;
       				*j = a;
       			}
       	vector<string> sol;
       	for (vector<player>::const_iterator i=tmp.begin(); i!=tmp.end(); ++i)
       		sol.push_back(i->name);
       	return sol;
    }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "AA", "BA", "CA", "DA", "EA", "FA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] =  {"L", "T", "L", "FA", "A", "AA", "M", "M", "G", "L", "H", "S", "P", "H", "J", "S", "BA", "P", "", "P", "N", "P", "CA", "S", "M", "R", "S", "CA", "S", "Z", "R", "J"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"S", "P", "L", "M", "CA", "R", "J", "H", "AA", "T", "A", "G", "BA", "Z", "FA", "N", "X", "V", "C", "Y", "W", "EA", "O", "K", "F", "B", "E", "I", "Q", "DA", "D", "U"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, rankTeams(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"DUKE", "SETON HALL", "ILLINOIS", "CINCINNATI",
 "NORTH CAROLINA", "TEXAS", "XAVIER", "MISSISSIPPI STATE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"", "DUKE", "DUKE", "ILLINOIS",
 "TEXAS", "XAVIER", "DUKE", "XAVIER"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "DUKE",  "XAVIER",  "ILLINOIS",  "TEXAS",  "SETON HALL",  "MISSISSIPPI STATE",  "CINCINNATI",  "NORTH CAROLINA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, rankTeams(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"JAVA", "VISUAL BASIC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"VISUAL BASIC", ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "VISUAL BASIC",  "JAVA" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, rankTeams(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TournamentRanker ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
