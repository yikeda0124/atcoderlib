struct edge{
    ll to, cost;
};

struct graph_dij{
    ll V;
    vector<vector<edge>> G;
    vector<ll> dist;

    graph_dij(ll n){
        V = n;
        G.resize(V);
        dist.resize(V);
        for (int i = 0; i < V; i++){
            dist[i] = LLINF;
        }
    }

    void add_edge(ll s, ll t, ll cost){
        edge e = {t, cost};
        G[s].push_back(e);
    }

    void dijkstra(ll s){
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
                    que.push({dist[e.to], e.to});
                }   
            }
        }
    }
};