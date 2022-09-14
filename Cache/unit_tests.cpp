#include <iostream>
#include <gtest/gtest.h>
#include "cache_factory.hpp"
#include "storage.hpp"
#include "inmemory_cache.hpp"
#include "lru_eviction_policy.hpp"
#include "custom_exception.hpp"

struct TextFixture : public ::testing::Test{
    public:
    Cache *cache;
    void SetUp() {
        cout<<"Alive";
        cache = CacheFactory::getLRUCache();
    }
    void TearDown() {
        cout<<"Dead";
        delete cache;
    }
};

TEST_F(TextFixture, KeyFound){

    cache->put(2,2);
    cache->put(1,1);
    cache->put(2,2);
    cache->put(3,3);
    cache->put(3,3);
    cache->put(3,3);

    ASSERT_EQ(2, cache->get(2));
}


TEST_F(TextFixture, KeyNotFound){

    cache->put(2,2);
    cache->put(1,1);
    cache->put(2,2);
    cache->put(3,3);
    cache->put(3,3);
    cache->put(3,3);

    ASSERT_THROW(cache->get(1), NotFoundException);
}