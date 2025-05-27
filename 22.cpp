
// this is just a depth-first search

class Solution {
    private:
        void backtrack(int n, string& cur, int open, int close,
                vector<string>& out) {
            if ((open == n) && (close == n)) {
                // valid string
                out.push_back(cur);
            }
            if (open < n) {
                cur.push_back('(');
                backtrack(n, cur, open+1, close, out);
                cur.pop_back();
            }
            if (close < open) {
                cur.push_back(')');
                backtrack(n, cur, open, close+1, out);
                cur.pop_back();
            }
        }
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            string cur;
            cur.reserve(2*n);
            backtrack(n, cur, 0, 0, result);
            return result;
        }
};

// grammar
// S -> S S
// P -> ( P )
// P -> empty
