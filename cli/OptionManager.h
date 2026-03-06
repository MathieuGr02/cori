//
// Created by mathieu on 3/5/26.
//

#ifndef CORI_OPTIONMANAGER_H
#define CORI_OPTIONMANAGER_H
#include <any>
#include <list>
#include <map>
#include <memory>

#include "Option.h"

class OptionManager {
    std::list<std::shared_ptr<Option<std::any>>> options;

    std::map<std::string, std::shared_ptr<Option<std::any>>> short_map;
    std::map<std::string, std::shared_ptr<Option<std::any>>> long_map;

public:
    template <typename T>
    void add_option(Option<T>& option);

    void parse(int argc, char* argv[]);
};


#endif //CORI_OPTIONMANAGER_H