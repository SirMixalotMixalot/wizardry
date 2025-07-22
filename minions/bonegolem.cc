#include "bonegolem.h"

using namespace std;
BoneGolem::BoneGolem(Player* owner) : Minion("Bone Golem", owner, "", 2, 1, 3) {}
bool BoneGolem::canUseAbilities() const {
    return true;
}
