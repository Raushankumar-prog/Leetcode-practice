class Solution {
public:
   
    int countSubarraysWithAtMostKOddNumbers(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int count = 0;
        int oddCount = 0;

        while (j < nums.size()) {
            
            if (nums[j] % 2 != 0) oddCount++;

            
            while (oddCount > k) {
                if (nums[i] % 2 != 0) oddCount--;
                i++;
            }

            
            count += (j - i + 1);

          
            j++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
    
        return countSubarraysWithAtMostKOddNumbers(nums, k) - countSubarraysWithAtMostKOddNumbers(nums, k - 1);
    }
};
