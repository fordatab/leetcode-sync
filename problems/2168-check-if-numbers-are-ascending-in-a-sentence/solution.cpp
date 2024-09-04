class Solution {
public:
bool areNumbersAscending(string s) {
        istringstream ss(s);
        int l=0;
        string word;
        while(ss>>word){
            if(isdigit(word[0])){
                if(stoi(word)<=l)return false;
                l=stoi(word);
            }
        }
        return true;
    }
};