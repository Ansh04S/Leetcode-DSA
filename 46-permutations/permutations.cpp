class Solution {
public:
    void permute(vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp,vector<bool>&visited){
        if(arr.size() == temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<visited.size(); i++){
            if(visited[i] == 0){
                visited[i] = 1;
                temp.push_back(arr[i]);
                permute(arr,ans,temp,visited);
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        vector<bool>visited(nums.size(), 0);
        permute(nums,ans,temp,visited);
        return ans;
    }
};