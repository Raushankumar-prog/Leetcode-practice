class Solution {
public:
    bool checkSort(vector<int>& nums, int start, int n){
        int i = start;
        int j = (i+1)%n;
        int counter = 0;
        bool ans = true;
        while(counter < n-1){
            if(nums[i] > nums[j]){
                ans = false;
                break;
            }
            i = (i+1)%n;
            j = (j+1)%n;
            counter++;
        }
        return ans;
    }
    
    bool check(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(checkSort(nums, i, n)){
                return true;
            }
        }

        return false;
    }
};