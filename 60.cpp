// my first hard of this summer
// though I already knew the alg because I figured it out for a hw in 182

// time complexity of factorial(n) is O(n).
// The while loop in getPermutation() runs n times.
// Honestly, n is so small (at most 9) so I don't think asymptotic time complexity is the goal
// We should look at the exact cost.

class Solution {
    private:
        // The C++ standard library has no factorial function :'(
        // (probably because it grows too quickly to support over all the integers)
        // However, we only need to calculate the factorial for n in [1, 9]
        // I could precalculate the factorials tbh, but I already got 0 ms runtime.
        int factorial(int n) {
            int result = 1;
            for (int i = 2; i <= n; i++) {
                result *= i;
            }
            return result;
        }
    public:
        string getPermutation(int n, int k) {
            // create a list of integers 1...n
            // to represent the set of elements being permuted.
            vector<int> elements(n);
            iota(elements.begin(), elements.end(), 1);
            string permutation = "";
            permutation.reserve(n);
            // convert k to a zero-based index for more convenient calculation
            k--;
            int d_index;
            // loop runs n times.
            while (!elements.empty()) {
                // factorial() is O(n) but can be made O(1) with a lookup table.
                int n_minus_1_factorial = factorial(n - 1);
                d_index = k / n_minus_1_factorial;
                k = k % n_minus_1_factorial;
                permutation.push_back('0' + elements[d_index]);
                // this is unfortunately O(n).
                // Is there a better data structure for this my use case?
                elements.erase(elements.begin() + d_index); 
                n--;
            }
            return permutation;
        }
};
