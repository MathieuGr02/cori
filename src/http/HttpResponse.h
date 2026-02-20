//
// Created by mathieu on 2/6/26.
//

#ifndef CORI_HTTPRESPONSE_H
#define CORI_HTTPRESPONSE_H
#include <nlohmann/json.hpp>

#include "HttpStatus.h"

using json = nlohmann::json;

template <typename T>
class HttpResponse {
private:
    HttpStatus status_;
    T body;

public:
    HttpResponse(uint16_t code, T body):
        status_(static_cast<HttpStatus>(code)),
        body(std::move(body))
    {}

    [[nodiscard]]
    T getBody() { return this->body; };

    [[nodiscard]]
    HttpStatus getStatusCode() const { return this->status_; };

    [[nodiscard]]
    bool informationalResponse() const {
        return this->status_ / 100 == 1;
    }

    [[nodiscard]]
    bool success() const {
        return this->status_ / 100 == 2;
    }

    [[nodiscard]]
    bool redirect() const {
        return this->status_ / 100 == 3;
    }

    [[nodiscard]]
    bool clientError() const {
        return this->status_ / 100 == 4;
    }

    [[nodiscard]]
    bool serverError() const {
        return this->status_ / 100 == 5;
    }
};


#endif //CORI_HTTPRESPONSE_H