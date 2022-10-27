/*
  ==============================================================================

    SheetGridComponent.h
    Created: 8 Sep 2022 1:36:51pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CellComponent.h"


using namespace juce;

//==============================================================================
/*
*/
class SheetGridComponent : public juce::Component, public MouseListener
{
public:
    SheetGridComponent();
    ~SheetGridComponent() override;


    void paint (juce::Graphics&) override;
    void resized() override;
    void addExtraBeat();
    void addExtraBeat(int num);
    void addExtraLine();
    void turnOnBeat(String key, int beat);
    void turnOffBeat(String key, int beat);

private:
    OwnedArray<OwnedArray<CellComponent>> cells;
    int numCells = 5;
    int numBeats = 4;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetGridComponent)
};
