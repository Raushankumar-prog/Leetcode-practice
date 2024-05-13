class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countprevious=0;
        int next=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                next++;
            }
            else{
                if(countprevious<next){
                countprevious=next;
                }
                next=0;

            }
             if (next > countprevious) {
            countprevious = next;
        }

        }
        return countprevious;
    }
};