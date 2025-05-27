class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> s;
            for (auto a : asteroids) {
                if (a > 0) {
                    s.push_back(a);
                }
                else {
                    // consider a as the incoming asteroid, and the stack
                    // as the existing stable asteroid order.
                    while (1) {
                        if (s.empty()) {
                            s.push_back(a);
                            break;
                        }
                        // destroy incoming asteroid only
                        else if ((s.back() > 0) && (abs(s.back()) > abs(a))) {
                            break;
                        }
                        // destroy existing asteroid
                        else if ((s.back() > 0) && (abs(s.back()) < abs(a))) {
                            s.pop_back();
                        }
                        // mad, destroy existing and incoming asteroid.
                        else if ((s.back() > 0) && (abs(s.back()) == abs(a))) {
                            s.pop_back();
                            break;
                        }
                        // existing is negative, no destruction
                        // incoming will live peacefully
                        else {
                            s.push_back(a);
                            break;
                        }
                    }
                }
            }
            return s;
        }
};

