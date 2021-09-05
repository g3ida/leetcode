
//////////////////////////////////////////////////////////////
// 32. Longest Valid Parentheses
//////////////////////////////////////////////////////////////
// Given a string containing just the characters '(' and ')', find the length of the longest valid
// (well-formed) parentheses substring.
// Example 1:
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
//
// Example 2:
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
//
// Example 3:
// Input: s = ""
// Output: 0
//
// Constraints:
//     0 <= s.length <= 3 * 104
//     s[i] is '(', or ')'.
//////////////////////////////////////////////////////////////

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int counter = 0;
        int depth = 0;
        int maxSequence = 0;
        for (auto c : s) {
            counter++;
            if (c == ')') {
                depth+=2;
            }
            if (depth == counter) {
                maxSequence = std::max(maxSequence, depth);
            }
            if (depth > counter) {
                depth = 0;
                counter  = 0;
            }
        }
        counter = 0;
        depth = 0;
        for (int i= n-1; i >= 0; i--) {
            counter++;
            if (s[i] == '(') {
                depth+=2;
            }
            if (depth == counter) {
                maxSequence = std::max(maxSequence, depth);
            }
            if (depth > counter) {
                depth = 0;
                counter  = 0;
            }
        }
        return maxSequence;
    }
};

//driver program
int main() {
    auto s = Solution();
    assert(s.longestValidParentheses("(()") == 2);
    assert(s.longestValidParentheses(")()())") == 4);
    assert(s.longestValidParentheses("") == 0);
    assert(s.longestValidParentheses("(()()(((((((((((((()))))(((((()))()())()") == 14);
}