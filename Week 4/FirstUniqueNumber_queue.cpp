class FirstUnique {
public:
    unordered_map<int,int> count;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(auto value : nums)
            add(value);
    }
    
    int showFirstUnique() {
        while(!q.empty() && count[q.front()]!=1)
            q.pop();
        return q.size()==0?-1:q.front();
    }
    
    void add(int value) {
        q.push(value);
        count[value]++;  
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */