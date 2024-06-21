class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n=nums.size();
       vector<int>ans;
       nums.insert(nums.begin()+n,nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        bool bl=false;
           for(int j=i+1;j<nums.size();j++){
                 if(nums[j]>nums[i]){
                    ans.push_back(nums[j]);
                    bl=true;
                    break;
                 }
           }
           if(bl==false)ans.push_back(-1);
       } 
       return ans;
    }
};