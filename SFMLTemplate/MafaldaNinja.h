#pragma once
#include "Characters.h"
class MafaldaNinja : public Characters
{
public:
	MafaldaNinja();


    float getHP() const override;
    float getJumpForce() const override;
    float getDMG() const override;

    void setHP(float value) override;
    void setJumpForce(float value) override;
    void setDMG(float value) override;

};

