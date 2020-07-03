stack<int> s;
MinStack::MinStack() {
    while(!s.empty())
        s.pop();
}

void MinStack::push(int x) {
    if(s.empty())
    {
        s.push(x);
        s.push(x);
        return;
    }
    int mine = s.top();
    mine = min(mine,x);
    s.push(x);
    s.push(mine);
}

void MinStack::pop() {
    if(!s.empty())
    {
        s.pop();
        s.pop();
    }
}

int MinStack::top() {
    if(s.empty())
        return -1;
    int x = s.top();
    s.pop();
    int y = s.top();
    s.push(x);
    return y;
}

int MinStack::getMin() {
    if(s.empty())
        return -1;
    return s.top();
}

