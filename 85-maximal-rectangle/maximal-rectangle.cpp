/*class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, heights[el] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int el = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, heights[el] * (nse - pse - 1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        int maxi = 0;

        vector<vector<int>> prefixsum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '0') {
                    sum = 0;
                } else {
                    sum += 1;
                }
                prefixsum[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, largestRectangleArea(prefixsum[i]));
        }

        return maxi;
    }
};
*/

class Solution {
public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> height(m,0);
        int maxsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            int area=largestRectangleArea(height);
            maxsum=max(area,maxsum);
        }
        return maxsum;
    }
};

