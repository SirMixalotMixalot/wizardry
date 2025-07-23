#include "abilities.h"

using namespace std;

Ability::Ability(string description) : description(description) {}

string Ability::getDescription() {
    return description;
}
