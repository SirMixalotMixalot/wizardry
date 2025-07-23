#include "raisedead.h"
#include "raisedeadcommand.h"

using namespace std;

RaiseDead::RaiseDead(Player* owner)
    : Spell("Raise Dead", owner, "Resurrect the top minion in your graveyard and set its defence to 1", 1) {}

unique_ptr<Command> RaiseDead::use(int index, char target) {
    throw runtime_error("RaiseDead spell does not require a target index or player.");
}

unique_ptr<Command> RaiseDead::use() {
    return make_unique<RaiseDeadCommand>();
}
