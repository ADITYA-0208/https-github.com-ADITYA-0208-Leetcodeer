class Solution {
public:
    int solveab(string s, int x, int y) {
        stack<char> st;
        int sum = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                sum += x;
            } else {
                st.push(c);
            }
        }
        string rem = "";
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        for (char c : rem) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                sum += y;
            } else {
                st.push(c);
            }
        }

        return sum;
    }

    int solveba(string s, int x, int y) {
        stack<char> st;
        int sum = 0;
        for (char c : s) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                sum += y;
            } else {
                st.push(c);
            }
        }
        string rem = "";
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        for (char c : rem) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                sum += x;
            } else {
                st.push(c);
            }
        }

        return sum;
    }

    int maximumGain(string s, int x, int y) {
        if (x >= y)
            return solveab(s, x, y); 
        else
            return solveba(s, x, y); 
    }
};
