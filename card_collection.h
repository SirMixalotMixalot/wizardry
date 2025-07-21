#ifndef CARD_COLLECTION_H
#define CARD_COLLECTION_H

#include "card.h"
#include <vector>
#include <memory>

using namespace std;

class CardCollection {
    protected:
        vector<unique_ptr<Card>> cards;
    
    public:
        virtual ~CardCollection() = 0;
        
        void addCard(unique_ptr<Card> card);
        void removeCard(int index);
        Card* getCard(int index) const;
    
    private: 
        int getSize() const;
};

#endif