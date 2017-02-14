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
    string server, name, id, input;
    int serving = 0, timer = 0;

    while(cin >> input) {
        if(input == "end") {
            break;
        }

        if(name == "table") {
            cin >> name >> serving >> server;
            Table orderUp(name, serving, server);
            available.append(orderUp);
        } else if (name == "party") {
            cin >> serving >> name >> timer;
            Party orderOut(name, serving, timer);
            waiting.append(orderOut);
        }
    }
}

void Restaurant::serveParties() {
    
}