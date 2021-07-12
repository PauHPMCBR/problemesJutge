#include <bits/stdc++.h>
#include <chrono>
#include <thread>
    
void long_operation()
{
    int l = 0;
    for (int i = 0; i < 1e5; ++i) {
        for (int j = 0; j < 1e4; ++j) {

        }
    }
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    auto t1 = high_resolution_clock::now();
    long_operation();
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    std::cout << ms_int.count() << "ms\n";
    return 0;
}