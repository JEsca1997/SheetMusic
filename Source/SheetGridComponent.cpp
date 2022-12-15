/*
  ==============================================================================

    SheetGridComponent.cpp
    Created: 8 Sep 2022 1:36:51pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SheetGridComponent.h"

using namespace juce;

//==============================================================================


SheetGridComponent::SheetGridComponent()
{
    for (int c = 0; c < 16; c++)
    {
        cells.add(new OwnedArray<CellComponent>);
    }
    for (int c = 0; c < 16; c++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (c <= 6 && 3 <= c)
            {
                cells[c]->add(new CellComponent(cellNumberToKey(c), x, false));
            }

            cells[c]->add(new CellComponent("", 0, false));
            addAndMakeVisible(cells[c]->operator[](x));

        }
    }
}


String SheetGridComponent::cellNumberToKey(int num)
{
    switch (num)
    {
    case 3 :
        return "E";
        break;
    case 4 : 
        return "C";
        break;
    case 5:
        return "A";
        break;
    case 6:
        return "F";
        break;
    }
}

SheetGridComponent::~SheetGridComponent()
{

}

bool SheetGridComponent::bufferPriorsCheck(Kinfo* info)
{
    String key = info->key;
    int beat = info->beat;
    bool isdown = info->isOn;

    if (active_notes_buffer.size() != 0)
    {
        for (int c = 0; c < active_notes_buffer.size(); c++)
        {
            auto* frame = active_notes_buffer[c];
            bool bKey = (frame->key.equalsIgnoreCase(key));
            bool bBeat = (beat == frame->beat);
            bool state = (isdown == frame->isOn);

            if (bKey && bBeat && state)
            {
                return false;
            }

        }
    }
    return true;
}

void SheetGridComponent::updateActiveNotesBuffer(int bar)
{
    for (int c = 0; c < 16; c++)
    {
        //for (int x = 0; x < 4; x++)
        int x = bar;
        {
            if (cells[c]->operator[](x)->downState())
            {
                String key = cells[c]->operator[](x)->getKey();
                int beat = cells[c]->operator[](x)->getBeat();
                auto* info = new Kinfo(key, beat, true);

                DBG(info->toString() + "In sheet grid component");
                if (bufferPriorsCheck(info))
                {
                    active_notes_buffer.add(info);
                    
                    //DBG(info->toString() + "in active");
                }

            }
        }
    }
}

void SheetGridComponent::addExtraLine()
{
    /*
    cells.add(new OwnedArray<CellComponent>);
    for (int c = 0; c < numBeats; c++)
    {
        cells[cells.size() - 1]->add(new CellComponent);
        addAndMakeVisible(cells[cells.size() - 1]->operator[](c));
    }
    resized();
    */
}

void SheetGridComponent::addExtraBeat()
{
    /*
    numBeats++;
    for (int c = 0; c < 16; c++)
    {
        cells[c]->add(new CellComponent);
        addAndMakeVisible(cells[c]->operator[](cells[c]->size()-1));
    }
    resized();
    */
}

void SheetGridComponent::addExtraBeat(int num)
{
    for (int c = 0; c < num; c++)
    {
        addExtraBeat();
    }
}

void SheetGridComponent::turnOnBeat(String key, int beat)
{
    active_notes_buffer.add(new Kinfo(key, beat, true));

    if (key.contains("A"))
    {
        cells[5]->operator[](beat)->turnOn();
    }
    if (key.contains("B"))
    {

    }
    if (key.contains("C"))
    {
        cells[4]->operator[](beat)->turnOn();
    }
    if (key.contains("D"))
    {

    }
    if (key.contains("E"))
    {
        cells[3]->operator[](beat)->turnOn();
    }
    if (key.contains("F"))
    {
        cells[6]->operator[](beat)->turnOn();
    }
    if (key.contains("G"))
    {

    }
}


void SheetGridComponent::turnOffBeat(String key, int beat)
{
    for (int c = 0; c < active_notes_buffer.size(); c++)
    {
        if (active_notes_buffer[c]->key.equalsIgnoreCase(key) && active_notes_buffer[c]->beat == beat)
        {
            active_notes_buffer.remove(c);
        }
    }

    if (key.contains("A"))
    {
        cells[5]->operator[](beat)->turnOff();
    }
    if (key.contains("B"))
    {

    }
    if (key.contains("C"))
    {
        cells[4]->operator[](beat)->turnOff();
    }
    if (key.contains("D"))
    {

    }
    if (key.contains("E"))
    {
        cells[3]->operator[](beat)->turnOff();
    }
    if (key.contains("F"))
    {
        cells[6]->operator[](beat)->turnOff();
    }
    if (key.contains("G"))
    {

    }
}

void SheetGridComponent::paint(juce::Graphics& g)
{
    
}

void SheetGridComponent::resized()
{
    int size = cells.size();

    for (int c = 0; c < size ; c++)
    {
        for (int x = 0; x < numBeats; x++)
        {
            cells[c]->operator[](x)->setBounds(x * getWidth()/numBeats, c * getHeight() / size, getWidth() / numBeats, getHeight() / size);
        }
    }
}
