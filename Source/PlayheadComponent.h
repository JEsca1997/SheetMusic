/*
  ==============================================================================

    PlayheadComponent.h
    Created: 18 Sep 2022 1:28:28pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

//==============================================================================
/*
*/

class PlayheadComponent  : public juce::Component
{
public:
    PlayheadComponent();
    ~PlayheadComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayheadComponent)
};
