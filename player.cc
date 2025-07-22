#include "player.h"
#include "minion.h"
#include <iostream>

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
            hand->addCard(deck->draw());
        }
    }
}

Card* Player::discardCard(int index) {}

Card* Player::playCard(int index) {}

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
