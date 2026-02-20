//
// Created by mathieu on 2/10/26.
//

#ifndef CORI_SPAWNABLE_H
#define CORI_SPAWNABLE_H


class Spawnable {
public:
    virtual ~Spawnable() = default;

    virtual void create() = 0;
    virtual void setup() = 0;
    virtual void deploy() = 0;
};


#endif //CORI_SPAWNABLE_H