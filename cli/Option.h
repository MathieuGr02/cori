//
// Created by mathieu on 3/5/26.
//

#ifndef CORI_OPTION_H
#define CORI_OPTION_H

#include <optional>
#include <string>
#include <utility>

template <typename T>
class Option {
    std::string long_;
    std::optional<std::string> short_;

    std::optional<T> value;

public:
    Option(std::string l): short_(std::nullopt), long_(std::move(l)) {}
    Option(std::string s, std::string l): long_(std::move(l)), short_(std::move(s)) {}

    const std::optional<std::string> get_short();
    const std::string get_long();

    bool has_value();
    T get_value();
    void set_value(const std::string& value);
};


#endif //CORI_OPTION_H