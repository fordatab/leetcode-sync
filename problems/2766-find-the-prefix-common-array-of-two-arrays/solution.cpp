class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> out(n);
        unordered_set<int> ct;
        for (int i = 0; i < n; i++) {
            ct.insert(A[i]);
            for (int j = 0; j <= i; j++) {
                if (ct.find(B[j]) != ct.end()) {
                    out[i]++;
                }
            }
        }
        return out;
    }
};