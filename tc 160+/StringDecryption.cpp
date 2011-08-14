#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

long long am[501][11][2];
const long long mod = 1000000009;
class StringDecryption {
	public:
	int decrypt(vector <string> code) {
		string s = accumulate(code.begin(), code.end(), string());
        int n = s.size();
        
        memset(am, 0, sizeof am);
        am[0][10][1] = 1;
        // str0 = original
        // str1 = first encrypt
        // str2 = second encrypt == s
        for (int last=1; last<=n; ++last) { // last-1 == pos of character code in str2
            long long mult = 0; // integer count for the last char code
            long long p10 = 1;
            int lastChar = s[last-1] - '0';
            for (int prev=last-2; prev>=0; --prev) { // prev-1 == pos of the previous char code in str2
                mult = (mult + p10*(s[prev]-'0')) % mod;
                p10 = (p10*10) % mod;
                if (s[prev] == '0') { // implies a leading zero so it is not allowed to be an actual integer count
                    continue; 
                }
                if (prev>0 && s[prev-1]-'0'==lastChar) { // adjacent char codes must be different in str2
                    continue;
                }
                for (int prevDigit=0; prevDigit<11; ++prevDigit) { // digit code in str1! (now we need to create a new digit code based on last)
                    for (int prevLastTaken=0; prevLastTaken<2; ++prevLastTaken) { // was the last character generated from 'prev' in str1 taken?
                        if (am[prev][prevDigit][prevLastTaken] == 0) { // if this situation is impossible, no point to go on
                            continue;
                        }
                        if (lastChar==0 && prevLastTaken==1) { // this means this new part of str2 (from prev to last) creates a bunch of zeros
                            continue;                          // in str1 - if al the chars created before in str1 are taken, this implies leading zeroes in int in str1! (not allowed)
                        }
                        // we can let all the created lastChar characters in str1 be a part of a long int multiplier code
                        am[last][prevDigit][0] = (am[last][prevDigit][0] + am[prev][prevDigit][prevLastTaken]) % mod;
                        // or if lastChar is not prevDigit, we can actually pick one of the created lastChars in str1 to be a new char code (in str1)
                        if (prevDigit != lastChar) {
                            // if last char is not zero and we are creating more than one lastChar in str1 (mult is getting moded, so we're also checking the lenght of the number)
                            // then we can use lastChar as a new code and leave some of the generated lastChars for the next item
                            // if prevLastTaken is not set (i.e. 0), we can pick the first generated lastChar to be the char code (otherwise we can't)
                            // the -1 is because we can't pick the last generated lastChar since we are covering the case where we leave some lastChars in str1
                            // for the next item
                            if (lastChar>0 && (prev<last-2 || mult>1)) { 
                                am[last][lastChar][0] = (am[last][lastChar][0] + am[prev][prevDigit][prevLastTaken] * (mult-1-prevLastTaken+mod) % mod) % mod;
                            }
                            // if we generated more than one lastChar in str1 or if we have got some remaining chars from previously for the count part of the item
                            // we can make a choice that doesn't leave anything for the next item (i.e. pick the last generated lastChar for the char code)
                            if (prev<last-2 || mult>1 || prevLastTaken==0) {
                                am[last][lastChar][1] = (am[last][lastChar][1] + am[prev][prevDigit][prevLastTaken]) % mod;
                            }
                        }
                    }
                }
            }
        }
        
        return am[n][s[s.size()-1]-'0'][1];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"2122"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, decrypt(Arg0)); }
	void test_case_1() { string Arr0[] = {"012345"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, decrypt(Arg0)); }
	void test_case_2() { string Arr0[] = {"123","4056","789"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1555366; verify_case(2, Arg1, decrypt(Arg0)); }
	void test_case_3() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, decrypt(Arg0)); }
	void test_case_4() { string Arr0[] = {"10000000101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, decrypt(Arg0)); }
	void test_case_5() { string Arr0[] = {"36029876684872327223276091861774662608610223162723",
 "03488815136338720301059585173865765204966825388127",
 "28905156607840356770675251838346615448480878517234",
 "48346801533058114299540857443030369316232988018148",
 "10266938012137248616925283167856138261491565599857",
 "63098906296356837907112034583226442670798371015701",
 "04431120878401385924047425666758653777487585276695",
 "60451685064284613241730873806124686837402534256835",
 "74510620643600499901411494702324867762597665590427",
 "82564618006706585886295436740966342057330943523869"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 882582353; verify_case(5, Arg1, decrypt(Arg0)); }
	void test_case_6() { string Arr0[] = {"11111111111111111111111111111111111111111111111111",
 "12222222222222211122222222222221112222222222222111",
 "12000000000000211120000000000021112000000000002111",
 "12222220222222211120222222222221112022222222202111",
 "11111120211111111120222222222221112022222222202111",
 "11111120211111111120000000000021112000000000002111",
 "11111120211111111122222222222021112022222222202111",
 "11111120211111111122222222222021112021111111202111",
 "11111120211111111120000000000021112021111111202111",
 "11111122211111111122222222222221112221111111222111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 371459312; verify_case(6, Arg1, decrypt(Arg0)); }
	void test_case_7() { string Arr0[] = {"89210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 95; verify_case(7, Arg1, decrypt(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StringDecryption ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
