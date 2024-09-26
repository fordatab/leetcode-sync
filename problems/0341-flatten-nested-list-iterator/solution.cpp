class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1;i>=0;i--) stk.push(&nestedList[i]);
    }
    int next() {
        int nxt = stk.top()->getInteger();
        stk.pop();
        return nxt;
    }
    bool hasNext() {
        while(!stk.empty()) {
            NestedInteger *p = stk.top();
            if(p->isInteger()) return 1;
            vector<NestedInteger> &vec = p->getList();
            stk.pop();
            for(int i=vec.size()-1;i>=0;i--) stk.push(&vec[i]);
        }
        return 0;
    }
private:
    stack<NestedInteger*> stk;
};