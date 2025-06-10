class Solution {
public:
    vector<int> nextsmaller(vector<int> arr){
        stack<int> st;
        int n=arr.size();
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> previoussmallerequal(vector<int> arr) {
    stack<int> st;
    int n = arr.size();
    vector<int> pse(n);

    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pse;
}


    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
       int mod=(int)(1e9+7);
       int sum=0;
       vector<int> nse=nextsmaller(arr);
       vector<int> psee=previoussmallerequal(arr);
       for(int i=0;i<n;i++){
        int left=i-psee[i];
        int right=nse[i]-i;
        sum=(sum+(left*right*1ll*arr[i])%mod)%mod;
       }
       return sum;
    }
};