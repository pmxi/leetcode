// this was easy
// there is an in-place solution because nums[i] is in [0,1000). This means it takes 10 bits
// to store a num. Since we are working with 32 bit ints, we can fit another num in there.


class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            vector<int> ret(nums.size());
            for (int i = 0; i < nums.size(); i++) {
                ret[i] = nums[nums[i]];
            }
            return ret;
        }
};
