#include <unordered_map>
#include <algorithm>
#include "api_monitor.hpp"

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data) {
    std::unordered_map<std::string, int> api_call_count;
    // fill the unordered map with the log data, key is endpoint and value is
    // the frequency
    for (size_t i = 0; i < log_data.size(); i++) {
        if (api_call_count.contains(log_data[i])) {
            api_call_count[log_data[i]]++;
        } else {
            api_call_count.insert({log_data[i], 1});
        }
    }
    std::vector<std::pair<std::string, int>> frequencies;
    for (auto it = api_call_count.begin(); it != api_call_count.end(); it++) {
        std::pair<std::string, int> p(it->first, it->second);
        frequencies.push_back(p);
    }
    // need to sort based on second field of iterator, which is the integer
    // frequency of each element
    std::sort(frequencies.begin(), frequencies.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    // if multiple strings have the same frequency, they all go in
    // a vector together
    std::vector<std::string> maxes = {};
    maxes.push_back(frequencies[0].first);
    int max_int = frequencies[0].second;
    // add more strings in the vector if the maximum frequencies occurs more
    // than once
    for (size_t i = 1; i < frequencies.size(); i++) {
        if (frequencies[i].second == max_int) {
            maxes.push_back(frequencies[i].first);
        }
    }
    std::pair<std::vector<std::string>, int> result(maxes, max_int);
    return result;
}
