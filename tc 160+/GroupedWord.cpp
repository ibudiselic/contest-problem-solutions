#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class GroupedWord {
	public:
	string restore(vector <string> parts) {
        while (1) {
            bool change = false;
            
            for (int i=0; i<(int)parts.size(); ++i) {
                if (parts[i] == string(parts[i].size(), parts[i][0])) {
                    for (int j=i+1; j<(int)parts.size(); ++j) {
                        if (parts[j][0]==parts[i][0] && parts[j]==string(parts[j].size(), parts[j][0])) {
                            parts[i] += parts[j];
                            parts[j] = parts.back();
                            parts.pop_back();
                            change = true;
                            break;
                        }
                    }
                }
                if (change) {
                    break;
                }
            }
            if (!change) {
                break;
            }
        }
        
        while (1) {
            bool change = false;
            
            for (int i=0; i<(int)parts.size(); ++i) {
                if (parts[i] == string(parts[i].size(), parts[i][0])) {
                    for (int j=i+1; j<(int)parts.size(); ++j) {
                        if (parts[j][0] == parts[i][0]) {
                            parts[i] += parts[j];
                            parts[j] = parts.back();
                            parts.pop_back();
                            change = true;
                            break;
                        } else if (parts[j][parts[j].size()-1] == parts[i][0]) {
                            parts[i] = parts[j] + parts[i];
                            parts[j] = parts.back();
                            parts.pop_back();
                            change = true;
                            break;
                        }
                    }
                }
                if (change) {
                    break;
                }
            }
            if (!change) {
                break;
            }
        }
        while (1) {
            bool change = false;
            
            for (int i=0; i<(int)parts.size(); ++i) {
                for (int j=i+1; j<(int)parts.size(); ++j) {
                    if (parts[j][0] == parts[i][parts[i].size()-1]) {
                        parts[i] += parts[j];
                        parts[j] = parts.back();
                        parts.pop_back();
                        change = true;
                        break;
                    } else if (parts[j][parts[j].size()-1] == parts[i][0]) {
                        parts[i] = parts[j] + parts[i];
                        parts[j] = parts.back();
                        parts.pop_back();
                        change = true;
                        break;
                    }
                }
                if (change) {
                    break;
                }
            }
            if (!change) {
                break;
            }
        }
        
        bool seen[26] = {0};
        string all;
        for (int i=0; i<(int)parts.size(); ++i) {
            all += parts[i];
        }
        for (int i=0; i<(int)all.size(); ++i) {
            if (seen[all[i]-'a'] && i>0 && all[i]!=all[i-1]) {
                return "IMPOSSIBLE";
            }
            seen[all[i]-'a'] = true;
        }
        
        if (parts.size() > 1) {
            return "MANY";
        }
        return all;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"aaa", "a", "aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaaaa"; verify_case(0, Arg1, restore(Arg0)); }
	void test_case_1() { string Arr0[] = {"ab", "bba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; verify_case(1, Arg1, restore(Arg0)); }
	void test_case_2() { string Arr0[] = {"te", "st"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "stte"; verify_case(2, Arg1, restore(Arg0)); }
	void test_case_3() { string Arr0[] = {"te", "s", "t"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MANY"; verify_case(3, Arg1, restore(Arg0)); }
	void test_case_4() { string Arr0[] = {"orr", "rd", "woo", "www"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "wwwwooorrrd"; verify_case(4, Arg1, restore(Arg0)); }
	void test_case_5() { string Arr0[] = {"abcb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IMPOSSIBLE"; verify_case(5, Arg1, restore(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GroupedWord ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
