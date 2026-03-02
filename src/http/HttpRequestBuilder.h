//
// Created by mathieu on 2/6/26.
//

#ifndef CORI_HTTPREQUESTBUILDER_H
#define CORI_HTTPREQUESTBUILDER_H

#include <string>
#include <vector>
#include <nlohmann/json_fwd.hpp>

#include "HttpRequest.h"
#include "RequestMethod.h"

class HttpRequestBuilder {
private:
    CURL* curl;
    curl_slist* headers = nullptr;

public:
    HttpRequestBuilder(): curl(curl_easy_init()) {}
    HttpRequest build();

    HttpRequestBuilder& method(RequestMethod method);
    HttpRequestBuilder& GET();
    HttpRequestBuilder& POST();
    HttpRequestBuilder& PUT();
    HttpRequestBuilder& DELETE();

    HttpRequestBuilder& setHeaders(const std::vector<std::string> &headers);
    HttpRequestBuilder& addHeader(const std::string &header);
    HttpRequestBuilder& setURL(const std::string &URL);
    HttpRequestBuilder& setUnixSocket(const std::string &socket);

    HttpRequestBuilder& setBody(const std::string &body);
    HttpRequestBuilder& setVerbose();

    CURL* getCurl();
};


#endif //CORI_HTTPREQUESTBUILDER_H