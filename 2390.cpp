// This is optimal asymptotic but is slow.
// a more manual approach with pointers will be much better.


class Solution {
public:
    string removeStars(string s) {
        string result = "";
        for (char c : s) {
            if (c == '*') {
                result.pop_back();
            }
            else {
                result.push_back(c);
            }
        }
        return result;
    }
};
