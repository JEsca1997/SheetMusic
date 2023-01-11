/*
  ==============================================================================

    SheetGridComponent.cpp
    Created: 8 Sep 2022 1:36:51pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SheetGridComponent.h"

#include "PluginEditor.h"
using namespace juce;

//==============================================================================


SheetGridComponent::SheetGridComponent()
{
    return;
    for (int c = 0; c < 16; c++)
    {
        cells.add(new OwnedArray<CellComponent>);
    }


    for (int c = 0; c < 16; c++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (c <= 6 && 3 <= c)
            {
                cells[c]->add(new CellComponent(cellNumberToKey(c), x, false));
            }

            cells[c]->add(new CellComponent("", 0, false));
            addAndMakeVisible(cells[c]->operator[](x));

        }
    }
}


String SheetGridComponent::cellNumberToKey(int num)
{
    switch (num)
    {
    case 3 :
        return "E";
        break;
    case 4 : 
        return "C";
        break;
    case 5:
        return "A";
        break;
    case 6:
        return "F";
        break;
    }
}

String SheetGridComponent::getTrebbleNote(int mid, int num, int& nNoteNum)
{
    if (mid == 0)
    {
        switch (num)
        {
        case 0:
            nNoteNum = 50;
            return "D";
            break;
        case 1:
            nNoteNum = 59;
            return "B";
            break;
        case 2:
            nNoteNum = 55;
            return "G"; //staff
            break;
        case 3:
            nNoteNum = 52;
            return "E"; //space
            break;
        case 4:
            nNoteNum = 48;
            return "C"; //staff
            break;
        case 5:
            nNoteNum = 57;
            return "A"; //space
            break;
        case 6:
            nNoteNum = 53;
            return "F"; //staff
            break;
        case 7:
            nNoteNum = 50;
            return "D"; //space
            break;
        case 8:
            nNoteNum = 59;
            return "B"; //staff
            break;
        case 9:
            nNoteNum = 55;
            return "G"; //space
            break;
        case 10:
            nNoteNum = 52;
            return "E"; //staff
            break;
        default:
            return"";
        }
    }
    else
    {
        switch (num)
        {
        case 0:
            nNoteNum = 49;
            return "C"; //staff
            break;
        case 1:
            nNoteNum = 58;
            return "A"; //space
            break;
        case 2:
            nNoteNum = 54;
            return "F"; //staff
            break;
        case 3:
            nNoteNum = 51;
            return "D"; //space
            break;
        case 4:
            nNoteNum = 58;
            return "B"; //staff
            break;
        case 5:
            nNoteNum = 56;
            return "G"; //space
            break;
        case 6:
            nNoteNum = 51;
            return "E"; //staff
            break;
        case 7:
            nNoteNum = 49;
            return "C"; //space
            break;
        case 8:
            nNoteNum = 58;
            return "A"; //staff
            break;
        case 9:
            nNoteNum = 54;
            return "F"; //space
            break;
        case 10:
            nNoteNum = 51;
            return "D"; //staff
            break;
        default:
            return"";
        }
    }
}


String SheetGridComponent::getBassNote(int mid, int num, int& nNoteNum)
{

    if (mid == 0)
    {
        switch (num)
        {
        case 0:
            nNoteNum = 65;
            return "F";
            break;
        case 1:
            nNoteNum = 62;
            return "D";
            break;
        case 2:
            nNoteNum = 71;
            return "B"; //staff
            break;
        case 3:
            nNoteNum = 67;
            return "G"; //space
            break;
        case 4:
            nNoteNum = 64;
            return "E"; //staff
            break;
        case 5:
            nNoteNum = 72;
            return "C"; //space
            break;
        case 6:
            nNoteNum = 69;
            return "A"; //staff
            break;
        case 7:
            nNoteNum = 65;
            return "F"; //space
            break;
        case 8:
            nNoteNum = 62;
            return "D"; //staff
            break;
        case 9:
            nNoteNum = 71;
            return "B"; //space
            break;
        case 10:
            nNoteNum = 67;
            return "G"; //staff
            break;
        default:
            return"";
        }
    }
    else
    {
        switch (num)
        {
        case 0:
            nNoteNum = 63;
            return "E"; //staff
            break;
        case 1:
            nNoteNum = 61;
            return "C"; //space
            break;
        case 2:
            nNoteNum = 70;
            return "A"; //staff
            break;
        case 3:
            nNoteNum = 66;
            return "F"; //space
            break;
        case 4:
            nNoteNum = 63;
            return "D"; //staff
            break;
        case 5:
            nNoteNum = 70;
            return "B"; //space
            break;
        case 6:
            nNoteNum = 68;
            return "G"; //staff
            break;
        case 7:
            nNoteNum = 63;
            return "E"; //space
            break;
        case 8:
            nNoteNum = 61;
            return "C"; //staff
            break;
        case 9:
            nNoteNum = 70;
            return "A"; //space
            break;
        case 10:
            nNoteNum = 66;
            return "F"; //staff
            break;
        default:
            return"";
        }
    }
}

SheetGridComponent::~SheetGridComponent()
{

}

bool SheetGridComponent::bufferPriorsCheck(Kinfo* info)
{
    String key = info->key;
    int beat = info->beat;
    bool isdown = info->isOn;

    if (active_notes_buffer.size() != 0)
    {
        for (int c = 0; c < active_notes_buffer.size(); c++)
        {
            auto* frame = active_notes_buffer[c];
            bool bKey = (frame->key.equalsIgnoreCase(key));
            bool bBeat = (beat == frame->beat);
            bool state = (isdown == frame->isOn);

            if (bKey && bBeat && state)
            {
                return false;
            }

        }
    }
    return true;
}

void SheetGridComponent::updateActiveNotesBuffer(int bar)
{



    for (CellComponent* c : noteCollection)
    {
        if (c->getBeat() == bar && c->downState())
        {
            String key = c->getKey();
            int beat = c->getBeat();
            auto* info = new Kinfo(key, beat, true);
            DBG(info->toString() + "In Sheet grid component");
            if (key.isEmpty())
                String brk = "";
        }
    }
    //for (int c = 0; c < 16; c++)
    //{
    //    //for (int x = 0; x < 4; x++)
    //    int x = bar;
    //    {
    //        if (cells[c]->operator[](x)->downState())
    //        {
    //            String key = cells[c]->operator[](x)->getKey();
    //            int beat = cells[c]->operator[](x)->getBeat();
    //            auto* info = new Kinfo(key, beat, true);
    //            DBG(info->toString() + "In sheet grid component");
    //            if (bufferPriorsCheck(info))
    //            {
    //                active_notes_buffer.add(info);
    //                
    //                //DBG(info->toString() + "in active");
    //            }
    //        }
    //    }
    //}
}

void SheetGridComponent::addExtraLine()
{
    /*
    cells.add(new OwnedArray<CellComponent>);
    for (int c = 0; c < numBeats; c++)
    {
        cells[cells.size() - 1]->add(new CellComponent);
        addAndMakeVisible(cells[cells.size() - 1]->operator[](c));
    }
    resized();
    */
}

void SheetGridComponent::addExtraBeat()
{
    /*
    numBeats++;
    for (int c = 0; c < 16; c++)
    {
        cells[c]->add(new CellComponent);
        addAndMakeVisible(cells[c]->operator[](cells[c]->size()-1));
    }
    resized();
    */
}

void SheetGridComponent::addExtraBeat(int num)
{
    for (int c = 0; c < num; c++)
    {
        addExtraBeat();
    }
}

void SheetGridComponent::turnOnBeat(String key, int beat)
{
    active_notes_buffer.add(new Kinfo(key, beat, true));

    if (key.contains("A"))
    {
        cells[5]->operator[](beat)->turnOn();
    }
    if (key.contains("B"))
    {

    }
    if (key.contains("C"))
    {
        cells[4]->operator[](beat)->turnOn();
    }
    if (key.contains("D"))
    {

    }
    if (key.contains("E"))
    {
        cells[3]->operator[](beat)->turnOn();
    }
    if (key.contains("F"))
    {
        cells[6]->operator[](beat)->turnOn();
    }
    if (key.contains("G"))
    {

    }
}


void SheetGridComponent::turnOffBeat(String key, int beat)
{
    for (int c = 0; c < active_notes_buffer.size(); c++)
    {
        if (active_notes_buffer[c]->key.equalsIgnoreCase(key) && active_notes_buffer[c]->beat == beat)
        {
            active_notes_buffer.remove(c);
        }
    }

    if (key.contains("A"))
    {
        cells[5]->operator[](beat)->turnOff();
    }
    if (key.contains("B"))
    {

    }
    if (key.contains("C"))
    {
        cells[4]->operator[](beat)->turnOff();
    }
    if (key.contains("D"))
    {

    }
    if (key.contains("E"))
    {
        cells[3]->operator[](beat)->turnOff();
    }
    if (key.contains("F"))
    {
        cells[6]->operator[](beat)->turnOff();
    }
    if (key.contains("G"))
    {

    }
}

void SheetGridComponent::paint(juce::Graphics& g)
{
    g.fillAll(bgCol.withAlpha(float(0.2)));
    g.setColour(Colours::aquamarine);
    g.drawRect(getLocalBounds());
}

void SheetGridComponent::resized()
{
    int size = cells.size();

    for (int c = 0; c < size ; c++)
    {
        for (int x = 0; x < numBeats; x++)
        {
            cells[c]->operator[](x)->setBounds(x * getWidth()/numBeats, c * getHeight() / size, getWidth() / numBeats, getHeight() / size);
        }
    }
}

void SheetGridComponent::mouseDown(const MouseEvent& e)
{
    int dx = e.getMouseDownX();
    int dy = e.getMouseDownY();

    int nCol = dx / (getWidth() / 4);

    if (dy >= getHeight() / 2)
    {
        // work for bass

        dy -= getHeight() / 2;

        int rowHeight = getHeight() / 20;
        int Note = dy / rowHeight;
        int midNote = dy % rowHeight;
        int noteIndex = Note;
        String strNote = "";
        int noteX = nCol * (getWidth() / 4);
        int noteY = (noteIndex)*rowHeight;
        if ((midNote >= (rowHeight - 2)) || (midNote <= 2))
        {
            //line note

            if (midNote <= 2)
            {
                noteIndex--;
                noteY -= rowHeight / 2;
            }
            else
            {
                noteIndex++;
                noteY += rowHeight / 2;
            }
        }
        int nNoteNum = 60;
        strNote = getBassNote(noteY % rowHeight, noteY / rowHeight, nNoteNum);
        if (strNote.isEmpty())
            return;
        noteCollection.add(new CellComponent(strNote, nCol, true));
        addAndMakeVisible(noteCollection.getLast());
        noteCollection.getLast()->turnOn();
        noteCollection.getLast()->setNoteNum(nNoteNum);
        noteCollection.getLast()->setBounds(noteX, noteY + getHeight() / 2, getWidth() / 4, rowHeight);
    }
    else
    {
        //work for trebble

        int rowHeight = getHeight() / 20;
        int Note = dy / rowHeight;
        int midNote = dy % rowHeight;
        int noteIndex = Note;
        String strNote = "";
        int noteX = nCol * (getWidth() / 4);
        int noteY = (noteIndex)*rowHeight;
        if ((midNote >= (rowHeight - 2)) || (midNote <= 2))
        {
            //line note

            if (midNote <= 2)
            {
                noteIndex--;
                noteY -= rowHeight / 2;
            }
            else
            {
                noteIndex++;
                noteY += rowHeight / 2;
            }
        }
        int nNoteNum = 60;
        strNote = getTrebbleNote(noteY % rowHeight, noteY / rowHeight, nNoteNum);
        if (strNote.isEmpty())
            return;
        noteCollection.add(new CellComponent(strNote, nCol, true));
        addAndMakeVisible(noteCollection.getLast());
        noteCollection.getLast()->turnOn();
        noteCollection.getLast()->setNoteNum(nNoteNum);
        noteCollection.getLast()->setBounds(noteX, noteY, getWidth() / 4, rowHeight);
    }
}


void SheetGridComponent::playnote(int xShift)
{
    if ((xShift % (getWidth() / 4)) == 0)
    {
        for (CellComponent* c : noteCollection)
        {
            if (c->getBeat() == (xShift / (getWidth() / 4)) && c->downState())
            {
                String key = c->getKey();
                int beat = c->getBeat();
                auto* info = new Kinfo(key, beat, true);
                DBG(info->toString() + "In Sheet grid component");
                if (key.isEmpty())
                    String brk = "";

                const MidiMessage mOn(MidiMessage::noteOn(1, c->getNoteNum(), (uint8)100), Time::getMillisecondCounterHiRes() * 0.001);
                MidiBuffer buff(mOn);
                SheetMusicAudioProcessorEditor::g_midiBUffer.swapWith(buff);
                //msgCollector->addMessageToQueue(mOn);

                //MidiMessage mOff(MidiMessage::noteOff(1, c->getNoteNum(), (uint8)100), Time::getMillisecondCounterHiRes() * 0.001);
                //m_pMsgCollector->addMessageToQueue(mOff);
            }
        }
    }
    if (((xShift + 1) % (getWidth() / 4)) == 0)
    {
        for (CellComponent* c : noteCollection)
        {
            if (c->getBeat() == (xShift / (getWidth() / 4)) && c->downState())
            {
                String key = c->getKey();
                int beat = c->getBeat();
                auto* info = new Kinfo(key, beat, true);
                DBG(info->toString() + "Leaving grid component");
                if (key.isEmpty())
                    String brk = "";

                //MidiMessage mOn(MidiMessage::noteOn(1, c->getNoteNum(), (uint8)100), Time::getMillisecondCounterHiRes() * 0.001);
                //msgCollector->addMessageToQueue(mOn);

                MidiMessage mOff(MidiMessage::noteOff(1, c->getNoteNum(), (uint8)100), Time::getMillisecondCounterHiRes() * 0.001);
                MidiBuffer buff(mOff);
                SheetMusicAudioProcessorEditor::g_midiBUffer.swapWith(buff);
                //m_pMsgCollector->addMessageToQueue(mOff);
            }
        }
    }
}