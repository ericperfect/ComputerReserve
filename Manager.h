//
// Created by Eric on 2020/11/23.
//

#ifndef COMPUTERRESERVE_MANAGER_H
#define COMPUTERRESERVE_MANAGER_H

#include <iostream>
#include "Identity.h"
#include <fstream>
#include "GlobalFile.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "ComputerRoom.h"

using namespace std;

class Manager : public Identity
{
public:
    Manager();

    Manager(string name, string pwd);

    virtual void operMenu();

    void addPerson();

    void showPerson();

    void showComputer();

    void cleanFile();

    void initVector();

    bool checkRepeat(int id, int type);

    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<ComputerRoom> vCom;
};


#endif //COMPUTERRESERVE_MANAGER_H
