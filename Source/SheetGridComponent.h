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

private:

    OwnedArray<CellComponent> cells_1; 
    OwnedArray<CellComponent> cells_2;
    OwnedArray<CellComponent> cells_3;
    OwnedArray<CellComponent> cells_4;
    OwnedArray<CellComponent> cells_5;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetGridComponent)
};
