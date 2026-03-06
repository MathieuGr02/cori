//
// Created by mathieu on 3/5/26.
//

#include "Option.h"

template<typename T>
const std::string Option<T>::get_long() {
    return this->long_;
}

template<typename T>
const std::optional<std::string> Option<T>::get_short() {
    return this->short_;
}

template<typename T>
bool Option<T>::has_value() {
    return this->value.has_value();
}

template<typename T>
T Option<T>::get_value() {
    return this->value.value();
}

template<typename T>
void Option<T>::set_value(const std::string& value) {
    this->value = dynamic_cast<T>(value);
}
