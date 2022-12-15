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

class keyInfo

{
public:

    keyInfo(String k_param, bool on)
    {
        key = k_param;
        isOn = on;
    }

    String key;
    bool isOn;

};


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

    void updateActiveBuffer(int bar_number);

    OwnedArray<keyInfo>& getBuffer() { return active_buffer; };

private:

    int staff_number = 0;
    int bar_number = 0;
    bool shouldColorBackground = false;
    SheetGridComponent grid;
    
    OwnedArray<keyInfo> active_buffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotesSectionComponent)
};
