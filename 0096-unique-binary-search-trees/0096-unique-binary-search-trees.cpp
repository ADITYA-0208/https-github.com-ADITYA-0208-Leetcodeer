class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1; // base case

        int total = 0;
        for (int i = 1; i <= n; i++) {
            // choose i as root
            int left = numTrees(i - 1);   // left subtree
            int right = numTrees(n - i); // right subtree
            total += left * right;
        }
        return total;
    }
};
