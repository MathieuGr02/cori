//
// Created by mathieu on 2/6/26.
//

#ifndef CORI_NOSUCHIMAGEEXCEPTION_H
#define CORI_NOSUCHIMAGEEXCEPTION_H
#include <exception>
#include <string>


class NoSuchImageException: public std::exception {
private:
    std::string message;

public:
    NoSuchImageException(const std::string msg): message(msg) {}
};


#endif //CORI_NOSUCHIMAGEEXCEPTION_H