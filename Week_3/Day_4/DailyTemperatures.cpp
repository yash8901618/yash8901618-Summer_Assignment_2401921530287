
    #include <vector>
    #include <stack>

    using namespace std;

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stores indices of temperatures
        
        for (int i = 0; i < n; ++i) {
            // While current temp is warmer than the temp at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i - prevIndex; // Days to wait
            }
            st.push(i);
        }
        return ans;
    }
