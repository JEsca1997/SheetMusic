/*
  ==============================================================================

    StaffHeaderComponent.cpp
    Created: 9 Sep 2022 8:19:15pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "StaffHeaderComponent.h"

//==============================================================================
StaffHeaderComponent::StaffHeaderComponent(headerInfo info)
{
    if (info == headerInfo::BassCleff)
    {
        bassCleff.setImage(ImageCache::getFromMemory(BinaryData::Bass_Clef_png, BinaryData::Bass_Clef_pngSize));
        bassCleff.setBoundingBox(Rectangle<float>(0, -6, 50, 73));
        addAndMakeVisible(bassCleff);
    }
    if (info == headerInfo::TrebleCleff)
    {
        trebleCleff.setImage(ImageCache::getFromMemory(BinaryData::Treble_Clef_png, BinaryData::Treble_Clef_pngSize));
        trebleCleff.setBoundingBox(juce::Rectangle<float>(0, -10, 50, 97));
        addAndMakeVisible(trebleCleff);
    }
}

bool StaffHeaderComponent::isInterestedInDragSource(const SourceDetails& dragSourceDetails)
{
    return true;
}
void StaffHeaderComponent::itemDropped(const SourceDetails& dragSourceDetails)
{
  
}

StaffHeaderComponent::~StaffHeaderComponent()
{

}

void StaffHeaderComponent::paint (juce::Graphics& g)
{
    g.drawLine(0, 0, 0, getHeight());
    for (int c = 0; c < 6; c++)
    {
        g.drawLine(0, c * (1.2) * getHeight() / 6, getWidth(), c * (1.2) * getHeight() / 6);
    }

}

void StaffHeaderComponent::resized()
{
    

}
