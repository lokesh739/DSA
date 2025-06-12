class Solution {
public:
    int sumlessthangoal(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        while (r < n) {
            sum = sum + nums[r];
            while (l <= r && sum > goal) {
                sum = sum - nums[l];
                l = l + 1;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    int sumlessthangoalminusone(vector<int>& nums, int goal) {
        if (goal <= 0) return 0; // ✅ Avoid negative goal - 1 (important!)
        int n = nums.size();
        int count = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        while (r < n) {
            sum = sum + nums[r];
            while (l <= r && sum > goal - 1) {
                sum = sum - nums[l];
                l = l + 1;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumlessthangoal(nums, goal) - sumlessthangoalminusone(nums, goal);
    }
};
