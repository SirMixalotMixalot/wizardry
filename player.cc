#include "player.h"
#include "minion.h"
#include <iostream>
#include "spell.h"
#include <stdexcept>
#include <memory>
using namespace std;

Player::Player(const string& name, const string& deckFile, Game* game) : name(name), magic(3), health(20), game(game) {
    deck = make_unique<Deck>(deckFile, this);
    hand = make_unique<Hand>();
    board = make_unique<Board>();
    graveyard = make_unique<Graveyard>();
}

void Player::drawCard() {
    if (!hand->isFull() && !deck->isEmpty()) {
        unique_ptr<Card> card = deck->draw();
        if (card) {
            hand->addCard(move(card));
        }
    }
}

void Player::discardCard(int index) {
    hand->removeCard(index);
}

Card* Player::playCard(int index, int targetPlayer, int targetCard) {
    if (index < 0 || index >= hand->getSize()) {
        return nullptr;
    }

    Card* card = hand->getCard(index);
    if (magic < card->getCost()) {
        return nullptr;
    }
    magic -= card->getCost();

    // get the cards command
    unique_ptr<Command> command;
    if (targetPlayer == -1) {
        // no target player, just use the card
        command = card->use();
    } else {
        // use the card with a target player and target card
        command = card->use(targetCard, targetPlayer);
    }

    // notify the game with the command
    game->notify(move(command));
    unique_ptr<Card> playedCard = hand->removeCard(index);
    Card* rawCard = playedCard.get();
    
    // check if the card played was not a spell
    if (!dynamic_cast<Spell*>(rawCard)) {
        board->addCard(move(playedCard));
    }
    return rawCard;
}

Minion* Player::getMinion(int index) {
    Card* card = board->getCard(index);
    return dynamic_cast<Minion*>(card);
}

Game* Player::getGame() const {
    return game;
}

Hand* Player::getHand() const {
    return hand.get();
}

Deck* Player::getDeck() const {
    return deck.get();
}

Board* Player::getBoard() const {
    return board.get();
}

Graveyard* Player::getGraveyard() const {
    return graveyard.get();
}

void Player::trigger(Triggers trigger) {}

int Player::getMagic() const {
    return magic;
}

void Player::setMagic(int magic) {
    this->magic = magic;
}

string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int health) {
    this->health = health;
}

void Player::killMinion(int index) {
    if (index < 0 || index >= board->getSize()) {
        throw std::out_of_range("Invalid minion index");
    }
    
    auto card = board->removeCard(index);
    if (card) {
        graveyard->addCard(move(card));
    }
}

void Player::returnMinionToHand(int index) {
    if (index < 0 || index >= board->getSize()) {
        throw std::out_of_range("Invalid minion index");
    }
    
    auto card = board->removeCard(index);
    if (card) {
        hand->addCard(move(card));
    }
}

Graveyard* Player::getGraveyard() const {
    return graveyard.get();
}
