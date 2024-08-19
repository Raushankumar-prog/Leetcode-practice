class Solution {
    private:
       int solve(vector<int>& nums,int k){
         int l=0,r=0;
         int zeroes=0;
         int maxi=INT_MIN;
         int lne=0;
     while(r<nums.size()){
        if(nums[r]==0) zeroes++;
          while(zeroes>k){
        if(nums[l]==0){
            zeroes--;
        }
        l++;
     }

     if(zeroes<=k){
        lne=r-l+1;
     }
     maxi=max(lne,maxi);
    r++;
       }
       return maxi;
       }


public:
    int longestOnes(vector<int>& nums, int k) {
        return solve(nums,k);
    }
};