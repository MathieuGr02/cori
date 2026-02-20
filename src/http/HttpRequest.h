//
// Created by mathieu on 2/6/26.
//

#ifndef CORI_HTTPREQUEST_H
#define CORI_HTTPREQUEST_H
#include <curl/curl.h>

#include "HttpResponse.h"


class HttpRequest {
    CURL* curl_;

public:
    HttpRequest(CURL* curl): curl_(curl) {}

    template <typename T>
    HttpResponse<T> send();

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};


#endif //CORI_HTTPREQUEST_H