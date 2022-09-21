/*
  ==============================================================================

    PlayheadComponent.cpp
    Created: 18 Sep 2022 1:28:28pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PlayheadComponent.h"

//==============================================================================
PlayheadComponent::PlayheadComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

PlayheadComponent::~PlayheadComponent()
{
}

void PlayheadComponent::paint (juce::Graphics& g)
{
    g.setColour(Colours::red);
    g.fillRect(0, 0, getWidth(), getHeight());

}

void PlayheadComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
