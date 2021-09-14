
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

    string minWindow(string s, string t) {
        
        if (t.length() > s.length())
            return "";
        
        int tcount [128];
        int scount [128];
        
        std::memset(tcount, 0, sizeof(int) * 128);    
        std::memset(scount, 0, sizeof(int) * 128);
        
        int i = 0, j = 0, n = s.length();
        int tchars = 0;
        for(auto c : t) {
            if(tcount[c] == 0) tchars++;
            tcount[c]++;
        }
        
        string solution;
        int isol = 0, jsol = 0;
        int lenSolution = n + 1;

        int schars = 0;
        
        do {
            scount[s[j]]++;
            
            if(tcount[s[j]] == scount[s[j]]) {
                schars++;
                if (schars == tchars) { //there is a match
                    do {
                        if (scount[s[i]] == tcount[s[i]]) {
                            if(lenSolution > j-i) {
                                isol = i;
                                jsol = j;
                                lenSolution = j-i;
                            }
                            schars--;
                            scount[s[i]]--;
                            i++;
                            break;
                        }
                        scount[s[i]]--;
                        i++;
                    }while(true);
                }
            }
            j++;
            
        } while (j != n);
        
        if (lenSolution > n) return string();
        return s.substr(isol, jsol-isol+1);
    }
};

//driver program
int main() {
    auto s = Solution();
    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(s.minWindow("a", "a") == "a");
    assert(s.minWindow("a", "aa") == "");
}
