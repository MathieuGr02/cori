//
// Created by mathieu on 1/29/26.
//

#ifndef CORI_STORE_H
#define CORI_STORE_H
#include "Object.h"


class Store:
    public Object
{
    void create() override;
    void setup() override;
    void deploy() override;
};


#endif //CORI_STORE_H