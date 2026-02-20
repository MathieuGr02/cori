//
// Created by mathieu on 2/15/26.
//

#ifndef CORI_SSH_H
#define CORI_SSH_H
#include "../../types/Uploader.h"

#define LIBSSH_STATIC 1
#include <string>
#include <libssh/libssh.h>

class Ssh: public Uploader {
private:
    ssh_session session_;
    std::string host;
    std::string user;
    uint16_t port;

public:
    Ssh(std::string host, std::string user, uint16_t port): session_(ssh_new()) {
        this->host = host;
        this->user = user;
        this->port = port;
        ssh_options_set(session_, SSH_OPTIONS_HOST, &host);
        ssh_options_set(session_, SSH_OPTIONS_USER, &user);
        ssh_options_set(session_, SSH_OPTIONS_PORT, &port);
    }

    void connect() override;
    void disconnect() override;

    void execute(std::string& cmd) override;

    void upload_file() override;
    void upload_directory() override;
};


#endif //CORI_SSH_H