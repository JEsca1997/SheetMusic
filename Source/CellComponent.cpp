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
CellComponent::CellComponent()
{
   
}

CellComponent::~CellComponent()
{

}

void CellComponent::mouseDown(const MouseEvent& e)
{
    isDown = !isDown;
    repaint();
}

void CellComponent::paint (juce::Graphics& g)
{
    if (isDown)
    {
        g.fillAll(Colours::red);
    }
    else
    {
        g.fillAll(Colours::transparentWhite);
    }
}

void CellComponent::resized()
{
   
}
