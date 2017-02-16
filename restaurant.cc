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
using std::map;

/**
 * @brief   Gets input and places them in the doubly linked list queues
 * @param   Nothing
 * @return  Nothing
 *
 * Begins input loop for the restaurant, seating appropriate parties and tables
 * in appropriate queues.
 */
void Restaurant::getInput() {
    string server, name, id, input;
    int serving = 0, timer = 0;

    while(cin >> input) {
        if(input == "end") {
            break;
        }

        if(input == "table") {
            cin >> name >> serving >> server;
            Table* orderUp = new Table(name, serving, server);
            available.append(orderUp);
        } else if (input == "party") {
            cin >> serving >> name >> timer;
            Party* orderOut = new Party(name, serving, timer);
            waiting.append(orderOut);
        }
    }
}

/**
 * @brief   Serves tables and parties from queues
 * @param   Nothing
 * @return  Nothing
 *
 * Seats parties at tables, as well as seating people at tables,
 * when enough space becomes available at the first table it can find.
 */
void Restaurant::serveParties() {
    string waiter;

    while(!waiting.empty()) {
        for(Table* reserved = occupied.first(); reserved != nullptr; reserved = occupied.next()) {
            reserved->decrementTimer();

            if(reserved->getTimer() == 0) {
                cout << (reserved->getParty())->getReservationName() << " finished" << endl;
                occupied.remove();
                reserved->clearTable();
                available.append(reserved);
            }
        }

        for(Party* in_line = waiting.first(); in_line != nullptr; in_line = waiting.next()) {
            for(Table* up_next = available.first(); up_next != nullptr; up_next = available.next()) {
                if(in_line->getNumDiners() <= up_next->getNumSeats()) {
                    cout << in_line->getReservationName() << " seated" << endl;
                    waiter = *(up_next->getServerName());
                    servers[waiter] = servers[waiter] + in_line->getNumDiners();
                    up_next->seatParty(in_line);
                    occupied.append(up_next);
                    available.remove();
                }
            }
        }

        for(auto it = servers.begin(); it != servers.end(); it++) {
            cout << it->first << " served " << it->second << endl;
        }
    }
}

/**
 * @brief   Opens restaurant by starting functions
 * @param   Nothing
 * @return  0
 *
 * Creates a new restaurant and starts functions for getting input
 * and serving parties.
 */
int main() {
    Restaurant coleco;

    coleco.getInput();
    coleco.serveParties();

    return 0;
}