/*
  ==============================================================================

    BarComponent.h
    Created: 8 Sep 2022 2:06:41pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SheetGridComponent.h"


using namespace juce;

//==============================================================================
/*
*/
class BarComponent  : public juce::Component
{
public:
    BarComponent();
    ~BarComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    SheetGridComponent grid;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BarComponent)
};
