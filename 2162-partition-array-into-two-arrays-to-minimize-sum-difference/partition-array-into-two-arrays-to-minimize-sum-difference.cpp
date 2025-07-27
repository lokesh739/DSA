class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // map: subset size -> all possible sums
        unordered_map<int, vector<int>> leftMap, rightMap;

        // generate all subset sums for left side
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, count = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    count++;
                }
            }
            leftMap[count].push_back(sum);
        }

        // generate all subset sums for right side
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, count = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    count++;
                }
            }
            rightMap[count].push_back(sum);
        }

        // sort all rightMap vectors for binary search
        for (auto &[k, vec] : rightMap) {
            sort(vec.begin(), vec.end());
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        // try combining all (i, n - i) subsets from left/right
        for (int i = 0; i <= n; i++) {
            for (int a : leftMap[i]) {
                int target = totalSum / 2 - a;
                const auto& vec = rightMap[n - i];
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sum1 = a + *it;
                    int sum2 = totalSum - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }
                if (it != vec.begin()) {
                    --it;
                    int sum1 = a + *it;
                    int sum2 = totalSum - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }

        return ans;
    }
};
