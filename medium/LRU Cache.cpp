class LRUCache {
public:


    class Node{
    public:
        int key,val;
        Node* next;
        Node* prev;

        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
            next=NULL;
            prev=NULL;
        }
    };

    int capacity;
    unordered_map<int,Node*>m;
    Node* head;
    Node* tail;

    LRUCache(int capacity) 
    {
        this->capacity=capacity;
        head=NULL;
        tail=NULL;
    }
    
    int get(int key) 
    {
        if(m.find(key)==m.end())return -1;
        Node* temp=m[key];
        if(tail==temp)return temp->val;
        if(head==temp)
        {
            head=head->next;
            head->prev=NULL;
            tail->next=temp;
            temp->prev=tail;
            temp->next=NULL;
            tail=tail->next;
            return temp->val;
        }
        Node* pv=temp->prev;
        Node* nx=temp->next;
        pv->next=nx;
        nx->prev=pv;

        tail->next=temp;
        temp->prev=tail;
        temp->next=NULL;
        tail=tail->next;

        return temp->val;
    }
    
    void put(int key, int value) 
    {
        if(m.size()==0)
        {
            Node* temp=new Node(key,value);
            m[key]=temp;
            head=temp;
            tail=temp;
            return;
        }
        if(m.find(key)!=m.end())
        {
            get(key);
            m[key]->val=value;
            return;
        }
        if(m.size()==capacity)
        {
            Node* tdel=head;
            m.erase(tdel->key);
            head=head->next;
            if(head)head->prev=NULL;
            delete tdel;
        }
        Node* temp=new Node(key,value);
        if(!head)
        {
            head=temp;
            tail=temp;
            m[key]=temp;
            return;
        }
        tail->next=temp;
        temp->prev=tail;
        tail=tail->next;
        m[key]=temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
