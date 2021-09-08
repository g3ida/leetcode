
#############################################################
# 5. Longest Palindromic Substring
#############################################################
# Given a string s, return the longest palindromic substring in s.
#
# Example 1:
# Input: s = "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
#
# Example 2:
# Input: s = "cbbd"
# Output: "bb"
#
# Example 3:
# Input: s = "a"
# Output: "a"
#
# Example 4:
# Input: s = "ac"
# Output: "a"
#
# Constraints:
#     1 <= s.length <= 1000
#     s consist of only digits and English letters.
#############################################################

from typing import List

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        maxi = 0;
        result = ''
        for i in range(0, n):
            k = 0
            m = 1
            p = [s[i]]
            #odd palindroms
            while i-k-1 >= 0 and i+k+1 < n:
                if s[i-k-1] == s[i+k+1]:
                    m = m+2
                    p.append(s[i-k-1])
                else:
                    break
                k = k+1
            if m > maxi:
                maxi = m
                result = ''.join(p[::-1][:len(p)-1]) + ''.join(p)
            
            k = 0
            m = 0
            p = []
            #even palindroms
            while i-k >= 0 and i+k+1 < n:
                if s[i-k] == s[i+k+1]:
                    p.append(s[i-k])
                    m = m+2
                else:
                    break
                k = k+1
            if m > maxi:
                maxi = m
                result = ''.join(p[::-1]) + ''.join(p)
        return result

#driver program
s = Solution()
assert(s.longestPalindrome("babad") == "bab")
assert(s.longestPalindrome("cbbd") == "bb")
assert(s.longestPalindrome("a") == "a")
assert(s.longestPalindrome("ac") == "a")