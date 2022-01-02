#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void critical_section(int change_v)
{
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);

    // execute contention works
    v = change_v;

    // mtx will be released after leaving the scopt
}

void demo1()
{
    std::thread t1(critical_section, 3), t2(critical_section, 2);
    t1.join();
    t2.join();

    std::cout << v << std::endl;
}

void critical_section_lock(int change_v)
{
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);

    // do contention operations
    v = change_v;
    std::cout << v << std::endl;
    // release the lock
    lock.unlock();

    // during this period,
    // others are allowed to acquire v
    // start another group of contention operations // lock again
    lock.lock();
    v += 1;
    std::cout << v << std::endl;
}

void demo2()
{
    std::cout << "-----demo2-----" << std::endl;
    std::thread t1(critical_section_lock, 2), t2(critical_section_lock, 3);
    t1.join();
    t2.join();
}

int main()
{
    demo1();
    demo2();
    return 0;
}