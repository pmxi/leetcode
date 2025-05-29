class Solution {
    public:
        string defangIPaddr(string address) {
            string defanged = "";
            // three "." are replaced with "[.]" creating 6 extra chars.
            defanged.reserve(address.size() + 6);
            for (char c : address) {
                if (c == '.') {
                    defanged += "[.]";
                }
                else {
                    defanged += c;
                }
            }
            return defanged;
        }
};
