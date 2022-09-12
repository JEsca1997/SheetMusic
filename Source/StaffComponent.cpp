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
StaffComponent::StaffComponent()
{
    for (int c = 0; c < 4; c++)
    {
        bars.add(new BarComponent);
        addAndMakeVisible(bars[c]);
    }
    addAndMakeVisible(headerComponent);
}

StaffComponent::~StaffComponent()
{

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
