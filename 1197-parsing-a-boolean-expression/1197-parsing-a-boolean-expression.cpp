class Solution {
    void fucc(stack<char>& op, stack<char>& opr) {
        char top = op.top();  
        op.pop();           

        bool ans;

        if (top == '|') {
            ans = false;
            while (opr.top() != '(') {
                ans |= (opr.top() == 't');
                opr.pop();
            }
            opr.pop(); 
        } 
        else if (top == '&') {
            ans = true; 
            while (opr.top() != '(') {
                ans &= (opr.top() == 't');
                opr.pop();
            }
            opr.pop(); 
        } 
        else if (top == '!') {
            ans = (opr.top() == 't');
            ans = !ans;   
            opr.pop();  
            opr.pop(); 
        }

        if (ans) opr.push('t');  
        else     opr.push('f');  
    }

public:
    bool parseBoolExpr(string s) {
        stack<char> optr, opr;
        int idx = 0;

        while (s[idx]) {
            if (s[idx] == '!' || s[idx] == '&' || s[idx] == '|') {
                optr.push(s[idx]); 
            } 
            else if (s[idx] == 't' || s[idx] == 'f') {
                opr.push(s[idx]);
            } 
            else if (s[idx] == '(') {
                opr.push(s[idx]); 
            } 
            else if (s[idx] == ')') {
                fucc(optr, opr);  
            }
            idx++;
        }
        return opr.top() == 't';  
    }
};