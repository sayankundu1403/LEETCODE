class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n,0);
        vector<int> vals;

        for(auto &e: edges){
            adj[e[0]].push_back({e[1],e[2]});
            indeg[e[1]]++;
            vals.push_back(e[2]);
        }

        // Topological order
        queue<int> q;
        vector<int> topo;
        vector<int> deg = indeg;

        for(int i=0;i<n;i++)
            if(deg[i]==0) q.push(i);

        while(!q.empty()){
            int u=q.front(); q.pop();
            topo.push_back(u);
            for(auto &[v,c]:adj[u]){
                if(--deg[v]==0)
                    q.push(v);
            }
        }

        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());

        auto check=[&](int lim)->bool{
            const long long INF = (1LL<<60);
            vector<long long> dist(n,INF);
            dist[0]=0;

            for(int u:topo){
                if(dist[u]==INF) continue;

                if(u!=0 && u!=n-1 && !online[u]) continue;

                for(auto &[v,w]:adj[u]){
                    if(w<lim) continue;
                    if(v!=0 && v!=n-1 && !online[v]) continue;

                    dist[v]=min(dist[v],dist[u]+(long long)w);
                }
            }

            return dist[n-1]<=k;
        };

        int l=0,r=(int)vals.size()-1;
        int ans=-1;

        while(l<=r){
            int mid=(l+r)/2;
            if(check(vals[mid])){
                ans=vals[mid];
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        return ans;
    }
};