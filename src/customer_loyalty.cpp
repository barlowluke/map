#include <string>
#include <map>
#include "customer_loyalty.hpp"

std::map<int, std::string> createLoyaltyTiers() {
    std::map<int, std::string> u = { {0, "Bronze"}, {500, "Silver"}, 
        {1000, "Gold"}, {2000, "Platinum"} };
    return u;
}

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score) {
    // returns first element greater than or equal to 
    auto it = tiers.lower_bound(score);
    if (it->first != score) {
        it--;
    }
    return it->second;
}
