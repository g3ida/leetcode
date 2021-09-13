
//////////////////////////////////////////////////////////////
// 25. Reverse Nodes in k-Group
//////////////////////////////////////////////////////////////
// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring of s such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return the empty string "".
//
// The testcases will be generated such that the answer is unique.
//
// A substring is a contiguous sequence of characters within the string.
//
// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
//
// Example 2:
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
//
// Example 3:
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
//
// Constraints:
//     m == s.length
//     n == t.length
//     1 <= m, n <= 105
//     s and t consist of uppercase and lowercase English letters.
//
// Follow up: Could you find an algorithm that runs in O(m + n) time?
//////////////////////////////////////////////////////////////

#include <vector>
#include <assert.h>
#include <initializer_list>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    
    bool contains(std::unordered_map<char, int>& count, std::unordered_map<char, int>& match) {
        for(auto& el : match) {
            auto x = count.find(el.first);
            if(x == count.end() || el.second > x->second) {
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        
        if (t.length() > s.length())
            return "";
        
        int i = 0, j = 0, n = s.length();
        std::unordered_map<char, int> count;
        std::unordered_map<char, int> match;
        
        for(auto c : t) {
            if(match.find(c) == match.end()) {
                match[c] = 1;
            } else {
                match[c]++;
            }
        }
        
        string solution;
        int lenSolution = n + 1;
        do {
            if(count.find(s[j]) == match.end()) {
                count[s[j]] = 1;
            } else {
                count[s[j]]++;
            }
                
            if (contains(count, match)) {
                do {
                    auto matchj = match.find(s[i]);
                    if (matchj != match.end() && count[s[i]] == matchj->second) {
                        if(lenSolution > j-i) {
                            solution = s.substr(i, j-i+1);
                            lenSolution = j-i;
                        }
                        count[s[i]]--;
                        i++;
                        break;
                    }
                    count[s[i]]--;
                    i++;
                } while(true);
            }
            j++;
        } while (j != n);
        
        return solution;
    }
};

//driver program
int main() {
    auto s = Solution();
    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(s.minWindow("a", "a") == "a");
    assert(s.minWindow("a", "aa") == "");
}
