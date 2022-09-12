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
    StaffComponent();
    ~StaffComponent() override;

    bool isInterestedInDragSource(const SourceDetails& dragSourceDetails) override;
    void itemDropped(const SourceDetails& dragSourceDetails) override;


    void paint (juce::Graphics&) override;
    void resized() override;

private:

    OwnedArray<BarComponent> bars;
    StaffHeaderComponent headerComponent{ headerInfo::BassCleff };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StaffComponent)
};
