class kQueues {

  public:
  
    int n,k;
    int cnt;
    
    vector<int>a;
    vector<int>next;
    vector<int>front;
    vector<int>rear;
    int in;
    
    kQueues(int n, int k) 
    {
        in=0;
        a=vector<int>(n,-1);
        front=vector<int>(k,-1);
        rear=vector<int>(k,-1);
        next=vector<int>(n,-1);
        for(int i=0;i<n-1;i++)next[i]=i+1;
        this->cnt=0;
        this->n=n;
        this->k=k;
    }

    void enqueue(int x, int i) 
    {
        if(in==-1)return;
        
        int tp=in;
        in=next[in];
        
        if(front[i]==-1)front[i]=tp;
        else next[rear[i]]=tp;
        rear[i]=tp;
        a[tp]=x;
        next[tp]=-1;
    }

    int dequeue(int i) 
    {
        if(front[i]==-1)return -1;
        int tp=front[i];
        front[i]=next[tp];
        if(front[i]==-1)rear[i]=-1;
        next[tp]=in;
        in=tp;
        return a[tp];
    }

    bool isEmpty(int i) 
    {
       return front[i]==-1;
    }

    bool isFull() 
    {
        return in==-1;
    }
};
