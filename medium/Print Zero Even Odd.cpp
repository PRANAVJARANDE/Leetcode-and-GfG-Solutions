class ZeroEvenOdd {
private:
    int n;
    binary_semaphore zr{1};
    binary_semaphore od{0};
    binary_semaphore ev{0};

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) 
    {
        for(int i=1;i<=n;i++)
        {
            zr.acquire();
            printNumber(0);
            if(i%2)od.release();
            else ev.release();
        }
    }

    void even(function<void(int)> printNumber) 
    {
        for(int i=2;i<=n;i+=2)
        {
            ev.acquire();
            printNumber(i);
            zr.release();
        }
    }

    void odd(function<void(int)> printNumber) 
    {
        for(int i=1;i<=n;i+=2)
        {
            od.acquire();
            printNumber(i);
            zr.release();
        }
    }
};
