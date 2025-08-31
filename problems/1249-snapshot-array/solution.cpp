class SnapshotArray {
public:
    int snaps = 0;
    vector<vector<pair<int, int>>> changes; 
    
    SnapshotArray(int length) {
        changes = vector<vector<pair<int, int>>>(length);
        // Initialize each index with value 0 at snap_id -1 (before any snapshots)
        for (int i = 0; i < length; i++) {
            changes[i].push_back({-1, 0});
        }
    }
    
    void set(int index, int val) {
        auto &vec = changes[index];
        // If the last change was in the current snapshot, update it
        if (!vec.empty() && vec.back().first == snaps) {
            vec.back().second = val;
        } else {
            // Otherwise, add a new change for the current snapshot
            vec.push_back({snaps, val});
        }
    }
    
    int snap() {
        return snaps++;
    }
    
    int get(int index, int snap_id) {
        auto &vec = changes[index];
        // Find the last change with snap_id <= requested snap_id
        auto it = upper_bound(vec.begin(), vec.end(), make_pair(snap_id, INT_MAX));
        --it;
        return it->second;
    }
};