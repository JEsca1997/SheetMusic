/*
  ==============================================================================

    SheetComponent.cpp
    Created: 8 Sep 2022 1:36:26pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SheetComponent.h"

using namespace juce;

//==============================================================================
SheetComponent::SheetComponent()
{
    for (int c = 0; c < 8; c++)
    {
        staffs.add(new StaffComponent);
    }

}

SheetComponent::~SheetComponent()
{

}

void SheetComponent::setState(bool state)
{
    for (int c = 0; c < 8; c++)
    {
        staffs[c]->setBarPlayheadState(state);
    }
}

void SheetComponent::paint (juce::Graphics& g)
{

    g.fillAll(Colours::white);

    for(int c = 0; c < 8; c++)
    addAndMakeVisible(staffs[c]);

}

void SheetComponent::resized()
{
    for (int c = 0; c < 8; c++)
    {
        staffs[c]->setBounds(getWidth()/8, c * 1.4 * getHeight() / 12, getWidth()/2, getHeight() / 12);
    }
}
