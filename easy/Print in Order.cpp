class Foo {
public:
    binary_semaphore b{0};
    binary_semaphore c{0};
    Foo() 
    {
        

    }

    void first(function<void()> printFirst) 
    {
        
        printFirst();
        b.release();
    }

    void second(function<void()> printSecond) {
        
        b.acquire();
        printSecond();
        c.release();
    }

    void third(function<void()> printThird) {
        
        c.acquire();
        printThird();

    }
};
