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
    int keep_time;
    Party* up_next;
    Table* remove_table;
    Table* next_table;

    while(!occupied.empty() || !waiting.empty()) {
        Table* order_out = occupied.first();

        while(order_out != nullptr) {
            keep_time = order_out->getTimer();

            if(keep_time == 0) {
                const Party* party_one = order_out->getParty();

                cout << *(party_one->getReservationName()) << " served at "
                    << *(order_out->getTableID()) << endl;
                
                delete party_one;
                party_one = nullptr;
                order_out->clearTable();
                available.append(order_out);
                order_out = occupied.remove();
            } else {
                order_out->decrementTimer();
            }

            order_out = occupied.next();
        }

        up_next = waiting.first();
        
        while(up_next != nullptr) {
            Table* order_in = available.first();

            while(order_in != nullptr) {
                if(up_next == nullptr) {
                    break;
                } else if(up_next->getNumDiners() <= order_in->getNumSeats()) {
                    cout << *(up_next->getReservationName()) << " seated at "
                        << *(order_in->getTableID()) << endl;
                    
                    order_in->seatParty(up_next);
                    waiter = *(order_in->getServerName());
                    servers[waiter] = servers[waiter] + order_in->getParty()
                        ->getNumDiners();
                    
                    occupied.append(order_in);
                    order_in = available.remove();
                    order_in = available.first();
                    up_next = waiting.remove();
                } else {
                    order_in = available.next();
                }
            }

            if(up_next == nullptr) {
                break;
            }

            up_next = waiting.next();
        }
    }

    for(auto it = servers.begin(); it != servers.end(); ++it) {
        cout << it->first << " served " << it->second << endl;
    }

    remove_table = available.first();

    while(next_table != nullptr) {
        next_table = available.next();
        delete remove_table;
        remove_table = nullptr;
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