class FizzBuzz {
private:
    int n;
    mutex m;
    int curr;

public:

    FizzBuzz(int n) 
    {
        curr=1;
        this->n=n;
    }

    void fizz(function<void()> printFizz) 
    {
        while(true) 
        {
            m.lock();
            if(curr>n) 
            {
                m.unlock();
                return;
            }
            if(curr%3==0 && curr%5!=0) 
            {
                printFizz();
                curr++;
            }
            m.unlock();
        }
    }

    void buzz(function<void()> printBuzz) 
    {
        while(true) 
        {
            m.lock();
            if(curr>n) 
            {
                m.unlock();
                return;
            }
            if(curr%5==0 && curr%3!=0) 
            {
                printBuzz();
                curr++;
            }
            m.unlock();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) 
    {
        while(true) 
        {
            m.lock();
            if(curr>n) 
            {
                m.unlock();
                return;
            }
            if(curr%3==0 && curr%5==0) 
            {
                printFizzBuzz();
                curr++;
            }
            m.unlock();
        }
    }

    void number(function<void(int)> printNumber) 
    {
        while(true) 
        {
            m.lock();
            if(curr>n) 
            {
                m.unlock();
                return;
            }
            if(curr%3!=0 && curr%5!=0) 
            {
                printNumber(curr);
                curr++;
            }
            m.unlock();
        }
    }
};
