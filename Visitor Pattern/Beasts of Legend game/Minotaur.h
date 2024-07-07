#pragma once
#include "Beast.h"

class Minotaur : public Beast{
public:
    Minotaur() = default;
    virtual Beast* clone() const override;
    virtual BattleOutput beats(const Beast* other) const override;
    virtual BattleOutput beatsMinotaur(const Minotaur* other) const override;
    virtual BattleOutput beatsCentaur(const Centaur* other) const override;
    virtual BattleOutput beatsSphinx(const Sphinx* other) const override;
};
