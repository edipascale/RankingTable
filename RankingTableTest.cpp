/* 
 * File:   main.cpp
 * Author: Emanuele
 *
 * Created on 29 July 2014, 17:25
 */

#include <cstdlib>

#include "RankingTable.hpp"
using namespace std;

int main(int argc, char** argv) {    
    RankingTable<int> table;
    table.insert(0);
    table.insert(1);
    table.insert(2);
    const auto rightMap = table.getRightMap();
    table.printRanking();
    cout << endl << "Hit at element 2" << endl;
    table.hit(2);
    cout << endl << "Hit at element 2" << endl;
    table.hit(2);
    table.printRanking();
    cout << endl << "Hit at element 0" << endl;
    table.hit(0);
    table.printRanking();
    cout << endl << "Erasing element 1" << endl;
    table.erase(1);
    table.printRanking();
    cout << endl << "Inserting element 3" << endl;
    table.insert(3);
    table.printRanking();
    cout << endl << "2xHit at element 3" << endl;
    table.hit(3);
    table.hit(3);
    table.printRanking();
    return 0;
}

