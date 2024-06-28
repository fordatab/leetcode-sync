class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto a : nums) {
            set.insert(a);
        }


        int out = 0;
        while (!set.empty()) {
            auto curr_itr = set.begin();
            cout << *curr_itr << endl;
            int count = 0;
            if (curr_itr != set.end()) {
                int curr = *curr_itr;
                set.erase(curr);
                while (set.find(++curr) != set.end()) {
                    count++;
                    set.erase(curr);
                }
                curr -= count + 1;
                while (set.find(--curr) != set.end()) {
                    count++;
                    set.erase(curr);
                }
                count++;
            }
            out = max(count, out);
        }
        return out;
        
    }
};
