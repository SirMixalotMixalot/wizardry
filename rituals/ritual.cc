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

<<<<<<< HEAD
void Ritual::setNumberOfCharges(int numCharges) {
    this->numCharges = numCharges;
}

=======
>>>>>>> 3d1e4b3 (dark ritual implementation)
unique_ptr<Command> Ritual::use() {
    return nullptr;
}

unique_ptr<Command> Ritual::use(int player, int targetCard) {
    return nullptr;
}
