#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Student {
    string name;
    int score;

    // 重载<运算符
    bool operator <(const Student& oStudent) {
        return score != oStudent.score ?
            score < oStudent.score :
            name < oStudent.name;
    }

    // 重载<<符号, 定义Student实例的打印输出方式
    friend ostream& operator<<(ostream &os, const Student &student) {

        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};