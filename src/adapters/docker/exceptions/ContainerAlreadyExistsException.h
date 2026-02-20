//
// Created by mathieu on 2/6/26.
//

#ifndef CORI_CONTAINERALREADYEXISTS_H
#define CORI_CONTAINERALREADYEXISTS_H
#include <stdexcept>


class ContainerAlreadyExistsException: public std::exception {
private:
    std::string message;

public:

    ContainerAlreadyExistsException(const char* msg): message(msg) {}
};


#endif //CORI_CONTAINERALREADYEXISTS_H