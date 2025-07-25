#include "summonminions.h"
#include "summoncommand.h"

SummonMinions::SummonMinions(string description, int cost, string minionName, int minionCount) : ActivatedAbility(move(description), cost), minionName(move(minionName)), minionCount(minionCount) {}

SummonMinions::~SummonMinions() = default;

unique_ptr<Command> SummonMinions::use() {
    return make_unique<SummonCommand>(minionName, minionCount);
}

unique_ptr<Command> SummonMinions::use(int player, int targetCard) {
    throw runtime_error("This activated ability does not require a target index or player.");
}