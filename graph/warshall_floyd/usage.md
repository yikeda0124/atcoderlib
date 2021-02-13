初期化
`graph_wfd g(n+1);`

辺の追加
`g.add_edge(from, to, cost);`

グラフ上で頂点sからdijkstra
`g.dijkstra(s);`

頂点sからtまでの最短距離を出力
`cout << g.dist[s][t] << endl;`

頂点sからtまでの最短経路を復元
`vector<int> vec = g.get_path(s, t)`

g.dist[i][i]が負ならば負の閉路が存在

AC Code
http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5222140#1