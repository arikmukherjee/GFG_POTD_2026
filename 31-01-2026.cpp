class kQueues {
  private:
    int n, k;
    int freeIndex;
    vector<int> arr, front, rear, next;

  public:
    kQueues(int n, int k){
      this->n = n;
      this->k = k;
      
      freeIndex=0;
      arr.resize(n); next.resize(n);
      front.assign(k, -1); rear.assign(k, -1);
      
      for(int i=0; i<n-1; i++) next[i] = i+1;
      next[n-1] = -1;
      
      return;
    }

    virtual void enqueue(int x, int qi){
      if(isFull()) return;
      
      int freeIndexClone = freeIndex;
      freeIndex = next[freeIndexClone];
      
      arr[freeIndexClone] = x;
      
      if(front[qi]==-1) front[qi]=freeIndexClone;
      else next[rear[qi]] = freeIndexClone;
      
      rear[qi] = freeIndexClone;
      next[freeIndexClone] = -1;
      return;
    }

    virtual int dequeue(int qi){
      if(isEmpty(qi)) return -1;
      
      int rmIndex = front[qi];
      front[qi] = next[rmIndex];
      
      next[rmIndex] = freeIndex;
      freeIndex = rmIndex;
      
      return arr[rmIndex];
      
    }

    virtual bool isEmpty(int qi){
      return front[qi]==-1;    
    }

    virtual bool isFull(){
      return freeIndex==-1;    
    }
};

