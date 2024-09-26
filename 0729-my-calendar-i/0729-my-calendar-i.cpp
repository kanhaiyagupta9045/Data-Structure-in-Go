class MyCalendar {
public:
   set<pair<int,int>>s;
    MyCalendar() {
        s.insert({0,0});
    }
    
    bool book(int start, int end) {
        bool check = true;
        for(auto it : s){
            pair<int,int> p = it ;

            if((start<p.first && end<=p.first) || start>=p.second && end>=p.second){
                continue;
            }else{
                check = false;
                break;
            }
        }
        if(check){
            s.insert({start,end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */