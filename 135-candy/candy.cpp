class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int peak = 1;
        int down = 0;
        int sum = 1;
        int i = 1;

        while(i < n) {
            if(ratings[i] == ratings[i - 1]) {
                // reset for a new flat segment
                peak = 1;
                down = 0;
                sum = sum + 1;
                i++;
                continue;
            }

            // increasing slope
            peak = 1;
            while(i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum = sum + peak;
                i++;
            }

            // decreasing slope
            down = 0;
            while(i < n && ratings[i] < ratings[i - 1]) {
                down++;
                sum = sum + down;
                i++;
            }

            // if down > peak, we must compensate since peak element was counted only once
            if(down >= peak) {
                sum += (down - peak + 1);
            }
        }

        return sum;
    }
};
