/*
ID: ivan.bu1
PROG: cryptcow
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <utility>
#include <cassert>

using namespace std;

string target = "Begin the Escape execution at the Break of Dawn";
inline bool is_delim(char c) {
    return c=='C' || c=='O' || c=='W';
}
unsigned hash(const string &s) {
    unsigned h = 5381;
    for (int i=0; i<(int)s.size(); ++i) {
        h = (h*33)^s[i];
    }
    return h;
}

struct Set {
    set< pair<unsigned, string> > internal;
    bool count(const string &s) {
        return internal.count(make_pair(hash(s), s));
    }
    bool insert(const string &s) {
        return internal.insert(make_pair(hash(s), s)).second;
    }
} memo, parts;

bool go(const string &s, int level) {
	const int len = s.size();
    string tmp(len-3, ' ');
    const int sz = len-3;

	for (int i=0; i<len-2; ++i) {
		if (s[i] != 'C') continue;
        for (int x=0; x<i; ++x) {
            tmp[x] = s[x];
        }
        for (int j=i+1; j<len-1; ++j) {
            if (s[j] != 'O') continue;
            for (int k=len-1; k>=j+1; --k) {
                if (s[k] != 'W') continue;
                const int lim1 = i+k-j-1;
                for (int x=i, y=j+1; x<lim1; ++x, ++y) {
                    tmp[x] = s[y];
                }
                const int lim2 = lim1+j-i-1;
                for (int x=lim1, y=i+1; x<lim2; ++x, ++y) {
                    tmp[x] = s[y];
                }
                for (int x=lim2, y=k+1; y<len; ++x, ++y) {
                    tmp[x] = s[y];
                }
                /*string tmp2 = s.substr(0, i)+s.substr(j+1, k-j-1)+s.substr(i+1, j-i-1);
                if (k != (int)s.length()-1) tmp2 += s.substr(k+1);
                assert(tmp == tmp2);*/

                if (sz==target.size() && memcmp(&tmp[0], &target[0], sz)==0) {
                    return true;
                }
                int c = 0;
                while (c<sz && tmp[c]!='C') {
                    ++c;
                }
                if (c == sz) {
                    return false;
                }
                int w = sz - 1;
                bool last_not_w = false;
                while (w>=0 && tmp[w]!='W') {
                    if (tmp[w]=='C' || tmp[w]=='O') {
                        last_not_w = true;
                    }
                    --w;
                }
                if (w == -1) {
                    return false;
                }
                if (last_not_w) continue;
                if (c >= (int)target.size()) continue;
                if (memcmp(&tmp[0], &target[0], c) != 0) continue;
                if (sz-w-1>target.size()) continue;
                if (w!=sz-1 && memcmp(&tmp[w+1], &target[target.size()-(sz-w-1)], sz-w-1)!=0)
                    continue;

                int i1 = 0;
                while (i1<sz && !is_delim(tmp[i1])) {
                    ++i1;
                }
                if (tmp[i1] != 'C') {
                    goto NEXT_K;
                }
                while (i1 < sz) {
                    if (is_delim(tmp[i1])) {
                        int j1 = i1+1;
                        while (j1<sz && !is_delim(tmp[j1])) {
                            ++j1;
                        }
                        if (j1 < sz) {
                            if (!parts.count(tmp.substr(i1+1, j1-i1-1))) goto NEXT_K;
                        }
                        i1 = j1-1;
                    }
                    ++i1;
                }
                if (memo.insert(tmp)) {
                    if (go(tmp, level-1)) {
                        return true;
                    }
                }
                NEXT_K: ;
            }
        }
    }
    
    return false;
}

int main() {
    string src;
	ifstream fin("cryptcow.in");
    getline(fin, src);
    fin.close();
    
    int cs = 0;
    int os = 0;
    int ws = 0;
    for (int i=0; i<(int)src.size(); ++i) {
        if (src[i] == 'C') { ++cs; }
        else if (src[i] == 'O') { ++os; }
        else if (src[i] == 'W') { ++ws; }
    }

    ofstream fout("cryptcow.out");
    if (src == target) {
        fout << "1 0\n";
    } else if (cs!=os || cs!=ws || os!=ws || cs==0 || (int)src.size()-3*cs!=target.size()) {
        fout << "0 0\n";
    } else {
        parts.insert("");
        for (int i=0; i<(int)target.size(); ++i) {
            for (int j=i+1; j<=(int)target.size(); ++j) {
                parts.insert(target.substr(i, j-i));
            }
        }
        if (go(src, cs)) {
            fout << "1 " << cs << '\n';
        } else {
            fout << "0 0\n";
        }
    }
    fout.close();

	return 0;
}
