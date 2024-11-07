class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        int result =0;

        for(int i=0;i<32;i++){
            int count=0;
            for(int &num:candidates){
                if((num & (1<<i))!=0){
                    count++;
                }
            }
            result=max(result,count);
        }
        return result;
    }
};