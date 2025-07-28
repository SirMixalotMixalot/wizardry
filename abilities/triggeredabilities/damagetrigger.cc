#include "damagetrigger.h"
#include "damagecommand.h"
#include "game.h"
#include "player.h"

DamageTrigger::DamageTrigger(string description, Triggers trigger, Player* owner, int damage) : 
    TriggeredAbility(description, trigger), owner(owner), damage(damage) {}

unique_ptr<Command> DamageTrigger::use() {
    return make_unique<DamageCommand>(owner, damage);
}