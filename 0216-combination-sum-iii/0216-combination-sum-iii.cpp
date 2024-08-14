class Solution {
public:
    void combo(vector<int>& candidates, int remaining, vector<vector<int>>& st, vector<int>& vt, int start, int k) {
        if (remaining == 0 && vt.size() == k) {
            st.push_back(vt);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > remaining) {
                continue;
            }
            
            vt.push_back(candidates[i]);
            combo(candidates, remaining - candidates[i], st, vt, i + 1, k);
            vt.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> st;
        vector<int> vt;
        combo(candidates, n, st, vt, 0, k);
        return st;
    }
};
