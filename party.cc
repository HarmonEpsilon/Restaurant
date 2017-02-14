/**
 * @file party.cc
 *
 * @brief
 *    Functions for a party of diners in a restaurant, using party.h
 *
 * @author Landon Mote
 * @date 2/12/2017
 */

#include <string>
#include "doublylinkedlist.h"
#include "party.h"

Party::Party() {
    reservationName = nullptr;
    numDiners = 0;
    timeRequired = 0;
}

Party::Party(const string& reservation, int diners, int time_req) {
    reservationName = reservation;
    numDiners = diners;
    timeRequired = time_req;
}

Party::~Party() {
    
}