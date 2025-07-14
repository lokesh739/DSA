class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        // Min-heap: {time_so_far, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int node = it.second;

            if (time > dist[node]) continue;  // we already have a better path

            for (auto iter : adj[node]) {
                int adjnode = iter.first;
                int weight = iter.second;

                if (time + weight < dist[adjnode]) {
                    dist[adjnode] = time + weight;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;  // unreachable node
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
