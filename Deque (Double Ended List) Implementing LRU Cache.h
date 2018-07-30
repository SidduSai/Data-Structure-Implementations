class LRUCache {
public:
    class ListNode
    {
        public:
        ListNode* next;
        ListNode* prev;
        int val;
        ListNode(int value)
        {
            val = value;
            prev = next = NULL;
        }
    };
    
    class LinkedList
    {
        public:
        ListNode* head;
        ListNode* tail;
        LinkedList()
        {
            head = tail = NULL;
        }
        
        void insert_back(ListNode* node)
        {
            if(head == NULL)
            {
                head = tail = node;
            }
            else
            {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        
        void remove(ListNode* node)
        {
            if(head == node)
            {
                head = head->next;
                if(head != NULL)
                {
                    head->prev = NULL;
                    free(node);
                }
                else
                {
                    free(node);
                    head = tail = NULL;
                }
            }
            else if(node == tail)
            {
                node->prev->next = NULL;
                tail = node->prev;
                free(node);
            }
            else
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                free(node);
            }
        }
    };
    
    LinkedList *ll;
    int space;
    map<int, ListNode*> mp;
    LRUCache(int capacity) {
        space = capacity;
        ll = new LinkedList();
    }
    
    int get(int key) {
//        cout<<"get "<<key<<endl;
        if(mp.count(key))
        {
            int keyval = mp[key]->val;
//            cout<<"yes key "<<key<<" is present with keyval "<<keyval<<endl;
            ll->remove(mp[key]);
            mp.erase(key);
            ListNode* temp = new ListNode(keyval);
            ll->insert_back(temp);
            mp[key] = temp;
            return keyval;
        }
        else return -1;
    }
    
    void put(int key, int value) {
//        cout<<"put "<<key<<' '<<value<<endl;
        
        if(mp.count(key))
        {
            ll->remove(mp[key]);
            mp.erase(key);
            ListNode* temp = new ListNode(value);
            ll->insert_back(temp);
            mp[key] = temp;
        }
        else
        {
            ListNode* temp = new ListNode(value);
            ll->insert_back(temp);
            if(mp.size() == space)
            {
                int del;
                for(auto a:mp)
                {
                    if(a.second == ll->head)
                    {
                        del = a.first;
                        break;
                    }
                }
                mp.erase(del);
                ll->remove(ll->head);
            }
            mp[key] = temp;
        }
        
//        cout<<"ll elements are ";
        // ListNode* temp = ll->head;
        // while(temp != NULL)
        // {
        //     cout<<temp->val<<' ';
        //     temp = temp->next;
        // }
        // cout<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */