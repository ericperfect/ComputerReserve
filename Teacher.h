//
// Created by Eric on 2020/11/23.
//

#ifndef COMPUTERRESERVE_TEACHER_H
#define COMPUTERRESERVE_TEACHER_H

#include <iostream>
#include "Identity.h"
#include "OrderFile.h"
#include <vector>

using namespace std;

class Teacher : public Identity
{
public:
    Teacher();

    Teacher(int id, string name, string pwd);

    virtual void operMenu();

    void showAllOrder();

    void validOrder();

    int m_EmpId;
};


#endif //COMPUTERRESERVE_TEACHER_H
