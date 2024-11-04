class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int cnt=1;
        int n=word.length();
        for(int i=0;i<n-1;i++){
            if(word[i]==word[i+1]){
                cnt++;
                if(cnt==9){
                comp+=to_string(cnt)+word[i];
                cnt=0;
                }
            }
            else{
                if(cnt>0)
                comp+=to_string(cnt)+word[i];
                cnt=1;
            }
        }
        if(n==1)
        comp+=to_string(1)+word;
        else if(cnt>0)
        comp+=to_string(cnt)+word[n-1];
        return comp;
    }
};