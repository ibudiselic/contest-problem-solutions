#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

// The first observation is that you always want to use at most two colonies because
// with more colonies, two or more will have the same value (pigeonhole).
// Therefore, there are 4 possible inputs - (0, 0), (0, 1), (1, 0) and (1, 1).
// You need to find out if it is possible to choose a setting of left/right input
// bacteria to the '?' locations in the formula that will produce a discriminating
// output, i.e. that lets you know the value of at least one input.
//
// By the constraints of the problem, you can always get every possible input.
// Imagine there is a formula that gives the outputs 0, 0, 0, 1 for the four different
// inputs. Then, you can just try all the possible inputs (pairs of colonies, or 
// "two instances" of the same colony) and when you get the output 1, you know both
// inputs have the value 1.
//
// This leads to the following solution. Use a 16-bit bitmask to represent a subexpression
// of the formula. The i-th bit in the bitmask will be set iff the formula can output the 
// 4-bit number i for the four different inputs.
// Obviously, the formula '0' gives zeroes for all for inputs, i.e. only the 0-bit will be set.
// For the '1' formula, the 15-bit will be set. For the '?' formula, we can choose either the
// first or the second input. In the first case, we get the output 0011 (3), in the second 0101 (5).
//
// For two arbitrary expressions joined by an operator, we do a 16x16 loop. If you can get some output
// X for the left operand and the output Y for the right operand, you can get XopY for the resulting
// expression.
//
// When you compute the bitmask for the whole expression, you can solve the problem if the output
// is of the 3-1 form (just try all inputs until you get a 0 or 1 and then you know what the input was),
// or if it is of the 2-2 form that reveals one of the inputs. If you use two instances of the same 
// colony as the input, you need a formula that has a 0-1 output for the cases (0, 0) and (1, 1).
// It turns out that doesn't add any extra good outcomes.
int main() {
    int n;
    scanf("%d", &n);
    int ch;
    stack<int> operands;
    stack<char> ops;
    getchar();
    while ((ch=getchar()) != EOF) {
        char c = char(ch);
        if (c == '\n') break;
        switch (c) {
            case '(': break;
            case '0': operands.push(1); break;
            case '1': operands.push(1<<15); break;
            case '?': operands.push((1<<3) | (1<<5)); break;
            case ')': 
                {
                    int y = operands.top(); operands.pop();
                    int x = operands.top(); operands.pop();
                    char op = ops.top(); ops.pop();
                    int res = 0;
                    for (int i=0; i<16; ++i) {
                        if (~x & (1<<i)) continue;
                        for (int j=0; j<16; ++j) {
                            if (~y & (1<<j)) continue;
                            switch (op) {
                                case '|': res |= 1<<(i|j); break;
                                case '&': res |= 1<<(i&j); break;
                                case '^': res |= 1<<(i^j); break;
                                default: assert(0);
                            }
                        }
                    }
                    operands.push(res);
                    break;
                }
            case '|': case '&': case '^': ops.push(c); break;
            default: break;
        }
    }
    assert(operands.size() == 1);

    int need = ((1<<16)-1) ^ 1 ^ (1<<6) ^ (1<<9) ^ (1<<15);
    puts(operands.top()&need ? "YES" : "NO");
    return 0;
}
