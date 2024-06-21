class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
         for(int i=0;i<nums1.size();i++){
            int n=nums1[i];
            int index=INT_MAX;
            bool bl=false;
            for(int j=0;j<nums2.size();j++){

                if(n==nums2[j]){
                    index=j;
                }
                if(j>index && n<nums2[j]){
                    bl=true;
                    ans.push_back(nums2[j]);
                     break;
                }
             
                
            }
               if(bl==false)ans.push_back(-1);
         }
         return ans;
    }
};