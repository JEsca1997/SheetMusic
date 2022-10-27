/*
  ==============================================================================

    StaffHeaderComponent.h
    Created: 9 Sep 2022 8:19:15pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/

using namespace juce;

enum headerInfo
{
    BassCleff,
    TrebleCleff
};

class StaffHeaderComponent  : public juce::Component, public DragAndDropTarget
{
public:
    StaffHeaderComponent(headerInfo info);
    ~StaffHeaderComponent() override;

    bool isInterestedInDragSource(const SourceDetails& dragSourceDetails) override;
    void itemDropped(const SourceDetails& dragSourceDetails) override;

    bool isKey(String name);
    bool isTime(String name);

    void clearLastKey(String name);
    void clearLastTime(String name);

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    DrawableImage bassCleff;
    DrawableImage trebleCleff;
    DrawableImage TwoFour;
    DrawableImage ThreeFour;
    DrawableImage FourFour;
    DrawableImage FiveFour;
    DrawableImage SixFour;
    DrawableImage ThreeEight;
    DrawableImage SixEight;
    DrawableImage NineEight;
    DrawableImage TwelveEight;
    DrawableImage CommonTime;
    DrawableImage CutTime;

    DrawableImage Major;
    DrawableImage CMajorInSharp;
    DrawableImage CMajorInFlat;
    DrawableImage GMajor;
    DrawableImage DMajor;
    DrawableImage AMajor;
    DrawableImage EMajor;
    DrawableImage BMajor;
    DrawableImage FSharpMajor;
    DrawableImage CSharpMajor;

    DrawableImage AMinorInSharp;
    DrawableImage AMinorInFlat;
    DrawableImage EMinor;
    DrawableImage BMinor;
    DrawableImage FSharpMinor;
    DrawableImage CSharpMinor;
    DrawableImage GSharpMinor;
    DrawableImage DSharpMinor;
    DrawableImage ASharpMinor;

    //   DrawableImage CMajor;
    DrawableImage BFlatMajor;
    DrawableImage EFlatMajor;
    DrawableImage AFlatMajor;
    DrawableImage DFlatMajor;
    DrawableImage GFlatMajor;
    DrawableImage CFlatMajor;

    DrawableImage Minor;
    //   DrawableImage AMinor;
    DrawableImage DMinor;
    DrawableImage GMinor;
    DrawableImage CMinor;
    DrawableImage FMinor;
    DrawableImage BFlatMinor;
    DrawableImage EFlatMinor;
    DrawableImage AFlatMinor;

    String last_key {""};
    String last_time{ "" };


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StaffHeaderComponent)
};
