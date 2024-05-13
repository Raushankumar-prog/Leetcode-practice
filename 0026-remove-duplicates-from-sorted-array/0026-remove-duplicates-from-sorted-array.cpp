class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        
        for (auto j = nums.begin() + 1; j != nums.end(); ++j) {
            if (nums[i] != *j) {
                ++i;
                nums[i] = *j;
            }
        }
        return i + 1;
    }
};
