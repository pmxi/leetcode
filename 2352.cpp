// time: average case O(n^2)
// alg
// let rowBag be a bag indexed over the relevant vector space.
// for each row in grid           O(n)
//   rowBag.add(row)              O(1)
// let pairs = 0
// for column in grid              O(n)
//   if (rowBag.contains(column)) O(1)
//     pairs += rowBag.count(column)   O(1)
//  

#include <vector>
#include <unordered_map>

struct VecHash {
    size_t operator()(const vector<int>& v) const noexcept {
        // simple rolling‐hash
        size_t h = v.size();
        for (int x : v) {
            h = h * 31 + hash<int>()(x);
        }
        return h;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<vector<int>, int, VecHash> rowBag;
        for (auto& row : grid) {
            rowBag[row]++;
        }

        int pairs = 0;
        vector<int> col(n);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                col[i] = grid[i][j];
            }
            auto it = rowBag.find(col);
            if (it != rowBag.end()) {
                pairs += it->second;
            }
        }
        return pairs;
    }
};
