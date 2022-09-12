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
        bassCleff.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        addAndMakeVisible(bassCleff);
    }
    if (info == headerInfo::TrebleCleff)
    {
        trebleCleff.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        addAndMakeVisible(trebleCleff);
    }
}

bool StaffHeaderComponent::isInterestedInDragSource(const SourceDetails& dragSourceDetails)
{
    return true;
}
void StaffHeaderComponent::itemDropped(const SourceDetails& dragSourceDetails)
{
    DBG("Item Dropped");
}

StaffHeaderComponent::~StaffHeaderComponent()
{

}

void StaffHeaderComponent::paint (juce::Graphics& g)
{
   

}

void StaffHeaderComponent::resized()
{
    

}
