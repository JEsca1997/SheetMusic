/*
  ==============================================================================

    CellComponent.h
    Created: 8 Sep 2022 3:45:54pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

//==============================================================================
/*
*/
class CellComponent : public juce::Component, public MouseListener
{
public:
    CellComponent();
    ~CellComponent() override;

    void mouseDown(const MouseEvent& e) override;
    void turnOn();
    void turnOff();

    void paint (juce::Graphics&) override;
    void resized() override;
    void setName(String name);

private:

    String name;
    bool isDown = false; 

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CellComponent)
};
