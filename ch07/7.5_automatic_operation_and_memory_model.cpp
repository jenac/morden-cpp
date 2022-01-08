#include <atomic>
#include <thread>
#include <iostream>
#include <vector>

std::atomic<int> count = 0;

void atomic_demo()
{
    std::cout << "-----atomic_demo-----" << std::endl;
    std::thread t1([]()
                   { std::cout << "count = " << count.fetch_add(1) << std::endl; });

    std::thread t2([]()
                   {
                       count++;    // identical to fetch_add
                       count += 1; // identical to fetch_add
                   });
    t1.join();
    t2.join();
    std::cout << count << std::endl;
}

struct A
{
    float x;
    int y;
    long long z;
};

void is_lock_free_demo()
{
    std::cout << "-----is_lock_free_demo-----" << std::endl;
    std::atomic<A> a;
    std::cout << std::boolalpha << a.is_lock_free() << std::endl;
}

void memory_relaxed_model_demo()
{
    std::cout << "-----memory_relaxed_model_demo-----" << std::endl;
    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 100; ++i)
    {
        vt.emplace_back([&]()
                        { counter.fetch_add(1, std::memory_order_relaxed); });
    }

    for (auto &t : vt)
    {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
}

void memory_release_consumption_demo()
{
    std::cout << "-----memory_release_consumption_demo-----" << std::endl;
    // initialize as nullptr to prevent consumer load a dangling pointer
    std::atomic<int *> ptr(nullptr);
    int v;

    std::thread producer([&]()
                         {
                             int *p = new int(42);
                             v = 1024;
                             ptr.store(p, std::memory_order_release);
                         });

    std::thread consumer([&]()
                         {
                             int *p;
                             while (!(p = ptr.load(std::memory_order_consume)))
                                 ;
                             std::cout << "p: " << *p << std::endl;
                             std::cout << "v: " << v << std::endl;
                         });

    producer.join();
    consumer.join();
}

void memory_release_acquire_demo()
{
    std::cout << "-----memory_release_acquire_demo-----" << std::endl;
    std::vector<int> v;
    std::atomic<int> flag = {0};
    std::thread release([&]()
                        {
                            v.push_back(42);
                            flag.store(1, std::memory_order_release);
                        });

    std::thread acqrel([&]()
                       {
                           int expected = 1; // must before compare_exchange_strong
                           while (!flag.compare_exchange_strong(expected, 2, std::memory_order_acq_rel))
                           {
                               expected = 1; // must after compare_exchange_strong
                           }
                           // flag has changed to 2
                       });

    std::thread acquire([&]()
                        {
                            while (flag.load(std::memory_order_acquire) < 2)
                                ;
                            std::cout << v.at(0) << std::endl; // must be 42
                        });

    release.join();
    acqrel.join();
    acquire.join();
}

void memory_sequential_demo()
{
    std::cout << "-----memory_sequential_demo-----" << std::endl;
    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 100; ++i)
    {
        vt.emplace_back([&]()
                        { counter.fetch_add(1, std::memory_order_seq_cst); });
    }

    for (auto &t : vt)
    {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
}

int main()
{
    atomic_demo();
    std::cout << std::endl;
    is_lock_free_demo();
    std::cout << std::endl;
    memory_relaxed_model_demo();
    std::cout << std::endl;
    memory_release_consumption_demo();
    std::cout << std::endl;
    memory_release_acquire_demo();
    std::cout << std::endl;
    memory_sequential_demo();
    return 0;
}