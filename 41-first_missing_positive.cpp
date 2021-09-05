
//////////////////////////////////////////////////////////////
// 41. First Missing Positive
//////////////////////////////////////////////////////////////
// Given an unsorted integer array nums, return the smallest missing positive integer.
// You must implement an algorithm that runs in O(n) time and uses constant extra space.
//
// Example 1:
// Input: nums = [1,2,0]
// Output: 3
//
// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
//
// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1
//
// Constraints:
//     1 <= nums.length <= 5 * 105
//     -231 <= nums[i] <= 231 - 1
//////////////////////////////////////////////////////////////

#include <vector>
#include <assert.h>
#include <initializer_list>

using namespace std;

class Solution {
public:
    int firstMissingPositive(const vector<int>& nums) {
        int n = nums.size();
        std::vector<char> t(n+1, 0);
        for(int i = 0; i < n; i++) {
            if (nums[i] > n || nums[i] <= 0) {
                continue;
            }
            t[nums[i]-1] = 1;
        }
        for(int i = 0; i < n; i++) {
            if(t[i] == 0) {
                return i+1;
            } 
        }
        return n+1;
    }
};

//driver program
int main() {
    auto s = Solution();
    assert(s.firstMissingPositive({1,2,0}) == 3);
    assert(s.firstMissingPositive({3,4,-1,1}) == 2);
}

