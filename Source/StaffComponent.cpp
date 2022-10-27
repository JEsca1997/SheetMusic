/*
  ==============================================================================

    StaffComponent.cpp
    Created: 8 Sep 2022 1:42:12pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "StaffComponent.h"

using namespace juce;

//==============================================================================

StaffComponent::StaffComponent(int staff)
{
    staff_num = staff;
    for (int c = 0; c < 4; c++)
    {
        bars.add(new BarComponent(c,true));
        bars[c]->setStaffAndBarNumber(staff_num, c);
        addAndMakeVisible(bars[c]);
    }
    addAndMakeVisible(headerComponent);
}

StaffComponent::~StaffComponent()
{

}

void StaffComponent::turnOnBeat(String key, int bar, int beat)
{
    bars[bar]->turnOnBeat(key, beat);
}

void StaffComponent::addBeat()
{
    for (int c = 0; c < 4; c++)
    {
      bars[c]->addBeat();
    }
}
void StaffComponent::addLine()
{
    for (int c = 0; c < 4; c++)
    {
        bars[c]->addLine();
    }
}

BarComponent* StaffComponent::getBarAt(int index)
{
    return bars[index];
}

void StaffComponent::setBarPlayheadState(bool state, int bar)
{
     bars[bar]->setPlayheadOn(state);
}

bool StaffComponent::isInterestedInDragSource(const SourceDetails& dragSourceDetails)
{
    return true;
}

void StaffComponent::itemDropped(const SourceDetails& dragSourceDetails)
{
    
}

void StaffComponent::paint (juce::Graphics& g)
{
    
}

void StaffComponent::resized()
{
    for (int c = 0; c < 4; c++)
    {
        bars[c]->setBounds((c+1) * getWidth() / 5, 0, getWidth() / 5, getHeight());
    }

    headerComponent.setBounds(0, 0, getWidth() / 5, getHeight());

}
