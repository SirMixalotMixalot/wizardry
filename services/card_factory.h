#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include <memory>
#include <string>
#include <functional>
#include <unordered_map>

class Player;
class Card;

class CardFactory {
public:
    using CreatorFunc = std::function<std::unique_ptr<Card>(Player*)>;

    // Throws std::invalid_argument if the name is unknown
    static std::unique_ptr<Card> createCard(const std::string& type, Player* owner);
};

#endif
