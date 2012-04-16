#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int cnt[26];
int done[26];
class PasswordXPalindrome {
public:
    int minSwaps(string S) {
        int n = S.size();
        memset(cnt, 0, sizeof cnt);
        for (int i=0; i<n; ++i) {
            cnt[S[i]-'a']++;
        }
        int n1 = 0;
        int i1 = -1;
        for (int i=0; i<n; ++i) {
            if (cnt[S[i]-'a'] == 1) {
                ++n1;
                i1 = i;
            }
        }
        if (n1>1 || (n1==1 && n%2==0)) {
            return -1;
        }
        int sol = 0;
        if (i1!=-1 && i1!=n/2) {
            swap(S[i1], S[n/2]);
            S.erase(n/2, 1);
            --n;
            ++sol;
        }
        
        for (int i=0; i<n/2; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (S[i] == S[j]) {
                    if (j != n-1-i) {
                        swap(S[j], S[n-1-i]);
                        ++sol;
                    }
                    break;
                }
            }
        }
        
        return sol;
    }
};
