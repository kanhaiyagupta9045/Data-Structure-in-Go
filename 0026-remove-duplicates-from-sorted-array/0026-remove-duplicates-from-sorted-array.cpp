class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        set<int>s;
        for(auto it : nums){
           
            if(s.find(it)==s.end()){
                nums[i++]=it;
                s.insert(it);
            }
        }
        return i;
    }
};