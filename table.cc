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

/**
 * @brief Table default constructor
 */
Table::Table() {
    tableID = nullptr;
    numSeats = 0;
    serverName = nullptr;
    timer = 0;
    party = nullptr; 
}

/**
 * @brief Table constructor with items
 */
Table::Table(const string& tableID, int numSeats, const string& serverName) {
    this->tableID = new string(tableID);
    this->numSeats = numSeats;
    this->serverName = new string(serverName);
}

/**
 * @brief Table deconstructor
 */
Table::~Table() {
    delete tableID;
    tableID = nullptr;
    delete serverName;
    serverName = nullptr;
    delete party;
    party = nullptr;
}

/**
 * @brief Seats a party at a table
 * @param Takes in a new party
 * @return Nothing
 *
 * Takes in a new party, starts the timer by getting the required time,
 * and then places the party at the table.
 */
void Table::seatParty(const Party* newParty) {
    setTimer(newParty->getTimeRequired());
    party = newParty;
}

