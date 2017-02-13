/**
 * @file restaurant.cc
 *
 * @brief
 *    Main functions utilizing table.cc and party.cc, as well as Restaurant functions
 *
 * @author Landon Mote
 * @date 2/12/2017
 */

#include <string>
#include <iostream>
#include "party.h"
#include "table.h"
#include "restaurant.h"

using namespace std;

void Restaurant::getInput() {
    string server, name, id;
    int serving_tables = 0;

    while (name != "party") {
        cin >> name >> id >> server;
        
        Table serving(name, serving_tables, server);
        available.append(serving);
    }

    while (name == "party") {

    }
}
void serveParties();