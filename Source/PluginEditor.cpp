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
    breaks_spacer(new TreeViewItemComponent("Breaks/Spaces")),
    AccidentalSharps(new TreeViewItemComponent("Sharps")),
    AccidentalFlats(new TreeViewItemComponent("Flats")),
    KeySigFlats(new TreeViewItemComponent("Flats")),
    KeySigSharps(new TreeViewItemComponent("Sharps")),
    MajorSharps(new TreeViewItemComponent("MajorSharps")),
    MinorSharps(new TreeViewItemComponent("MinorSharps")),
    MajorFlats(new TreeViewItemComponent("MajorFlats")),
    MinorFlats(new TreeViewItemComponent("MinorFlats")),
    Naturals(new TreeViewItemComponent("Naturals")),
    Acciacuta(new TreeViewItemComponent("Acciacuta")),
    Appogiatura(new TreeViewItemComponent("Appogiatura")),
    GraceSixteenth(new TreeViewItemComponent("GraceSixteenth")),
    GraceQuarter(new TreeViewItemComponent("GraceQuarter")),
    GraceThirtySecond(new TreeViewItemComponent("GraceThirtySecond")),
    Major(new TreeViewItemComponent("Major")),
    DMajor(new TreeViewItemComponent("DMajor")),
    GMajor(new TreeViewItemComponent("GMajor")),
    AMajor(new TreeViewItemComponent("AMajor")),
    EMajor(new TreeViewItemComponent("EMajor")),
    BMajor(new TreeViewItemComponent("BMajor")),
    FSharpMajor(new TreeViewItemComponent("FSharpMajor")),
    CSharpMajor(new TreeViewItemComponent("CSharpMajor")),
    AMinorInSharp(new TreeViewItemComponent("AMinor")),
    AMinorInFlat(new TreeViewItemComponent("AMinor")),
    EMinor(new TreeViewItemComponent("EMinor")),
    BMinor(new TreeViewItemComponent("BMinor")),
    FSharpMinor(new TreeViewItemComponent("FSharpMinor")),
    CSharpMinor(new TreeViewItemComponent("CSharpMinor")),
    GSharpMinor(new TreeViewItemComponent("GSharpMinor")),
    DSharpMinor(new TreeViewItemComponent("DSharpMinor")),
    ASharpMinor(new TreeViewItemComponent("ASharpMinor")),
    CMajorInFlat(new TreeViewItemComponent("CMajorInFlat")),
    CMajorInSharp(new TreeViewItemComponent("CMajorInSharp")),
    BFlatMajor(new TreeViewItemComponent("BFlatMajor")),
    EFlatMajor(new TreeViewItemComponent("EFlatMajor")),
    AFlatMajor(new TreeViewItemComponent("AFlatMajor")),
    DFlatMajor(new TreeViewItemComponent("DFlatMajor")),
    GFlatMajor(new TreeViewItemComponent("GFlatMajor")),
    CFlatMajor(new TreeViewItemComponent("CFlatMajor")),
    Minor(new TreeViewItemComponent("Minor")),
    DMinor(new TreeViewItemComponent("DMinor")),
    GMinor(new TreeViewItemComponent("GMinor")),
    CMinor(new TreeViewItemComponent("CMinor")),
    FMinor(new TreeViewItemComponent("FMinor")),
    BFlatMinor(new TreeViewItemComponent("BFlatMinor")),
    EFlatMinor(new TreeViewItemComponent("EFlatMinor")),
    AFlatMinor(new TreeViewItemComponent("AFlatMinor")),
    TwoFour(new TreeViewItemComponent("TwoFour")),
    ThreeFour(new TreeViewItemComponent("ThreeFour")),
    FourFour(new TreeViewItemComponent("FourFour")),
    FiveFour(new TreeViewItemComponent("FiveFour")),
    SixFour(new TreeViewItemComponent("SixFour")),
    ThreeEight(new TreeViewItemComponent("ThreeEight")),
    SixEight(new TreeViewItemComponent("SixEight")),
    NineEight(new TreeViewItemComponent("NineEight")),
    TwelveEight(new TreeViewItemComponent("TwelveEight")),
    CommonTime(new TreeViewItemComponent("CommonTime")),
    CutTime(new TreeViewItemComponent("CutTime")),
    SingleLine(new TreeViewItemComponent("SingleLine")),
    DoubleLine(new TreeViewItemComponent("DoubleLine")),
    RepeatSign(new TreeViewItemComponent("RepeatSign")),
    RightEndRepeatSign(new TreeViewItemComponent("RightEndRepeatSign")),
    RightAndLeft(new TreeViewItemComponent("RightAndLeft")),
    Dashed(new TreeViewItemComponent("Dashed")),
    FinalBarLine(new TreeViewItemComponent("FinalBarLine")),
    DottedBarLine(new TreeViewItemComponent("DottedBarLine")),
    ReverseFinalBarline(new TreeViewItemComponent("ReverseFinalBarline")),
    HeavyBarLine(new TreeViewItemComponent("HeavyBarLine")),
    DashedBarLine(new TreeViewItemComponent("DashedBarLine")),
    TickedBarline(new TreeViewItemComponent("TickedBarLine")),
    ShortBarline(new TreeViewItemComponent("ShortBarLine")),
    ShortBarlineTwo(new TreeViewItemComponent("ShortBarLineTwo")),
    Slur(new TreeViewItemComponent("Slur")),
    Crescendo(new TreeViewItemComponent("Crescendo")),
    Diminuendo(new TreeViewItemComponent("Diminuendo")),
    CrescendoLine(new TreeViewItemComponent("CrescendoLine")),
    DiminuendoLine(new TreeViewItemComponent("DiminuendoLine")),
    PrimaVolta(new TreeViewItemComponent("PrimaVolta")),
    SecondVolta(new TreeViewItemComponent("Second Volta")),
    SecondVoltaOpen(new TreeViewItemComponent("SecondVoltaOpen")),
    EighthVoltaAlta(new TreeViewItemComponent("Eighth Volta Alta")),
    EighthVoltaBassa(new TreeViewItemComponent("Eight Volta Bassa")),
    Pedal(new TreeViewItemComponent("Pedal")),
    PedalAngled(new TreeViewItemComponent("PedalAngled")),
    PedalBothAngled(new TreeViewItemComponent("PedalBothAngled")),
    PedalAngledStartHook(new TreeViewItemComponent("PedalAngledStartHook")),
    SystemTextLine(new TreeViewItemComponent("SystemTextLine")),
    Line(new TreeViewItemComponent("Line")),
    Ambitus(new TreeViewItemComponent("Ambitus")),
    LetRing(new TreeViewItemComponent("LetRing")),
    MFDynamicHairpin(new TreeViewItemComponent("MFDynamicHairpin")),
    TerzaVolta(new TreeViewItemComponent("TerzaVolta")),
    FifteenAlta(new TreeViewItemComponent("FifteenAlta")),
    FifteenBassa(new TreeViewItemComponent("FifteenBassa")),
    TwentyTwoMAAbove(new TreeViewItemComponent("TwentyTwoMAAbove")),
    PedalwithLine(new TreeViewItemComponent("PedalwithLine")),
    PedalWithAsterik(new TreeViewItemComponent("PedalWithAsterik")),
    Trill(new TreeViewItemComponent("Trill")),
    Uprall(new TreeViewItemComponent("Uprall")),
    Downprall(new TreeViewItemComponent("Downprall")),
    PrallprallLine(new TreeViewItemComponent("PrallprallLine")),
    StaffTextLine(new TreeViewItemComponent("StaffTextLine")),
    GuitarVibrato(new TreeViewItemComponent("GuitarVibrato")),
    GuitarVibratoWide(new TreeViewItemComponent("GuitarVibratoWide")),
    VibratoSawtooth(new TreeViewItemComponent("VibratoSawTooh")),
    TremoloSawtoothWide(new TreeViewItemComponent("TremoloSawtoothWide")),
    PalmMute(new TreeViewItemComponent("PalmMute")),
    arpeggio(new TreeViewItemComponent("arpeggio")),
    up_arpeggio(new TreeViewItemComponent("up_arpeggio")),
    down_arpeggio(new TreeViewItemComponent("down_arpeggio")),
    bracket_arpeggio(new TreeViewItemComponent("bracket_arpeggio")),
    up_arpeggio_straight(new TreeViewItemComponent("up_arpeggio_straight")),
    down_arpeggio_straight(new TreeViewItemComponent("down_arpeggio_straight")),
    straight_glissando(new TreeViewItemComponent("straight_glissando")),
    wavy_glissando(new TreeViewItemComponent("wavy_glissando")),
    fall(new TreeViewItemComponent("fall")),
    Doit(new TreeViewItemComponent("Doit")),
    Plop(new TreeViewItemComponent("Plop")),
    Scoop(new TreeViewItemComponent("Scoop")),
    slide_out_down(new TreeViewItemComponent("slide_out_down")),
    slide_out_up(new TreeViewItemComponent("slide_out_up")),
    slide_in_above(new TreeViewItemComponent("slide_in_above")),
    slide_in_below(new TreeViewItemComponent("slide_in_below")),
    BreatheMarkComma(new TreeViewItemComponent("BreatheMarkComma")),
    BreatheMarkTick(new TreeViewItemComponent("BreatheMarkTick")),
    BreatheMarkSalzedo(new TreeViewItemComponent("BreatheMarkSalzedo")),
    BreatheMarkUpBowLike(new TreeViewItemComponent("BreatheMarkUpBowLike")),
    CurvedCaesura(new TreeViewItemComponent("CurvedCaesura")),
    Caesura(new TreeViewItemComponent("Caesura")),
    ShortCaesura(new TreeViewItemComponent("ShortCaesura")),
    ThickCaesura(new TreeViewItemComponent("ThickCaesura")),
   // Caesura(new TreeViewItemComponent("Caesura")),
    Bracket(new TreeViewItemComponent("Bracket")),
    Brace(new TreeViewItemComponent("Brace")),
    Square(new TreeViewItemComponent("Square")),
    //Line(new TreeViewItemComponent("Line")),
    Staccato(new TreeViewItemComponent("Staccato")),
    Accent(new TreeViewItemComponent("Accent")),
    Tenuto(new TreeViewItemComponent("Tenuto")),
    Marcato(new TreeViewItemComponent("Marcato")),
    //Slur(new TreeViewItemComponent("Slur")),
    LongFermataAbove(new TreeViewItemComponent("LongFermataAbove")),
    LongFermataAboveHenze(new TreeViewItemComponent("LongFermataAboveHenze")),
    ShortFermataAbove(new TreeViewItemComponent("ShortFermataAbove")),
    ShortFermataAboveHenze(new TreeViewItemComponent("ShortFermataAboveHenze")),
    VeryLongFermataAbove(new TreeViewItemComponent("VeryLongFermataAbove")),
    VeryShortFermataAbove(new TreeViewItemComponent("VeryShortFermataAbove")),
    //LongFermataAboveHenze(new TreeViewItemComponent("VeryLongFermataAboveHenze")),
    StaccatissimoAbove(new TreeViewItemComponent("StaccatissimoAbove")),
    AccentStaccatoAbove(new TreeViewItemComponent("AccentStaccatoAbove")),
    AccentStaccato(new TreeViewItemComponent("AccentStaccato")),
    LaissezViber(new TreeViewItemComponent("LaissezViber")),
    MarcatoStaccatoAbove(new TreeViewItemComponent("MarcatoStaccatoAbove")),
    MarcatoTenutoAbove(new TreeViewItemComponent("MarcatoTenutoAbove")),
    StaccatissimoStrokeAbove(new TreeViewItemComponent("StaccatissimoStrokeAbove")),
    StaccatissimoWedgeAbove(new TreeViewItemComponent("StaccatissimoWedgeAbove")),
    StressAbove(new TreeViewItemComponent("StressAbove")),
    Harmonic(new TreeViewItemComponent("Harmonic")),
    TremoloBar(new TreeViewItemComponent("Tremolobar")),
    TenutoAccentAbove(new TreeViewItemComponent("TenutoAccentAbove")),
    UnstressAbove(new TreeViewItemComponent("UnstressAbove")),
    SoftAccentAbove(new TreeViewItemComponent("SoftAccentAbove")),
    //Harmonic(new TreeViewItemComponent("Harmonic")),
   // TremoloBar(new TreeViewItemComponent("TremoloBar")),
    //TenutoAccentAbove(new TreeViewItemComponent("TenutoAccentAbove")),
    //UnstressAbove(new TreeViewItemComponent("UnstressAbove")),
    //SoftAccentAbove(new TreeViewItemComponent("SoftAccentAbove")),
    SoftAccentStaccato(new TreeViewItemComponent("SoftAccentStaccato")),
    SoftAccentTenutoAbove(new TreeViewItemComponent("SoftAccentTenutoAbove")),
    FadeIn(new TreeViewItemComponent("FadeIn")),
    FadeOut(new TreeViewItemComponent("FadeOut")),
    VolumeSwell(new TreeViewItemComponent("VolumeSwell")),
    SawtoothLineSegment(new TreeViewItemComponent("SawToothLineSegment")),
    WideSawToothLineSegment(new TreeViewItemComponent("WideSawToothLineSegment")),
    VibratoLargeFaster(new TreeViewItemComponent("VibratoLargeFaster")),
    Open(new TreeViewItemComponent("Open")),
    Muted(new TreeViewItemComponent("Muted")),
    DownBow(new TreeViewItemComponent("DownBow")),
    SwapPizzicatoAbove(new TreeViewItemComponent("SwapPizzicatoAbove")),
    UpBow(new TreeViewItemComponent("UpBow")),
    Bend(new TreeViewItemComponent("Bend")),
    //Tempo(new TreeViewItemComponent("Tempo")),
    StaffText(new TreeViewItemComponent("StaffText")),
    StaffType(new TreeViewItemComponent("StaffType")),
    RehearsalMark(new TreeViewItemComponent("RehearsalMark")),
    SwingSystem(new TreeViewItemComponent("SwingSystem")),
    Pizzicato(new TreeViewItemComponent("Pizzicato")),
    Arco(new TreeViewItemComponent("Arco")),
    Mute(new TreeViewItemComponent("Mute")),
    Straight(new TreeViewItemComponent("Straight")),
    //Mute(new TreeViewItemComponent("Mute")),
    MeasureNumber(new TreeViewItemComponent("MeasureNumber")),
    Tremolo(new TreeViewItemComponent("Tremolo")),
    pppppp(new TreeViewItemComponent("pppppp")),
    ppppp(new TreeViewItemComponent("ppppp")),
    pppp(new TreeViewItemComponent("pppp")),
    ppp(new TreeViewItemComponent("ppp")),
    pp(new TreeViewItemComponent("pp")),
    P(new TreeViewItemComponent("p")),
    mp(new TreeViewItemComponent("mp")),
    mf(new TreeViewItemComponent("mf")),
    F(new TreeViewItemComponent("F")),
    ff(new TreeViewItemComponent("ff")),
    fff(new TreeViewItemComponent("fff")),
    ffff(new TreeViewItemComponent("ffff")),
    fffff(new TreeViewItemComponent("fffff")),
    ffffff(new TreeViewItemComponent("ffffff")),
    fp(new TreeViewItemComponent("fp")),
    pf(new TreeViewItemComponent("pf")),
    sf(new TreeViewItemComponent("sf")),
    sfz(new TreeViewItemComponent("sfz")),
    sff(new TreeViewItemComponent("sff")),
    sffz(new TreeViewItemComponent("sffz")),
    sfp(new TreeViewItemComponent("sfp")),
    sfpp(new TreeViewItemComponent("sfpp")),
    rfz(new TreeViewItemComponent("rfz")),
    rf(new TreeViewItemComponent("rf")),
    fz(new TreeViewItemComponent("fz")),
    m(new TreeViewItemComponent("m")),
    r(new TreeViewItemComponent("r")),
    s(new TreeViewItemComponent("s")),
    z(new TreeViewItemComponent("z")),
    n(new TreeViewItemComponent("n")),
    RepeatLastBar(new TreeViewItemComponent("RepeatLastBar")),
    Segno(new TreeViewItemComponent("Segno")),
    Coda(new TreeViewItemComponent("Coda")),
    Fine(new TreeViewItemComponent("Fine")),
    ToCoda(new TreeViewItemComponent("ToCoda")),
    DaCapo(new TreeViewItemComponent("DaCapo")),
    DaCapoAlFine(new TreeViewItemComponent("DaCapoAlFine")),
    DSAlFine(new TreeViewItemComponent("DSAlFine")),
    DS(new TreeViewItemComponent("DS")),
    LeftStartRepeatSign(new TreeViewItemComponent("LeftStartRepeatSign")),
    RightEnd(new TreeViewItemComponent("RightEnd")),
    LeftAndRightRepeat(new TreeViewItemComponent("LeftAndRightRepeat")),
    //RightEndRepeatSign(new TreeViewItemComponent("RightEndRepeatSign")),
    //LeftAndRightRepeat(new TreeViewItemComponent("LeftAndRightRepeat")),
    SegnoVariation(new TreeViewItemComponent("S")),
    VariedCoda(new TreeViewItemComponent("VariedCoda")),
    //ToCoda(new TreeViewItemComponent("ToCoda")),
    SystemBreak(new TreeViewItemComponent("SystemBreak")),
    PageBreak(new TreeViewItemComponent("PageBreak")),
    SectionBreak(new TreeViewItemComponent("SectionBreak")),
    StaffSpacerDown(new TreeViewItemComponent("StaffSpacerUpDown")),
    StaffSpacerUp(new TreeViewItemComponent("StaffSpacerUp")),
    StaffSpacerFixedDown(new TreeViewItemComponent("StaffSpacerFixedDown")),
    LinesLine(new TreeViewItemComponent("Line")),
    BracketsLine(new TreeViewItemComponent("Line"))
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
    tree.setDefaultOpenness(false);
    tree.setOpenCloseButtonsVisible(true);
    
    author.setColour(TextEditor::ColourIds::backgroundColourId, Colours::white);
    author.setColour(TextEditor::ColourIds::textColourId, Colours::black);
    addAndMakeVisible(author);
    
    addAndMakeVisible(tree);
    tree.setColour(TreeView::ColourIds::backgroundColourId, Colours::grey);

    play_Button.setColour(TextButton::ColourIds::buttonOnColourId, Colours::green);
    play_Button.setColour(TextButton::ColourIds::buttonColourId, Colours::red);
    play_Button.setToggleState(true, NotificationType::dontSendNotification);

    play_Button.onClick = [this]() {
        playButtonPushed();
    };

    root->addSubItem(Cleffs);
    Cleffs->addSubItem(treble_Cleff);
    Cleffs->addSubItem(bass_Cleff);

    root->addSubItem(Notes);

    root->addSubItem(Accidentals);
    Accidentals->addSubItem(AccidentalSharps);
    Accidentals->addSubItem(AccidentalFlats);
    Accidentals->addSubItem(Naturals);

    root->addSubItem(Grace_Notes);
    Grace_Notes->addSubItem(Acciacuta);
    Grace_Notes->addSubItem(Appogiatura);
    Grace_Notes->addSubItem(GraceQuarter);
    Grace_Notes->addSubItem(GraceSixteenth);
    Grace_Notes->addSubItem(GraceThirtySecond);
    //Grace_Notes->addSubItem(GraceSixteenth);

    root->addSubItem(key_Signatures);

    key_Signatures->addSubItem(KeySigSharps);
    key_Signatures->addSubItem(KeySigFlats);

    KeySigSharps->addSubItem(MajorSharps);
    MajorSharps->addSubItem(CMajorInSharp);
  //Major->addSubItem(Gmajor);
    MajorSharps->addSubItem(DMajor);
    MajorSharps->addSubItem(AMajor);
    MajorSharps->addSubItem(EMajor);
    MajorSharps->addSubItem(BMajor);
    MajorSharps->addSubItem(FSharpMajor);
    MajorSharps->addSubItem(CSharpMajor);
  
    KeySigSharps->addSubItem(MinorSharps);
    MinorSharps->addSubItem(AMinorInSharp);
    MinorSharps->addSubItem(EMinor);
    MinorSharps->addSubItem(BMinor);
    MinorSharps->addSubItem(FSharpMinor);
    MinorSharps->addSubItem(CSharpMinor);
    MinorSharps->addSubItem(GSharpMinor);
    MinorSharps->addSubItem(DSharpMinor);
    MinorSharps->addSubItem(ASharpMinor);

    KeySigFlats->addSubItem(MajorFlats);
    MajorFlats->addSubItem(CMajorInFlat);
    MajorFlats->addSubItem(BFlatMajor);
    MajorFlats->addSubItem(EFlatMajor);
    MajorFlats->addSubItem(AFlatMajor);
    MajorFlats->addSubItem(DFlatMajor);
    MajorFlats->addSubItem(GFlatMajor);
    MajorFlats->addSubItem(CFlatMajor);

    KeySigFlats->addSubItem(MinorFlats);
    MinorFlats->addSubItem(AMinorInFlat);
    MinorFlats->addSubItem(DMinor);
    MinorFlats->addSubItem(GMinor);
    MinorFlats->addSubItem(CMinor);
    MinorFlats->addSubItem(FMinor);
    MinorFlats->addSubItem(BFlatMinor);
    MinorFlats->addSubItem(EFlatMinor);
    MinorFlats->addSubItem(AFlatMinor);

    root->addSubItem(time_Signatures);
    time_Signatures->addSubItem(TwoFour);
    time_Signatures->addSubItem(ThreeFour);
    time_Signatures->addSubItem(FourFour);
    time_Signatures->addSubItem(FiveFour);
    time_Signatures->addSubItem(SixFour);
    time_Signatures->addSubItem(ThreeEight);
    time_Signatures->addSubItem(SixEight);
    time_Signatures->addSubItem(NineEight);
    time_Signatures->addSubItem(TwelveEight);
    time_Signatures->addSubItem(CommonTime);
    time_Signatures->addSubItem(CutTime);
    
    root->addSubItem(Barlines);
    Barlines->addSubItem(SingleLine);
    Barlines->addSubItem(DoubleLine);
    Barlines->addSubItem(RepeatSign);
    Barlines->addSubItem(RightEndRepeatSign);
    Barlines->addSubItem(RightAndLeft);
    Barlines->addSubItem(Dashed);
    Barlines->addSubItem(FinalBarLine);
    Barlines->addSubItem(DottedBarLine);
  //Barlines->addSubItem(ReverseFinalBarLine);
    Barlines->addSubItem(HeavyBarLine);
    Barlines->addSubItem(DashedBarLine);
 // Barlines->addSubItem(TickedBarLine);
 // Barlines->addSubItem(ShortBarLine);
 // Barlines->addSubItem(ShortBarLineTwo);

    
//===============================================================================
//  Improper declarations causing nullptr exceptions
//===============================================================================

    root->addSubItem(Lines);
    Lines->addSubItem(Slur);
    Lines->addSubItem(Crescendo);
    Lines->addSubItem(Diminuendo);
    Lines->addSubItem(CrescendoLine);
    Lines->addSubItem(DiminuendoLine);
    Lines->addSubItem(PrimaVolta);
    Lines->addSubItem(SecondVolta);
    Lines->addSubItem(SecondVoltaOpen);
    Lines->addSubItem(EighthVoltaAlta);
    Lines->addSubItem(EighthVoltaBassa);
    Lines->addSubItem(Pedal);
    Lines->addSubItem(PedalAngled);
    Lines->addSubItem(PedalBothAngled);
    Lines->addSubItem(PedalAngledStartHook);
    Lines->addSubItem(SystemTextLine);
    Lines->addSubItem(LinesLine);
    Lines->addSubItem(Ambitus);
    Lines->addSubItem(LetRing);
    Lines->addSubItem(MFDynamicHairpin);
    Lines->addSubItem(TerzaVolta);

 //   Lines->addSubItem(FifteenmaAlta);
 //   Lines->addSubItem(fifteenmaBassa);
 //   Lines->addSubItem(TwentytwoMAAbove);
 //   Lines->addSubItem(TwentyTwoMABelow);
 //   Lines->addSubItem(PedalWithLine);

    Lines->addSubItem(PedalWithAsterik);
    Lines->addSubItem(Trill);
    Lines->addSubItem(Uprall);
    Lines->addSubItem(Downprall);
    Lines->addSubItem(PrallprallLine);
    Lines->addSubItem(StaffTextLine);
    Lines->addSubItem(GuitarVibrato);
    Lines->addSubItem(GuitarVibratoWide);
    Lines->addSubItem(VibratoSawtooth);
    Lines->addSubItem(TremoloSawtoothWide);
    Lines->addSubItem(PalmMute);

    root->addSubItem(arpeggios_glissandos);
    arpeggios_glissandos->addSubItem(arpeggio);
    arpeggios_glissandos->addSubItem(up_arpeggio);
    arpeggios_glissandos->addSubItem(down_arpeggio);
    arpeggios_glissandos->addSubItem(bracket_arpeggio);
    arpeggios_glissandos->addSubItem(up_arpeggio_straight);
    arpeggios_glissandos->addSubItem(down_arpeggio_straight);
    arpeggios_glissandos->addSubItem(straight_glissando);
    arpeggios_glissandos->addSubItem(wavy_glissando);
    arpeggios_glissandos->addSubItem(fall);
    arpeggios_glissandos->addSubItem(Doit);
    arpeggios_glissandos->addSubItem(Plop);
//  arpeggios_glissandos->addSubItem(scoop);
    arpeggios_glissandos->addSubItem(slide_out_down);
    arpeggios_glissandos->addSubItem(slide_out_up);
    arpeggios_glissandos->addSubItem(slide_in_above);
    arpeggios_glissandos->addSubItem(slide_in_below);
  
    root->addSubItem(breathes_pauses);
    breathes_pauses->addSubItem(BreatheMarkComma);
    breathes_pauses->addSubItem(BreatheMarkTick);
    breathes_pauses->addSubItem(BreatheMarkSalzedo);
    breathes_pauses->addSubItem(BreatheMarkUpBowLike);
    breathes_pauses->addSubItem(CurvedCaesura);
    breathes_pauses->addSubItem(Caesura);
    breathes_pauses->addSubItem(ShortCaesura);
    breathes_pauses->addSubItem(ThickCaesura);
  //  breathes_pauses->addSubItem(Caesura);

    root->addSubItem(brackets);
    brackets->addSubItem(Bracket);
    brackets->addSubItem(Brace);
    brackets->addSubItem(Square);
    brackets->addSubItem(BracketsLine);
 
    root->addSubItem(articulations_Ornaments);
    articulations_Ornaments->addSubItem(Staccato);
    articulations_Ornaments->addSubItem(Accent);
    articulations_Ornaments->addSubItem(Tenuto);
    articulations_Ornaments->addSubItem(Marcato);
  //  articulations_Ornaments->addSubItem(Slur);
    articulations_Ornaments->addSubItem(ShortFermataAbove);
    articulations_Ornaments->addSubItem(LongFermataAbove);
    articulations_Ornaments->addSubItem(LongFermataAboveHenze);
 //   articulations_Ornaments->addSubItem(ShortFermataAbove);
    articulations_Ornaments->addSubItem(ShortFermataAboveHenze);
    articulations_Ornaments->addSubItem(VeryLongFermataAbove);
    articulations_Ornaments->addSubItem(VeryShortFermataAbove);
//    articulations_Ornaments->addSubItem(StaccatisimoAbove);
    articulations_Ornaments->addSubItem(AccentStaccatoAbove);
    articulations_Ornaments->addSubItem(AccentStaccato);
    articulations_Ornaments->addSubItem(LaissezViber);
    articulations_Ornaments->addSubItem(MarcatoStaccatoAbove);
    articulations_Ornaments->addSubItem(MarcatoTenutoAbove);
    articulations_Ornaments->addSubItem(StaccatissimoStrokeAbove);
//    articulations_Ornmanets->addSubItem(StaccatissimoWedgeAbove);
    articulations_Ornaments->addSubItem(StressAbove);
    articulations_Ornaments->addSubItem(Harmonic);
    articulations_Ornaments->addSubItem(TremoloBar);
    articulations_Ornaments->addSubItem(TenutoAccentAbove);
    articulations_Ornaments->addSubItem(UnstressAbove);
    articulations_Ornaments->addSubItem(SoftAccentAbove);
    articulations_Ornaments->addSubItem(SoftAccentStaccato);
    articulations_Ornaments->addSubItem(SoftAccentTenutoAbove);
//    articulations_Ornaments->addSubItem(SoftAccentTenutoStaccato);
    articulations_Ornaments->addSubItem(FadeIn);
    articulations_Ornaments->addSubItem(FadeOut);
    articulations_Ornaments->addSubItem(VolumeSwell);
    articulations_Ornaments->addSubItem(SawtoothLineSegment);
//    articulations_Ornaments->addSubItem(WideSawtoothLineSegment);
    articulations_Ornaments->addSubItem(VibratoLargeFaster);
//    articulations_Ornaments->addSubItem(VibratoLargeSlower);
    articulations_Ornaments->addSubItem(Open);
    articulations_Ornaments->addSubItem(Muted);
    articulations_Ornaments->addSubItem(DownBow);
    articulations_Ornaments->addSubItem(SwapPizzicatoAbove);
    articulations_Ornaments->addSubItem(UpBow);
    articulations_Ornaments->addSubItem(Bend);


   
    root->addSubItem(Tempo);
    Tempo->addSubItem(StaffText);
    Tempo->addSubItem(StaffType);
    Tempo->addSubItem(RehearsalMark);
    Tempo->addSubItem(SwingSystem);
    Tempo->addSubItem(Pizzicato);
    Tempo->addSubItem(Arco);
    Tempo->addSubItem(Mute);
    Tempo->addSubItem(Straight);
    Tempo->addSubItem(MeasureNumber);
    Tempo->addSubItem(Tremolo);

    root->addSubItem(dynamics);
    dynamics->addSubItem(pppppp);
    dynamics->addSubItem(ppppp);
    dynamics->addSubItem(pppp);
    dynamics->addSubItem(ppp);
    dynamics->addSubItem(pp);
    dynamics->addSubItem(P);
    dynamics->addSubItem(mp);
    dynamics->addSubItem(mf);
    dynamics->addSubItem(F);
    dynamics->addSubItem(ff);
    dynamics->addSubItem(fff);
    dynamics->addSubItem(ffff);
    dynamics->addSubItem(fffff);
    dynamics->addSubItem(ffffff);
    dynamics->addSubItem(fp);
    dynamics->addSubItem(pf);
    dynamics->addSubItem(sf);
    dynamics->addSubItem(sfz);
    dynamics->addSubItem(sff);
    dynamics->addSubItem(sffz);
    dynamics->addSubItem(sfp);
    dynamics->addSubItem(sfpp);
    dynamics->addSubItem(rfz);
    dynamics->addSubItem(rf);
    dynamics->addSubItem(fz);
    dynamics->addSubItem(m);
    dynamics->addSubItem(r);
    dynamics->addSubItem(s);
    dynamics->addSubItem(z);
    dynamics->addSubItem(n);

   
    root->addSubItem(repeats_jumps);
    repeats_jumps->addSubItem(RepeatLastBar);
    repeats_jumps->addSubItem(Segno);
    repeats_jumps->addSubItem(Coda);
    repeats_jumps->addSubItem(Fine);
    repeats_jumps->addSubItem(ToCoda);
    repeats_jumps->addSubItem(DaCapo);
    repeats_jumps->addSubItem(DaCapoAlFine);
    repeats_jumps->addSubItem(DSAlFine);
    repeats_jumps->addSubItem(DS);
    repeats_jumps->addSubItem(LeftStartRepeatSign);
    repeats_jumps->addSubItem(RightEnd);
    repeats_jumps->addSubItem(LeftAndRightRepeat);
    repeats_jumps->addSubItem(SegnoVariation);
    repeats_jumps->addSubItem(VariedCoda);
//    repeats_jumps->addSubItem(ToCoda);

    
    root->addSubItem(breaks_spacer);
    breaks_spacer->addSubItem(SystemBreak);
    breaks_spacer->addSubItem(PageBreak);
    breaks_spacer->addSubItem(SectionBreak);
    breaks_spacer->addSubItem(StaffSpacerDown);
    breaks_spacer->addSubItem(StaffSpacerUp);
    breaks_spacer->addSubItem(StaffSpacerFixedDown);

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

    button4.onClick = [this]()
    {
        sheet.addBeat();
    };
    button5.onClick = [this]()
    {
        audioProcessor.loadFile();
    };

    startTimer(42);

    addAndMakeVisible(bpm);

}

SheetMusicAudioProcessorEditor::~SheetMusicAudioProcessorEditor()
{

  
}

//==============================================================================

void SheetMusicAudioProcessorEditor::playButtonPushed()
{
    if (play_Button.getToggleState())
    {
        play_Button.setToggleState(false, NotificationType::dontSendNotification);
        play_state = true;
    }
    else
    {
        play_Button.setToggleState(true, NotificationType::dontSendNotification);
        play_state = false;
    }

}

void SheetMusicAudioProcessorEditor::timerCallback()
{

    sheet.staffs[current_staff]->getBarAt(current_bar)->isCurrentBarAndStaff(current_staff, current_bar);

    auto bar = sheet.staffs[current_staff]->getBarAt(current_bar);

    

    if (current_bar < 4)
    {
        if (play_state)
        {
            sheet.setState(true, current_staff, current_bar);
        }
        else
        {
            sheet.setState(false, current_staff, current_bar);
        }
    }

    auto isPlaying = sheet.getBarAt(current_staff, current_bar)->isPlayheadInBounds();

    if (!isPlaying)
    {
        if (current_bar < 3)
        {
            sheet.getBarAt(current_staff, current_bar)->resetIndex();
            sheet.getBarAt(current_staff, current_bar)->setPlayheadOn(false);
            current_bar++;
        }
        else  if (current_staff < sheet.staffs.size() - 1)
        {
            current_staff++;
            current_bar = 0;
        }
        else if(current_staff == sheet.staffs.size()-1 && current_bar == 3)
        {
            current_staff = 0;
            current_bar = 0;
        }
    }

    auto messages = audioProcessor.getTempMidiBuffer();

    for (auto m : messages)
    {
        auto key = m.key;
        int current_section = sheet.staffs[current_staff]->getBarAt(current_bar)->getCurrentNumSection();
        sheet.turnOnBeat(key, current_staff, current_bar, current_section);
    }

}

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
    tree.setBounds(0, getHeight()/10, getWidth() / 6, getHeight());
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

    bpm.setBounds(28 * getWidth() / 33, getHeight() / 10, 5 * getWidth() / 33, getHeight() / 10);

}
