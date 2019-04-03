#ifndef EVENTSIGNAL_H
#define EVENTSIGNAL_H

#include <functional>
#include "EventData.h"
#include "EventType.h"

namespace events {

class EventSignal
{
public:

    virtual void eventCallback(const EventType& type, const EventData& data) = 0;


private:
};

}
#endif // EVENTSIGNAL_H
