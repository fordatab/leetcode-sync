class Solution {
public:
    int minFlips(string target) {
        int out = 0;
        char current_state = '0'; // Initially, all characters are '0'
        
        for (int i = 0; i < target.size(); i++) {
            // When the target character differs from our current state, we must flip
            if (target[i] != current_state) {
                out++;
                current_state = target[i]; // Update the state of the remaining suffix
            }
        }
        
        return out;
    }
};