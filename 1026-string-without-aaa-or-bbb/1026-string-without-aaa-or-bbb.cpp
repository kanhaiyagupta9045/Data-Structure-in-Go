class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";

        while(a>0 || b>0){
            int curr_size = ans.size();
            bool writeA = false;

            if(curr_size>=2 && ans[curr_size-1]== ans[curr_size-2]){
                if(ans[curr_size-1]=='b'){
                    writeA = true;
                }
            }else{
                if(a>=b){
                    writeA = true;
                }
            }

            if(writeA){
                ans+='a';
                a--;
            }else{
                ans +='b';
                b--;
            }
        }
        return ans;
    }
};