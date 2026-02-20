//
// Created by mathieu on 2/5/26.
//

#ifndef CORI_UTIL_H
#define CORI_UTIL_H
#include <string>
#include <vector>


static std::vector<std::string> split(std::string &s, const std::string &delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }

    tokens.push_back(s);

    return tokens;
}

#endif //CORI_UTIL_H