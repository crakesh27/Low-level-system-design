#include "fixed_window_rate_limiter.hpp"
#include <unordered_map>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;
using namespace chrono;

mutex mtx; 

bool FixedWindowRateLimiter::rateLimit(int customerId){
    mtx.lock();
    long timestamp = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    // cout<<customerId<<" "<<timestamp<<endl;
    if(custReqCounter.find(customerId) != custReqCounter.end()){
        long prev_timestamp = custReqCounter[customerId].second;

        if(timestamp - prev_timestamp > expiry_time){
            custReqCounter[customerId] = make_pair(1, timestamp);
            mtx.unlock();
            return true;
        }
        else if(custReqCounter[customerId].first >= max_request){
            mtx.unlock();
            return false;
        }
        else{
            custReqCounter[customerId].first++;
            mtx.unlock();
            return true;
        }

    }
    else{
        custReqCounter[customerId] = make_pair(1, timestamp);
        mtx.unlock();
        return true;
    }
};