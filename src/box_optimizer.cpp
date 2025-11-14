#include <vector>
#include <unordered_map>

std::pair<int, int> findItemsForBox(const std::vector<int>& item_weights, int box_capacity) {
    std::unordered_map<int, int> u;
    int remaining = 0;
    int index = -1;
    for (size_t i = 0; i < item_weights.size(); i++) {
        remaining = box_capacity - item_weights[i];
        if (u.contains(remaining)) {
            int index = u.at(remaining);
            return std::pair<int, int> p(index, i);
        } else {
            u.insert({remaining,i});
        }
    }
    return std::pair<int, int> p(-1, -1);
}
