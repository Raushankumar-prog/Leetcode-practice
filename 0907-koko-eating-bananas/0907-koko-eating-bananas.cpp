#include <vector>
#include <algorithm> // for max_element

class Solution {
public:
    
    long long kokoeatingspeed(vector<int>& piles, int speed) {
        long long timetaken = 0;
        for (int pile : piles) {
          
            timetaken += (pile + speed - 1) / speed;
        }
        return timetaken;
    }
int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long timetaken = kokoeatingspeed(piles, mid);

            if (timetaken <= h) {
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        return low; 
    }
};
