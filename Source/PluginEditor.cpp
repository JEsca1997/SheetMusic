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

    addAndMakeVisible(button1);
    addAndMakeVisible(button2);
    addAndMakeVisible(button3);
    addAndMakeVisible(button4);
    addAndMakeVisible(button5);
    addAndMakeVisible(button6);
    addAndMakeVisible(button7);
    addAndMakeVisible(button8);
    addAndMakeVisible(button9);
    addAndMakeVisible(button10);

    addAndMakeVisible(button11);
    addAndMakeVisible(button12);
    addAndMakeVisible(button13);
    addAndMakeVisible(button14);
    addAndMakeVisible(button15);
    addAndMakeVisible(button16);
    addAndMakeVisible(button17);
    addAndMakeVisible(button18);
    addAndMakeVisible(button19);



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

    button1.setBounds(getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    button2.setBounds(2*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    button3.setBounds(3*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    button4.setBounds(4*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);

    button5.setBounds(0, getHeight() / 20, getWidth() / 16, getHeight() / 20);
    button6.setBounds(getWidth()/16, getHeight() / 20, getWidth() / 16, getHeight() / 20);
    button7.setBounds(2*getWidth()/16, getHeight() / 20, getWidth() / 16, getHeight() / 20);
    button8.setBounds(3*getWidth()/16, getHeight() / 20, getWidth() / 16, getHeight() / 20);
    button9.setBounds(4*getWidth() / 16, getHeight()/20, getWidth() / 16, getHeight() / 20);

    button10.setBounds(10*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    button11.setBounds(11*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    button12.setBounds(12*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    button13.setBounds(13*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    button14.setBounds(14*getWidth() / 16, 0, getWidth()/16, getHeight() / 20);
    
    button15.setBounds(10 * getWidth() / 16, getHeight()/20, getWidth() / 16, getHeight() / 20);
    button16.setBounds(11 * getWidth() / 16, getHeight()/20, getWidth() / 16, getHeight() / 20);
    button17.setBounds(12 * getWidth() / 16, getHeight()/20, getWidth() / 16, getHeight() / 20);
    button18.setBounds(13 * getWidth() / 16, getHeight()/20, getWidth() / 16, getHeight() / 20);
    button19.setBounds(14 * getWidth() / 16, getHeight()/20, getWidth() / 16, getHeight() / 20);

}
