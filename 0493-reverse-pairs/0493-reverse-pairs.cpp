class Solution {
public:
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp(high - low + 1); 
        int left = low;      
        int right = mid + 1;   
        int k = 0; 
        long long cnt = 0;

        // Count reverse pairs
        for (int i = low; i <= mid; ++i) {
            while (right <= high && arr[i] > 2LL * arr[right]) {  // Use 2LL to avoid overflow
                ++right;
            }
            cnt += (right - (mid + 1));
        }

        left = low;
        right = mid + 1;

        // Merge the two halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];
            } else {
                temp[k++] = arr[right++];
            }
        }

        while (left <= mid) {
            temp[k++] = arr[left++];
        }

        while (right <= high) {
            temp[k++] = arr[right++];
        }

        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            cnt += mergeSort(arr, low, mid);  
            cnt += mergeSort(arr, mid + 1, high); 
            cnt += merge(arr, low, mid, high);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};
