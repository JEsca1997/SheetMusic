/*
  ==============================================================================

    CellComponent.cpp
    Created: 8 Sep 2022 3:45:54pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CellComponent.h"

//==============================================================================

CellComponent::CellComponent(String key, int beat, bool state)
{
    info.key = key;
    info.beat = beat;
    info.isOn = state;
}

CellComponent::~CellComponent()
{

}

void CellComponent::turnOn()
{
    isDown = true;
    repaint();
}
void CellComponent::turnOff()
{
    isDown = false;
    repaint();
}
void CellComponent::mouseDown(const MouseEvent& e)
{
    isDown = !isDown;
    repaint();
   // DBG(info.toString());
}

void CellComponent::paint (juce::Graphics& g)
{
    if (isDown)
    {
        //g.fillAll(Colours::red);
        g.setColour(Colours::red);
        g.drawText(info.key, getLocalBounds(),Justification::centred);
    }
    else
    {
        g.fillAll(Colours::transparentWhite);
    }
}

void CellComponent::resized()
{
   
}
