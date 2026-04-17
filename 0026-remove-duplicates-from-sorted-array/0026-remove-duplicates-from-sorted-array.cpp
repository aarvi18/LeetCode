class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int high = low + 1;
        int k = 1;
        int n = nums.size();

        while(high<n) {
            if(nums[high] == nums[high-1]){
                high++;
                continue;
            }
            nums[low+1] = nums[high];
            low++;
            k++;
            high++;
        }
        return k;
    }
};