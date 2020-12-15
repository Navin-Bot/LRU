#include "CLass_LRU.h"




int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size_hash;
    cout << "Размер кэша?" << endl << ">_";
    do {
        cin >> size_hash;
    } while (size_hash <= 0);

    LRUCache ca(size_hash);//размер кэша

    int num;
    while (true) {
        cout << endl;
        cout << ">_"; cin >> num;
        ca.refer(num);

        ca.display();

    }

    return 0;
}