#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstddef>

#include "sortings.hpp"

using namespace std;
using namespace ticket;

// Функция сортирует вектор объектов
// класса T методом сортировки выбором
template <class T>
void selection_sort(size_t size, vector<T> &a)
{
    for(size_t i=0; i<size; ++i)
    {
        size_t min_value=i;

        for(size_t j=i+1; j<size; ++j)
        {
            if (a[j]<a[min_value])
            {
                min_value=j;
            }
        }
        if (i != min_value)
        {
            swap(a[i], a[min_value]);
        }
    }
}

// Функция формирует бинарное сортирующее дерево
template <class T>
void shiftDown(vector <T> &a, size_t i, size_t length)
{
    size_t left = 2*i+1;
    size_t right = left+1;
    size_t maxChild = left;
    while (maxChild < length)
    {
        if (right < length)
        {
            if (a[left] < a[right])
            {
                maxChild = right;
            }
        }
        if (a[i]<a[maxChild])
        {
            swap(a[i], a[maxChild]);
        }
        else
        {
            break;
        }
        i=maxChild;
        left=2*i+1;
        right=left+1;
        maxChild=left;
    }
}

// Функция сортирует вектор объектов
// класса T методом пирамидальной сортировки
template <class T>
void heap_sort(size_t size, vector <T> &a)
{
    int i;
    for(i=size/2 - 1; i>=0; i--)
    {
        shiftDown(a, i, size);
    }
    for(i=size-1; i>0; i--)
    {
        swap(a[0], a[i]);
        shiftDown(a, 0, i);
    }
}


int main()
{
    srand(time(0));
    ifstream data_list;
    data_list.open("ticket_list.txt");
    if (!data_list)
    {
        cout << "Can't open file!"<< endl;
        return 1;
    }

    size_t number;
    long double cost;
    size_t date;
    long double prize;

    vector <Ticket> tickets_select, tickets_heap;

    // Заполняем вектор билетов данными из файла
    while(data_list >> number >> cost >> date >> prize)
    {
        Ticket item;
        item.fill_ticket(number, cost, date, prize);
        tickets_select.push_back(item);
        tickets_heap.push_back(item);
    }

    cout << "Tickets data clist:" << endl;
    for(auto &it: tickets_select)
    {
        it.showData();
    }
    cout << endl;

    // Размер векторов
    size_t list_size = tickets_select.size();
    cout << "Size of ticket list: " << list_size << " items." << endl<< endl;

    // Таймер для засечки времени
    double *timer = new double[2];

    // Сортировка выбором
    cout << "SELECTION SORT" << endl;
    timer[0]=clock()/1000.0;
    selection_sort(list_size, tickets_select);
    timer[1]=clock()/1000.0;
    cout << "Runtime: " << timer[1]-timer[0] << " sec." << endl << endl;

    // Сортировка кучей
    cout << "HEAP SORT" << endl;
    timer[0]=clock()/1000.0;
    heap_sort(list_size, tickets_heap);
    timer[1]=clock()/1000.0;
    cout << "Runtime: " << timer[1]-timer[0] << " sec." << endl << endl;

    // Итоговый отсортированный список (по возрастанию)
    cout << "Sorted list: \n";
    for(auto &it: tickets_select)
    {
        it.showData();
    }
    cout << endl;

    delete[] timer;

    data_list.close();

    return 0;
}
