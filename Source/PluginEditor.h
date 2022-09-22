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


    TextButton button1;
    TextButton button2;
    TextButton button3;
    TextButton button4;
    TextButton button5;
    TextButton button6;
    TextButton button7;
    TextButton button8;
    TextButton button9;
    TextButton button10;

    TextButton button11;
    TextButton button12;
    TextButton button13;
    TextButton button14;
    TextButton button15;
    TextButton button16;
    TextButton button17;
    TextButton button18;
    TextButton button19;
    TextButton button20;


    TextButton play_Button { "Play" };

    TextEditor title{ "Title" };
    TextEditor author{ "Author" };
   


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetMusicAudioProcessorEditor)
};
