struct graph_wsf{
    int V;
    vector<vector<ll>> dist;
    vector<vector<int>> prev;

    graph_wsf(int n){
        V = n;
        dist.resize(V);
        prev.resize(V);
        for (int i = 0; i < V; i++){
            dist[i].resize(V);
            prev[i].resize(V);
        }
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = LLINF;
                prev[i][j] = i;
            }
        }
    }

    void add_edge(int s, int t, ll cost){
        dist[s][t] = cost;
    }

    void warshall_floyd(){
        for (int k = 0; k < V; k++){
            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    if (dist[i][k] == LLINF || dist[k][j] == LLINF) continue;
                    if (dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        prev[i][j] = prev[k][j];
                    }
                }
            }
        }
    }

    vector<int> get_path(int s, int t){
        vector<int> path;
        for (int now = t; now != s; now = prev[s][now]){
            path.push_back(now);
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        return path;
    }
};