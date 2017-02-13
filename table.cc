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
#include "table.h"


Table::Table() {
    tableID = nullptr;
    numSeats = 0;
    serverName = nullptr;
    timer = 0;
    party = nullptr; 
}

Table::Table(const string& tableID, int numSeats, const string& serverName) {
    tableID = new string(tableID);
    numSeats = numSeats;
    serverName = new string(serverName);
}

Table::~Table() {
    
}

void Table::seatParty(const Party* newParty) {

}