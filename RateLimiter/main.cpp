#include <iostream>
#include <gtest/gtest.h>
#include "rate_limiter.hpp"
#include "fixed_window_rate_limiter.hpp"
#include <thread>

using namespace std;

int task1(IRateLimiter *rateLimiter){
    cout<<this_thread::get_id()<<endl;
    cout<<rateLimiter->rateLimit(1)<<endl;
    cout<<this_thread::get_id()<<endl;
    return 0;
}

int main(int argc, char **argv) {
    // insert code here...
    ::testing::InitGoogleTest(&argc, argv);

    IRateLimiter *rateLimiter = new FixedWindowRateLimiter(2, 1000);

    thread threads[3];

    for(int i=0; i<3; i++){
        threads[i] = thread(task1, rateLimiter);
    }

    for(auto& th : threads)
        th.join();

    cout<<rateLimiter->rateLimit(1)<<endl;

    cout<<rateLimiter->rateLimit(1)<<endl;

    cout<<rateLimiter->rateLimit(1)<<endl;


    cout<<rateLimiter->rateLimit(2)<<endl;

    cout<<rateLimiter->rateLimit(2)<<endl;

    cout<<rateLimiter->rateLimit(2)<<endl;

    sleep(5);

    cout<<rateLimiter->rateLimit(1)<<endl;

    return 0;

}