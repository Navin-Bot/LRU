#include "CLass_LRU.h"

LRUCache::LRUCache(int n)
{
    csize = n;//размер кэша
}


void LRUCache::refer(int x)
{
    //нет в кэше
    if (ma.find(x) == ma.end()) {
        // кэш заполнен 
        if (dq.size() == csize)
        {
            //удаления наименее часто используемого элемента
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    //присутствует в кэше 
    else { dq.erase(ma[x]); }

    //Добавление
    dq.push_front(x);
    ma[x] = dq.begin();
}

// отображение содержимого кэша 
void LRUCache::display()
{
    cout << "Кэш на данный момент: ";
    for (auto it = dq.begin(); it != dq.end();
        it++)
        cout << (*it) << " ";

    cout << endl;
}