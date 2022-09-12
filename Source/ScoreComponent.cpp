/*
  ==============================================================================

    ScoreComponent.cpp
    Created: 8 Sep 2022 1:42:25pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ScoreComponent.h"

//==============================================================================

ScoreComponent::ScoreComponent()
{
    

}

ScoreComponent::~ScoreComponent()
{
}

void ScoreComponent::paint (juce::Graphics& g)
{
    addAndMakeVisible(sheet);
}

void ScoreComponent::resized()
{
    sheet.setBounds(0, 0, getWidth(), getHeight());
}
