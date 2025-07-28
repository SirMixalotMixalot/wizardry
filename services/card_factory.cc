#include "card_factory.h"

#include "airelemental.h"
#include "earthelemental.h"
#include "firelemental.h"
#include "novicepyromancer.h"
#include "apprenticesummoner.h"
#include "mastersummoner.h"
#include "bonegolem.h"
#include "potionseller.h"

#include "unsummon.h"
#include "raisedead.h"
#include "banish.h"
#include "blizzard.h"

#include "enrage.h"
#include "giantstrength.h"
#include "haste.h"
#include "magicfatigue.h"
#include "silence.h"

#include "darkritual.h"
#include "auraofpower.h"
#include "standstill.h"

#include <stdexcept>
#include <unordered_map>

static const std::unordered_map<std::string, CardFactory::CreatorFunc>& creators() {
    static const std::unordered_map<std::string, CardFactory::CreatorFunc> table{
        // minions
        {"Air Elemental",  [](Player* o){ return std::make_unique<AirElemental>(o); }},
        {"Earth Elemental",[](Player* o){ return std::make_unique<EarthElemental>(o); }},
        {"Fire Elemental",[](Player* o){ return std::make_unique<FireElemental>(o); }},
        {"Novice Pyromancer", [](Player* o){ return std::make_unique<NovicePyromancer>(o); }},
        {"Apprentice Summoner",[](Player* o){ return std::make_unique<ApprenticeSummoner>(o); }},
        {"Master Summoner", [](Player* o){ return std::make_unique<MasterSummoner>(o); }},
        {"Bone Golem",[](Player* o){ return std::make_unique<BoneGolem>(o); }},
        {"Potion Seller",[](Player* o){ return std::make_unique<PotionSeller>(o); }},
        // spells
        {"Unsummon", [](Player* o){ return std::make_unique<Unsummon>(o); }},
        {"Raise Dead", [](Player* o){ return std::make_unique<RaiseDead>(o); }},
        {"Banish", [](Player* o){ return std::make_unique<Banish>(o); }},
        {"Blizzard", [](Player* o){ return std::make_unique<Blizzard>(o); }},
        // enchantments
        {"Enrage", [](Player* o){ return std::make_unique<Enrage>(o, nullptr); }},
        {"Giant Strength", [](Player* o){ return std::make_unique<GiantStrength>(o, nullptr); }},
        {"Haste", [](Player* o){ return std::make_unique<Haste>(o, nullptr); }},
        {"Magic Fatigue", [](Player* o){ return std::make_unique<MagicFatigue>(o, nullptr); }},
        {"Silence", [](Player* o){ return std::make_unique<Silence>(o, nullptr); }},

        // rituals
        {"Dark Ritual", [](Player* o){ return std::make_unique<DarkRitual>(o); }},
        {"Aura of Power", [](Player* o){ return std::make_unique<AuraOfPower>(o); }},
        {"Standstill", [](Player* o){ return std::make_unique<Standstill>(o); }},
    };
    return table;
}

std::unique_ptr<Card> CardFactory::createCard(const std::string& type, Player* owner) {
    const auto& creationTable = creators();
    auto it = creationTable.find(type);
    if (it == creationTable.end()) {
        throw std::invalid_argument("Unknown card: " + type);
    }
    return it->second(owner);
}
