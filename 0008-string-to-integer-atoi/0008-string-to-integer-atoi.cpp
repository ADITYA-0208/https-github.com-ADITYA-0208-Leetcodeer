class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.length() && s[i]==' ') i+=1;
        bool negative=false;
        if(s[i]=='-' || s[i]=='+'){
            negative=(s[i]=='-');
            i+=1;
        }
        long long ans=0;
        while(i<s.length() && isdigit(s[i])){
           ans=ans*10+(s[i]-'0');
           if(ans>INT_MAX && !negative) return INT_MAX;
           if(-ans<INT_MIN  && negative) return INT_MIN;
           i+=1;
        }
        return negative?ans*-1:ans;
    }
};