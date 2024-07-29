class Solution {

public:
int binary_search(vector<int>&nums,int low, int high,int target){   
       if (low > high) return -1;  
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(target<nums[mid]) return binary_search(nums,low,mid-1,target);
        else return binary_search(nums,mid+1,high,target);

}

public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        return  binary_search(nums,low,high,target);
    
}

};