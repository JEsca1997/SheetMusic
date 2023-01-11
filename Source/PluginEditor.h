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
#include "PlayheadComponent.h"

//==============================================================================
/**
*/
class SheetMusicAudioProcessorEditor  : public juce::AudioProcessorEditor, public AsyncUpdater//, public Timer
{
public:

    static MidiBuffer g_midiBUffer;

    SheetMusicAudioProcessorEditor (SheetMusicAudioProcessor&);
    ~SheetMusicAudioProcessorEditor() override;

    void timerCallback();// override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void SetPlayHeadPos(int x, int y, int w, int h);
    void loadFile();

    void playButtonPushed();
    void handleAsyncUpdate() override;
private:
    class PlayHeadThread : public Thread
    {
    public:
        PlayHeadThread(SheetMusicAudioProcessorEditor* pParent) : Thread("PlayHead thread"), objParent(*pParent) { xTempLimit = 0; }
        void setTempLimit(int nXlimit) {
            xTempLimit = nXlimit;
        }
        int GetXShift() { 
            int temp = XShift / 160;
            if (temp == 4)
            {
                temp = 0;
                XShift = 0;
                YShift++;
                if (YShift > 3)
                    YShift = 0;
            }
            return  XShift + 30 * temp;
        }
        int GetYShift() { return YShift; }
        int GetXValue() { return XShift; }
        void ResetXShift() { XShift = 0; }
        void pauseThread(bool bPause) { m_bPauseShift = bPause; }
        void run() override;

        bool m_bPauseShift = false;
        SheetMusicAudioProcessorEditor& objParent;
        std::atomic<int> XShift{ 0 };
        std::atomic<int> YShift{ 0 };
        std::atomic<int> xTempLimit;
    };
    PlayHeadThread objPlayHeadThread;
    PlayheadComponent m_objPlayHead;


    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SheetMusicAudioProcessor& audioProcessor;

    MidiBuffer buffer;

    TextEditor bpm;
    int current_bar = 0;
    int current_staff = 0;

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

   // TreeViewItemComponent* Accidentals;
    TreeViewItemComponent* AccidentalSharps;
    TreeViewItemComponent* AccidentalFlats;
    TreeViewItemComponent* KeySigSharps;
    TreeViewItemComponent* KeySigFlats;
    TreeViewItemComponent* MajorSharps;
    TreeViewItemComponent* MajorFlats;
    TreeViewItemComponent* MinorSharps;
    TreeViewItemComponent* MinorFlats;
    TreeViewItemComponent* Naturals;
    TreeViewItemComponent* Acciacuta;
    TreeViewItemComponent* Appogiatura;
    TreeViewItemComponent* GraceQuarter;
    TreeViewItemComponent* GraceSixteenth;
    TreeViewItemComponent* GraceThirtySecond;
  //  TreeViewItemComponent* GraceSixteenth;

    TreeViewItemComponent* Major;
    TreeViewItemComponent* CMajorInSharp;
    TreeViewItemComponent* CMajorInFlat;
    TreeViewItemComponent* GMajor;
    TreeViewItemComponent* DMajor;
    TreeViewItemComponent* AMajor;
    TreeViewItemComponent* EMajor;
    TreeViewItemComponent* BMajor;
    TreeViewItemComponent* FSharpMajor;
    TreeViewItemComponent* CSharpMajor;

    TreeViewItemComponent* AMinorInSharp;
    TreeViewItemComponent* AMinorInFlat;
    TreeViewItemComponent* EMinor;
    TreeViewItemComponent* BMinor;
    TreeViewItemComponent* FSharpMinor;
    TreeViewItemComponent* CSharpMinor;
    TreeViewItemComponent* GSharpMinor;
    TreeViewItemComponent* DSharpMinor;
    TreeViewItemComponent* ASharpMinor;

 //   TreeViewItemComponent* CMajor;
    TreeViewItemComponent* BFlatMajor;
    TreeViewItemComponent* EFlatMajor;
    TreeViewItemComponent* AFlatMajor;
    TreeViewItemComponent* DFlatMajor;
    TreeViewItemComponent* GFlatMajor;
    TreeViewItemComponent* CFlatMajor;

    TreeViewItemComponent* Minor;
 //   TreeViewItemComponent* AMinor;
    TreeViewItemComponent* DMinor;
    TreeViewItemComponent* GMinor;
    TreeViewItemComponent* CMinor;
    TreeViewItemComponent* FMinor;
    TreeViewItemComponent* BFlatMinor;
    TreeViewItemComponent* EFlatMinor;
    TreeViewItemComponent* AFlatMinor;

    TreeViewItemComponent* TwoFour;
    TreeViewItemComponent* ThreeFour;
    TreeViewItemComponent* FourFour;
    TreeViewItemComponent* FiveFour;
    TreeViewItemComponent* SixFour;
    TreeViewItemComponent* ThreeEight;
    TreeViewItemComponent* SixEight;
    TreeViewItemComponent* NineEight;
    TreeViewItemComponent* TwelveEight;
    TreeViewItemComponent* CommonTime;
    TreeViewItemComponent* CutTime;

    TreeViewItemComponent* SingleLine;
    TreeViewItemComponent* DoubleLine;
    TreeViewItemComponent* RepeatSign;
    TreeViewItemComponent* RightEndRepeatSign;
    TreeViewItemComponent* RightAndLeft;
    TreeViewItemComponent* Dashed;
    TreeViewItemComponent* FinalBarLine;
    TreeViewItemComponent* DottedBarLine;
    TreeViewItemComponent* ReverseFinalBarline;
    TreeViewItemComponent* HeavyBarLine;
    TreeViewItemComponent* DashedBarLine;
    TreeViewItemComponent* TickedBarline;
    TreeViewItemComponent* ShortBarline;
    TreeViewItemComponent* ShortBarlineTwo;

    TreeViewItemComponent* LinesLine;
    TreeViewItemComponent* Slur;
    TreeViewItemComponent* Crescendo;
    TreeViewItemComponent* Diminuendo;
    TreeViewItemComponent* CrescendoLine;
    TreeViewItemComponent* DiminuendoLine;
    TreeViewItemComponent* PrimaVolta;
    TreeViewItemComponent* SecondVolta;
    TreeViewItemComponent* SecondVoltaOpen;
    TreeViewItemComponent* EighthVoltaAlta;
    TreeViewItemComponent* EighthVoltaBassa;
    TreeViewItemComponent* Pedal;
    TreeViewItemComponent* PedalAngled;
    TreeViewItemComponent* PedalBothAngled;
    TreeViewItemComponent* PedalAngledStartHook;
    TreeViewItemComponent* SystemTextLine;
    TreeViewItemComponent* Line;
    TreeViewItemComponent* Ambitus;
    TreeViewItemComponent* LetRing;
    TreeViewItemComponent* MFDynamicHairpin;
    TreeViewItemComponent* TerzaVolta;
    TreeViewItemComponent* FifteenAlta;
    TreeViewItemComponent* FifteenBassa;
    TreeViewItemComponent* TwentyTwoMAAbove;
    TreeViewItemComponent* PedalwithLine;
    TreeViewItemComponent* PedalWithAsterik;
    TreeViewItemComponent* Trill;
    TreeViewItemComponent* Uprall;
    TreeViewItemComponent* Downprall;
    TreeViewItemComponent* PrallprallLine;
    TreeViewItemComponent* StaffTextLine;
    TreeViewItemComponent* GuitarVibrato;
    TreeViewItemComponent* GuitarVibratoWide;
    TreeViewItemComponent* VibratoSawtooth;
    TreeViewItemComponent* TremoloSawtoothWide;
    TreeViewItemComponent* PalmMute;

    TreeViewItemComponent* arpeggio;
    TreeViewItemComponent* up_arpeggio;
    TreeViewItemComponent* down_arpeggio;
    TreeViewItemComponent* bracket_arpeggio;
    TreeViewItemComponent* up_arpeggio_straight;
    TreeViewItemComponent* down_arpeggio_straight;
    TreeViewItemComponent* straight_glissando;
    TreeViewItemComponent* wavy_glissando;
    TreeViewItemComponent* fall;
    TreeViewItemComponent* Doit;
    TreeViewItemComponent* Plop;
    TreeViewItemComponent* Scoop;
    TreeViewItemComponent* slide_out_down;
    TreeViewItemComponent* slide_out_up;
    TreeViewItemComponent* slide_in_above;
    TreeViewItemComponent* slide_in_below;

    TreeViewItemComponent* BreatheMarkComma;
    TreeViewItemComponent* BreatheMarkTick;
    TreeViewItemComponent* BreatheMarkSalzedo;
    TreeViewItemComponent* BreatheMarkUpBowLike;
    TreeViewItemComponent* CurvedCaesura;
    TreeViewItemComponent* Caesura;
    TreeViewItemComponent* ShortCaesura;
    TreeViewItemComponent* ThickCaesura;
 //   TreeViewItemComponent* Caesura;

    TreeViewItemComponent* Bracket;
    TreeViewItemComponent* Brace;
    TreeViewItemComponent* Square;
    TreeViewItemComponent* BracketsLine;

    TreeViewItemComponent* Staccato;
    TreeViewItemComponent* Accent;
    TreeViewItemComponent* Tenuto;
    TreeViewItemComponent* Marcato;
 //   TreeViewItemComponent* Slur;
    TreeViewItemComponent* ShortFermataAbove;
    TreeViewItemComponent* LongFermataAbove;
    TreeViewItemComponent* LongFermataAboveHenze;
 //   TreeViewItemComponent* ShortFermataAbove;
    TreeViewItemComponent* ShortFermataAboveHenze;
    TreeViewItemComponent* VeryLongFermataAbove;
    TreeViewItemComponent* VeryShortFermataAbove;
    TreeViewItemComponent* StaccatissimoAbove;
    TreeViewItemComponent* AccentStaccatoAbove;
    TreeViewItemComponent* AccentStaccato;
    TreeViewItemComponent* LaissezViber;
    TreeViewItemComponent* MarcatoStaccatoAbove;
    TreeViewItemComponent* MarcatoTenutoAbove;
    TreeViewItemComponent* StaccatissimoStrokeAbove;
    TreeViewItemComponent* StaccatissimoWedgeAbove;
    TreeViewItemComponent* StressAbove;
    TreeViewItemComponent* Harmonic;
    TreeViewItemComponent* TremoloBar;
    TreeViewItemComponent* TenutoAccentAbove;
    TreeViewItemComponent* UnstressAbove;
    TreeViewItemComponent* SoftAccentAbove;
    TreeViewItemComponent* SoftAccentStaccato;
    TreeViewItemComponent* SoftAccentTenutoAbove;
    TreeViewItemComponent* FadeIn;
    TreeViewItemComponent* FadeOut;
    TreeViewItemComponent* VolumeSwell;
    TreeViewItemComponent* SawtoothLineSegment;
    TreeViewItemComponent* WideSawToothLineSegment;
    TreeViewItemComponent* VibratoLargeFaster;
    TreeViewItemComponent* VibratoLargeSlower;
    TreeViewItemComponent* Open;
    TreeViewItemComponent* Muted;
    TreeViewItemComponent* DownBow;
    TreeViewItemComponent* SwapPizzicatoAbove;
    TreeViewItemComponent* UpBow;
    TreeViewItemComponent* Bend;
 //   TreeViewItemComponent* Tempo;
    TreeViewItemComponent* StaffText;
    TreeViewItemComponent* StaffType;
    TreeViewItemComponent* RehearsalMark;
    TreeViewItemComponent* SwingSystem;
    TreeViewItemComponent* Pizzicato;
    TreeViewItemComponent* Arco;
    TreeViewItemComponent* Mute;
    TreeViewItemComponent* Straight;
    TreeViewItemComponent* MeasureNumber;
    TreeViewItemComponent* Tremolo;

    TreeViewItemComponent* pppppp;
    TreeViewItemComponent* ppppp;
    TreeViewItemComponent* pppp;
    TreeViewItemComponent* ppp;
    TreeViewItemComponent* pp;
    TreeViewItemComponent* P;
    TreeViewItemComponent* mp;
    TreeViewItemComponent* mf;
    TreeViewItemComponent* F;
    TreeViewItemComponent* ff;
    TreeViewItemComponent* fff;
    TreeViewItemComponent* ffff;
    TreeViewItemComponent* fffff;
    TreeViewItemComponent* ffffff;
    TreeViewItemComponent* fp;
    TreeViewItemComponent* pf;
    TreeViewItemComponent* sf;
    TreeViewItemComponent* sfz;
    TreeViewItemComponent* sff;
    TreeViewItemComponent* sffz;
    TreeViewItemComponent* sfp;
    TreeViewItemComponent* sfpp;
    TreeViewItemComponent* rfz;
    TreeViewItemComponent* rf;
    TreeViewItemComponent* fz;
    TreeViewItemComponent* m;
    TreeViewItemComponent* r;
    TreeViewItemComponent* s;
    TreeViewItemComponent* z;
    TreeViewItemComponent* n;

    TreeViewItemComponent* RepeatLastBar;
    TreeViewItemComponent* Segno;
    TreeViewItemComponent* Coda;
    TreeViewItemComponent* Fine;
    TreeViewItemComponent* ToCoda;
    TreeViewItemComponent* DaCapo;
    TreeViewItemComponent* DaCapoAlFine;
    TreeViewItemComponent* DSAlFine;
    TreeViewItemComponent* DS;
    TreeViewItemComponent* LeftStartRepeatSign;
    TreeViewItemComponent* RightEnd;
    TreeViewItemComponent* LeftAndRightRepeat;
    TreeViewItemComponent* SegnoVariation;
    TreeViewItemComponent* VariedCoda;
  //  TreeViewItemComponent* ToCoda;

    TreeViewItemComponent* SystemBreak;
    TreeViewItemComponent* PageBreak;
    TreeViewItemComponent* SectionBreak;
    TreeViewItemComponent* StaffSpacerDown;
    TreeViewItemComponent* StaffSpacerUp;
    TreeViewItemComponent* StaffSpacerFixedDown;

    TextButton button1{ "File" };
    TextButton button2{ "Edit" };
    TextButton button3{ "View" };
    TextButton button4{ "Add" };

    TextButton button5{ "1/32" };
    TextButton button6{ "1/16" };
    TextButton button7{ "1/8" };
    TextButton button8{ "1/4" };
    TextButton button9{ "1/2" };

    TextButton button10{ "Format" };
    TextButton button11{ "Tools" };
    TextButton button12{ "Plugins" };
    TextButton button13{ "Help" };
    TextButton button14{ "Options" };

    TextButton button15{ "Repeat" };
    TextButton button16{ "Metronome" };
    TextButton button17{ "MIDI" };
    TextButton button18{ "Save" };
    TextButton button19{ "Print" };
    TextButton button20{ "20" };

    TextButton play_Button { "Play" };

    TextEditor title{ "Title" };
    TextEditor author{ "Author" };

   
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetMusicAudioProcessorEditor)
};
