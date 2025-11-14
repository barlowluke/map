#include <string>
#include <map>

std::map<int, std::string> createLoyaltyTiers() {
    std::map<int, std::string> u = { {0, "Bronze"}, {500, "Silver"}, 
        {1000, "Gold"}, {2000, "Platinum"} };
}

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score) {
    auto it = tiers.lower_bound(score);
    if (it == tiers.begin() || it == tiers.end()) {
        return it;
    } else {
        return it--;
    }
}
