// deletion criteria is A[i] = A[i-1]



// kinda cheesed it but I need to sleep

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto new_end = std::unique(nums.begin(), nums.end());
        nums.erase(new_end, nums.end());
        return nums.size();
    }
};
