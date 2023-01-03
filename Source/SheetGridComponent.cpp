/*
  ==============================================================================

    SheetGridComponent.cpp
    Created: 8 Sep 2022 1:36:51pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SheetGridComponent.h"

using namespace juce;

//==============================================================================


SheetGridComponent::SheetGridComponent()
{
    //return;
    for (int c = 0; c < 16; c++)
    {
  //      cells.add(new OwnedArray<CellComponent>);
    }

    //for (int c = 0; c < 16; c++)
    //{
    //    cells.add(new OwnedArray<CellComponent>);
    //}


    for (int c = 0; c < 16; c++)
    {
       for (int x = 0; x < 4; x++)
       {
           if (c <= 6 && 3 <= c)
            {
    //            cells[c]->add(new CellComponent(cellNumberToKey(c), x, false));
            }

   //        cells[c]->add(new CellComponent("", 0, false));
           //addAndMakeVisible(cells[c]->operator[](x));

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

String SheetGridComponent::getTrebbleNote(int num)
{
    switch (num)
    {

    case 2:
        return "F";
        break;
    case 3:
        return "E";
        break;
    case 4:
        return "D";
        break;
    case 5:
        return "C";
        break;
    case 6 :
        return "B";
        break;
    case 7 : 
        return "A";
        break;
    case 8:
        return "G";
        break;
    case 9:
        return "F";
        break;
    case 10:
        return "E";
        break;
    default:
        return"";
    }
}
String SheetGridComponent::getBassNote(int num)
{
    switch (num)
    {

    case 2:
        return "A";
        break;
    case 3:
        return "G";
        break;
    case 4:
        return "F";
        break;
    case 5:
        return "E";
        break;
    case 6:
        return "D";
        break;
    case 7:
        return "C";
        break;
    case 8:
        return "B";
        break;
    case 9:
        return "A";
        break;
    case 10:
        return "G";
        break;
    default:
        return"";
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
    //for (int c = 0; c < 16; c++)
    //{
        //for (int x = 0; x < 4; x++)
        //int x = bar;
        //DBG(String(x));
        //String val = cells[c]->operator[](x)->downState()?"true":"false";
        //DBG(val);
        //{   
            //if (cells[c]->operator[](x)->downState())
            //{
            //    String key = cells[c]->operator[](x)->getKey();
            //    int beat = cells[c]->operator[](x)->getBeat();
            //    auto* info = new Kinfo(key, beat, true);

            //    DBG(info->toString() + "In sheet grid component");
            //    if (bufferPriorsCheck(info))
            //    {
            //        active_notes_buffer.add(info);
            //        
            //        //DBG(info->toString() + "in active");
            //    }

            //}

        //}
    //}

    int x = bar;
    //iterate throught the notecollection 
    for (CellComponent* c : noteCollection){
        if (c->getBeat() == bar) {
            String key = c->getKey();
            int beat = c->getBeat();
            auto* info = new Kinfo(key, beat, true);
            DBG(info->toString() + "In sheet grid component");

            //adding to midi messages
            auto message = juce::MidiMessage::noteOn(1, (int)key[0], (uint8)100);
            message.setTimeStamp(juce::Time::getMillisecondCounterHiRes() * 0.001 - startTime);

            auto messageOff = juce::MidiMessage::noteOff(message.getChannel(), message.getNoteNumber());
            messageOff.setTimeStamp(juce::Time::getMillisecondCounterHiRes() * 0.001 - startTime);

            addMessagetoBuffer(message);
            addMessagetoBuffer(messageOff);

        }

    }



}



void SheetGridComponent::addMessagetoBuffer(MidiMessage& message) {
    
    auto timestamp = message.getTimeStamp();
    auto sampleNumber = (int)(timestamp * sampleRate);
    midiBuffer.addEvent(message, sampleNumber);

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
  //      cells[5]->operator[](beat)->turnOn();
    }
    if (key.contains("B"))
    {

    }
    if (key.contains("C"))
    {
  //      cells[4]->operator[](beat)->turnOn();
    }
    if (key.contains("D"))
    {

    }
    if (key.contains("E"))
    {
   //     cells[3]->operator[](beat)->turnOn();
    }
    if (key.contains("F"))
    {
   //     cells[6]->operator[](beat)->turnOn();
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
     //   cells[5]->operator[](beat)->turnOff();
    }
    if (key.contains("B"))
    {

    }
    if (key.contains("C"))
    {
      //  cells[4]->operator[](beat)->turnOff();
    }
    if (key.contains("D"))
    {

    }
    if (key.contains("E"))
    {
     //   cells[3]->operator[](beat)->turnOff();
    }
    if (key.contains("F"))
    {
    //    cells[6]->operator[](beat)->turnOff();
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
    /*int size = cells.size();

    for (int c = 0; c < size ; c++)
    {
        for (int x = 0; x < numBeats; x++)
        {
            cells[c]->operator[](x)->setBounds(x * getWidth()/numBeats, c * getHeight() / size, getWidth() / numBeats, getHeight() / size);
        }
    }*/
}
int SheetGridComponent::roundOff(int n) {
    // Smaller multiple
    int a = (n / 10) * 10;

    // Larger multiple
    int b = a + 10;

    // Return of closest of two
    return (n - a > b - n) ? b : a;
}

void SheetGridComponent::mouseDown(const MouseEvent& e)
{
    int dx = e.getMouseDownX();
    int dy = e.getMouseDownY();

    int nCol = dx / (getWidth() / 4);

    if (dy >= getHeight() / 2)
    {
        // work for bass

        //dy -= getHeight() / 2;

        //int rowHeight = getHeight() / 20;
        //int Note = dy / 10;
        //int midNote = Note % rowHeight;

        //if ((midNote >= (rowHeight - 2)) || (midNote <= 2))
        //{
        //    //line note
        //}
        //else
        //{
        //    //whitespace note
        //}
        //work for trebble

        int rowHeight = getHeight() / 20;
        int Note = dy / rowHeight;
        int midNote = dy % rowHeight;
        int noteIndex = Note;
        int noteY;
        //if ((2<=midNote && midNote <= 4) || (midNote <= 1
        if (midNote >= 7 || midNote <= 2)
        {
            //line note

            String strNote = "";
            /* if (midNote <=2)
             {*/
             //noteY = (dy + 1) - rowHeight / 2;
            int rounded = roundOff(dy);
            noteY = rounded - 5;
            noteIndex--;
            //}
            //else if( 2 <=midNote && midNote <= 4)
            //{   
            //    noteY = (dy - (dy % 10) + 1) - rowHeight / 2;
            //    noteIndex++;
            //    //strNote = getTrebbleNote(noteIndex + 1);
            //}
            /*else {
                noteY = (noteIndex)*rowHeight + rowHeight / 2;
            }*/
            int noteX = nCol * (getWidth() / 4);
            //  int noteY = (noteIndex)*rowHeight + rowHeight / 2;
              //int noteY = (dy + 1) - rowHeight / 2;
            strNote = getBassNote(noteIndex);
            noteCollection.add(new CellComponent(strNote, nCol, true));
            addAndMakeVisible(noteCollection.getLast());
            noteCollection.getLast()->turnOn();
            noteCollection.getLast()->setBounds(noteX, noteY, getWidth() / 4, rowHeight);

        }
        else
        {
            //whitespace note

            String strNote = getTrebbleNote(noteIndex);
            int noteX = nCol * (getWidth() / 4);

            int noteY = roundOff(dy);
            if (midNote == 6) noteY = roundOff(dy) - 10;
            //int noteY = (dy + 1) - rowHeight / 2;
            strNote = getTrebbleNote(noteIndex);
            noteCollection.add(new CellComponent(strNote, nCol, true));
            addAndMakeVisible(noteCollection.getLast());
            noteCollection.getLast()->turnOn();
            noteCollection.getLast()->setBounds(noteX, noteY, getWidth() / 4, rowHeight);
        }
    }
    else
    {
        //work for trebble

        int rowHeight = getHeight() / 20;
        int Note = dy / rowHeight;
        int midNote = dy % rowHeight;
        int noteIndex = Note;
        int noteY;
        //if ((2<=midNote && midNote <= 4) || (midNote <= 1
        if(midNote>=7 || midNote<=2)
        {
            //line note

            String strNote = "";
           /* if (midNote <=2)
            {*/
                //noteY = (dy + 1) - rowHeight / 2;
                int rounded = roundOff(dy);
                noteY = rounded - 5;
                noteIndex--;
            //}
            //else if( 2 <=midNote && midNote <= 4)
            //{   
            //    noteY = (dy - (dy % 10) + 1) - rowHeight / 2;
            //    noteIndex++;
            //    //strNote = getTrebbleNote(noteIndex + 1);
            //}
            /*else {
                noteY = (noteIndex)*rowHeight + rowHeight / 2;
            }*/
            int noteX = nCol * (getWidth() / 4);
          //  int noteY = (noteIndex)*rowHeight + rowHeight / 2;
            //int noteY = (dy + 1) - rowHeight / 2;
            strNote = getTrebbleNote(noteIndex);
            noteCollection.add(new CellComponent(strNote, nCol, true));
            addAndMakeVisible(noteCollection.getLast());
            noteCollection.getLast()->turnOn();
            noteCollection.getLast()->setBounds(noteX, noteY, getWidth() / 4, rowHeight);

        }
        else
        {
            //whitespace note

            String strNote = getTrebbleNote(noteIndex);
            int noteX = nCol * (getWidth() / 4);
            
            int noteY = roundOff(dy);
            if (midNote == 6) noteY = roundOff(dy) - 10;
              //int noteY = (dy + 1) - rowHeight / 2;
            strNote = getTrebbleNote(noteIndex);
            noteCollection.add(new CellComponent(strNote, nCol, true));
            addAndMakeVisible(noteCollection.getLast());
            noteCollection.getLast()->turnOn();
            noteCollection.getLast()->setBounds(noteX, noteY, getWidth() / 4, rowHeight);
        }
    }


}
