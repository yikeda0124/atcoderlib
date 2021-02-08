初期化
`graph_dij g(n+1);`

辺の追加
`g.add_edge(from, to, cost);`

グラフ上で頂点sからdijkstra
`g.dijkstra(s);`

頂点sからtまでの最短距離を出力
`cout << g.dist[t] << endl;`