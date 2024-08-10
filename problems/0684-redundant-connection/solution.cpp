class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> parents(n);
        vector<int> ranks(n, 1);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        int result = n;
        for (auto e : edges) {
            if (!doUnion(parents, ranks, e[0], e[1])) {
                return e;
            }
        }
        return {};
    }
private:
    int doFind(vector<int>& parents, int n) {
        int p = parents[n];
        while (p != parents[p]) {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }
    
    bool doUnion(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
        int p1 = doFind(parents, n1);
        int p2 = doFind(parents, n2);
        if (p1 == p2) {
            return false;
        }
        
        if (ranks[p1] > ranks[p2]) {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        } else {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        
        return true;
    }
};