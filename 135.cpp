// I discovered that if we consider the directed graph where the vertices are children
// and there exists an edge from a to b if b should receive more candy than a
// Then the candies is equal to the depth of the kid in the topological sort search tree
// However, this solution wouldn't be very fast.

/* pseudo
 * let R be the ratings array
 * let C be an array initialized to ones
 * // satisfy left constraints
 * for i=1 to n-1
 *   if R[i] > R[i-1]
 *     C[i] = C[i-1] + 1
 *   else
 *     C[i] = 1
 * end for
 *
 * // satisfy right constraints
 * for i=n-2 downto 0
 *   if R[i] > R[i+1]
 *     C[i] = max(C[i], C[i+1] + 1)
 * end for
 * return sum of elements in C.
 */

// O(n)-time and O(n)-space

class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> candies(ratings.size());
            candies[0] = 1;
            // enforce "left constraints"
            for (int i = 1; i < ratings.size(); i++) {
                if (ratings[i] > ratings[i-1]) {
                    candies[i] = candies[i-1] + 1;
                }
                else {
                    candies[i] = 1;
                }
            }
            // enforce "right constraints"
            for (int i = ratings.size() - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    candies[i] = max(candies[i], candies[i+1] + 1);
                }
            }
            return accumulate(candies.begin(), candies.end(), 0);
        }
};
