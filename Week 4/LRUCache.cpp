/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
The cache is initialized with a positive capacity.
Follow up:
Could you do both operations in O(1) time complexity?


*/

/*
1. Store the value of each key in a map.
2. Take a linked list to maintain an order of keys.
3. Maintain two pointers to add and delete from either side of linkedlist
4. Take another map to store the address of each node in the linked for deleting any middle node.

*/

class LRUCache {
public:
    class ll{
        public:
        int key;
        ll* next;
        ll(int data){key = data; next=NULL;}
    };
    
    int cap;
    unordered_map<int,int> cache;
    unordered_map<int,ll*> ll_add;
    ll* head=NULL;
    ll* tail=NULL;
    int sizeSoFar=0;
    
    void push_back_ll(int key){
        ll* temp = new ll(key);
        if(tail && tail->key == key){
            ll_add[key]=tail;
            sizeSoFar++;
            return;
        }
        else if(head==NULL && tail ==NULL){
            head=temp;
            tail=temp;
        }
        else if(!head)
            head=tail;
        else{
            tail->next = temp;
            tail=temp;
        }
        ll_add[key]=temp;
        sizeSoFar++;
    }
    void pop_front_ll(){
        
        head=head->next;
        sizeSoFar--;
    }
    
    void remove_ll(int key){
        
        ll * temp = ll_add[key];
        if(temp->next == tail)
            tail=temp;
        if(temp->next!=NULL){
            temp->key = temp->next->key;
            ll_add[temp->next->key] = temp;
            temp->next = temp->next->next;
        }
        
        ll_add[key]=NULL;
        sizeSoFar--;
    }
    
    LRUCache(int capacity) {
        
        cap=capacity;
    }
    
    int get(int key) {
        
        if(cache[key]==0)
            return -1;
        remove_ll(key);
        push_back_ll(key);
        return cache[key];
    }
    
    void put(int key, int value) {

        if(cache[key]==0){
            if(sizeSoFar==cap){
                int temp = head->key;
                pop_front_ll();
                cache[temp]=0;
            }    
        }   
        else
            remove_ll(key);
        
        push_back_ll(key);
        cache[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */