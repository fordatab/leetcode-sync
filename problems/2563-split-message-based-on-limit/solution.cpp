class Solution {
public:
    int digits(int x) {
        return to_string(x).size();
    }

    vector<string> splitMessage(string message, int limit) {
        int n = message.size();

        for (int parts = 1; parts <= n; parts++) {
            int d = digits(parts);
            long long total = 0;
            bool ok = true;

            // group by digit length of i
            for (int k = 1; k <= d; k++) {
                int lo = (k == 1 ? 1 : pow(10, k-1));
                int hi = min(parts, (int)pow(10, k) - 1);
                if (hi < lo) continue;

                int cnt = hi - lo + 1;
                int suffixLen = 3 + k + d;
                int capacity = limit - suffixLen;

                if (capacity <= 0) { ok = false; break; }
                total += 1LL * cnt * capacity;
            }

            if (!ok) continue;
            if (total < n) continue;

            // reconstruct
            vector<string> res;
            int idx = 0;
            for (int i = 1; i <= parts; i++) {
                int suffixLen = 3 + digits(i) + d;
                int capacity = limit - suffixLen;
                int take = min(capacity, n - idx);
                string chunk = message.substr(idx, take);
                idx += take;
                chunk += "<" + to_string(i) + "/" + to_string(parts) + ">";
                res.push_back(chunk);
            }
            return res;
        }

        return {};
    }
};
