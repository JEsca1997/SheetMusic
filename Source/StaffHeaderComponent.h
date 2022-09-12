/*
  ==============================================================================

    StaffHeaderComponent.h
    Created: 9 Sep 2022 8:19:15pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/

using namespace juce;

enum headerInfo
{
    BassCleff,
    TrebleCleff
};

class StaffHeaderComponent  : public juce::Component, public DragAndDropTarget
{
public:
    StaffHeaderComponent(headerInfo info);
    ~StaffHeaderComponent() override;

    bool isInterestedInDragSource(const SourceDetails& dragSourceDetails) override;
    void itemDropped(const SourceDetails& dragSourceDetails) override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    DrawableImage bassCleff;
    DrawableImage trebleCleff;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StaffHeaderComponent)
};
