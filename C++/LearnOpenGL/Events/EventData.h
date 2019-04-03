#ifndef EVENTDATA_H
#define EVENTDATA_H

#include <glm/glm.hpp>

namespace events {

struct EventData
{
    glm::vec<2, double> mousePos;
    int button;
    int buttonAction;
    int key;
    int keyAction;
    double scroll;
};

}
#endif // EVENTDATA_H
