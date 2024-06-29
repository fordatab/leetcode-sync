class Solution {
public:

    static bool sortByFirst(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int, int>> stack;

        vector<pair<int, int>> cars(position.size());
        for (int x = 0; x < position.size(); x++) {
            cars[x] = {position[x], speed[x]};
        }

        sort(cars.begin(), cars.end(), sortByFirst);

        for (auto a : cars) {
            if (!stack.empty()) {
                double t1 = (target - a.first)/(double)a.second;
                double t2 = (target - stack.top().first)/(double)stack.top().second;
                if (t1 > t2) {
                    stack.push({a.first, a.second});
                }
            } else {
                stack.push({a.first, a.second});
            }
        }

       


        return stack.size();
        






        


    }
};
