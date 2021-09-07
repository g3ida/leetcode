
//////////////////////////////////////////////////////////////
// 30. Substring with Concatenation of All Words
//////////////////////////////////////////////////////////////
// You are given a string s and an array of strings words of the same length. Return all 
// starting indices of substring(s) in s that is a concatenation of each word in words
// exactly once, in any order, and without any intervening characters.
// You can return the answer in any order.
//
// Example 1:
// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
//
// Example 2:
// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []
//
// Example 3:
// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// Output: [6,9,12]
//
// Constraints:
//     1 <= s.length <= 104
//     s consists of lower-case English letters.
//     1 <= words.length <= 5000
//     1 <= words[i].length <= 30
//     words[i] consists of lower-case English letters.
//////////////////////////////////////////////////////////////
#include <string>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <initializer_list>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, const vector<string>& words) {
        
        const int m = words.size();
        const int l =  words[0].length();
        const int xm = m * l;
        const int n = s.length();
        
        vector<int> result{};
        
        if (xm > n) {
            return result;
        }
        
        unordered_map<string, int> occurences;
        for (const auto& w : words) {
            if (occurences.find(w) == occurences.end()) {
                occurences[w] = -1;
            } else {
                occurences[w]--;
            }
        }
        
        std::vector<unordered_map<string, int>> occ(l, occurences);
        
        auto notFound = true;
            
        for(int j = 0; j < l; j++) {
            for(int i=0; i < xm; i+=l) {
                auto w = s.substr(i+j, l);
                if (occ[j].find(w) != occ[j].end()) {
                    occ[j][w]++;
                }    
            }
        }
        
        if (notFound) {
            for(int j = 0; j < l; j++) {
                notFound = true;
                for (auto& el: occ[j]) {
                    if(el.second != 0) {
                        notFound = false;
                        break;
                    }
                }
                if (notFound) {  
                    result.emplace_back(j);
                }
            }
        }
        
        for(int i=l; i <= n - xm; i+=l) {
            for(int j=0; j < l; j++) {

                string in = s.substr(i+j-l, l);
                                
                notFound = true;
                if (occ[j].find(in) != occ[j].end()) {
                    occ[j][in]--;
                }

                in = s.substr(i+j+xm-l, l);
                if (occ[j].find(in) != occ[j].end()) {
                    occ[j][in]++;
                } else {
                    notFound = false;
                }
                
                if (notFound) {        
                    for (auto& el: occ[j]) {
                        if(el.second != 0) {
                            notFound = false;
                            break;
                        }
                    }   
                }
                if (notFound) {
                    result.emplace_back(i+j);
                }
            }
        }
        return result;
    }
};

//driver program
int main() {
    auto s = Solution();
    assert((s.findSubstring("barfoothefoobarman", {"foo","bar"}) == std::vector<int>({0,9})));
    assert((s.findSubstring("wordgoodgoodgoodbestword", {"word","good","best","word"}) == std::vector<int>()));
    assert((s.findSubstring("barfoofoobarthefoobarman", {"bar","foo","the"}) == std::vector<int>({6,9,12})));
    assert((s.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", {"fooo","barr","wing","ding","wing"}) == std::vector<int>({13})));
}

