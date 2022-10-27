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
BarComponent::BarComponent(int bar, bool first)
{
    isFirstTime = first;
    bar_number = bar;
    addAndMakeVisible(play_head);
    startTimer(42);
    for (int c = 0; c < 4; c++)
    {
        notes.add(new NotesSectionComponent);
        addAndMakeVisible(notes[c]);
    }
   
}

BarComponent::~BarComponent()
{

}

void BarComponent::turnOnBeat(String key, int beat)
{
    notes[beat]->turnOnBeat(key);
}

void BarComponent::addLine()
{
   
}

void BarComponent::addBeat()
{
    notes.add(new NotesSectionComponent());
    addAndMakeVisible(notes[notes.size() - 1]);
    resized();
}

void BarComponent::setNoteSectionBackgroundColor(int note, bool color)
{
    notes[note]->turnOnBackgroundColoring(color);
}

void BarComponent::setStaffNumber(int staff)
{
    staff_number = staff;
}

void BarComponent::setBarNumber(int bar)
{
    bar_number = bar;
}

void BarComponent::setStaffAndBarNumber(int staff, int bar)
{
    staff_number = staff;
    bar_number = bar;
}

void BarComponent::isPlayheadInSectionBounds()
{
  if (index < (current_section + 1) * getWidth() / notes.size() && isCurrentBar)
     {
        setNoteSectionBackgroundColor(current_section, true);

     }
  else
     {
        setNoteSectionBackgroundColor(current_section, false);
        if (p_state)
        {
            if(current_section+1 < notes.size())
            current_section++;
        }
     }  
}
bool BarComponent::isCurrentBarAndStaff(int staff, int bar)
{
    if (staff_number == staff && bar_number == bar)
    {
        isCurrentBar = true;
        return isCurrentBar;
    }
    else
    {
        isCurrentBar = false;
        return isCurrentBar;
    }
}
void BarComponent::timerCallback()
{
    if (p_state && isPlayheadInBounds())
    {
        index++;
        resized();
        isPlayheadInSectionBounds();
    }
    else
    {
           p_state = false;
           setNoteSectionBackgroundColor(current_section, false);
    }
}

bool BarComponent::isPlayheadInBounds()
{
    if (index < getWidth())
    {
        return true;
    }
    else return false;
}

void BarComponent::paint (juce::Graphics& g)
{
    g.fillAll(Colours::white);
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
    for (int c = 0; c < 5; c++)
    {
        g.drawLine(0, (c+3) * getHeight() / 16, getWidth(), (c+3) * getHeight() / 16);
    }
 
}

void BarComponent::resized()
{
    if (!isFirstTime)
    {
        play_head.setBounds(index, 0, 2, getHeight());
    }
    int size = notes.size();
    for (int c = 0; c < size; c++)
    {
        notes[c]->setBounds(c * getWidth() / size, 0, getWidth() / size, getHeight());
    }
}
