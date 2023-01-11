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
#include "NotesSectionComponent.h"


using namespace juce;

//==============================================================================
/*
*/

class BarComponent  : public juce::Component//, public Timer
{

public:

    BarComponent(int bar, bool first);
    ~BarComponent() override;

    void timerCallback();// override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void mouseDown(const MouseEvent& e) override;
    void playnote(int xShift);
    void setBGColour(juce::Colour color)
    {
        bgCol = color;
    }


    void setStaffNumber(int staff);
    void setBarNumber(int bar);
    void setStaffAndBarNumber(int staff, int bar);

    void setPlayheadOn(bool state) { p_state = state; isFirstTime = false; };
    void setNoteSectionBackgroundColor(int note, bool color);
    void resetIndex() { index = 0; isCurrentBar = false; };
    void isPlayheadInSectionBounds();
    int getStaffNumber() { return staff_number; };
    bool isCurrentBarAndStaff(int staff, int bar);

    void addBeat();
    void addLine();
    int getCurrentNumSection() { return current_section; };

    void turnOnBeat(String key, int beat);
    bool isPlayheadInBounds();
     
    bool getPlayState()
    {
        return p_state;
    }

private:

    bool isFirstTime = false;
    bool isCurrentBar = false;

    int current_section = 0;
    int staff_number = 0;
    int bar_number = 0;

    OwnedArray<NotesSectionComponent> notes;
    PlayheadComponent play_head;

    bool p_state = false;
    int index = 0;
    int current = 0;

    Array<int> current_section_buffer;
    // have only one buffer which is the one thats currently playing
    

    juce::Colour bgCol;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BarComponent)
};
