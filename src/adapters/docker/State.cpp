//
// Created by mathieu on 2/5/26.
//

#include "State.h"

State State::fromString(std::string s) {
    if (s == "created") return Created;
    if (s == "running") return Running;
    if (s == "restarting") return Restarting;
    if (s == "exited") return Exited;
    if (s == "paused") return Paused;
    if (s == "dead") return Dead;
}

std::string State::toString() {
    switch (this->value) {
        case Created:
            return "Created";
        case Running:
            return "Running";
        case Restarting:
            return "Restarting";
        case Exited:
            return "Exited";
        case Paused:
            return "Paused";
        case Dead:
            return "Dead";
    }
}

json State::toJson() {
    return this->toString();
}

State State::fromJsonInternal(json j) {
    return fromString(j["State"]);
}
