void Restaurant::serveParties() {
    string waiter;
    int keep_time:
    Party* up_next;
    Table* remove_table, next_table;

    while(!occupied.empty() || !waiting.empty()) {
        Table* order_out = occupied.first();
        up_next = waiting.first();

        while(order_up != nullptr) {
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

            order_out = order_out.next();
        }

        while(up_next != nullptr) {
            Table* order_in = available.first();

            while(order_in != nullptr) {
                if(order_in == nullptr) {
                    break;
                } else if(up_next->getNumDiners() <= order_in->getNumSeats()) {
                    cout << *(up_next->getReservationName()) << " seated at"
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

            if(order_in == nullptr) {
                break;
            }

            order_in = waiting.next();
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