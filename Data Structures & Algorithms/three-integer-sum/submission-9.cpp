class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{};
        for (int num: nums) {
            cout << num << " ";
        }

        for (int i{}; i < nums.size(); ++i) {
            if (i > 0 && (nums[i] == nums[i-1])) continue;
            int target{-nums[i]};
            int left{i+1};
            int right{static_cast<int>(nums.size()) - 1};
            bool found{};
            vector<pair<int, int>> stuff{};
            while ((left < right) && (left > i)) {
                int sum{nums[left] + nums[right]};
                if (sum == target) {
                    found = true;
                    stuff.push_back({nums[left], nums[right]});
                    ++left;
                    --right;
                    while ((left < right) && (nums[left] == nums[left-1])) {
                        ++left;
                    }
                     while ((left < right) && (nums[right] == nums[right+1])) {
                        --right;
                    }
                }
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    right --;
                }
            }
            
            if (!found) continue;
            for (const auto& thing: stuff) {
                result.push_back(vector<int>{nums[i], thing.first, thing.second});
            }
            
        }
        return result;
    }
};
