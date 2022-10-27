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
            cells[c]->add(new CellComponent);
            addAndMakeVisible(cells[c]->operator[](x));
        }
    }
}

SheetGridComponent::~SheetGridComponent()
{
}
void SheetGridComponent::addExtraLine()
{
    cells.add(new OwnedArray<CellComponent>);
    for (int c = 0; c < numBeats; c++)
    {
        cells[cells.size() - 1]->add(new CellComponent);
        addAndMakeVisible(cells[cells.size() - 1]->operator[](c));
    }
    resized();
}
void SheetGridComponent::addExtraBeat()
{
    numBeats++;
    for (int c = 0; c < 16; c++)
    {
        cells[c]->add(new CellComponent);
        addAndMakeVisible(cells[c]->operator[](cells[c]->size()-1));
    }
    resized();
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
