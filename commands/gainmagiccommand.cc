#include "gainmagiccommand.h"
#include "game.h"

using namespace std;

GainMagicCommand::GainMagicCommand(int magic) : magic(magic) {}

void GainMagicCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();

    activePlayer->setMagic(activePlayer->getMagic() + magic);
}
