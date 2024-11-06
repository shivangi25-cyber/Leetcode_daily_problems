// class Solution {
// public:
//     int setbit(int n) {
//         int cnt = 0;
//         while (n != 0) {
//             n = n & (n - 1);
//             cnt++;
//         }
//         return cnt;
//     }

//     void merge(vector<int>& arr, int low, int mid, int high, vector<int>& temp) {
//         int left = low;      // Starting index of left half
//         int right = mid + 1; // Starting index of right half
//         int idx = low;       // Starting index for merging into temp

//         // Merge both halves into temp in sorted order
//         while (left <= mid && right <= high) {
//             if (arr[left] <= arr[right]) {
//                 temp[idx++] = arr[left++];
//             } else {
//                 // Check if set bits are the same
//                 if (setbit(arr[left]) == setbit(arr[right])) {
//                     // Swap only if they have the same number of set bits
//                     int tempVal = arr[left];
//                     arr[left] = arr[right];
//                     arr[right] = tempVal;
//                 }
//                 temp[idx++] = arr[right++];
//             }
//         }

//         // Copy remaining elements of left half, if any
//         while (left <= mid) {
//             temp[idx++] = arr[left++];
//         }

//         // Copy remaining elements of right half, if any
//         while (right <= high) {
//             temp[idx++] = arr[right++];
//         }

//         // Copy temp back to arr for the current segment
//         for (int i = low; i <= high; i++) {
//             arr[i] = temp[i];
//         }
//     }

//     void mergeSort(vector<int>& arr, int low, int high, vector<int>& temp) {
//         if (low >= high)
//             return;
//         int mid = low + (high - low) / 2;
//         mergeSort(arr, low, mid, temp);      // Left half
//         mergeSort(arr, mid + 1, high, temp); // Right half
//         merge(arr, low, mid, high, temp);    // Merge sorted halves
//     }

//     bool canSortArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> temp(n); // Temporary array for merging
//         vector<int> sorted_nums = nums;
//         mergeSort(nums, 0, n - 1, temp);
//         sort(sorted_nums.begin(), sorted_nums.end());
//         return (nums == sorted_nums);
//     }
// };

class Solution {
public:
    static bool canSortArray(const vector<int> &nums) {
        const uint8_t n = nums.size();
        uint16_t pmax = 0, cmin = 0, cmax = 0;
        uint8_t pcnt = 0;
        for (const uint16_t v : nums) {
            if (const uint8_t ccnt = popcount(v); pcnt == ccnt) {
                cmin = min(cmin, v);
                cmax = max(cmax, v);
            } else if (cmin < pmax) {
                return false;
            } else {
                pmax = cmax;
                cmin = cmax = v;
                pcnt = ccnt;
            }
        }
        return cmin >= pmax;
    }
};