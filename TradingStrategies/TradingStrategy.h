/* 
 * File:   TradingStrategy.h
 * Author: Piotr Gregor  postmaster@cf16.eu
 *
 * Created on August 3, 2013, 12:21 AM
 */

#ifndef TRADINGSTRATEGY_H
#define	TRADINGSTRATEGY_H

#include <CommonDefs.h>
#include <DataAccessLayer/MarketData.h>


class TradingStrategy {
public:
    TradingStrategy();
    TradingStrategy(const TradingStrategy& orig);
    virtual ~TradingStrategy();
    
    // Template Method Pattern
    void subscribeToData(IB::TickerId tickerId){
        doSubscribeToData(tickerId);
    }
    void start(){
        doStart();
    }
private:
    virtual void doSubscribeToData(IB::TickerId tickerId)=0;
    virtual void doStart()=0;
    virtual void tickPriceUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void tickSizeUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void tickStringUpdate(int tickerId, rec_ptr record_ptr)=0;
    virtual void marketDepthUpdate(int tickerId, rec_ptr recor_ptr)=0;
    virtual void marketDepthL2update(int tickerId, rec_ptr recor_ptr)=0;
};

#endif	/* TRADINGSTRATEGY_H */
