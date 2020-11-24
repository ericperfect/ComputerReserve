//
// Created by Eric on 2020/11/23.
//
#include <iostream>
#include "Identity.h"
#include <fstream>
#include "GlobalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;

void studentMenu(Identity *&student)
{
    while (true)
    {
        student->operMenu();
        Student *stu = (Student *) student;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            stu->applyOrder();
        }
        else if (select == 2)
        {
            stu->showMyOrder();
        }
        else if (select == 3)
        {
            stu->showAllOrder();
        }
        else if (select == 4)
        {
            stu->cancelOrder();
        }
        else
        {
            delete student;
            cout << "注销成功" << endl;
            getchar();
            getchar();
            system("clear");
            return;
        }
    }
}

void teacherMenu(Identity *&teacher)
{
    while (true)
    {
        teacher->operMenu();
        Teacher *tea = (Teacher *) teacher;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功" << endl;
            getchar();
            getchar();
            system("clear");
            return;
        }
    }
}

void managerMenu(Identity *&manager)
{
    while (true)
    {
        manager->operMenu();
        Manager *man = (Manager *) manager;
        int select = 0;
        cin >> select;

        if (select == 1)
        {
//            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if (select == 2)
        {
//            cout << "查看账号" << endl;
            man->showPerson();
        }
        else if (select == 3)
        {
//            cout << "查看机房" << endl;
            man->showComputer();
        }
        else if (select == 4)
        {
//            cout << "清空预约" << endl;
            man->cleanFile();
        }
        else
        {
            delete manager;
            cout << "注销成功" << endl;
            getchar();
            getchar();
            system("clear");
            return;
        }

    }
}


void loginIn(string fileName, int type)
{
    Identity *person = NULL;

    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    int id = 0;
    string name;
    string pwd;

    if (type == 1)    //学生登录
    {
        cout << "请输入你的学号" << endl;
        cin >> id;
    }
    else if (type == 2) //教师登录
    {
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;

    cout << "请输入密码： " << endl;
    cin >> pwd;


    if (type == 1)
    {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "学生验证登录成功" << endl;
                getchar();
                getchar();
                system("clear");
                person = new Student(id, name, pwd);

                studentMenu(person);
                return;
            }
        }
    }
    else if (type == 2)
    {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd)
        {
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "老师验证登录成功" << endl;
                getchar();
                getchar();
                system("clear");
                person = new Teacher(id, name, pwd);
                teacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3)
    {
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd)
        {
            if (fName == name && fPwd == pwd)
            {
                cout << "管理员验证登录成功" << endl;
                getchar();
                getchar();
                system("clear");
                person = new Manager(name, pwd);
                managerMenu(person);
                return;
            }
        }
    }

    cout << "验证登录失败!" << endl;

}


int main()
{
    int select = 0;

    while (true)
    {
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select; //接受用户选择

        switch (select)
        {
            case 1:  //学生身份
                loginIn(STUDENT_FILE, 1);
                break;
            case 2:  //老师身份
                loginIn(TEACHER_FILE, 2);
                break;
            case 3:  //管理员身份
                loginIn(ADMIN_FILE, 3);
                break;
            case 0:  //退出系统
                cout << "欢迎下一次使用" << endl;
                getchar();
                getchar();
                return 0;
            default:
                cout << "输入有误，请重新选择！" << endl;
                getchar();
                getchar();
                system("clear");
                break;
        }
    }
}