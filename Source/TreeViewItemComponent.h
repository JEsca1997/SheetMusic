/*
  ==============================================================================

    TreeViewItemComponent.h
    Created: 8 Sep 2022 10:11:13pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

//==============================================================================
/*
*/
class TreeViewItemComponent  : public juce::Component, public TreeViewItem, public DragAndDropContainer
{
public:
    TreeViewItemComponent(String name);
    ~TreeViewItemComponent() override;

    bool mightContainSubItems() override;
    juce::Component* createItemComponent() override;
    int getItemWidth() const override;
    int getItemHeight() const override;

    void mouseDrag(const MouseEvent& e) override;

    void setNodeName(String name) { my_name = name; }

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    String my_name{ "" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TreeViewItemComponent)
};
