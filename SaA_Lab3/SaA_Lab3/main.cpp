#include <iostream>
#include <cstdlib>
#include <ctime>

/////////////////////////////Алгоритмы поиска в неупорядоченных массивах
unsigned linear_search(const int* arr, const int des, const unsigned sz)
{
    unsigned comp_num = 0;
    unsigned i;
    for (i = 0; i < sz; comp_num++, i++)
    {
        comp_num++;
        if(arr[i] == des) break;
    }
    comp_num++;
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
    for (i = 0;;i++)
    {
        comp_num++;
        if (new_array[i] == des)
        {
            comp_num++;
            if (i == sz) break;
            else break;
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
        comp_num++;
        if (new_array[i] > des) break;    //В массиве нет элемента
        comp_num++;
        if (new_array[i] == des)
        {
            comp_num++;
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
        comp_num++;
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
    unsigned block = sz / 10;   //Разбиваем массив на равные блоки
    i = block - 1;
    comp_num++;
    while (des > arr[i])        //Просматриваем последний элемент каждого блока
    {
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
void fill_comparisons_array(unsigned* c_arr, const unsigned sz, unsigned(*ptr)(const int*, const int, const unsigned),const int* arr)
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
        setlocale(0, "");
        const unsigned SIZE = 100;
        using namespace std;
        int disordered_array[SIZE];
        unsigned i;
        int j;
        srand(time(NULL));
        for (i = 0; i < SIZE; i++)
        {
            disordered_array[i] = rand();
            disordered_array[i] %= 999;     //генерация случайных чисел в диапазоне до 999
        }
        /////////////////////////////Создание упорядоченного массива
        int ordered_array[SIZE];
        for (i = 0; i < SIZE; i++) ordered_array[i] = disordered_array[i];
        for (i = 1; i < SIZE; i++)
        {
            for (j = i; j > 0 && ordered_array[j - 1] > ordered_array[j]; j--)
            {
                int temp = ordered_array[j];
                ordered_array[j] = ordered_array[j - 1];
                ordered_array[j - 1] = temp;
            }
        }
    
        unsigned comparisons_array[SIZE] = {0};
        cout << "1. АЛГОРИТМЫ ПОИСКА В НЕУПОРЯДОЧЕННОМ МАССИВЕ РАЗМЕРА " << SIZE << "\n\n";
        cout << "1.1. Линейный поиск\n";
        fill_comparisons_array(comparisons_array, SIZE, linear_search, disordered_array);
        cout << "Максимальное количество операций сравнения = " <<
        max_comparisons_number(comparisons_array, SIZE) << endl;
        cout << "Среднее количество операций сравнения = " <<
        comparisons_average_number(comparisons_array, SIZE) << endl << endl;
        cout << "1.2. Быстрый линейный поиск\n";
        fill_comparisons_array(comparisons_array, SIZE, fast_linear_search_for_disordered, disordered_array);
        cout << "Максимальное количество операций сравнения = " <<
        max_comparisons_number(comparisons_array, SIZE) << endl;
        cout << "Среднее количество операций сравнения = " <<
        comparisons_average_number(comparisons_array, SIZE) << endl << endl << endl;
        
        cout << "2. АЛГОРИТМЫ ПОИСКА В УПОРЯДОЧЕННОМ МАССИВЕ РАЗМЕРА " << SIZE << "\n\n";
        cout << "2.1. Быстрый линейный поиск\n";
        fill_comparisons_array(comparisons_array, SIZE, fast_linear_search_for_ordered, ordered_array);
        cout << "Максимальное количество операций сравнения = " <<
        max_comparisons_number(comparisons_array, SIZE) << endl;
        cout << "Среднее количество операций сравнения = " <<
        comparisons_average_number(comparisons_array, SIZE) << endl << endl;
        cout << "2.2. Бинарный поиск\n";
        fill_comparisons_array(comparisons_array, SIZE, binary_search, ordered_array);
        cout << "Максимальное количество операций сравнения = " <<
        max_comparisons_number(comparisons_array, SIZE) << endl;
        cout << "Среднее количество операций сравнения = " <<
        comparisons_average_number(comparisons_array, SIZE) << endl << endl;
        cout << "2.3. Блочный поиск\n";
        fill_comparisons_array(comparisons_array, SIZE, block_search, ordered_array);
        cout << "Максимальное количество операций сравнения = " <<
        max_comparisons_number(comparisons_array, SIZE) << endl;
        cout << "Среднее количество операций сравнения = " <<
        comparisons_average_number(comparisons_array, SIZE) << endl;

    return 0;
}
