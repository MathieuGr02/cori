//
// Created by mathieu on 3/5/26.
//

#include "OptionManager.h"

#include <iostream>

template <typename T>
void OptionManager::add_option(Option<T>& option) {
    std::shared_ptr<T> option_ptr(option);
    this->options.push_back(option_ptr);

    const std::optional<std::string> option_short = option.get_short();
    const std::string option_long = option.get_long();
    if (option_short.has_value()) {
        this->short_map[option_short.value()] = option_ptr;
    }

    this->long_map[option_long] = option_ptr;
}

void OptionManager::parse(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
}
