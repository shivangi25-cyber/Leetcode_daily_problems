// class Solution {
// public:
//     void f(int i,int j,vector<int>& nums,int l,int u,long long cnt,int n,
//     set<pair<int,int>>& st){
//         if(i==n-1)
//         return;
//         if(j==n-1)
//         return f(i,0,nums,l,u,cnt,n,st);
//         if(nums[i]+nums[j]>=l && nums[j]+nums[i]<=u && i<j &&
//         st.find({i,j})==st.end())
//         {
//             cnt++;
//             st.insert({i,j});
//         }
//         return f(i,j+1,nums,l,u,cnt,n,st);
//         return f(i+1,0,nums,l,u,cnt,n,st);
//     }
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int n=nums.size();
//         long long cnt=0;
//         set<pair<int,int>>st;
//         f(0,1,nums,lower,upper,cnt,n,st);
//         return cnt;
//     }
// };

// class Solution {
// public:
//     long long f(int i, int j, const vector<int>& nums, int lower, int upper, int n,
//     vector<vector<long long>>&dp) {
//         // Base case to stop recursion
//         if (i >= n - 1) return 0; // All pairs for this index have been considered
//         if (j >= n) return f(i + 1, i + 2, nums, lower, upper, n); // Move to next `i` and reset `j`
        
//         long long count = 0;

//         // Check if the current pair (i, j) meets the criteria
//         if (nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper) {
//             count++;
//         }
        
//         // Recursively call for the next `j` and accumulate the count
//         return count + f(i, j + 1, nums, lower, upper, n);
//     }

//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int n = nums.size();

//         // Start recursion with initial indices i=0, j=1
//         vector<vector<long long>>dp(n,vector<long long>(n,-1));
//         return f(0, 1, nums, lower, upper, n,dp);
//     }
// };


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long cnt = 0;
        
        // Sort the array to enable efficient two-pointer technique
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; ++i) {
            int start = i + 1, end = n - 1;
            
            // Find the first valid `j` such that nums[i] + nums[j] >= lower
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (nums[i] + nums[mid] >= lower) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            int lowerBound = start;

            start = i + 1;
            end = n - 1;
            
            // Find the last valid `j` such that nums[i] + nums[j] <= upper
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (nums[i] + nums[mid] <= upper) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            int upperBound = end;

            // Count valid pairs between `lowerBound` and `upperBound`
            if (lowerBound <= upperBound) {
                cnt += (upperBound - lowerBound + 1);
            }
        }
        
        return cnt;
    }
};


