#ifndef ENUMS_H
#define ENUMS_H

enum class Triggers {
    START_OF_TURN,
    END_OF_TURN,
    MINION_ENTERS_PLAY,
    MINION_LEAVES_PLAY
};

class Player;
class Game;
class Card;
class Minion;
class Spell;
class Ritual;
class Enchantment;
class Board;
class Hand;
class Deck;
class Graveyard;
class Ability;
class TriggeredAbility;
class ActivatedAbility;
class Command;
class View;

#endif