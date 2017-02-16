#include "restaurant.h"
#include<iostream>
using std::endl;
using std::map;
using std::cin;
using std::cout;

void Restaurant::getInput(){
    string input;
    string tname;
    int tsize;
    string sname;
    string resname;
    int psize;
    int restime;
    std::cin >> input;
    while(input != "end"){
        if(input == "table"){
            cin >> tname >> tsize >> sname;
            Table* table = new Table(tname, tsize, sname);
            available.append(table);
        }
        else if(input == "party"){
            cin >> psize >> resname >> restime;
            Party* party = new Party(resname, psize, restime);
            waiting.append(party);
        }
        cin >> input;
    }
}

void Restaurant::serveParties(){
    int timer;
    Party* reservation;
    string server;
    while(!waiting.empty() || !occupied.empty()){
        Table* table = occupied.first();
        while(table != nullptr){
            timer = table->getTimer();
            if(timer == 0){
                const Party* tparty = table->getParty();
                cout << *(tparty->getReservationName()) << " finished at " << *(table->getTableID()) << endl;
                delete tparty;
                tparty = nullptr;
                table->clearTable();
                available.append(table);
                table = occupied.remove();
            }
            else{
                table->decrementTimer();
            }
            table = occupied.next();
        }
        reservation = waiting.first();
        while(reservation != nullptr){
            Table* openTable = available.first();
            while( openTable != nullptr){
                if(reservation == nullptr){
                    break;
                }
                else if(reservation->getNumDiners() <= openTable->getNumSeats()){
                    cout << *(reservation->getReservationName()) << " seated at " << *(openTable->getTableID()) << endl;
                    openTable->seatParty(reservation);
                    server = *(openTable->getServerName());
                    servers[server] = servers[server] + openTable->getParty()->getNumDiners();
                    occupied.append(openTable);
                    openTable = available.remove();
                    openTable = available.first();
                    reservation = waiting.remove();
                }
                else{
                    openTable = available.next();
                }
            }
            if(reservation == nullptr){
                break;
            }
            reservation = waiting.next();
        }
    }
    for( map<string, int>::iterator i = servers.begin(); i != servers.end(); ++i){
        cout << i->first << " served " << i->second << endl;
    }

    Table* rmtable = available.first();
    Table* nxtable;
    while(nxtable != nullptr){
        nxtable = available.next();
        delete rmtable;
        rmtable = nullptr;
    }
}

int main(){
    Restaurant myRestaurant;
    myRestaurant.getInput();
    myRestaurant.serveParties();
    return 0;
}
