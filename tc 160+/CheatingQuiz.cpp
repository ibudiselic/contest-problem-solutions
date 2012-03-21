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

class CheatingQuiz {
public:
    vector <int> howMany(string answers) {
        int A = 0, B = 0, C = 0;
        for (int i=0; i<(int)answers.size(); ++i) {
            if (answers[i] == 'A') {
                ++A;
            } else if (answers[i] == 'B') {
                ++B;
            } else {
                ++C;
            }
        }
        
        vector<int> sol(answers.size());
        for (int i=0; i<(int)sol.size(); ++i) {
            sol[i] = ((A>0)+(B>0)+(C>0));
            if (answers[i] == 'A') {
                --A;
            } else if (answers[i] == 'B') {
                --B;
            } else {
                --C;
            }
        }
        return sol;
    }
};
