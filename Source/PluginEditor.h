/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SheetComponent.h"
#include "TreeViewItemComponent.h"

//==============================================================================
/**
*/
class SheetMusicAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SheetMusicAudioProcessorEditor (SheetMusicAudioProcessor&);
    ~SheetMusicAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SheetMusicAudioProcessor& audioProcessor;

    SheetComponent sheet; 
    Viewport sheet_port;

    bool play_state = false;

    TreeView tree;
    TreeViewItemComponent* root;
    TreeViewItemComponent* Cleffs;
    TreeViewItemComponent* bass_Cleff;
    TreeViewItemComponent* treble_Cleff;
    TreeViewItemComponent* Notes;
    TreeViewItemComponent* Accidentals;
    TreeViewItemComponent* Grace_Notes;
    TreeViewItemComponent* key_Signatures;
    TreeViewItemComponent* time_Signatures;
    TreeViewItemComponent* Barlines;
    TreeViewItemComponent* Lines;
    TreeViewItemComponent* arpeggios_glissandos;
    TreeViewItemComponent* breathes_pauses;
    TreeViewItemComponent* brackets;
    TreeViewItemComponent* articulations_Ornaments;
    TreeViewItemComponent* Tempo;
    TreeViewItemComponent* dynamics;
    TreeViewItemComponent* repeats_jumps;
    TreeViewItemComponent* breaks_spacer;

    TextButton play_Button { "Play" };

    TextEditor title{ "Title" };
    TextEditor author{ "Author" };
   


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetMusicAudioProcessorEditor)
};
