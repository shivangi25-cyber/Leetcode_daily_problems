class Solution {
public:
    int minChanges(string s) {
        int n=s.length();
        int cnt=0,i=0,j=1;
        while(j<n){
            if(s[i]!=s[j]) cnt++;
            i+=2;
            j+=2;
        }
        return cnt;
    }
};