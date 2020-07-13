int minEle;
stack<int> stk;

MinStack::MinStack() {
    minEle = INT_MAX;
    stk=stack<int>();
}

void MinStack::push(int x) {
    if(stk.empty() || x>=minEle){
        if(stk.empty()) minEle=x;
        stk.push(x);
    }
    else {
        stk.push(2*x-minEle);
        minEle=x;
    }
}

void MinStack::pop() {
    if(!stk.empty()){
        if(stk.top()>=minEle) stk.pop();
        else{
            minEle=2*minEle-stk.top();
            stk.pop();
        }
    }
}

int MinStack::top() {
    if(stk.empty()) return -1;
    if(stk.top()>=minEle) return stk.top();
    else return minEle;
}

int MinStack::getMin() {
    if(stk.empty()) return -1;
    return minEle;
}

