class DiningPhilosophers {
public:

    mutex forks[5];

    DiningPhilosophers() {
        
    }

    void wantsToEat(
        int id,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork
    ) {

        int l=id;
        int r=(id+1)%5;

        if(id%2==0) 
        {
            forks[l].lock();
            forks[r].lock();
        } 
        else 
        {
            forks[r].lock();
            forks[l].lock();
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        forks[l].unlock();
        forks[r].unlock();
    }
};
