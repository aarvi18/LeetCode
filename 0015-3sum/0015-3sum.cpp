class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n - 2) {
            int a = nums[i], l = i + 1, r = n - 1;
            while (l < r) {
                int b = nums[l], c = nums[r], sum = a + b + c;
                if (sum == 0)
                    res.push_back({a, b, c});
                if (sum <= 0) {
                    while (l < r && nums[l] == b)
                        ++l;
                }
                if (sum >= 0) {
                    while (l < r && nums[r] == c)
                        --r;
                }
            }
            while (i < n - 2 && nums[i] == a)
                ++i;
        }
        return res;
    }
};