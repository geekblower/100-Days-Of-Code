class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int maxCount =0 ;
        int back = 0 ;
        int ans =0 ;
        
        for(int r=0; r<nums.size(); r++){
            if(map.find(nums[r]) == map.end()){
                map[nums[r]] = 0;
            }

            // adding into map
            map[nums[r]]++;

            // count max freq
            if(map[nums[r]] > maxCount) maxCount = map[nums[r]];

            if((r - back+1 - maxCount) > k){
                map[nums[back]] -= 1;
                back++;
            }
            
            if(maxCount > ans) ans = maxCount;
        }
        
        return ans;
    }
};
