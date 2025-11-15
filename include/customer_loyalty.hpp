#pragma once

#include <string>
#include <map>

std::map<int, std::string> createLoyaltyTiers();

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score);
