#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H

#include "ability.h"
#include "enums.h"
#include <string>

using namespace std;

class TriggeredAbility : public Ability {
    Triggers trigger;

    public:
        TriggeredAbility(string description, Triggers trigger);
<<<<<<< HEAD
        virtual ~TriggeredAbility() = default;
        
        Triggers getTrigger();

        virtual unique_ptr<Command> use() = 0;
=======
        virtual ~TriggeredAbility() = 0;
        
        Triggers getTrigger();
>>>>>>> 3d1e4b3 (dark ritual implementation)
};

#endif