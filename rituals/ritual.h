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

        TriggeredAbility* getTriggeredAbility() const;
        int getActivationCost() const;
        int getNumberOfCharges() const;
        void setNumberOfCharges(int numCharges);

        virtual unique_ptr<Command> use() override;
        virtual unique_ptr<Command> use(int player, int targetCard) override;
};

#endif
