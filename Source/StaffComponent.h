/*
  ==============================================================================

    StaffComponent.h
    Created: 8 Sep 2022 1:42:12pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SheetGridComponent.h"
#include "BarComponent.h"
#include "StaffHeaderComponent.h"

using namespace juce; 

//==============================================================================
/*
*/
class StaffComponent  : public juce::Component, public DragAndDropTarget
{
public:
    StaffComponent(int staff);
    ~StaffComponent() override;

    bool isInterestedInDragSource(const SourceDetails& dragSourceDetails) override;
    void itemDropped(const SourceDetails& dragSourceDetails) override;

    void setBarPlayheadState(bool state, int bar);

    void addBeat();
    void paint (juce::Graphics&) override;
    void resized() override;
    void addLine();
    void turnOnBeat(String key, int bar, int beat);
    BarComponent* getBarAt(int index);
    void setStaffNum(int num) { staff_num = num; };
    int getStaffNum() { return staff_num; };

private:

    int staff_num = 0;
    OwnedArray<BarComponent> bars;
    StaffHeaderComponent headerComponent{ headerInfo::BassCleff };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StaffComponent)
};
