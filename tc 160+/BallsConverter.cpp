#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int val(char c) {
    if (c <= 'Z') {
        return c-'A';
    } else {
        return c-'a'+26;
    }
}
class BallsConverter {
	public:
	string theGood(vector <string> A) {
        int n = A.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int v1 = val(A[i][j]);
                for (int k=0; k<n; ++k) {
                    if (A[v1][k] != A[i][val(A[j][k])]) {
                        return "Bad";
                    }
                }
            }
        }
        return "Good";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AB", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Good"; verify_case(0, Arg1, theGood(Arg0)); }
	void test_case_1() { string Arr0[] = {"BA", "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bad"; verify_case(1, Arg1, theGood(Arg0)); }
	void test_case_2() { string Arr0[] = {"ACB", "CBA", "BAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bad"; verify_case(2, Arg1, theGood(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAAA", "ABBB", "ABCC", "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Good"; verify_case(3, Arg1, theGood(Arg0)); }
	void test_case_4() { string Arr0[] = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcd",
"ACEGIKMOQSUWYacACEGIKMOQSUWYac",
"ADGJMPSVYbADGJMPSVYbADGJMPSVYb",
"AEIMQUYcCGKOSWaAEIMQUYcCGKOSWa",
"AFKPUZAFKPUZAFKPUZAFKPUZAFKPUZ",
"AGMSYAGMSYAGMSYAGMSYAGMSYAGMSY",
"AHOVcFMTaDKRYBIPWdGNUbELSZCJQX",
"AIQYCKSaEMUcGOWAIQYCKSaEMUcGOW",
"AJSbGPYDMVAJSbGPYDMVAJSbGPYDMV",
"AKUAKUAKUAKUAKUAKUAKUAKUAKUAKU",
"ALWDOZGRcJUBMXEPaHSdKVCNYFQbIT",
"AMYGSAMYGSAMYGSAMYGSAMYGSAMYGS",
"ANaJWFSBObKXGTCPcLYHUDQdMZIVER",
"AOcMaKYIWGUESCQAOcMaKYIWGUESCQ",
"APAPAPAPAPAPAPAPAPAPAPAPAPAPAP",
"AQCSEUGWIYKaMcOAQCSEUGWIYKaMcO",
"AREVIZMdQDUHYLcPCTGXKbOBSFWJaN",
"ASGYMASGYMASGYMASGYMASGYMASGYM",
"ATIbQFYNCVKdSHaPEXMBUJcRGZODWL",
"AUKAUKAUKAUKAUKAUKAUKAUKAUKAUK",
"AVMDYPGbSJAVMDYPGbSJAVMDYPGbSJ",
"AWOGcUMEaSKCYQIAWOGcUMEaSKCYQI",
"AXQJCZSLEbUNGdWPIBYRKDaTMFcVOH",
"AYSMGAYSMGAYSMGAYSMGAYSMGAYSMG",
"AZUPKFAZUPKFAZUPKFAZUPKFAZUPKF",
"AaWSOKGCcYUQMIEAaWSOKGCcYUQMIE",
"AbYVSPMJGDAbYVSPMJGDAbYVSPMJGD",
"AcaYWUSQOMKIGECAcaYWUSQOMKIGEC",
"AdcbaZYXWVUTSRQPONMLKJIHGFEDCB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Good"; verify_case(4, Arg1, theGood(Arg0)); }
	void test_case_5() { string Arr0[] = {"AAAAAFAAAAAAAAAAAAAAAAAXAAAAcAAAAAAAAAAnAAAAAAAvAA",
"ABBBBFBBBBBLBBBBQBBBBBBXYBBBcBBBBBBBBBBnBBBBBBBvwB",
"ABCCCFCCCCCLMCOCQRCCCCCXYCCCcCCCCCCCCCCnCCCCsCCvwC",
"ABCDEFGHDDDLMDODQRSDUVWXYDDbcdDfghDDklDnopDrsDDvwx",
"ABCEEFEEEEELMEOEQRSEUVWXYEEbcEEfEhEEklEnEpEEsEEvwE",
"FFFFFFFFFFFFFFFFFFFFFFFXFFFFcFFFFFFFFFFFFFFFFFFvFF",
"ABCGEFGGGGGLMGOGQRSGUVWXYGGbcGGfGhGGklGnGpGGsGGvwG",
"ABCHEFGHHHHLMHOHQRSHUVWXYHHbcdHfHhHHklHnHpHHsHHvwH",
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx",
"ABCDEFGHJJJLMJOJQRSJUVWXYJJbcdJfghJJklJnopJrsJJvwx",
"ABCDEFGHKJKLMNOPQRSTUVWXYZKbcdefghijklmnopqrsKKvwx",
"ALLLLFLLLLLLLLLLLLLLLLLXLLLLcLLLLLLLLLLnLLLLLLLvwL",
"ABMMMFMMMMMLMMOMQMMMMMMXYMMMcMMMMMMMMMMnMMMMMMMvwM",
"ABCDEFGHNJNLMNOPQRSTUVWXYZNbcdefghijklmnopqrsNNvwx",
"ABOOOFOOOOOLOOOOQOOOOOOXYOOOcOOOOOOOOOOnOOOOOOOvwO",
"ABCDEFGHPJPLMPOPQRSTUVWXYZPbcdPfghiPklmnopPrsPPvwx",
"AQQQQFQQQQQLQQQQQQQQQQQXQQQQcQQQQQQQQQQnQQQQQQQvwQ",
"ABRRRFRRRRRLMRORQRRRRRRXYRRRcRRRRRRRRRRnRRRRRRRvwR",
"ABCSSFSSSSSLMSOSQRSSSSSXYSSScSSSSSSSSSSnSSSSsSSvwS",
"ABCDEFGHTJTLMTOTQRSTUVWXYTTbcdTfghiTklTnopTrsTTvwx",
"ABCUUFUUUUULMUOUQRSUUUWXYUUUcUUUUhUUklUnUUUUsUUvwU",
"ABCVVFVVVVVLMVOVQRSVUVWXYVVbcVVfVhVVklVnVVVVsVVvwV",
"ABCWWFWWWWWLMWOWQRSWWWWXYWWWcWWWWhWWkWWnWWWWsWWvwW",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXvXX",
"AYYYYFYYYYYLYYYYQYYYYYYXYYYYcYYYYYYYYYYnYYYYYYYvwY",
"ABCDEFGHZJZLMZOZQRSTUVWXYZZbcdZfghiZklZnopZrsZZvwx",
"ABCDEFGHaJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx",
"ABCbbFbbbbbLMbObQRSbUbWXYbbbcbbfbhbbklbnbbbbsbbvwb",
"cccccccccccccccccccccccXcccccccccccccccccccccccvcc",
"ABCdEFGddddLMdOdQRSdUVWXYddbcddfdhddkldndpddsddvwd",
"ABCDEFGHeJeLMeOPQRSTUVWXYZebcdefghijklmnoperseevwx",
"ABCffFfffffLMfOfQRSfUfWXYfffcffffhffklfnffffsffvwf",
"ABCgEFGHgggLMgOgQRSgUVWXYggbcdgfghggklgngpggsggvwg",
"ABChhFhhhhhLMhOhQRShhhhXYhhhchhhhhhhkhhnhhhhshhvwh",
"ABCDEFGHiJiLMiOiQRSiUVWXYiibcdifghiiklinopirsiivwx",
"ABCDEFGHjJjLMjOPQRSTUVWXYZjbcdjfghijklmnopjrsjjvwx",
"ABCkkFkkkkkLMkOkQRSkkkkXYkkkckkkkkkkkkknkkkkskkvwk",
"ABCllFlllllLMlOlQRSlllWXYlllcllllhllkllnllllsllvwl",
"ABCDEFGHmJmLMmOmQRSTUVWXYZmbcdmfghimklmnopmrsmmvwx",
"nnnnnFnnnnnnnnnnnnnnnnnXnnnncnnnnnnnnnnnnnnnnnnvnn",
"ABCoEFGHoooLMoOoQRSoUVWXYoobcdofghooklonoporsoovwx",
"ABCppFpppppLMpOpQRSpUVWXYppbcppfphppklpnpppSsppvwp",
"ABCDEFGHqJqLMqOPQRSTUVWXYZqbcdefghijklmnopqrsqqvwx",
"ABCrEFGHrrrLMrOrQRSrUVWXYrrbcdrfghrrklrnrSrrsrrvwx",
"ABsssFsssssLMsOsQRsssssXYssscssssssssssnsssssssvws",
"ABCDEFGHtJKLMNOPQRSTUVWXYZtbcdefghijklmnopqrsttvwx",
"ABCDEFGHuJKLMNOPQRSTUVWXYZubcdefghijklmnopqrstuvwx",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"AwwwwFwwwwwwwwwwwwwwwwwXwwwwcwwwwwwwwwwnwwwwwwwvww",
"ABCxEFGHxxxLMxOxQRSxUVWXYxxbcdxfghxxklxnxpxxsxxvwx"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bad"; verify_case(5, Arg1, theGood(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BallsConverter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
