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
#include "PlayheadComponent.h"


using namespace juce;

//==============================================================================
/*
*/
class BarComponent  : public juce::Component, public Timer
{
public:
    BarComponent();
    ~BarComponent() override;

    void timerCallback() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void setPlayheadOn(bool state) { my_state = state; }

private:

    SheetGridComponent grid;
    PlayheadComponent play_head;
    bool my_state = false;
    int index = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BarComponent)
};
