#include "actionsmodifier.h"

ActionsModifier::ActionsModifier(Player* owner, unique_ptr<Minion> next, int actionsModifier)
    : Enchantment("Actions Modifier", owner, "", 0, "", "", std::move(next), false), actionsModifier(actionsModifier) {}

int ActionsModifier::getActions() const {
    return next->getActions() + actionsModifier;
}