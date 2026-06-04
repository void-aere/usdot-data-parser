#pragma once

#include <string>

const std::string lookup(const std::string& code, const std::string& table);

void resolveColumn(std::vector<std::string>& col, const std::string& table);
