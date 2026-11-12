class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> nge(n, -1);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(st.size()>0 && arr[st.top()]<=arr[i]) {
                st.pop();
            }

            if(st.size()>0) {
                nge[i] = st.top();
            }

            st.push(i);
        }

        vector<int> ans(n-k+1);

        int j = 0;

        for(int i=0; i<n-k+1; i++) {

            if(j<i) j=i;

            while(nge[j]!=-1 && nge[j]<i+k) {
                j=nge[j];
            }

            ans[i]=arr[j];
        }

        return ans;
    }
};

// TC = O(n)


// Method 1(Brute Force)//TLE aayega

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {

//         int n = nums.size();

//         vector<int> ans(n-k+1, 0);

//         for(int i=0; i<=n-k; i++) {

//             int maxi = nums[i];

//             for(int j=i; j<i+k; j++) {
//                 maxi = max(maxi, nums[j]);
//             }

//             ans[i] = maxi;
//         }

//         return ans;
//     }
// };