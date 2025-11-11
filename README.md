# A12: E-Commerce Analytics Toolkit

This project simulates a backend analytics system for e-commerce platform. You will implement below utilities to:

* Match products into shipping boxes
* Identify common product trends across shopping carts
* Grade customers based on purchase behavior
* Track the most frequently called API endpoint for system usage

The system is modular, and each module (problem) contributes to a different functional requirement of the platform.

## Module 1: Box Fitting Optimizer

* You need to pack customer orders into boxes. This utility finds two items that together fit exactly in a box of given capacity.

```cpp
//include/box_optimizer.hpp
//src/box_optimizer.cpp
std::pair<int, int> findItemsForBox(const std::vector<int>& item_weights, int box_capacity);
```

* Given an array of weights of items and an integer target box weight, return indices of two items such that they add up to weight to fit in the box. 
* Important: You cannot use the same index twice.
* Brute-force Search (don't implement this approach)
  * Check all pairs of numbers if the addition matches with the target.
  * One loop can iterate over the array with element num
  * Use another nested loop to search for target-num
  * This will be O(n^2)
* Hash-Map Approach (with unordered_map)
  * Build hash map as you iterate over the loop and look in hashmap for value target-num
  * Insert and Search in unordered hashmap is O(1) expected so over all O(n)
  * Example: weights: {10, 20, 30, 40, 50} target=70
    * i=0, num = 10 and map ={} 
      * remaining=60 map.contains(60)? => false => insert num (with index) to map
      * => map{10:0}
    * i=1, num = 20 and map{10:0}
      * remaining=50 map.contains(50)? => false => insert num (with index) to map
      * => map{10:0, 20:1}
    * i=2, num = 30 and map{10:0, 20:1}
      * remaining=40 map.contains(40)? => false => insert num (with index) to map
      * => map{10:0, 20:1, 30:2}
    * i=3, num = 40 and map{10:0, 20:1, 30:2}
      * remaining=30 map.contains(30)? => true => map[30] = 2
      * there are two values i=3 and map[30]=2, sort the values and create pair
      * => return {2, 3}
    * If not found return {-1, -1}

## Module 2: Trending Products in Carts

* You want to know what products are popular across all users' carts. This function extracts the common items from multiple customer carts.

```cpp
//include/cart_analysis.hpp
//src/cart_analysis.cpp
std::vector<std::string> commonProductsAcrossCarts(const std::vector<std::vector<std::string>>& carts);
```

* Each individual Shopping Cart has distinct products.

  ```cpp
  shopping_carts = {{"laptop", "mouse", "keyboard", "usb"}, {"laptop", "mouse", "monitor"}, {"mouse", "laptop", "webcam"}}
  
  common = {"laptop", "mouse"}
  ```

* Use hash map unordered_map product_count to count the frequency of each item.

* Iterate over each inner array and update the product count for each product.

* After iterating over all carts, iterate over the hash map to check which products appear in all carts - i.e., the products whose frequency is exactly n, where n is the number of carts.

* return the products in sorted order. 

* You may use std::sort on common before return

## Module 3: Customer Loyalty Tier

* Based on customers’ total purchase value, assign loyalty grades (A, B, C...). This is useful for targeted marketing or rewards programs.

```cpp
//include/customer_loyalty.hpp
//src/customer_loyalty.cpp

std::map<int, std::string> createLoyaltyTiers();

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score);
```

| Minimum Score | Tier     |
| ------------- | -------- |
| 0             | Bronze   |
| 500           | Silver   |
| 1000          | Gold     |
| 2000          | Platinum |

* Create a function createLoyaltyTiers() that return a std::map<int, std::string> that stores the tiers as in above table.
* Write function getLoyaltyTier that return tier based on score
  * Compute lower_bound of score on map tiers. Remember the lower_bound function returns iterator to maximum key which >= key.
    * map.lower_bound(1000) returns it_1000 and you can access Tier using it_1000->second
    * map.lower_bound(1200) returns it_2000
    * map.lower_bound(2500) returns end()
    * map.lower_bound(0) returns begin()
    * You may use ++, --, std::next, std::prev on iterators to adjust so it gives correct tier
  * Test Cases:
    * getLoyaltyTier(tiers, 0) == "Bronze"
    * getLoyaltyTier(tiers, 499) == "Bronze"
    * getLoyaltyTier(tiers, 500) == "Silver"
    * getLoyaltyTier(tiers, 5000) == "Platinum"

## Module 4: API Endpoint Tracker

* Your platform logs all backend API calls. Use this tool to monitor which endpoint (like /api/checkout or /api/cart) is hit most frequently.

```cpp
//include/api_monitor.hpp
//src/api_monitor.cpp

std::pair<std::vector<std::string>, int>
find_most_frequent_endpoints(const std::vector<std::string>& log_data) 
```

* You have been given following API Access logs

  ```cpp
  std::vector<std::string> logs = {"/api/cart", "/api/checkout", "/api/cart", "/api/login", "/api/cart"};
  ```

* Create an unordered map api_call_count to store api and its frequency.

* After creating the frequency counter then find the API Access Point that appears maximum times.

* If there are multiple API Access Points which appear equal maximum times then return all in sorted order. 

* Use std::sort on the list of most frequent endpoints before returning.

## Ecommerce Analytics (main.cpp)

```cpp
//ecommerce_analytics
//main.cpp

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
```



## Submissions:

* box_optimizer.hpp and box_optimizer.cpp
* cart_analysis.hpp and cart_analysis.cpp
* customer_loyalty.hpp and customer_loyalty.cpp
* api_monitor.hpp and api_monitor.cpp
* test.cpp (one test case for each module)
* main.cpp (not used for grading)

## Rubrics

* Include Guards in all header files [1 point]
* Proper Use of STL Maps [Autograder Points + 4 points - deduction if any]
  * unordered_map for Module 1, 2, 4
  * map (ordered) for Module 3
  * Autograder and manual check will confirm correct usage
  * Points deducted for not following specified data structure
* one test case for each module [4 points]
* No Partial Points if code not compiled by the Autogradrer
* Don't submit build/executables folder [-2 Points]