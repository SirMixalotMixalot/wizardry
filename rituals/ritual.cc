#include "ritual.h"

Ritual::Ritual(string name, Player* owner, string description, int cost, unique_ptr<TriggeredAbility> ability, int activationCost, int numCharges)
    : Card(name, owner, description, cost) {
        this->ability = move(ability);
        this->activationCost = activationCost;
        this->numCharges = numCharges;
    }

Ritual::~Ritual() = default;

TriggeredAbility* Ritual::getTriggeredAbility() {
    return ability.get();
}

int Ritual::getActivationCost() {
    return activationCost;
}

int Ritual::getNumberOfCharges() {
    return numCharges;
}

unique_ptr<Command> Ritual::use() {
    return nullptr;
}

unique_ptr<Command> Ritual::use(int player, int targetCard) {
    return nullptr;
}
