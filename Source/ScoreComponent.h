/*
  ==============================================================================

    ScoreComponent.h
    Created: 8 Sep 2022 1:42:25pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SheetComponent.h"

using namespace juce;

//==============================================================================
/*
*/
class ScoreComponent  : public juce::Component
{
public:
    ScoreComponent();
    ~ScoreComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    SheetComponent sheet;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScoreComponent)
};
