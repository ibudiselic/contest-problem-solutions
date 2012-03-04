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

class SRMRoomAssignmentPhase {
public:
    int countCompetitors(vector <int> ratings, int K) {
        int me = ratings[0];
        sort(ratings.begin(), ratings.end());
        int p = lower_bound(ratings.begin(), ratings.end(), me) - ratings.begin();
        return ((int)ratings.size()-1-p)/K;
    }
};
