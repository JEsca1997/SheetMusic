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

private:

    OwnedArray<StaffComponent> staffs;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetComponent)
};
