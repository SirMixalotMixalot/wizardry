#ifndef RITUAL_H
#define RITUAL_H

#include "card.h"
#include "triggeredability.h"

using namespace std;

class Ritual : public Card {
    unique_ptr<TriggeredAbility> ability;
    int activationCost;
    int numCharges;

    public:
        Ritual (string name, Player* owner, string description, int cost, unique_ptr<TriggeredAbility> ability, int activationCost, int numCharges);
        virtual ~Ritual() = 0;

        TriggeredAbility* getTriggeredAbility();
        int getActivationCost();
        int getNumberOfCharges();
<<<<<<< HEAD
        void setNumberOfCharges(int numCharges);
=======
>>>>>>> 3d1e4b3 (dark ritual implementation)

        virtual unique_ptr<Command> use() override;
        virtual unique_ptr<Command> use(int player, int targetCard) override;
};

#endif