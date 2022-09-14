#ifndef fixed_window_rate_limiter_hpp
#define fixed_window_rate_limiter_hpp

#include <iostream>
#include "rate_limiter.hpp"
#include <unordered_map>

using namespace std;

class FixedWindowRateLimiter : public IRateLimiter{
    private:
    int max_request;
    long expiry_time;
    unordered_map<int, pair<int, long> > custReqCounter;

    public:
    FixedWindowRateLimiter(int max_request, long expiry_time){
        this->max_request = max_request;
        this->expiry_time = expiry_time;
    }
    bool rateLimit(int customerId);
};

#endif