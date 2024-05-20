class Solution {
public:
    int findMin(vector<int>& nums) {
       int n=nums.size();
        int low=0;
        int high=n-1;
        int target=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
           
            if(nums[mid]<=nums[high]){
                  if(nums[mid]<=target & target<=nums[high] ){
                    if(target>nums[mid]){
                         target=nums[mid];
                    }
                   
                    low=mid+1;
                  }else{
                     if(target>nums[mid]){
                         target=nums[mid];
                    }
                    high=mid-1;
                  }
            }
            else{
                   if(nums[mid]>=target & target>=nums[low] ){
                       if(target>nums[mid]){
                         target=nums[mid];
                    }
                    high=mid-1;
                  }else{
                      if(target>nums[mid]){
                         target=nums[mid];
                    }
                    low=mid+1;
                  }
            }
        }
        return target;
    } 
};