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


Table::Table();
Table::Table(const string& tableID, int numSeats, const string& serverName);
Table::~Table();
void Table::seatParty(const Party* newParty);