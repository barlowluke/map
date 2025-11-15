#include <unordered_map>
#include <algorithm>
#include "cart_analysis.hpp"

std::vector<std::string> commonProductsAcrossCarts(const std::vector<std::vector<std::string>>& carts) {
    std::unordered_map<std::string, int> u;

    for (size_t i = 0; i < carts.size(); i++) {
        for (size_t j = 0; j < carts[i].size(); j++) {
            if (u.contains(carts[i][j])) {
                u[carts[i][j]]++;
            } else {
                u.insert({carts[i][j], 1});
            }
        }
    }

    std::vector<std::string> common = {};
    for (auto it = u.begin(); it != u.end(); it++) {
        if (it->second == carts.size()) {
            common.push_back(it->first);
        }
    }

    // default sorting behavior is increasing 
    std::sort(common.begin(), common.end());
    return common;
}
