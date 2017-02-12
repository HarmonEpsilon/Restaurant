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
#include "party.h"

Party::Party();
Party::Party(const string& reservationName, int numDiners, int timeRequired);
Party::~Party();