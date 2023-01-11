/*
  ==============================================================================

    NotesSectionComponent.cpp
    Created: 11 Oct 2022 9:48:16pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NotesSectionComponent.h"


//==============================================================================

NotesSectionComponent::NotesSectionComponent()
{

    addAndMakeVisible(grid);
   
}

NotesSectionComponent::~NotesSectionComponent()
{

}

void NotesSectionComponent::turnOnBackgroundColoring(bool color)
{
    shouldColorBackground = color;
    repaint();
}

void NotesSectionComponent::setBarNumber(int bar)
{
    bar_number = bar;
}

void NotesSectionComponent::setStaffNumber(int staff)
{
    staff_number = staff;
}

void NotesSectionComponent::setStaffAndBarNumber(int bar, int staff)
{
    staff_number = staff;
    bar_number = bar;
}

void NotesSectionComponent::updateActiveBuffer(int bar)
{
    grid.updateActiveNotesBuffer(bar);

}



void NotesSectionComponent::turnOnBeat(String key)
{
    grid.turnOnBeat(key, 1);
}

void NotesSectionComponent::paint (juce::Graphics& g)
{
    if (shouldColorBackground)
    {
        g.setColour(Colours::aquamarine);
        g.setOpacity(0.4f);
        g.fillRect(0, 0, getWidth(), getHeight());
    }
}

void NotesSectionComponent::resized()
{
    grid.setBounds(0, 0, getWidth(), getHeight());
}


void NotesSectionComponent::playnote(int xShift)
{
    grid.playnote(xShift);
}