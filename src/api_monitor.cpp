#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data) {
    std::unordered_map<std::string, int> api_call_count;
    for (size_t i = 0; i < log_data.size(); i++) {
        if (api_call_count.contains(log_data[i])) {
            api_call_count[log_data[i]]++;
        } else {
            api_call_count.insert({log_data[i], 1});
        }
    }
    std::vector<std::pair<std::string, int>> out;
    for (auto it = api_call_count.begin(); it != api_call_count.end(); it++) {
        std::pair<std::string, int> p(it->first, it->second);
        out.push_back(p);
    }
    std::sort(out.begin(), out.end());
    // need to sort based on second field of iterator, which is the frequency of
    // each element. if multiple strings have the same frequency, they all go in
    // a vector together, all sharing a common frequency. this frequency should
    // be the maximum frequency that is found in the array
}
