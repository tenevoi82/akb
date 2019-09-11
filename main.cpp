/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tenevoi
 *
 * Created on 12 августа 2019 г., 15:31
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>  
#include <iomanip>

using namespace std;

int srednee(vector<int> b) {

}

int summa(vector<int> b) {
    int summa = 0;
    for (auto it = b.begin(); it != b.end(); it++)
    {
        summa += *it;
    }
    return summa;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void PrintBattery(vector<int> bank[], int paralel, int serial, float srednee) {
    srednee = srednee * 3;
    for (int p = 0; p < paralel; p++)
    {
        for (int i = 0; i < serial; i++)
            cout << bank[i].at(p) << "\t";
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------\r\n";
    for (int i = 0; i < serial; i++)
    {
        cout << summa(bank[i]) << "\t";
    }
    cout << endl;
    for (int i = 0; i < serial; i++)
    {
        cout << fixed << setprecision(2) << abs(srednee - summa(bank[i])) / srednee * 100 << "%\t";
    }
    cout << endl;
}

void f(vector<int> b[], int size, int srednee) {

    for (int workcolumn = 0; workcolumn < size; workcolumn++)
        for (int workcell = 0; workcell < b[workcolumn].size(); workcell++)
        {
            int summ = 0;
            for (int i = 0; i < b[workcolumn].size(); i++)
            {
                summ += b[workcolumn].at(i);
            }
            summ -= b[workcolumn].at(workcell);
            int variants[size];
            int min = 100000;
            int minpos = workcolumn;
            for (int i = workcolumn; i < size; i++)
            {
                variants[i] = summ + b[i].at(workcell);
                variants[i] = abs(srednee - variants[i]);
                if (min > variants[i])
                {
                    min = variants[i];
                    minpos = i;
                }
            }
            if (workcolumn != minpos)
            {
                //cout << "меняем " << workcolumn << " c " << minpos << endl;
                swap(b[workcolumn].at(workcell), b[minpos].at(workcell));
            }
        }
}

/*
 * 
 */
int main(int argc, char** argv) {


    vector<int> battrey{
        2472, 1564, 1932, 1657, 2070, 2278, 1900, 2137, 1797, 2116, 1787, 1661, 2027,
        1823, 1907, 2241, 1968, 2078, 2002, 1962, 1730, 1577, 1808, 1898, 1667, 1683,
        1783, 1585, 2072, 1641, 1799, 1971, 1916, 1579, 1716, 1761, 1952, 1586, 1596 };
    vector<int> bank[13];

    srand(98567433);
    cout << "Дано: ";

    //    for (int i = 0; i < 91; i++)
    //    {
    //        int r = 1 + rand() % 10000;
    //        battrey.push_back(r);
    //        cout << " " << r;
    //    }

    for (auto it = battrey.begin(); it != battrey.end(); it++)
    {
        cout << *it << " ";
    }


    cout << endl;

    sort(battrey.begin(), battrey.end());
    cout << "После сортировки: ";
    int all_amp = 0;
    for (auto it = battrey.begin(); it != battrey.end(); it++)
    {
        int cur = *it;
        all_amp += cur;
        cout << " " << cur;
    }
    cout << endl;
    cout << "Сумма ёмкостей: " << all_amp << endl;



    int srednee = all_amp / battrey.size();
    cout << "Среднее значение: " << srednee << endl;
    cout << "Один банк должен быть примерно: " << srednee * 7 << endl;



    for (int i = 0; i < battrey.size();)
    {
        bank[0].push_back(battrey.at(i++));
        bank[1].push_back(battrey.at(i++));
        bank[2].push_back(battrey.at(i++));
        bank[3].push_back(battrey.at(i++));
        bank[4].push_back(battrey.at(i++));
        bank[5].push_back(battrey.at(i++));
        bank[6].push_back(battrey.at(i++));
        bank[7].push_back(battrey.at(i++));
        bank[8].push_back(battrey.at(i++));
        bank[9].push_back(battrey.at(i++));
        bank[10].push_back(battrey.at(i++));
        bank[11].push_back(battrey.at(i++));
        bank[12].push_back(battrey.at(i++));

        if (i >= battrey.size())break;

        bank[12].push_back(battrey.at(i++));
        bank[11].push_back(battrey.at(i++));
        bank[10].push_back(battrey.at(i++));
        bank[9].push_back(battrey.at(i++));
        bank[8].push_back(battrey.at(i++));
        bank[7].push_back(battrey.at(i++));
        bank[6].push_back(battrey.at(i++));
        bank[5].push_back(battrey.at(i++));
        bank[4].push_back(battrey.at(i++));
        bank[3].push_back(battrey.at(i++));
        bank[2].push_back(battrey.at(i++));
        bank[1].push_back(battrey.at(i++));
        bank[0].push_back(battrey.at(i++));
    }

    PrintBattery(bank, 3, 13, srednee);

    cout << "\n\n---------------------------------------Шаманим------------------------------------------------------\r\n";
    f(bank, 13, srednee * 3);
    f(bank, 13, srednee * 3);
    //swap(bank[11].at(0), bank[12].at(0));
    //swap(bank[11].at(2), bank[12].at(2));
    swap(bank[9].at(2), bank[12].at(2));

    PrintBattery(bank, 3, 13, srednee);

    //    cout << "\n\n---------------------------------------Шаманим2------------------------------------------------------\r\n";
    //
    //    f(bank, 13, srednee * 3 * 0.000907692 + srednee * 3);
    //    f(bank, 13, srednee * 3 * 0.000392308 + srednee * 3);
    //    f(bank, 13, srednee * 3 * 0.000353846 + srednee * 3);
    //
    //    PrintBattery(bank, 3, 13, srednee);

    fflush(stdout);

    return 0;
}

