#include "card_factory.h"

#include "airelemental.h"
#include "earthelemental.h"
#include "firelemental.h"
#include "novicepyromancer.h"
#include "apprenticesummoner.h"
#include "mastersummoner.h"
#include "bonegolem.h"
#include "potionseller.h"

#include <stdexcept>
#include <unordered_map>

static const std::unordered_map<std::string, CardFactory::CreatorFunc>& creators() {
    static const std::unordered_map<std::string, CardFactory::CreatorFunc> table{
        {"Air Elemental",  [](Player* o){ return std::make_unique<AirElemental>(o); }},
        {"Earth Elemental",[](Player* o){ return std::make_unique<EarthElemental>(o); }},
        {"Fire Elemental",[](Player* o){ return std::make_unique<FireElemental>(o); }},
        {"Novice Pyromancer", [](Player* o){ return std::make_unique<NovicePyromancer>(o); }},
        {"Apprentice Summoner",[](Player* o){ return std::make_unique<ApprenticeSummoner>(o); }},
        {"Master Summoner", [](Player* o){ return std::make_unique<MasterSummoner>(o); }},
        {"Bone Golem",[](Player* o){ return std::make_unique<BoneGolem>(o); }},
        {"Potion Seller",[](Player* o){ return std::make_unique<PotionSeller>(o); }}
    };
    return table;
}

std::unique_ptr<Card> CardFactory::createMinion(const std::string& type, Player* owner) {
    const auto& creationTable = creators();
    auto it = creationTable.find(type);
    if (it == creationTable.end()) {
        throw std::invalid_argument("Unknown card: " + type);
    }
    return it->second(owner);
}
