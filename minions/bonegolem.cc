#include "bonegolem.h"
#include "miniongainstatstrigger.h"

using namespace std;
BoneGolem::BoneGolem(Player* owner) : Minion("Bone Golem", owner, "", 2, 1, 3, nullptr, 
    make_unique<MinionGainStatsTrigger>("Gain +1/+1 whenever a minion leaves play.", Triggers::MINION_LEAVES_PLAY, this, 1, 1)) {}

bool BoneGolem::canUseAbilities() const {
    return true;
}
