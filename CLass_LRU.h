#pragma once
#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <Windows.h>
using namespace std;





class LRUCache
{
    // ������� ����� ����
    list<int> dq;

    unordered_map<int, list<int>::iterator> ma;
    int csize; //������������ ������� ����

public:
    LRUCache(int);
    void refer(int);
    void display();
};

