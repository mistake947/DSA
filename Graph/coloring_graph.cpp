class Solution {
public:
  vector<int> vis, color;
  vector<vector<int>> g;
  bool dfs(int u, int currColor) {
    // vis karo and currColor assine karo
    vis[u] = 1;
    color[u] = currColor;

    for (auto v : g[u]) {
      if (vis[v] == 0) // agr child visited nahi hai to child ko vis karne  jao
                       // opposite color ke saah
      {
        // child agr nhi different color se color kar pata hai to return false;
        if (dfs(v, currColor ^ 1) == false)
          return false;
      }
      // agr child visited hai to child or parent ka color diffrent hona chaiye
      // agr same hai to color nahi kr paye return false
      if (vis[v] == 1 and color[u] == color[v])
        return false;
    }

    return true;
  }
  bool isBipartite(vector<vector<int>> &graph) {
    g = graph;
    int n = graph.size();
    vis.resize(n, 0);
    color.resize(n, 0);
    for (int u = 0; u < n; u++) {
      if (vis[u] == 0) {
        if (dfs(u, 0) == false)
          return false;
      }
    }
    return true;
  }
};