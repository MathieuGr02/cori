//
// Created by mathieu on 2/6/26.
//

#include "HttpRequestBuilder.h"

#include <iostream>

#include "RequestMethod.h"
#include "spdlog/spdlog.h"

HttpRequestBuilder &HttpRequestBuilder::setHeaders(std::vector<std::string> headers) {
    for (auto& header: headers) {
        this->headers = curl_slist_append(this->headers, header.c_str());
    }
    curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, this->headers);

    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::addHeader(const std::string &header) {
    this->headers = curl_slist_append(this->headers, header.c_str());
    curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, this->headers);

    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::setURI(const std::string &URI) {
    curl_easy_setopt(this->curl, CURLOPT_URL, URI.c_str());
    return *this;
}

HttpRequestBuilder& HttpRequestBuilder::setUnixSocket(const std::string &socket) {
    curl_easy_setopt(this->curl, CURLOPT_UNIX_SOCKET_PATH, socket.c_str());
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::method(const RequestMethod method) {
    std::cout << method << std::endl;
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
    curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "GET");
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::POST() {
    spdlog::debug("Setting POST method");
    curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "POST");
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::PUT() {
    spdlog::debug("Setting PUT method");
    curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "PUT");
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::DELETE() {
    spdlog::debug("Setting DELETE method");
    curl_easy_setopt(this->curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    return *this;
}

HttpRequestBuilder &HttpRequestBuilder::setBody(std::string body) {
    curl_easy_setopt(this->curl, CURLOPT_POSTFIELDS, body.c_str());
    return *this;
}

HttpRequest HttpRequestBuilder::build() {
    return HttpRequest(this->curl);
}


