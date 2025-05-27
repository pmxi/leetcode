class Solution {
    public:
        string predictPartyVictory(string senate) {

            // Prepare queues.
            queue<int> R;
            queue<int> D;
            for (size_t i = 0; i < senate.size(); i++) {
                if (senate[i] == 'R') {
                    R.push(i);
                }
                // senator is D.
                else {
                    D.push(i);
                }
            }

            // Simulate.
            int r, d;
            while (1) {
                if (R.empty()) {
                    return "Dire";
                }
                else if (D.empty()) {
                    return "Radiant";
                }
                r = R.front(); R.pop();
                d = D.front(); D.pop();
                // ban D ; reschedule R
                if (r < d) {
                    R.push(r + senate.size());
                }
                // ban R ; reschedule D
                else {
                    D.push(d + senate.size());
                }
            }
            return "failed";
        }
};
