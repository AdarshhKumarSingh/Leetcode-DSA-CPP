class Solution {
public:

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans1(n, n);

        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(st.size()>0 && arr[st.top()]>=arr[i]) {
                st.pop();
            }

            if(st.size()>0) ans1[i] = st.top();

            st.push(i);
        }

        return ans1;
    }

    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans2(n, -1);

        stack<int> st;

        for(int i=0; i<n; i++) {
            while(st.size()>0 && arr[st.top()]>=arr[i]) {
                st.pop();
            }

            if(st.size()>0) ans2[i] = st.top();

            st.push(i);
        }

        return ans2;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse = nextSmallerElement(heights);
        vector<int> pse = previousSmallerElement(heights);

        int maxi = 0;

        for(int i=0; i<n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};