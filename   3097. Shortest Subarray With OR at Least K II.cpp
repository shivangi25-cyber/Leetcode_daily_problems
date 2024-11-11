class Solution {
public:

    void update(int number,vector<int>&v,int val){
        for(int i=0;i<32;i++){
            if((number>>i)& 1){
                v[i]+=val;
            }
        }
    }

    int getDecimalFromBinary(vector<int>&v){
        int num=0;
        for(int i=0;i<32;i++){
            if(v[i]>0){
                num |=(1<<i);//ith position me 1 hai
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int minlen=INT_MAX;
    
        vector<int>v(32,0);
        //v[i]=total number ot set bits in ith position
        while(j<n){
            update(nums[j],v,1);//adding in the current window
            while(i<=j && getDecimalFromBinary(v)>=k){
                minlen=min(minlen,j-i+1);
                update(nums[i],v,-1);//remove the nums[i] from the window
                i++;
            }
            j++;
        }
        if(minlen==INT_MAX)
        return -1;
        return minlen;
    }
};