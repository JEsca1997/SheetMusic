/*
  ==============================================================================

    NotesSectionComponent.h
    Created: 11 Oct 2022 9:48:16pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SheetGridComponent.h"

//==============================================================================
/*
*/

using namespace juce;

class NotesSectionComponent  : public juce::Component
{
public:
    NotesSectionComponent();
    ~NotesSectionComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void turnOnBeat(String key);
    void turnOnBackgroundColoring(bool color);
    void setBarNumber(int bar);
    void setStaffNumber(int staff);
    void setStaffAndBarNumber(int bar, int staff);

private:

    int staff_number = 0;
    int bar_number = 0;
    bool shouldColorBackground = false;
    SheetGridComponent grid;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotesSectionComponent)
};
