/*
  ==============================================================================

    BarComponent.cpp
    Created: 8 Sep 2022 2:06:41pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "BarComponent.h"


//==============================================================================
BarComponent::BarComponent()
{
    
}

BarComponent::~BarComponent()
{
}

void BarComponent::paint (juce::Graphics& g)
{
    g.fillAll(Colours::white);
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());

    for (int c = 0; c < 5; c++)
    {
        g.drawLine(0, c * getHeight() / 5, getWidth(), c * getHeight() / 5);
    }

    addAndMakeVisible(grid);

}

void BarComponent::resized()
{
    grid.setBounds(0, 0, getWidth(), getHeight());
}
