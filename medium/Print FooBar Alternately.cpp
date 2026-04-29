class FooBar {
private:
    int n;
    binary_semaphore bs1{1};
    binary_semaphore bs2{0};
public:
    FooBar(int n) 
    {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            bs1.acquire();
        	printFoo();
            bs2.release();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            bs2.acquire();
        	printBar();
            bs1.release();
        }
    }
};
