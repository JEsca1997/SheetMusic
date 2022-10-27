/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/

using namespace juce;

class KeyInfo
{
public :

    KeyInfo(String k_param, bool on)
    {
        key = k_param;
        isOn = on;
    }

    String key;
    bool isOn;

};

class SheetMusicAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    SheetMusicAudioProcessor();
    ~SheetMusicAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
   
   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    void loadFile();
    int getNumSamplerSounds() { return mSampler.getNumSounds(); };
   
    AudioFormatManager manager;
    AudioFormatReader* mFormatReader{ nullptr };
    Synthesiser mSampler;
    const int mNumVoices{ 3 };

    std::vector<KeyInfo> getTempMidiBuffer();

private:
    //==============================================================================
    MidiBuffer temp_Midi;
    std::vector<KeyInfo> key_infos;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetMusicAudioProcessor)
};
