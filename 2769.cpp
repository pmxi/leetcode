class Solution {
    public:
        int theMaximumAchievableX(int num, int t) {
            // I wrote it like this for readability,
            // however, I expect the compiler to optimize this
            // to num + (t << 1)
            return num + 2 * t;
        }
};
