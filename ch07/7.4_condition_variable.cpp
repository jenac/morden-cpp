#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

int main()
{
    std::queue<int> produced_nums;
    std::mutex mtx;
    std::condition_variable cv;
    bool notified = false;

    auto producer = [&]()
    {
        for (int i = 0;; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "producing " << i << std::endl;
            produced_nums.push(i);
            notified = true;
            cv.notify_all();
        }
    };

    auto consumer = [&]()
    {
        while (true)
        {
            std::unique_lock<std::mutex> lock(mtx);
            while (!notified) // avoid spurious wakeup
            {
                cv.wait(lock);
            }

            // temporal unlock to allow producer produces more rather than
            // let consumer hold the lock until its consumed.
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            lock.lock();
            if (!produced_nums.empty())
            {
                std::cout << "consuming " << produced_nums.front() << std::endl;
                produced_nums.pop();
            }
            notified = false;
        }
    };

    std::thread p(producer);
    const int numOfConsumers = 2;
    std::thread cs[numOfConsumers];
    for (int i = 0; i < numOfConsumers; ++i)
    {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for (int i = 0; i < numOfConsumers; ++i)
    {
        cs[i].join();
    }
    return 0;
}