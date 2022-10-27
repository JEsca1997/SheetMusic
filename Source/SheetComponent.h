/*
  ==============================================================================

    SheetComponent.h
    Created: 8 Sep 2022 1:36:26pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SheetGridComponent.h"
#include "StaffComponent.h"

using namespace juce;

//==============================================================================
/*
*/
class SheetComponent  : public juce::Component
{
public:
    SheetComponent();
    ~SheetComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void setState(bool state, int staff, int bar);
    void addBeat();
    void addLine();
    void turnOnBeat(String key, int staff, int bar, int beat);
    BarComponent* getBarAt(int staff, int index);
    StaffComponent* getStaffAt(int index);

    OwnedArray<StaffComponent> staffs;

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetComponent)
};
