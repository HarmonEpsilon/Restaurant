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

Table::Table(const string& tableID, int numSeats, const string& serverName) {
    this->tableID = new string(tableID);
    this->numSeats = numSeats;
    this->serverName = new string(serverName);
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

