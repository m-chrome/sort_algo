#define SORTINGS_HPP

/* Массив данных о лотерейных билетах: номер билета,
 * номинальная стоимость, дата лотереи, сумма выигрыша
 * (сравнение по полям – дата лотереи, стоимость, номер)
 *
 * Сначала сортировать по дате, потом по стоимости,
 * потом по номеру билета
 * */


#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;

namespace ticket {

    class Ticket
    {
        private:

            size_t number;
            long double cost;
            size_t date;
            long double prize;

        public:

            // Конструктор класса Ticket
            Ticket()
            {}

            // Деструктор класса Ticket
            ~Ticket()
            {}

            // Заполнение данных по одному билету
            // НОМЕР ЦЕНА ДАТА ВЫИГРЫШ
            void fill_ticket(size_t tNum, long double tCost,
                             size_t tDate, long double tPrize)
            {
                number=tNum;
                cost=tCost;
                date=tDate;
                prize=tPrize;
            }

            /*
            bool operator==(const Ticket& other)
            {
                return (date==other.date) && (cost==other.cost) && (number==other.number);
            }*/

            bool operator<(const Ticket& other)
            {
                if (date!=other.date) return date<other.date;
                if (cost!=other.cost) return cost<other.cost;
                //if (number!=other.number)
                return number<other.number;

            }

            void showData()
            {
                cout << date << " " << cost << " " << number << " " << prize << endl;
            }
    };
}

#endif // SORTINGS_HPP
