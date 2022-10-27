/*
  ==============================================================================

    StaffHeaderComponent.cpp
    Created: 9 Sep 2522 8:19:15pm
    Author:  QWERTY SENPAI

  ==============================================================================
*/

#include <JuceHeader.h>
#include "StaffHeaderComponent.h"

//==============================================================================
StaffHeaderComponent::StaffHeaderComponent(headerInfo info)
{
        bassCleff.setImage(ImageCache::getFromMemory(BinaryData::Bass_Clef_png, BinaryData::Bass_Clef_pngSize));
        bassCleff.setBoundingBox(Rectangle<float>(0, 26, 50, 47));
        bassCleff.setAlwaysOnTop(false);

        trebleCleff.setImage(ImageCache::getFromMemory(BinaryData::Treble_Clef_png, BinaryData::Treble_Clef_pngSize));
        trebleCleff.setBoundingBox(Rectangle<float>(0, 23, 50, 65));
        trebleCleff.setAlwaysOnTop(false);
     
        TwoFour.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        TwoFour.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        TwoFour.setAlwaysOnTop(true);

        ThreeFour.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        ThreeFour.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        ThreeFour.setAlwaysOnTop(true);

        FourFour.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        FourFour.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        FourFour.setAlwaysOnTop(true);

        FiveFour.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        FiveFour.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        FiveFour.setAlwaysOnTop(true);

        SixFour.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        SixFour.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        SixFour.setAlwaysOnTop(true);

        ThreeEight.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        ThreeEight.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        ThreeEight.setAlwaysOnTop(true);

        SixEight.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        SixEight.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        SixEight.setAlwaysOnTop(true);

        NineEight.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        NineEight.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        NineEight.setAlwaysOnTop(true);

        TwelveEight.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        TwelveEight.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        TwelveEight.setAlwaysOnTop(true);

        CommonTime.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        CommonTime.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        CommonTime.setAlwaysOnTop(true);

        CutTime.setImage(ImageCache::getFromMemory(BinaryData::Channel_bg_png, BinaryData::Channel_bg_pngSize));
        CutTime.setBoundingBox(Rectangle<float>(30, 30, 20, 45));
        CutTime.setAlwaysOnTop(true);

        CMajorInSharp.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        CMajorInSharp.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        CMajorInSharp.setAlwaysOnTop(true);

        CMajorInFlat.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        CMajorInFlat.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        CMajorInFlat.setAlwaysOnTop(true);
      
        GMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        GMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        GMajor.setAlwaysOnTop(true);

        DMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        DMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        DMajor.setAlwaysOnTop(true);

        AMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        AMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        AMajor.setAlwaysOnTop(true);

        EMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        EMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        EMajor.setAlwaysOnTop(true);

        BMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        BMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        BMajor.setAlwaysOnTop(true);

        FSharpMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        FSharpMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        FSharpMajor.setAlwaysOnTop(true);

        CSharpMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        CSharpMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        CSharpMajor.setAlwaysOnTop(true);

        AMinorInSharp.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        AMinorInSharp.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        AMinorInSharp.setAlwaysOnTop(true);

        AMinorInFlat.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        AMinorInFlat.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        AMinorInFlat.setAlwaysOnTop(true);

        EMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        EMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        EMinor.setAlwaysOnTop(true);

        BMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        BMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        BMinor.setAlwaysOnTop(true);

        FSharpMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        FSharpMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        FSharpMinor.setAlwaysOnTop(true);

        CSharpMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        CSharpMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        CSharpMinor.setAlwaysOnTop(true);

        GSharpMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        GSharpMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        GSharpMinor.setAlwaysOnTop(true);

        DSharpMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        DSharpMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        DSharpMinor.setAlwaysOnTop(true);

        AMinorInSharp.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        AMinorInSharp.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        AMinorInSharp.setAlwaysOnTop(true);

        BFlatMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        BFlatMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        BFlatMajor.setAlwaysOnTop(true);

        EFlatMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        EFlatMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        EFlatMajor.setAlwaysOnTop(true);

        DFlatMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        DFlatMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        DFlatMajor.setAlwaysOnTop(true);

        GFlatMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        GFlatMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        GFlatMajor.setAlwaysOnTop(true);

        CFlatMajor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        CFlatMajor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        CFlatMajor.setAlwaysOnTop(true);

        DMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        DMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        DMinor.setAlwaysOnTop(true);

        GMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        GMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        GMinor.setAlwaysOnTop(true);

        CMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        CMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        CMinor.setAlwaysOnTop(true);

        FMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        FMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        FMinor.setAlwaysOnTop(true);
        
        BFlatMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        BFlatMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        BFlatMinor.setAlwaysOnTop(true);

        EFlatMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        EFlatMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        EFlatMinor.setAlwaysOnTop(true);

        AFlatMinor.setImage(ImageCache::getFromMemory(BinaryData::Orange_png, BinaryData::Orange_pngSize));
        AFlatMinor.setBoundingBox(Rectangle<float>(50, 30, 140, 45));
        AFlatMinor.setAlwaysOnTop(true);

}

bool StaffHeaderComponent::isInterestedInDragSource(const SourceDetails& dragSourceDetails)
{
    return true;
}

bool StaffHeaderComponent::isKey(String name)
{

    if (name.equalsIgnoreCase("CMajorInSharp"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("CMajorInFlat"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("GMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("DMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("AMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("EMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("BMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("FSharpMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("CSharpMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("AMinorInSharp"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("AMinorInFlat"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("EMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("BMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("FSharpMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("CSharpMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("GSharpMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("DSharpMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("AMinorInSharp"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("BFlatMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("EFlatMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("DFlatMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("GFlatMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("CFlatMajor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("DMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("GMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("CMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("FMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("BFlatMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("EFlatMinor"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("AFlatMinor"))
    {
        return true;
    }
}

bool StaffHeaderComponent::isTime(String name)
{
    if (name.equalsIgnoreCase("TwoFour"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("ThreeFour"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("FourFour"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("FiveFour"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("SixFour"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("ThreeEight"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("SixEight"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("NineEight"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("TwelveEight"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("CommonTime"))
    {
        return true;
    }
    if (name.equalsIgnoreCase("CutTime"))
    {
        return true;
    }
}

void StaffHeaderComponent::clearLastKey(String name)
{
    if (name.equalsIgnoreCase("CMajorInSharp"))
    {
        CMajorInSharp.setVisible(false);
    }
    if (name.equalsIgnoreCase("CMajorInFlat"))
    {
        CMajorInFlat.setVisible(false);
    }
    if (name.equalsIgnoreCase("GMajor"))
    {
        GMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("DMajor"))
    {
        DMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("AMajor"))
    {
        AMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("EMajor"))
    {
        EMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("BMajor"))
    {
        BMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("FSharpMajor"))
    {
        FSharpMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("CSharpMajor"))
    {
        CSharpMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("AMinorInSharp"))
    {
        AMinorInSharp.setVisible(false);
    }
    if (name.equalsIgnoreCase("AMinorInFlat"))
    {
        AMinorInFlat.setVisible(false);
    }
    if (name.equalsIgnoreCase("EMinor"))
    {
        EMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("BMinor"))
    {
        BMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("FSharpMinor"))
    {
        FSharpMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("CSharpMinor"))
    {
        CSharpMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("GSharpMinor"))
    {
        GSharpMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("DSharpMinor"))
    {
        DSharpMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("AMinorInSharp"))
    {
        AMinorInSharp.setVisible(false);
    }
    if (name.equalsIgnoreCase("BFlatMajor"))
    {
        BFlatMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("EFlatMajor"))
    {
        EFlatMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("DFlatMajor"))
    {
        DFlatMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("GFlatMajor"))
    {
        DFlatMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("CFlatMajor"))
    {
        CFlatMajor.setVisible(false);
    }
    if (name.equalsIgnoreCase("DMinor"))
    {
        DMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("GMinor"))
    {
        GMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("CMinor"))
    {
        CMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("FMinor"))
    {
        FMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("BFlatMinor"))
    {
        BFlatMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("EFlatMinor"))
    {
        EFlatMinor.setVisible(false);
    }
    if (name.equalsIgnoreCase("AFlatMinor"))
    {
        AFlatMinor.setVisible(false);
    }
}

void StaffHeaderComponent::clearLastTime(String name)
{
    if (name.equalsIgnoreCase("TwoFour"))
    {
        TwoFour.setVisible(false);
    }
    if (name.equalsIgnoreCase("ThreeFour"))
    {
        ThreeFour.setVisible(false);
    }
    if (name.equalsIgnoreCase("FourFour"))
    {
        FourFour.setVisible(false);
    }
    if (name.equalsIgnoreCase("FiveFour"))
    {
        FiveFour.setVisible(false);
    }
    if (name.equalsIgnoreCase("SixFour"))
    {
        SixFour.setVisible(false);
    }
    if (name.equalsIgnoreCase("ThreeEight"))
    {
        ThreeEight.setVisible(false);
    }
    if (name.equalsIgnoreCase("SixEight"))
    {
        SixEight.setVisible(false);
    }
    if (name.equalsIgnoreCase("NineEight"))
    {
        NineEight.setVisible(false);
    }
    if (name.equalsIgnoreCase("TwelveEight"))
    {
        TwelveEight.setVisible(false);
    }
    if (name.equalsIgnoreCase("CommonTime"))
    {
        CommonTime.setVisible(false);
    }
    if (name.equalsIgnoreCase("CutTime"))
    {
        CutTime.setVisible(false);
    }
}

void StaffHeaderComponent::itemDropped(const SourceDetails& dragSourceDetails)
{
   String name ( dragSourceDetails.description.toString());
   
   if (isKey(name))
   {
       clearLastKey(last_key);
       if (name.equalsIgnoreCase("CMajorInSharp"))
       {
           addAndMakeVisible(CMajorInSharp);
       }
       if (name.equalsIgnoreCase("CMajorInFlat"))
       {
           addAndMakeVisible(CMajorInFlat);
       }
       if (name.equalsIgnoreCase("GMajor"))
       {
           addAndMakeVisible(GMajor);
       }
       if (name.equalsIgnoreCase("DMajor"))
       {
           addAndMakeVisible(DMajor);
       }
       if (name.equalsIgnoreCase("AMajor"))
       {
           addAndMakeVisible(AMajor);
       }
       if (name.equalsIgnoreCase("EMajor"))
       {
           addAndMakeVisible(EMajor);
       }
       if (name.equalsIgnoreCase("BMajor"))
       {
           addAndMakeVisible(BMajor);
       }
       if (name.equalsIgnoreCase("FSharpMajor"))
       {
           addAndMakeVisible(FSharpMajor);
       }
       if (name.equalsIgnoreCase("CSharpMajor"))
       {
           addAndMakeVisible(CSharpMajor);
       }
       if (name.equalsIgnoreCase("AMinorInSharp"))
       {
           addAndMakeVisible(AMinorInSharp);
       }
       if (name.equalsIgnoreCase("AMinorInFlat"))
       {
           addAndMakeVisible(AMinorInFlat);
       }
       if (name.equalsIgnoreCase("EMinor"))
       {
           addAndMakeVisible(EMinor);
       }
       if (name.equalsIgnoreCase("BMinor"))
       {
           addAndMakeVisible(BMinor);
       }
       if (name.equalsIgnoreCase("FSharpMinor"))
       {
           addAndMakeVisible(FSharpMinor);
       }
       if (name.equalsIgnoreCase("CSharpMinor"))
       {
           addAndMakeVisible(CSharpMinor);
       }
       if (name.equalsIgnoreCase("GSharpMinor"))
       {
           addAndMakeVisible(GSharpMinor);
       }
       if (name.equalsIgnoreCase("DSharpMinor"))
       {
           addAndMakeVisible(DSharpMinor);
       }
       if (name.equalsIgnoreCase("AMinorInSharp"))
       {
           addAndMakeVisible(AMinorInSharp);
       }
       if (name.equalsIgnoreCase("BFlatMajor"))
       {
           addAndMakeVisible(BFlatMajor);
       }
       if (name.equalsIgnoreCase("EFlatMajor"))
       {
           addAndMakeVisible(EFlatMajor);
       }
       if (name.equalsIgnoreCase("DFlatMajor"))
       {
           addAndMakeVisible(DFlatMajor);
       }
       if (name.equalsIgnoreCase("GFlatMajor"))
       {
           addAndMakeVisible(GFlatMajor);
       }
       if (name.equalsIgnoreCase("CFlatMajor"))
       {
           addAndMakeVisible(CFlatMajor);
       }
       if (name.equalsIgnoreCase("DMinor"))
       {
           addAndMakeVisible(DMinor);
       }
       if (name.equalsIgnoreCase("GMinor"))
       {
           addAndMakeVisible(GMinor);
       }
       if (name.equalsIgnoreCase("CMinor"))
       {
           addAndMakeVisible(CMinor);
       }
       if (name.equalsIgnoreCase("FMinor"))
       {
           addAndMakeVisible(FMinor);
       }
       if (name.equalsIgnoreCase("BFlatMinor"))
       {
           addAndMakeVisible(BFlatMinor);
       }
       if (name.equalsIgnoreCase("EFlatMinor"))
       {
           addAndMakeVisible(EFlatMinor);
       }
       if (name.equalsIgnoreCase("AFlatMinor"))
       {
           addAndMakeVisible(AFlatMinor);
       }
   }
   if (isTime(name))
   {
       clearLastTime(last_key);
       if (name.equalsIgnoreCase("TwoFour"))
       {
           addAndMakeVisible(TwoFour);
       }
       if (name.equalsIgnoreCase("ThreeFour"))
       {
           addAndMakeVisible(ThreeFour);
       }
       if (name.equalsIgnoreCase("FourFour"))
       {
           addAndMakeVisible(FourFour);
       }
       if (name.equalsIgnoreCase("FiveFour"))
       {
           addAndMakeVisible(FiveFour);
       }
       if (name.equalsIgnoreCase("SixFour"))
       {
           addAndMakeVisible(SixFour);
       }
       if (name.equalsIgnoreCase("ThreeEight"))
       {
           addAndMakeVisible(ThreeEight);
       }
       if (name.equalsIgnoreCase("SixEight"))
       {
           addAndMakeVisible(SixEight);
       }
       if (name.equalsIgnoreCase("NineEight"))
       {
           addAndMakeVisible(NineEight);
       }
       if (name.equalsIgnoreCase("TwelveEight"))
       {
           addAndMakeVisible(TwelveEight);
       }
       if (name.equalsIgnoreCase("CommonTime"))
       {
           addAndMakeVisible(CommonTime);
       }
       if (name.equalsIgnoreCase("CutTime"))
       {
           addAndMakeVisible(CutTime);
       }
   }

   if (name.equalsIgnoreCase("Bass"))
   {
       trebleCleff.setVisible(false);
       addAndMakeVisible(bassCleff);
   }
   if (name.equalsIgnoreCase("Treble"))
   {
       bassCleff.setVisible(false);
       addAndMakeVisible(trebleCleff); 
   }


}

StaffHeaderComponent::~StaffHeaderComponent()
{
    
}

void StaffHeaderComponent::paint (juce::Graphics& g)
{
    g.drawLine(0, 0, 0, getHeight());
    for (int c = 0; c < 5; c++)
    {
        g.drawLine(0, (c+3) * getHeight() / 16, getWidth(), (c+3) * getHeight() / 16);
    }

}

void StaffHeaderComponent::resized()
{

}
