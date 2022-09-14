#ifndef rate_limiter_hpp
#define rate_limiter_hpp

class IRateLimiter{

    public:
    virtual bool rateLimit(int customerId) = 0;
};

#endif