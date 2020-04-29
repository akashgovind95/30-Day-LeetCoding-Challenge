class FirstUnique {
public:
    class ListNode{
        public:
        int val;
        ListNode * next;
        ListNode * prev;
        ListNode(int data){val=data;next=NULL;prev=NULL;}
    };
    ListNode * head = NULL;
    ListNode * tail = NULL;
    unordered_map<int,int> nodeVal;
    unordered_map<int,ListNode*> nodeAdd;
    
    
    FirstUnique(vector<int>& nums) {
        for(auto i:nums)
            add(i);
    }
    
    int showFirstUnique() {
        
        if(head)
            return head->val;
        return -1;
    }
    
    void add(int value) {
        if(nodeVal[value]==0){
            
            ListNode * temp = new ListNode(value);
            nodeAdd[value] = temp;
            if(!head && !tail){
                
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            }
            
        }
       
        else if(nodeAdd[value]){
            if(nodeAdd[value]==tail){
                if(!tail->prev){
                    head=NULL;
                    tail=NULL;
                }
                else{
                    tail=tail->prev;
                    tail->next=NULL;
                }
            }
            else if(nodeAdd[value]==head){
                if(!head->next){
                    head=NULL;
                    tail=NULL;
                }
                else{
                    head=head->next;
                    head->prev=NULL;
                }
            }
            else{
                ListNode * temp = nodeAdd[value];
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                temp=temp->next;
            }
            
            nodeAdd[value]=NULL;
        }
        nodeVal[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */