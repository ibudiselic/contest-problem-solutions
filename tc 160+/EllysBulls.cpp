//# strings, meet in the middle, important
//# => Brute force the first n/2 characters and compute the "keys" that result from that choice, where each key is the remaining number of hits per string (for the remaining n-n/2 characters). Then brute force the other half of the string and compute a similar key used to look up the results from the first half.
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class EllysBulls {
public:
    string getNumber(vector <string> guesses, vector <int> bulls) {
        int n = guesses[0].size();
        int half = n/2;
        int lim = 1;
        for (int i=0; i<half; ++i) {
            lim *= 10;
        }
        map<vector<int>, vector<int>> choices;
        vector<int> digits(half);
        bool any = false;
        for (int prefix=0; prefix<lim; ++prefix) {
            int x = prefix;
            for (int i=0; i<half; ++i) {
                digits[i] = x%10;
                x /= 10;
            }
            vector<int> key = bulls;
            bool ok = true;
            for (int i=0; i<(int)guesses.size(); ++i) {
                for (int j=0; j<half; ++j) {
                    if (guesses[i][j]-'0' == digits[j]) {
                        --key[i];
                    }
                }
                if (key[i] < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                any = true;
                choices[key].push_back(prefix);
            }
        }
        if (!any) {
            return "Liar";
        }

        int rem = n-half;
        digits.assign(rem, 0);
        lim = 1;
        for (int i=0; i<rem; ++i) {
            lim *= 10;
        }
        string sol(n, ' ');
        vector<int> key;
        for (int suffix=0; suffix<lim; ++suffix) {
            int x = suffix;
            for (int i=0; i<rem; ++i) {
                digits[i] = x%10;
                x /= 10;
            }
            key.assign(guesses.size(), 0);
            bool ok = true;
            for (int i=0; i<(int)guesses.size(); ++i) {
                for (int j=0; j<rem; ++j) {
                    if (guesses[i][half+j]-'0' == digits[j]) {
                        ++key[i];
                    }
                }
                if (key[i] > bulls[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                auto other = choices.find(key);
                if (other == end(choices)) continue;
                if (int(other->second.size())>1 || sol[0]!=' ') {
                    return "Ambiguity";
                }
                int x = other->second[0];
                for (int i=0; i<half; ++i) {
                    sol[i] = char('0'+x%10);
                    x /= 10;
                }
                x = suffix;
                for (int i=0; i<rem; ++i) {
                    sol[half+i] = char('0'+x%10);
                    x /= 10;
                }
            }
        }

        return sol[0]==' ' ? "Liar" : sol;
    }
};
