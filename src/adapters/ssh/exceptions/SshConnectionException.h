//
// Created by mathieu on 2/19/26.
//

#ifndef CORI_SSHCONNECTIONEXCEPTION_H
#define CORI_SSHCONNECTIONEXCEPTION_H
#include <exception>
#include <string>


class SshConnectionException: public std::exception {
private:
    std::string message;

public:
    SshConnectionException(const char* msg): message(msg) {}
};


#endif //CORI_SSHCONNECTIONEXCEPTION_H