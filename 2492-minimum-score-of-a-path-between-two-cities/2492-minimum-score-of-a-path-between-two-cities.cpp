class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;
    int ans = INT_MAX;

    void dfs(int u){
        vis[u] = 1;

        for(auto [v,w] : adj[u]){
            ans = min(ans, w);
            if(!vis[v]) dfs(v);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        vis.assign(n + 1, 0);

        for(auto &e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        dfs(1);

        return ans;
    }
};