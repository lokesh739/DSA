#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});

        int mod = 1e9+7;

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();


            for (auto& [adjnode, weight] : adj[node]) {
                if (d + weight < dist[adjnode]) {
                    dist[adjnode] = d + weight;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                else if (d + weight == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
