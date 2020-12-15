#include "CLass_LRU.h"

LRUCache::LRUCache(int n)
{
    csize = n;//������ ����
}


void LRUCache::refer(int x)
{
    //��� � ����
    if (ma.find(x) == ma.end()) {
        // ��� �������� 
        if (dq.size() == csize)
        {
            //�������� �������� ����� ������������� ��������
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    //������������ � ���� 
    else { dq.erase(ma[x]); }

    //����������
    dq.push_front(x);
    ma[x] = dq.begin();
}

// ����������� ����������� ���� 
void LRUCache::display()
{
    cout << "��� �� ������ ������: ";
    for (auto it = dq.begin(); it != dq.end();
        it++)
        cout << (*it) << " ";

    cout << endl;
}