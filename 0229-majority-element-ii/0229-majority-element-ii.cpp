class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umpp;
    for (int i = 0; i < nums.size(); i++) {
        umpp[nums[i]]++;
    }
    vector<int> v;
    for (auto it : umpp) {  
        if (it.second > nums.size() / 3) { 
             v.push_back(it.first); 
        }
    }
    return v; 
    }
};