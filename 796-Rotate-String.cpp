class Solution {
public:
    //think of adding strings in case of rotations
    bool rotateString(string s, string goal) {
        if(goal.length()!=s.length())
        return false;
        s=s+s;
        int n=goal.length();
        for(int i=0;i<n;i++){
            if(s.substr(i,n)==goal)
            return true;
        }
        return false;
    }
};