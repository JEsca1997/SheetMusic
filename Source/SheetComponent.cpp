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
        staffs.add(new StaffComponent(c));
    }
}

SheetComponent::~SheetComponent()
{

}

void SheetComponent::turnOnBeat(String key, int staff, int bar, int beat)
{
    staffs[staff]->turnOnBeat(key,bar,beat);
}

void SheetComponent::addLine()
{
    for (int c = 0; c < 8; c++)
    {
        staffs[c]->addLine();
    }
}

void SheetComponent::addBeat()
{
    for (int c = 0; c < 8; c++)
    {
        staffs[c]->addBeat();
    }
}

BarComponent* SheetComponent::getBarAt(int staff, int index)
{
    return staffs[staff]->getBarAt(index);
}

StaffComponent* SheetComponent::getStaffAt(int index)
{
    return staffs[index];
}

void SheetComponent::setState(bool state,int staff, int bar)
{
    // create cross coms for playhead position to bar length, trigger playheads in sequence
    // iterate through staffs in sequence once the first staff has finished.

    staffs[staff]->setBarPlayheadState(state,bar);

}

void SheetComponent::paint (juce::Graphics& g)
{

    g.fillAll(Colours::grey);

    for(int c = 0; c < 8; c++)
    addAndMakeVisible(staffs[c]);

}

void SheetComponent::resized()
{
    int nRemHeight = getHeight() - 60;
    for (int c = 0; c < 4; c++)
    {
        //staffs[c]->setBounds(getWidth()/8, c * 2 * getHeight() / 12 + 30, getWidth()/2, getHeight() / 6);
        //staffs[c]->setBounds(getWidth() / 8, c *(nRemHeight / 4) + 30, getWidth() / 2, nRemHeight / 4);
        staffs[c]->setBounds(getWidth() / 8, c * (nRemHeight / 4) + 30, getWidth() / 2, 200); //height for 20 rows
    }
}
