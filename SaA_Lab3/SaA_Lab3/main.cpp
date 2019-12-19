//
//  main.cpp
//  SaA_Lab3
//
//  Created by Олег Джинганин on 19.12.2019.
//  Copyright © 2019 Олег Джинганин. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

/////////////////////////////Алгоритмы поиска в неупорядоченных массивах
unsigned linear_search(const int* arr, const int des, const unsigned sz)
{
    unsigned comp_num = 0;
    unsigned i;
    for (i = 0; i < sz; i++)
    {
        comp_num++;
        if(arr[i] == des) break;
    }
    return comp_num;
}
              //Линейный

unsigned fast_linear_search_for_disordered(const int* arr, const int des, const unsigned sz)
{
    unsigned comp_num = 0;
    int* new_array = new int[sz + 1];
    new_array[sz] = des;
    for (unsigned j = 0; j < sz; j++)
    {
        new_array[j] = arr[j];
    }
    unsigned i;
    for (i = 0; ; i++)
    {
        comp_num++;
        if (new_array[i] == des)
        {
            if (i == sz) break;     //Элемент не найден
            else break;             //Элемент найден
        }
    }
    delete[] new_array;
    return comp_num;
}
 //Быстрый линейный (У)
/////////////////////////////Алгоритмы поиска в упорядоченных массивах
unsigned fast_linear_search_for_ordered(const int* arr, const int des, const unsigned sz)
{
    unsigned comp_num = 0;
    int* new_array = new int[sz + 1];
    new_array[sz] = des;
    for (unsigned j = 0; j < sz; j++)
    {
        new_array[j] = arr[j];
    }
    unsigned i;
    for (i = 0; ; i++)
    {
        if (new_array[i] > des) break;    //В массиве нет элемента
        comp_num++;
        if (new_array[i] == des)
        {
            if (i == sz) break;     //Элемент не найден
            else break;             //Элемент найден
        }
    }
    delete[] new_array;
    return comp_num;
}
 //Быстрый линейный (НУ)
unsigned binary_search(const int* arr, const int des, const unsigned sz)
{
    unsigned comp_num = 0;
    unsigned right = sz - 1;
    unsigned left = 0;
    unsigned middle = 0;
    for (;;)
    {
        middle = (left + right) / 2;
        comp_num++;
        if (arr[middle] == des) break;
        else
        {
            comp_num++;
            if (arr[middle] > des) right = middle - 1;
            else
            {
                comp_num++;
                if (arr[middle] < des) left = middle + 1;
            }
        }
        if (left > right) break;
    }
    return comp_num;
}
                       //Бинарный
unsigned block_search(const int* arr, const int des, const unsigned sz)
{
    unsigned comp_num = 1;
    unsigned i;
    int j = 0;
    unsigned block = sz / 10;   //Разбиваем массив на равные блоки, содержащие по 10 элементов
    i = block - 1;
    while (des > arr[i])        //Просматриваем последний элемент каждого блока
    {
        comp_num++;
        i += block;
    }
    for (j = i - block + 1; j < i; j++)    //Линейный поиск в нужном блоке
    {
        comp_num++;
        if (arr[j] == des) break;
    }
    return comp_num;
}
                   //Блочный
/////////////////////////////Заполнение массива с количествами операций сравнения
void fill_comparisons_array(unsigned* c_arr, const unsigned sz, unsigned(*ptr)(const int*, const int, const unsigned),
                            const int* arr)
{
    unsigned i;
    for (i = 0; i < sz; i++) c_arr[i] = ptr(arr, arr[i], sz);
}

/////////////////////////////Нахождения максимального количества операций сравнения
unsigned max_comparisons_number(const unsigned* arr, const unsigned sz)
{
    unsigned i, mc_index, mc_num;
    for (i = 1, mc_index = i - 1, mc_num = arr[mc_index]; i < sz; i++)
    {
        if (arr[mc_index] < arr[i])
        {
            mc_index = i;
            mc_num = arr[mc_index];
        }
    }
    return mc_num;
}

/////////////////////////////Нахождения среднего числа операций сравнения
unsigned comparisons_average_number(const unsigned* arr, const unsigned sz)
{
    unsigned i;
    unsigned sum = 0;
    for (i = 0; i < sz; i++) sum += arr[i];
    return sum / sz;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
