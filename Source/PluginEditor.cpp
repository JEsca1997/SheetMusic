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
    Accidentals(new TreeViewItemComponent("Accidentals")),
    Grace_Notes(new TreeViewItemComponent("Grace Notes")),
    key_Signatures(new TreeViewItemComponent("Key Signatures")),
    time_Signatures(new TreeViewItemComponent("time_Signatures")),
    Barlines(new TreeViewItemComponent("Barlines")),
    Lines(new TreeViewItemComponent("Lines")),
    arpeggios_glissandos(new TreeViewItemComponent("Arpeggios/Glissandos")),
    breathes_pauses(new TreeViewItemComponent("Breathes/Pauses")),
    brackets(new TreeViewItemComponent("Brackets")),
    articulations_Ornaments(new TreeViewItemComponent("Articulations/Ornaments")),
    Tempo(new TreeViewItemComponent("Tempo")),
    dynamics(new TreeViewItemComponent("Dynamics")),
    repeats_jumps(new TreeViewItemComponent("Repeats/Jumps")),
    breaks_spacer(new TreeViewItemComponent("Breaks/Spaces"))
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
            sheet.setState(true);
        }
        else
        {
            play_Button.setToggleState(true, NotificationType::dontSendNotification);
            sheet.setState(false);
        }
    };

    root->addSubItem(Cleffs);
    root->addSubItem(Notes);
    root->addSubItem(Accidentals);

    Cleffs->addSubItem(treble_Cleff);
    Cleffs->addSubItem(bass_Cleff);

    root->addSubItem(Grace_Notes);
    root->addSubItem(key_Signatures);
    root->addSubItem(time_Signatures);
    root->addSubItem(Barlines);
    root->addSubItem(Lines);
    root->addSubItem(arpeggios_glissandos);
    root->addSubItem(breathes_pauses);
    root->addSubItem(brackets);
    root->addSubItem(articulations_Ornaments);
    root->addSubItem(Tempo);
    root->addSubItem(dynamics);
    root->addSubItem(repeats_jumps);
    root->addSubItem(breaks_spacer);



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
