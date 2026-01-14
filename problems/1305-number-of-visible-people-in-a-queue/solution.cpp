class Solution {
public:
    void print_stack_popping(stack<int> s) { // Pass by value to work on a copy
        while (!s.empty()) {
            std::cout << s.top() << " ";
            s.pop();
        }
        std::cout << std::endl;
    }
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> out(n);
        stack<int> stk;
        for (int x = n - 1; x >= 0; x--) {
            // if (stk.size() and stk.top() > heights[x]) {
            //     cout << "a " << endl;
            //     out[x] = 1;
            // } else {
            int popped = 0;

            while (stk.size() and stk.top() < heights[x]) {
                stk.pop();
                out[x]++;
            }
            if (stk.size()) {
                out[x]++;
            } 
            // if (popped == 1) {
            //     out[x]--;
            // }
            // if popped = 
            // out[x] = popped ;

            // cout << "b " << endl;


            // }


            stk.push(heights[x]);
            // print_stack_popping(stk);
        }
        out[n-1] = 0;
        return out;
    }
};