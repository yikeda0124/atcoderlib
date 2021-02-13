struct graph_wsf{
    ll V;
    vector<vector<ll>> dist;

    graph_wsf(ll n){
        V = n;
        dist.resize(V);
        for (int i = 0; i < V; i++){
            dist[i].resize(V);
        }
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = LLINF;
            }
        }
    }

    void add_edge(ll s, ll t, ll cost){
        dist[s][t] = cost;
    }

    void warshall_floyd(){
        for (int k = 0; k < V; k++){
            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    if (dist[i][k] == LLINF || dist[k][j] == LLINF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};