//
// Created by Eric on 2020/11/23.
//

#ifndef COMPUTERRESERVE_STUDENT_H
#define COMPUTERRESERVE_STUDENT_H

#include <iostream>

using namespace std;

#include <vector>
#include "Identity.h"
#include "ComputerRoom.h"
#include "GlobalFile.h"
#include <fstream>
#include "OrderFile.h"

class Student : public Identity
{
public:
    Student();

    Student(int id, string name, string pwd);

    virtual void operMenu();

    void applyOrder();

    void showMyOrder();

    void showAllOrder();

    void cancelOrder();

    int m_Id;

    vector<ComputerRoom> vCom;
};


#endif //COMPUTERRESERVE_STUDENT_H
