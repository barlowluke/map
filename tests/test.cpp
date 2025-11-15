#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"
#include "api_monitor.hpp"
#include <vector>
#include <map>

TEST_CASE( "Testing Module 1: Box Fitting Optimizer" ) {
    SECTION("Example given in module") {
        const std::vector<int> weights = {10, 20, 30, 40, 50};
        int target = 70;
        auto [i, j] = findItemsForBox(weights, target);
        REQUIRE(i == 2);
        REQUIRE(j == 3);
    }
}

TEST_CASE("Testing Module 2: Trending Products in Carts") {
    SECTION("Example given in module") {
        std::vector<std::vector<std::string>> carts = {
            {"laptop", "mouse", "keyboard"},
            {"laptop", "mouse", "monitor"},
            {"mouse", "laptop", "webcam"}
        };
        auto common = commonProductsAcrossCarts(carts);
        REQUIRE(common[0] == "laptop");
        REQUIRE(common[1] == "mouse");
    }
}

TEST_CASE("Testing Module 3: Customer Loyalty Tier") {
    const std::map<int, std::string> tiers = createLoyaltyTiers();
    REQUIRE(tiers.at(0) == "Bronze");
    REQUIRE(tiers.at(500) == "Silver");
    REQUIRE(tiers.at(1000) == "Gold");
    REQUIRE(tiers.at(2000) == "Platinum");
    SECTION("Example given in module") {
        REQUIRE(getLoyaltyTier(tiers, 0) == "Bronze");
        REQUIRE(getLoyaltyTier(tiers, 499) == "Bronze");
        REQUIRE(getLoyaltyTier(tiers, 500) == "Silver");
        REQUIRE(getLoyaltyTier(tiers, 5000) == "Platinum");
    }
}

TEST_CASE("Testing Module 4: API Endpoint Tracker") {
    SECTION("Example given in module") {
        std::vector<std::string> api_logs = {
            "/api/login", "/api/cart", "/api/checkout", "/api/cart", "/api/login", "/api/cart", "/api/login"
        };
        auto [endpoints, count] = find_most_frequent_endpoints(api_logs);
        REQUIRE(count == 3);
        REQUIRE(endpoints.size() == 2);
        REQUIRE(endpoints.at(0) == "/api/cart");
        REQUIRE(endpoints.at(1) == "/api/login");
    }
}
