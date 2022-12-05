/*
  ==============================================================================

    TreeViewItemComponent.cpp
    Created: 8 Sep 2022 10:11:13pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TreeViewItemComponent.h"

//==============================================================================
TreeViewItemComponent::TreeViewItemComponent(String name)
{
    setNodeName(name);
    addMouseListener(this,true);
}

TreeViewItemComponent::~TreeViewItemComponent()
{
}

void TreeViewItemComponent::mouseDrag(const MouseEvent& e)
{
    juce::Image orange = juce::ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize);
    auto pic = orange.rescaled(35, 35);

    DragAndDropContainer::startDragging(my_name ,this, pic, true, {}, {});
}

bool TreeViewItemComponent::mightContainSubItems()
{
    return true;
}

std::unique_ptr<Component> TreeViewItemComponent::createItemComponent()
{
    std::unique_ptr<TextButton> button;
    button.reset(new TextButton(my_name));
    button->addMouseListener(this, true);
    return button;
}

int TreeViewItemComponent::getItemWidth() const
{
    return 100;
}

int TreeViewItemComponent::getItemHeight() const
{
    return 30;
}

void TreeViewItemComponent::paint (juce::Graphics& g)
{
   
}

void TreeViewItemComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
