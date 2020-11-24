//
// Created by Eric on 2020/11/23.
//

#ifndef COMPUTERRESERVE_ORDERFILE_H
#define COMPUTERRESERVE_ORDERFILE_H

#include <iostream>
#include <map>
#include <fstream>
#include "GlobalFile.h"

using namespace std;

class OrderFile
{
public:
    OrderFile();

    void updateOrder();

    int m_Size;

    map<int, map<string,string>>m_orderData;
};


#endif //COMPUTERRESERVE_ORDERFILE_H
