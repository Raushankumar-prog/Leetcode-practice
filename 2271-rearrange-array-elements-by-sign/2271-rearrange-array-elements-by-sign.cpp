class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
          vector<int> a(n); 
        for(int i=0;i<n/2;i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
       return a;
    }
};