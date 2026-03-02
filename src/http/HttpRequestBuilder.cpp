//
// Created by mathieu on 2/6/26.
//

#include "HttpRequestBuilder.h"

#include <iostream>

#include "RequestMethod.h"
#include "spdlog/spdlog.h"

HttpRequestBuilder &HttpRequestBuilder::setHeaders(const std::vector<std::string> &headers) {
    for (auto& header: headers) {
        this->headers = curl_slist_append(this->headers, header.c_str());
    }
    int res = curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, this->headers);

    if (res != CURLE_OK) {
        spdlog::error("Error while setting request headers. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::addHeader(const std::string &header) {
    this->headers = curl_slist_append(this->headers, header.data());
    int res = curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, this->headers);
    if (res != CURLE_OK) {
        spdlog::error("Error while adding request header. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::setURL(const std::string &URL) {
    int res = curl_easy_setopt(this->curl, CURLOPT_URL, URL.c_str());
    if (res != CURLE_OK) {
        spdlog::error("Error while setting URL. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder& HttpRequestBuilder::setUnixSocket(const std::string &socket) {
    int res = curl_easy_setopt(this->curl, CURLOPT_UNIX_SOCKET_PATH, socket.c_str());
    if (res != CURLE_OK) {
        spdlog::error("Error while setting unix socket path. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::method(const RequestMethod method) {
    switch (method) {
        case RequestMethod::GET: { GET(); break; }
        case RequestMethod::POST: { POST(); break; }
        case RequestMethod::PUT: { PUT(); break; }
        case RequestMethod::DELETE: { DELETE(); break; }
    }

    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::GET() {
    spdlog::debug("Setting GET method");
    int res = curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "GET");
    if (res != CURLE_OK) {
        spdlog::error("Error while setting GET request method. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::POST() {
    spdlog::debug("Setting POST method");
    int res = curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "POST");
    if (res != CURLE_OK) {
        spdlog::error("Error while setting POST request method. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::PUT() {
    spdlog::debug("Setting PUT method");
    int res = curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "PUT");
    if (res != CURLE_OK) {
        spdlog::error("Error while setting PUT request method. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::DELETE() {
    spdlog::debug("Setting DELETE method");
    int res = curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    if (res != CURLE_OK) {
        spdlog::error("Error while setting DELETE request method. Error {}", res);
    }
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::setBody(const std::string &body) {
    std::cout << body << std::endl;

    int res = curl_easy_setopt(this->curl, CURLOPT_POSTFIELDS, body.data());
    if (res != CURLE_OK) {
        spdlog::error("Error while setting request body. Error {}", res);
    }
    res = curl_easy_setopt(this->curl, CURLOPT_POSTFIELDSIZE, body.size());
    if (res != CURLE_OK) {
        spdlog::error("Error while setting request body size. Error {}", res);
    }
    return *this;
}

HttpRequest HttpRequestBuilder::build() {
    return HttpRequest(this->curl);
}

CURL *HttpRequestBuilder::getCurl() {
    return this->curl;
}

HttpRequestBuilder &HttpRequestBuilder::setVerbose() {
    curl_easy_setopt(this->curl, CURLOPT_VERBOSE, 1L);
    return *this;
}


