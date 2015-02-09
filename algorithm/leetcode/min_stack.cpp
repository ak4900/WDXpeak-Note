class MinStack {
public:
    void push(int x) {
        elements.push(x);
        if (mins.empty()||x<=mins.top())
            mins.push(x);
    }

    void pop() {
        if (elements.empty()) return;
        if (elements.top() == mins.top())
            mins.pop();
        elements.pop();
    }

    int top() {
        return elements.top();
    }

    int getMin() {
        return mins.top();
    }
private:
    stack<int> elements;
    stack<int> mins;
};