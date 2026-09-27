class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> keyMap{};
        for (int i{}; i < nums.size(); ++i) {
            int compliment {target-nums[i]};
            if (keyMap.contains(compliment)) {
                int compI = keyMap[compliment];
                return (compI < i) ? vector<int>{compI, i} : vector<int>{i, compI};
            }
            keyMap[nums[i]] = i;
        }
    }
};
