//
// Created by mathieu on 2/6/26.
//

#include "HttpRequest.h"

#include <iostream>

#include "spdlog/spdlog.h"

template<>
HttpResponse<std::string> HttpRequest::send<std::string>() {
    std::string readBuffer;
    std::string methodString;
    std::string x;

    curl_easy_setopt(this->curl_, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(this->curl_, CURLOPT_WRITEFUNCTION, WriteCallback);

    spdlog::debug("Sending curl request");
    CURLcode res = curl_easy_perform(this->curl_);

    if (res != CURLE_OK) {
        spdlog::error("Error during curl request");
        throw "";
    }

    long http_code = 0;
    curl_easy_getinfo(this->curl_, CURLINFO_RESPONSE_CODE, &http_code);

    return HttpResponse(http_code, readBuffer);
}

template<>
HttpResponse<json> HttpRequest::send<json>() {
    HttpResponse<std::string> response = this->send<std::string>();
    std::cout << response.getBody() << std::endl;
    // Wasted double object creation. Change!
    return HttpResponse(100, json::parse(response.getBody()));
}

size_t HttpRequest::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

