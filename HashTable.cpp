
#include <iostream>
#include "HashTable.h"
#include <vector>
#include <chrono>

int main()
{
    HashTable<int> t1(10000);
    std::vector<int> v1 = {};
    
    //for (int i{ 0 }; i < 10; i++) {
    //    t1.Insert(0);
    //}

    //t1.Insert(10000);
    //t1.Insert(2500);
    //t1.Insert(5389344);
    //t1.Insert(18230);

    //int find = 18230;

    //if (t1.Contains(find)) {
    //    std::cout << find << std::endl;
    //}
    //else {
    //    std::cout << "not found" << std::endl;
    //}

    //find = 20304;

    //if (t1.Contains(find)) {
    //    std::cout << find << std::endl;
    //}
    //else {
    //    std::cout << "not found" << std::endl;
    //}

    //t1.Print();

    for (int i = 0; i < 500000; i++) {
        t1.Insert(i * 2);
        v1.push_back(i * 2);
    }

    int find = 999998;

    //VECTOR PERFORMANCE
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] == find)
            break;
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Vector Find Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() <<std::endl;

    //HASH TABLE PERFORMANCE

    std::chrono::steady_clock::time_point timer1 = std::chrono::steady_clock::now();

    bool found = t1.Contains(find);

    std::chrono::steady_clock::time_point timer2 = std::chrono::steady_clock::now();

    std::cout << "HashTable Find Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(timer2 - timer1).count() << std::endl;


}
