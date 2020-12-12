#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

class LRUCache
{
    // хранить ключи кэша
    list<int> dq;

    // хранить ссылки ключа в кэше
    unordered_map<int, list<int>::iterator> ma;
    int csize; //максимальная емкость кэша

public:
    LRUCache(int);
    void refer(int);
    void display();
};

LRUCache::LRUCache(int n)
{
    csize = n;//размер кэша
}

/* Ссылается на ключ x в кэше LRU */
void LRUCache::refer(int x)
{
    //нет в кэше
    if (ma.find(x) == ma.end()){
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
    for (auto it = dq.begin(); it != dq.end();
        it++)
        cout << (*it) << " ";

    cout << endl;
}

// Программа драйвера для тестирования вышеуказанных функций
int main()
{
    LRUCache ca(4);//размер кэша

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.refer(36);
    ca.refer(546);
    ca.refer(1);
    ca.refer(8);
    ca.refer(7);
    ca.refer(0);

    ca.display();

    return 0;
}