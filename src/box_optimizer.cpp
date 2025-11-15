#include <unordered_map>
#include "box_optimizer.hpp"

std::pair<int, int> findItemsForBox(const std::vector<int>& item_weights, int box_capacity) {
    std::unordered_map<int, int> u;
    int remaining = 0;
    int index = -1;
    for (size_t i = 0; i < item_weights.size(); i++) {
        remaining = box_capacity - item_weights[i];
        if (u.contains(remaining)) {
            int index = u.at(remaining);
            std::pair<int, int> p(index, i);
            return p;
        } else {
            u.insert({item_weights[i], i});
        }
    }
    std::pair<int, int> p(-1, -1);
    return p;
}
