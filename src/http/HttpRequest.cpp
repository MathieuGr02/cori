//
// Created by mathieu on 2/6/26.
//

#include "HttpRequest.h"

#include <iostream>

#include "spdlog/spdlog.h"

HttpResponse HttpRequest::send() const {
    std::string readBuffer;
    std::string methodString;
    std::string x;

    curl_easy_setopt(this->curl_, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(this->curl_, CURLOPT_WRITEDATA, &readBuffer);

    curl_easy_setopt(this->curl_, CURLOPT_CONNECTTIMEOUT_MS, 5000L);
    curl_easy_setopt(this->curl_, CURLOPT_TIMEOUT_MS, 5000L);

    spdlog::trace("Sending curl request");
    CURLcode res = curl_easy_perform(this->curl_);

    spdlog::trace("Curl response {}", static_cast<int>(res));
    if (res != CURLE_OK) {
        spdlog::error("Error during curl request");
        throw "";
    }

    long http_code = 0;
    curl_easy_getinfo(this->curl_, CURLINFO_RESPONSE_CODE, &http_code);

    std::cout << std::boolalpha << (readBuffer == "") << std::endl;

    return HttpResponse(http_code, readBuffer);
}

size_t HttpRequest::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

