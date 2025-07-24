// what I wrote is pretty much identical to leetcode's official C++ solution
// except I used more readable variable names.

#include <vector>
#include <unordered_map>

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> indices;
            for (int index = 0; index < nums.size(); index++) {
                int complement = target - nums[index];
                auto complement_index_it = indices.find(complement);
                if (complement_index_it != indices.end()) {
                    return {complement_index_it->second, index};
                }
                indices[nums[index]] = index;
            }
            return {};
        }
};
