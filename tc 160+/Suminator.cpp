#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<long long, bool> pib;
pib pop(vector<pib> &S) {
    if (S.size() == 0) {
        return pib(0, 0);
    } else {
        pib ret = S.back();
        S.pop_back();
        return ret;
    }
}
void push(vector<pib> &S, pib &a, pib &b) {
    S.push_back(pib(a.first+b.first, a.second||b.second));
}
bool ok(vector <int> program, int X) {
    for (int i=0; i<(int)program.size(); ++i) {
        if (program[i] == -1) {
            program[i] = 0;
            break;
        }
    }
    vector<long long> S(100, 0);
    for (int i=0; i<(int)program.size(); ++i) {
        if (program[i] == 0) {
            long long a = S.back(); S.pop_back();
            long long b = S.back(); S.pop_back();
            S.push_back(a+b);
        } else {
            S.push_back(program[i]);
        }
    }
    return S.back() == X;
}
class Suminator {
public:
    int findMissing(vector <int> program, int X) {
        if (ok(program, X)) {
            return 0;
        }
        vector<pib> S;
        for (int i=0; i<(int)program.size(); ++i) {
            if (program[i] == 0) {
                pib a = pop(S);
                pib b = pop(S);
                push(S, a, b);
            } else if (program[i] == -1) {
                S.push_back(pib(0, 1));
            } else {
                S.push_back(pib(program[i], 0));
            }
        }

        pib res = pop(S);
        if (res.second == 0) {
            return X==res.first ? 1 : -1;
        } else {
            long long need = X - res.first;
            return need>0 ? int(need) : -1;
        }
    }
};
