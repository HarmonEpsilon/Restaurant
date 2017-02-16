/**
 * @file table.cc
 *
 * @brief
 *    Functions for table.h header file, dealing with tables at the restaurant.
 *
 * @author Landon Mote
 * @date 2/12/2017
 */

#include <string>
#include "party.h"
#include "table.h"
#include "restaurant.h"
#include "doublylinkedlist.h"


Table::Table() {
    tableID = nullptr;
    numSeats = 0;
    serverName = nullptr;
    timer = 0;
    party = nullptr; 
}

Table::Table(const string& table_id, int seats, const string& server) {
    tableID = new string(table_id);
    numSeats = seats;
    serverName = new string(server);
}

Table::~Table() {
    delete tableID;
    tableID = nullptr;
    delete serverName;
    serverName = nullptr;
    delete party;
    party = nullptr;
}

void Table::seatParty(const Party* newParty) {
    setTimer(newParty->getTimeRequired());
    party = newParty;
}

