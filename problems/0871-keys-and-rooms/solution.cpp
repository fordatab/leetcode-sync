class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> v(rooms.size());
        v[0] = true;
        dfs(rooms, 0, v);
        for (auto a : v) {
            if (!a) {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, int x, vector<bool>& v) {
        for (int a : rooms[x]) {
            if (!v[a]) {
                v[a] = true;
                dfs(rooms, a, v);
            }
        }
    }
};