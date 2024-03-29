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

    //startTimer(42);

    for (int c = 0; c < 4; c++)
    {
        notes.add(new NotesSectionComponent);
        addAndMakeVisible(notes[c]);
    }

    notes[0]->setBGColour(Colours::blueviolet);
    notes[1]->setBGColour(Colours::coral);
    notes[2]->setBGColour(Colours::greenyellow);
    notes[3]->setBGColour(Colours::green);
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
            if (current_section + 1 < notes.size())
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

    for (int c = 0; c < notes.size(); c++)
    {
        notes[c]->getBuffer();
    }

    if (getPlayState()) { 

        //check if the current_section was in the buffer 
        //bool exists = std::find(std::begin(current_section_buffer), std::end(current_section_buffer), current_section) != std::end(current_section_buffer);
        //DBG(String(int(exists)) + "Tt");

        int sync = index % 11;  

        

        if (sync==0) {
                //sync buffer with the buffer 
               
                notes[current_section]->updateActiveBuffer((index/12)%4);
                //if(index/12)
                //current_section_buffer.add(current_section);
            }
                         
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
        g.drawLine(0, (c+3) * getHeight() / 20, getWidth(), (c+3) * getHeight() / 20);

        g.drawLine(0, (c + 13) * getHeight() / 20, getWidth(), (c + 13) * getHeight() / 20);

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

void BarComponent::mouseDown(const MouseEvent& e)
{

}

void BarComponent::playnote(int xShift)
{
    int nNoteSectionIndex = xShift / notes[0]->getWidth();
    //if(nNoteSectionIndex > 0)
    notes[nNoteSectionIndex]->playnote(xShift % notes[0]->getWidth());
    //DBG(xShift);
}