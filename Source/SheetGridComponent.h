/*
  ==============================================================================

    SheetGridComponent.h
    Created: 8 Sep 2022 1:36:51pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CellComponent.h"


using namespace juce;

//==============================================================================
/*
*/

class Kinfo
{

public:

    Kinfo(String k_param, int be, bool on)
    {
        key = k_param;
        beat = be;
        isOn = on;
    };

    void setKey(String k) { key = k; };
    void setOn(bool on) { isOn = on; };
    void setBeat(int be) { beat = be; };
    String toString() { return String( " Key :: " + key + " Beat :: " + String(beat) ); };

    String key;
    bool isOn;
    int beat;

};

class SheetGridComponent : public juce::Component, public MouseListener //, public AsyncUpdater
{
public:
    SheetGridComponent();
    ~SheetGridComponent() override;

    void TriggerUpdate();

    String cellNumberToKey(int num);

    void paint (juce::Graphics&) override;
    void resized() override;

    void addExtraBeat();
    void addExtraBeat(int num);
    void addExtraLine();

    void turnOnBeat(String key, int beat);
    void turnOffBeat(String key, int beat);

    void updateActiveNotesBuffer(int bar);
    bool bufferPriorsCheck(Kinfo* info);

    OwnedArray<Kinfo>* getActiveNotesBuffer() { return &active_notes_buffer; };

private:

    OwnedArray<OwnedArray<CellComponent>> cells;

    OwnedArray<Kinfo> active_notes_buffer;

    int numCells = 5;
    int numBeats = 4;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetGridComponent)
};
