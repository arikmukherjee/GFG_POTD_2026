class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        stack<pair<int,int>> st;
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            int count = 1;
            
            while(!st.empty() && arr[i] >= st.top().first){
                count += st.top().second;
                st.pop();
            }
            st.push({arr[i],count});
            ans.push_back(count);
        }
        return ans;
    }
};