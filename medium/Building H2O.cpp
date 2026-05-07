class H2O {
public:
    
    counting_semaphore<2> h{2}; 
    counting_semaphore<1> o{1}; 
    counting_semaphore<2> done{0}; 

    H2O() {

    }

    void hydrogen(function<void()> releaseHydrogen) 
    {
        h.acquire();
        releaseHydrogen();
        done.release();
    }

    void oxygen(function<void()> releaseOxygen) 
    {
        o.acquire();
        done.acquire();
        done.acquire();
        releaseOxygen();
        h.release();
        h.release();
        o.release();
    }
};
