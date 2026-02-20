//
// Created by mathieu on 2/18/26.
//

#ifndef CORI_CONFIG_H
#define CORI_CONFIG_H

#include "util/JsonDeserializable.h"

enum LOG_LEVEL {
    INFO,
    TRACE,
    DEBUG,
    WARN,
    ERROR
};

class Config:
    public JsonDeserializable<Config>
{
protected:
    static Config fromJsonInternal(json j);

public:
    LOG_LEVEL log_level;
};


#endif //CORI_CONFIG_H