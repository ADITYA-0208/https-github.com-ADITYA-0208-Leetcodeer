class Solution {
public:
    string largestGoodInteger(string num) {
        int count=0;
        char prev='X', maxi=' ';
        for(char c: num){
            if (c==prev) count++;
            else count=1;
            if (count==3)
                maxi=max(maxi, c);
            prev=c;
        }
        return (maxi==' ')?"":string(3, maxi);
    }
};