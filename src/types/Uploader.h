//
// Created by mathieu on 2/15/26.
//

#ifndef CORI_UPLOADER_H
#define CORI_UPLOADER_H
#include <string>

class Uploader {
public:
    virtual ~Uploader() = default;

    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void execute(std::string& cmd) = 0;

    virtual void upload_file() = 0;
    virtual void upload_directory() = 0;
};


#endif //CORI_UPLOADER_H