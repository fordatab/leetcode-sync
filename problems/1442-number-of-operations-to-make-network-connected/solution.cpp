class Solution {
public:
    struct DSU {
        vector<int> p, r;
        DSU(int n): p(n), r(n,0) { iota(p.begin(), p.end(), 0); }
        int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
        void unite(int a,int b){
            a=find(a); b=find(b);
            if(a==b) return;
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        if ((int)connections.size() < n - 1) return -1;

        DSU dsu(n);
        for (auto &e : connections) dsu.unite(e[0], e[1]);

        int comps = 0;
        for (int i = 0; i < n; i++) if (dsu.find(i) == i) comps++;
        return comps - 1;
    }
};