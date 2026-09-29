class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount{};
        for (auto num: nums) {
            numCount[num] += 1;
        }
        vector<vector<int>> bucketCount(nums.size()+1);
        for (const auto& [key, value]: numCount) {
            // cout << key << " | " << value << '\n';
            bucketCount[value].push_back(key);
        }
        
        vector<int> result(k);
        int currIndex {};
        for (auto i{ ssize(nums) }; i>= 0; --i) {
            for (int j{}; j < bucketCount[i].size(); ++j) {
                if (currIndex == k) return result;
                // cout << "currIndex: " << currIndex << "\n";
                // cout << "i: " << i << "\n";
                // cout << "j: " << j << "\n";
                // cout << "bucketCount[i][j]: " << bucketCount[i][j]<< "\n";
                result[currIndex] = bucketCount[i][j]; 
                ++currIndex;
            }
        }
        return result;
    }
};
