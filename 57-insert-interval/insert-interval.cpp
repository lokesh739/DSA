class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> vt;
        int n = intervals.size();
        int i = 0;

        // Add intervals before the newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            vt.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        vt.push_back(newInterval);

        // Add remaining intervals
        while (i < n) {
            vt.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return vt;
    }
};
