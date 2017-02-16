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

Party::Party(const string& reservationName, int numDiners, int timeRequired) {
    this->reservationName = new string(reservationName);
    this->numDiners = numDiners;
    this->timeRequired = timeRequired;
}

Party::~Party() {
    delete reservationName;
    reservationName = nullptr;
    numDiners = 0;
    timeRequired = 0;
}