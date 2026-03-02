//
// Created by mathieu on 2/15/26.
//

#include "Ssh.h"

#include <format>

#include "exceptions/SshConnectionException.h"

void Ssh::connect() {
    int rc = ssh_connect(this->session_);

    if (rc != SSH_OK) {
        throw SshConnectionException(std::format("Unable to establish ssh connection %s", ssh_get_error(this->session_)).c_str());
    }
}

void Ssh::disconnect() {
    ssh_disconnect(this->session_);
    ssh_free(this->session_);
}

void Ssh::execute(std::string& cmd) {
    int res;

    const ssh_channel channel = ssh_channel_new(this->session_);
    res = ssh_channel_open_session(channel);

    if (res != SSH_OK) {
        ssh_channel_free(channel);
        throw SshConnectionException("Unable to open ssh session");
    }

    res = ssh_channel_request_exec(channel, cmd.c_str());
    if (res != SSH_OK) {
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        throw SshConnectionException("Unable to send command over ssh channel");
    }

    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
}

void Ssh::upload_directory() {

}

void Ssh::upload_file() {

}
