class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0; 
        auto it = nums.begin();
        while (it != nums.end()) {
            if (*it == 0) {
                it = nums.erase(it);
                count++; 
            } else {
                it++; 
            }
        }
        
 
        nums.insert(nums.end(), count, 0);
    }
};
