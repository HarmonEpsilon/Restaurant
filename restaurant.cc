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
#include "doublylinkedlist.h"

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
    while(!waiting.empty()) {
        for(Table* reserved = occupied.first(); reserved != nullptr; reserved = occupied.next()) {
            timer--;

            if(timer == 0) {
                cout << occupied.getReservationName() << " finished" << endl;
                occupied.remove();
                reserved.clear();
                available.append(reserved);
            }
        }

        for(Party* in_line = waiting.first(); in_line != nullptr; in_line = waiting.next()) {
            for(Table* up_next = available.first(); up_next != nullptr; up_next = available.next()) {
                if(in_line.getNumDiners() <= up_next.getNumSeats()) {
                    cout << in_line.getReservationName() << " seated" << endl;
                    up_next.seatParty(in_line);
                    occupied.append(up_next);
                    available.remove();
                }
            }
        }

        /*if(waiting.empty()) {
            
        }*/
    }
}

int main() {
    Restaurant coleco;

    coleco.getInput();
    coleco.serveParties();

    return 0;
}