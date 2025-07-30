#include "raisedeadcommand.h"
#include "game.h"
#include "minion.h"
#include "statsetter.h"
#include <iostream>
using namespace std;

void RaiseDeadCommand::execute(Game& game) {
    Player* activePlayer = game.getActivePlayer();

    // check if the active player has a graveyard
    if (activePlayer->getGraveyard()->getSize() == 0) {
        throw std::runtime_error("No cards in graveyard to raise.");
    }

    if (activePlayer->getBoard()->getSize() == 5)
    {
        throw std::runtime_error("Board is full.");
    }

    auto graveyard = activePlayer->getGraveyard();

    // implictly assumes we add last card to the end of the graveyard
    // ehhhh TODO: see if the design can be improved
    unique_ptr<Card> card = graveyard->removeCard(graveyard->getSize() - 1);
    if (!card) {
        throw std::runtime_error("No minions found in graveyard.");
    }

    // cast to minion
    Minion* minion = dynamic_cast<Minion*>(card.get());
    if (!minion) {
        throw std::runtime_error("Card is not a minion.");
    }

    // minion->setDefense(1);
    unique_ptr<StatSetter> statSetter = make_unique<StatSetter>(activePlayer, nullptr, minion->getAttack(), 1);
    unique_ptr<Minion> base(static_cast<Minion*>(card.release()));
    statSetter->setNext(move(base));

    game.setLastPlayedMinion(statSetter.get());

    activePlayer->getBoard()->addCard(move(statSetter));
    game.trigger(Triggers::MINION_ENTERS_PLAY);
}
