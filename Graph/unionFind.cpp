class Solution {
    class UnionFind{
        int num;
        int numComponents;
        vector<int> rank;
        vector<int> parent;
        public:
        UnionFind(int n){
            num = n; numComponents = n;
            rank = vector<int>(n, 0);
            parent = vector<int>(n);
            for(int i = 0; i<n; i++) parent[i] = i;
        }
        
        int size(){return num;}
        
        int components(){return numComponents;}
        
        int find(int p){
            while(p != parent[p]){
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }
        
        void unionn(int p, int q){
            int rootp = find(p); int rootq = find(q);
            if(rootp == rootq) return;
            if(rank[rootp] < rank[rootq]) parent[rootp] = rootq;
            else{
                parent[rootq] = rootp;
                if(rank[rootp] == rank[rootq]){rank[rootp]++;}
            }
            numComponents--;
        }
        
        int connected(int p, int q){
            return find(p) == find(q);
        }
        
    };
