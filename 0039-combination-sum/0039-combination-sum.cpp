
class Solution {
public:
    void combo(vector<int>& candidates, int target, int remaining,vector<vector<int>>& st, vector<int>& vt, int start) {
        if (remaining == 0) {
            vector<int> combination(vt);
            sort(combination.begin(), combination.end());
            st.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > remaining) {
                continue;
            }
            
            vt.push_back(candidates[i]);
            combo(candidates, target, remaining - candidates[i], st, vt, i);
            vt.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> st;
        vector<int> vt;
        combo(candidates, target, target, st, vt, 0);
        
    
        
        return st;
    }
};
