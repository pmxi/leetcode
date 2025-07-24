#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> groups;
        for (std::size_t i = 0; i < s.size(); i += k) {
            // grab up to k chars
            std::string part = s.substr(i, k);
            // need padding?
            if (part.size() < static_cast<std::size_t>(k))
                // pad with fill char
                part.append(k - part.size(), fill);
            // TODO need to understand this better
            groups.emplace_back(std::move(part));
        }
        return groups;
    }
};
