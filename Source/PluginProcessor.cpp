/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SheetMusicAudioProcessor::SheetMusicAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    manager.registerBasicFormats();
    for (int c = 0; c < mNumVoices; c++)
    {
        mSampler.addVoice(new SamplerVoice());
    }
}

SheetMusicAudioProcessor::~SheetMusicAudioProcessor()
{
    mFormatReader = nullptr; 
}

//==============================================================================

void SheetMusicAudioProcessor::loadFile()
{
    FileChooser chooser("", {}, {}, false, false, nullptr);
    if (chooser.browseForFileToOpen())
      {
        auto file = chooser.getResult();
         if (file.getFileExtension().equalsIgnoreCase(".wav") || file.getFileExtension().equalsIgnoreCase(".mp3") || file.getFileExtension().equalsIgnoreCase(".ogg") || file.getFileExtension().equalsIgnoreCase(".aiff"))
         {
             mFormatReader = manager.createReaderFor(file);
             BigInteger range;
             range.setRange(0, 128, true);
             mSampler.addSound(new SamplerSound("Sample", *mFormatReader, range, 60, 0.1, 0.1, 10.0));
         }
      }
}

const juce::String SheetMusicAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SheetMusicAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SheetMusicAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SheetMusicAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SheetMusicAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SheetMusicAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SheetMusicAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SheetMusicAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SheetMusicAudioProcessor::getProgramName (int index)
{
    return {};
}

void SheetMusicAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SheetMusicAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    mSampler.setCurrentPlaybackSampleRate(sampleRate);
}

void SheetMusicAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SheetMusicAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SheetMusicAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    for (auto i = totalNumInputChannels; i < getTotalNumOutputChannels(); ++i)
    {
        buffer.clear(i, 0, buffer.getNumSamples());
    }
     mSampler.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

     if (midiMessages.getNumEvents() != 0)
     {
         int index = 0;
         for (auto message : midiMessages)
         {
             auto key = message.getMessage().getMidiNoteName(message.getMessage().getNoteNumber(), true, false, 4);
             auto isOn = message.getMessage().isNoteOn();
             if (message.getMessage().isNoteOn())
             {
                 auto* key_info = new KeyInfo(key, isOn);
                 key_infos.push_back(*key_info);
             }
             else if (message.getMessage().isNoteOff())
             {
                 key_infos.erase(key_infos.begin() + index);
                 index--;
             }
             index++;
         }
     }
}


std::vector<KeyInfo> SheetMusicAudioProcessor::getTempMidiBuffer()
{
    return key_infos;
}

//==============================================================================
bool SheetMusicAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SheetMusicAudioProcessor::createEditor()
{
    return new SheetMusicAudioProcessorEditor (*this);
}

//==============================================================================
void SheetMusicAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SheetMusicAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SheetMusicAudioProcessor();
}
