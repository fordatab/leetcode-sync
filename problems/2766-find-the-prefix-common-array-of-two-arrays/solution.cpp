class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> ctA;
        unordered_set<int> ctB;
        int n = A.size();
        int ct = 0;
        vector<int> out(n);
        for (int i = 0; i < n; i++) {
            ctA.insert(A[i]);
            ctB.insert(B[i]);
            if (ctA.find(B[i]) != ctA.end()) {
                ct++;
            }
            if (ctB.find(A[i]) != ctB.end()) {
                ct++;
            }
            if (A[i] == B[i]) {
                ct--;
            }
            out[i] = ct;
        }
        return out;
    }
};