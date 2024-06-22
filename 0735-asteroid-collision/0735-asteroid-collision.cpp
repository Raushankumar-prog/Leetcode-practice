class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st1;
        stack<int> st2;

         reverse(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            st1.push(asteroids[i]);
        }

        while (!st1.empty()) {
            int topel = st1.top();
            st1.pop();
            bool bl = true;

            while (bl) {
                if (st2.empty()) {
                    st2.push(topel);
                    bl = false;
                } else {
                    int re = st2.top();
                    if (re>0 && topel < 0) { 
                        if (abs(re) > abs(topel)) {
                        
                            bl = false;
                            break;
                        } else if (abs(re) == abs(topel)) {
                            st2.pop();
                            bl = false;
                            break;
                        } else {
                            st2.pop();
                        }
                    } else {
                        st2.push(topel);
                        bl = false;
                    }
                }
            }
        }

        
        vector<int> result(st2.size());
        for (int i = st2.size() - 1; i >= 0; --i) {
            result[i] = st2.top();
            st2.pop();
        }
      
        return result;
    }
};
