//SIEVE OF ERATHANOSE PADH LENA

//or dry run krna

class Solution {
public:
    bool isPrime[1000];
    void sieve(){
        fill(isPrime,isPrime+1000,true);//initialize all true
        isPrime[0]=false;//0 is not a prime number
        isPrime[1]=false;//1 is not a prime number

        for(int i=0;i*i<1000;i++){
            if(isPrime[i]){
                for(int j=i*i;j<1000;j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();

        sieve();//it will populate my isPrime array O(1)
        //isPrime[i]==true means . i ia a prime number else i is not a
        // prme num
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                continue;
            }

            //nums[i]>=nums[i+1]
            //decrrease nums[i] atleast leass than nums[i-1]

            //check prime numbers less than nums[i]

            for(int p=2;p<nums[i];p++){
                if(!isPrime[p]){
                    continue;
                }

                if(nums[i]-p<nums[i+1]){
                    nums[i]-=p;
                    break;
                }
            }

            if(nums[i]>=nums[i+1]){
                return false;
            }
        }

        return true;
    }
};