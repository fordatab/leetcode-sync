class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node* root = new Node(1, true);
        dfs(root, grid, grid.size(), 0, 0);
        return root;
    }

    void dfs(Node*& root, vector<vector<int>>& grid, int sz, int i, int j) {
        int g = grid[i][j];
        root->val = g;
        if (sz == 1) {
            return;
        }
        bool uniform = true;
        for (int x = i; x < i + sz; x++) {
            for (int y = j; y < j + sz; y++) {
                if (grid[x][y] != g) {
                    uniform = false;
                    break;
                }
            }
            if (!uniform) {
                break;
            }
        }

        if (uniform) {
            return;
        }

        int nsz = sz/2;
        root->isLeaf = false;
        root->topLeft = new Node(g, true);
        root->topRight = new Node(g, true);
        root->bottomLeft = new Node(g, true);
        root->bottomRight = new Node(g, true);
        dfs(root->topLeft, grid, nsz, i, j);
        dfs(root->topRight, grid, nsz, i, j + nsz);  // Fixed: j + nsz instead of j
        dfs(root->bottomLeft, grid, nsz, i + nsz, j);  // Fixed: i + nsz instead of i
        dfs(root->bottomRight, grid, nsz, i + nsz, j + nsz);
    }
};