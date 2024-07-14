class Solution {
public:
    int rec(int m_f, int m_t, int n_f, int n_t, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // cout << m_f << " " << m_t << " " << n_f << " " <<n_t << endl;
        if (m_t - m_f == 1 && n_t - n_f == 1) {
            return 0;
        } 
        if (m_t - m_f == 1) {
            vector<int> a(verticalCut.begin()+n_f, verticalCut.begin()+n_t-1);
            int total = accumulate(begin(a), end(a), 0, plus<int>());
            return total;
        }
        if (n_t - n_f == 1) {
            vector<int> a(horizontalCut.begin()+m_f, horizontalCut.begin()+m_t-1);
            int total = accumulate(begin(a), end(a), 0, plus<int>());
            return total;
        }
        bool y = true;
        int index = 0;
        int m = 0;
        for (int x = m_f; x < m_t-1; x++) {
            if (horizontalCut[x] > m) {
                m = horizontalCut[x];
                index = x;
            }
        }
        for (int x = n_f; x < n_t-1; x++) {
            if (verticalCut[x] > m) {
                y = false;
                m = verticalCut[x];
                index = x;
            }
        }
        if (y) {
            return m + rec(m_f, index+1, n_f, n_t, horizontalCut, verticalCut) + rec(index+1, m_t, n_f, n_t, horizontalCut, verticalCut);
        } else {
            return m + rec(m_f, m_t, n_f, index+1, horizontalCut, verticalCut) + rec(m_f, m_t, index+1, n_t, horizontalCut, verticalCut);
        }


    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        cout << m << " " << n << endl;
        return rec(0, m, 0, n, horizontalCut, verticalCut);
    }
};