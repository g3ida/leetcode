
//////////////////////////////////////////////////////////////
// 87. Scramble String
//////////////////////////////////////////////////////////////
// We can scramble a string s to get a string t using the following algorithm:

//     If the length of the string is 1, stop.
//     If the length of the string is > 1, do the following:
//         Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
//         Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
//         Apply step 1 recursively on each of the two substrings x and y.
//
// Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
//
// Example 1:
// Input: s1 = "great", s2 = "rgeat"
// Output: true
// Explanation: One possible scenario applied on s1 is:
// "great" --> "gr/eat" // divide at random index.
// "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
// "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
// "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
// "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
// "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
// The algorithm stops now and the result string is "rgeat" which is s2.
// As there is one possible scenario that led s1 to be scrambled to s2, we return true.
//
// Example 2:
// Input: s1 = "abcde", s2 = "caebd"
// Output: false
//
// Example 3:
// Input: s1 = "a", s2 = "a"
// Output: true
//
// Constraints:
//     s1.length == s2.length
//     1 <= s1.length <= 30
//     s1 and s2 consist of lower-case English letters.
//////////////////////////////////////////////////////////////

#include <vector>
#include <assert.h>
#include <initializer_list>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    
    int cache[30000];
    string s;
    string s2;
    
    bool f(int i1, int n, int i2) {
        
        if (n == 1) {
            return s[i1] == s2[i2];
        }
        
        int index = i1*961+i2*31+n;
        if (cache[index] != 0) {
            return cache[index] == 1;
        }
        
        for (auto i=1; i < n; i++) { 
            if ((f(i1, i, i2) && f(i1+i, n-i, i2+i))
              || f(i1, i, i2+n-i) && f(i1+i, n-i, i2)) {
                cache[index] = 1;
                return true;
            }
        }
        cache[index] = 2;
        return false;
    }
    
    
    bool isScramble(const string& s1,const string& s2) {
        this->s = s1;
        this->s2 = s2;
        memset(cache, 0, 30000);
        return f(0, s1.length(), 0);
    }
};

//driver program
int main() {
    auto s = Solution();
    assert(s.isScramble("great", "rgeat"));
    assert(!s.isScramble("abcde", "caebd"));
    assert(s.isScramble("a", "a"));
}
