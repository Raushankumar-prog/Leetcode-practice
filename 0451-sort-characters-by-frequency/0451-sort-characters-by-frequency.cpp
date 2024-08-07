class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }

       
        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : mpp) {
            maxHeap.push({entry.second, entry.first});
        }

        
        string result;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            result += string(top.first, top.second); 
        }

        return result;
    }
};
