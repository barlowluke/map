#include "api_monitor.hpp"
#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"

#include <iostream>

int main() {
    // Module 1: Box Fitting Optimizer
    std::vector<int> weights = {10, 20, 30, 40, 50};
    int box_capacity = 70;
    auto [i, j] = findItemsForBox(weights, box_capacity);
    std::cout << "Box Fit Indices: " << i << ", " << j << "\n";

    // Module 2: Trending Products in Carts
    std::vector<std::vector<std::string>> carts = {
        {"laptop", "mouse", "keyboard"},
        {"laptop", "mouse", "monitor"},
        {"mouse", "laptop", "webcam"}
    };
    auto common = commonProductsAcrossCarts(carts);
    std::cout << "Common Products: ";
    for (const auto& product : common) 
        std::cout << product << " ";
    std::cout << "\n";

    // Module 3: Customer Loyalty Tier
    auto tiers = createLoyaltyTiers();
    int points = 1200;
    std::cout << "Loyalty Tier: " << getLoyaltyTier(tiers, points) << "\n";

    // Module 4: API Endpoint Tracker
    std::vector<std::string> api_logs = {
        "/api/login", "/api/cart", "/api/checkout", "/api/cart", "/api/login", "/api/cart", "/api/login"
    };

    auto [endpoints, count] = find_most_frequent_endpoints(api_logs);

    std::cout << "Top API Endpoint(s) with " << count << " calls:\n";
    for (const auto& ep : endpoints) {
        std::cout << "->" << ep << "\n";
    }

    return 0;
}

/*
Box Fit Indices: 2, 3
Common Products: laptop mouse 
Loyalty Tier: Gold
Top API Endpoint(s) with 3 calls:
->/api/cart
->/api/login
*/
