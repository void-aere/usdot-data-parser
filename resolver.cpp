#include "resolver.hpp"

const std::string lookup(const std::string& code, const std::string& table) {
    rapidcsv::Document doc(table, rapidcsv::LabelParams(0, 0));
    return doc.GetCell<std::string>("Description", code);
}

void resolveColumn(std::vector<std::string>& col, const std::string& table) {
    rapidcsv::Document doc(table, rapidcsv::LabelParams(0, 0));
    for (size_t i = 0; i < col.size(); ++i) {
        col[i] = doc.GetCell<std::string>("Description", col[i]);
    }
}
