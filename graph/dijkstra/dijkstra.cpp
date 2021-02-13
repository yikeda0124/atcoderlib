struct edge{
    ll to, cost;
};

struct graph_dij{
    int V;
    vector<vector<edge>> G;
    vector<int> prev;
    vector<ll> dist;

    graph_dij(ll n){
        V = n;
        G.resize(V);
        dist.resize(V);
        prev.resize(V, -1);
        for (int i = 0; i < V; i++){
            dist[i] = LLINF;
        }
    }

    void add_edge(int s, int t, ll cost){
        edge e = {t, cost};
        G[s].push_back(e);
    }

    void dijkstra(int s){
        for (int i = 0; i < V; i++){
            dist[i] = LLINF;
        }
        priority_queue<pint, vector<pint>, greater<pint>> que;
       	dist[s] = 0;
        que.push({0, s});
        while(!que.empty()){
            auto p = que.top();
            que.pop();
            if (dist[p.second] < p.first) continue;
            for (auto e : G[p.second]){
                if (dist[e.to] > p.first + e.cost){
                    dist[e.to] = p.first + e.cost;
                    prev[e.to] = p.second;
                    que.push({dist[e.to], e.to});
                }   
            }
        }
    }

    vector<int> get_path(int s, int t){
        vector<int> path;
        for (int now = t; now != -1; now = prev[now]){
            path.push_back(now);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};