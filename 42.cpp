class Solution {
    public:
        int trap(vector<int>& height) {
            int l = 0;
            int r = height.size() - 1;
            int leftmax = 0;
            int rightmax = 0;
            int ans = 0;
            while (l < r) {
                if (height[l] < height[r]) {
                    leftmax = max(leftmax, height[l]);
                    ans += leftmax - height[l];
                    l++;
                }
                else {
                    rightmax = max(rightmax, height[r]);
                    ans += rightmax - height[r];
                    r--;
                }
            }
            return ans;
        }
};
