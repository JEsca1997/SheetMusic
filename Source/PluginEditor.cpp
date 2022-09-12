/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SheetMusicAudioProcessorEditor::SheetMusicAudioProcessorEditor (SheetMusicAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    root(new TreeViewItemComponent("root")),
    Cleffs(new TreeViewItemComponent("Cleff")),
    treble_Cleff(new TreeViewItemComponent("Treble")),
    bass_Cleff(new TreeViewItemComponent("Bass")),
    Notes(new TreeViewItemComponent("Notes")),
    Accidentals(new TreeViewItemComponent("Accidentals"))
{
    title.setColour(TextEditor::ColourIds::backgroundColourId, Colours::white);
    title.setColour(TextEditor::ColourIds::textColourId, Colours::black);
    addAndMakeVisible(title);

    setSize (1900, 900);
    sheet_port.setViewedComponent(&sheet);
    sheet_port.setViewPosition(getWidth()/6, 0);
    addAndMakeVisible(play_Button);

    tree.setRootItem(root);
    tree.setRootItemVisible(false);
    tree.setDefaultOpenness(true);
    tree.setOpenCloseButtonsVisible(true);

    author.setColour(TextEditor::ColourIds::backgroundColourId, Colours::white);
    author.setColour(TextEditor::ColourIds::textColourId, Colours::black);
    addAndMakeVisible(author);
    
    addAndMakeVisible(tree);
    tree.setColour(TreeView::ColourIds::backgroundColourId, Colours::grey);


    play_Button.setColour(TextButton::ColourIds::buttonOnColourId, Colours::green);
    play_Button.setColour(TextButton::ColourIds::buttonColourId, Colours::red);

    play_Button.onClick = [this]() {
        if (play_Button.getToggleState())
        {
            play_Button.setToggleState(false, NotificationType::dontSendNotification);
        }
        else
        {
            play_Button.setToggleState(true, NotificationType::dontSendNotification);
        }
    };

    root->addSubItem(Cleffs);
    root->addSubItem(Notes);
    root->addSubItem(Accidentals);


    Cleffs->addSubItem(treble_Cleff);
    Cleffs->addSubItem(bass_Cleff);
   


}

SheetMusicAudioProcessorEditor::~SheetMusicAudioProcessorEditor()
{

  
}

//==============================================================================
void SheetMusicAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(Colours::white);
    addAndMakeVisible(sheet_port);
}

void SheetMusicAudioProcessorEditor::resized()
{
    sheet.setBounds(0, 0, getWidth(), 1000);
    sheet_port.setBounds(getWidth()/5.5, 100, getWidth()/1.5, getHeight() - 60);
    play_Button.setBounds(0, 0, getWidth()/16, getHeight() / 20);
    tree.setBounds(0, getHeight()/10, getWidth() / 6, 9*getHeight()/10);
    title.setBounds(getWidth() / 3, 0, getWidth() / 4, getHeight() / 20);
    author.setBounds(getWidth() / 3, getHeight()/20, getWidth() / 4, getHeight() / 20);
}
