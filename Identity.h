//
// Created by Eric on 2020/11/23.
//

#ifndef COMPUTERRESERVE_IDENTITY_H
#define COMPUTERRESERVE_IDENTITY_H

#include <iostream>

using namespace std;

class Identity
{
public:

    virtual void operMenu() = 0;

    string m_Name;
    string m_Pwd;
};


#endif //COMPUTERRESERVE_IDENTITY_H
