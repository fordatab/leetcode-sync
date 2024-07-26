/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

class Solution {
private:
    void s(pair<int, int>& p) {
        if (p.second == 1) {
            p.second = 0;
            p.first = 1;
        } else if (p.second == -1) {
            p.second = 0;
            p.first = -1;
        } else if (p.first == 1) {
            p.first = 0;
            p.second = -1;
        } else {
            p.first = 0;
            p.second = 1;
        }
    } 
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m, vector<int> (n, -1));  
        pair<int, int> dir = {0, 1};
        int i = 0;
        int j = 0;
        while (head) {
            // cout << i << " " << j << " " << dir.first << " " << dir.second<< endl ;
            v[i][j] = head->val;
            if (i + dir.first == m || j + dir.second == n || i + dir.first < 0 || j + dir.second < 0 || v[i+dir.first][j + dir.second] != -1) {
                // cout << " a" << endl;
                s(dir);
            }
            i += dir.first;
            j += dir.second;                   
            head = head->next;
        }
        return v;
    }
};