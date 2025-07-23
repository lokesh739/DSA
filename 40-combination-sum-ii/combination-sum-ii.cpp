class Solution {
private:
void generate(int index,int target,vector<int> &candidates,vector<vector<int>> &result,vector<int> &current){
    if(target==0){
        result.push_back(current);
        return;
    }

    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target) break;
        current.push_back(candidates[i]);
        generate(i+1,target-candidates[i],candidates,result,current);
        current.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        generate(0,target,candidates,result,current);
        return result;
    }
};