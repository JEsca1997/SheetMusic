/*
  ==============================================================================

    CellComponent.h
    Created: 8 Sep 2022 3:45:54pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

//==============================================================================
/*
*/

class mInfo
{

public:

    mInfo(String k_param, int be, bool on)
    {
        key = k_param;
        beat = be;
        isOn = on;
    };

    void setKey(String k) { key = k; };
    void setOn(bool on) { isOn = on; };
    void setBeat(int be) { beat = be; };
    String toString() { return String(" Key :: " + key + " Beat :: " + String(beat)); };

    String key;
    bool isOn;
    int beat;

};

class CellComponent : public juce::Component, public MouseListener
{
public:
    CellComponent(String key, int beat, bool state);
    ~CellComponent() override;

    void mouseDown(const MouseEvent& e) override;
    void turnOn();
    void setNoteNum(int num);
    void turnOff();

    bool downState() { return isDown; }

    void paint (juce::Graphics&) override;
    void resized() override;

    void setkey(String nm) { info.setKey(nm); };
    String getKey() { return info.key; };
    void setBeat(int bt) { info.setBeat(bt); };
    int getBeat() { return info.beat; };
    void setDownState(bool state) { info.isOn = state; };
    int  getNoteNum() {
        return m_nNoteNum;
    }
private:

    mInfo info { "", 0, false };

    int m_nNoteNum = 60;
    int beat;
    String name;
    bool isDown = false; 

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CellComponent)
};
