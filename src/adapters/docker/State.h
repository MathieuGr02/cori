//
// Created by mathieu on 2/5/26.
//

#ifndef CORI_STATE_H
#define CORI_STATE_H
#include <string>

#include "../../util/JsonDeserializable.h"
#include "../../util/JsonSerializable.h"


class State:
    public JsonDeserializable<State>,
    public JsonSerializable
{
public:
    enum Enum {
        Created,
        Running,
        Restarting,
        Exited,
        Paused,
        Dead
    };

    Enum value;

    State() {
        this->value = Dead;
    }

    State(const Enum value) {
        this->value = value;
    }

    static State fromJsonInternal(json j);
    json toJson() override;
    static State fromString(std::string s);
    std::string toString();
};


#endif //CORI_STATE_H