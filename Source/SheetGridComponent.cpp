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
    for (int c = 0; c < 4; c++)
    {
        cells_1.add(new CellComponent);
        cells_2.add(new CellComponent);
        cells_3.add(new CellComponent);
        cells_4.add(new CellComponent);
        cells_5.add(new CellComponent);

        addAndMakeVisible(cells_1[c]);
        addAndMakeVisible(cells_2[c]);
        addAndMakeVisible(cells_3[c]);
        addAndMakeVisible(cells_4[c]);
        addAndMakeVisible(cells_5[c]);

    }
}

SheetGridComponent::~SheetGridComponent()
{
}

void SheetGridComponent::paint (juce::Graphics& g)
{

}

void SheetGridComponent::resized()
{
    for (int c = 0; c < 4; c++)
    {
        cells_1[c]->setBounds(c * getWidth()/4, 0, getWidth() / 4, getHeight()/5);
        cells_2[c]->setBounds(c * getWidth() / 4,  getHeight() / 5, getWidth()/4, getHeight()/5);
        cells_3[c]->setBounds(c * getWidth() / 4, 2 * getHeight() / 5, getWidth()/4, getHeight()/5);
        cells_4[c]->setBounds(c * getWidth() / 4, 3 * getHeight() / 5, getWidth()/4, getHeight()/5);
        cells_5[c]->setBounds(c * getWidth() / 4, 4 * getHeight() / 5, getWidth() / 4, getHeight() / 5);
    }
}
