/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "AmpPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AmpPanel::AmpPanel (SynthParams &p)
    : params(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (amp = new Slider ("amp"));
    amp->setRange (-96, 12, 0);
    amp->setSliderStyle (Slider::LinearVertical);
    amp->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    amp->addListener (this);

    addAndMakeVisible (pan = new Slider ("pan"));
    pan->setRange (-100, 100, 0);
    pan->setSliderStyle (Slider::RotaryVerticalDrag);
    pan->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    pan->addListener (this);

    addAndMakeVisible (label2 = new Label ("R label",
                                           TRANS("R")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("L label",
                                           TRANS("L")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    amp->setValue(params.vol.getUI());
    amp->setTextValueSuffix(String(" ") + params.vol.unit());
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

AmpPanel::~AmpPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    amp = nullptr;
    pan = nullptr;
    label2 = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AmpPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AmpPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    amp->setBounds (8, 32, 64, 128);
    pan->setBounds (80, 96, 112, 64);
    label2->setBounds (161, 120, 24, 24);
    label3->setBounds (90, 120, 24, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AmpPanel::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == amp)
    {
        //[UserSliderCode_amp] -- add your slider handling code here..
        params.vol.setUI(static_cast<float>(amp->getValue()));
        //[/UserSliderCode_amp]
    }
    else if (sliderThatWasMoved == pan)
    {
        //[UserSliderCode_pan] -- add your slider handling code here..
		params.panDir.setUI(static_cast<float>(pan->getValue()));
        //[/UserSliderCode_pan]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AmpPanel" componentName=""
                 parentClasses="public Component" constructorParams="SynthParams &amp;p"
                 variableInitialisers="params(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="amp" id="3279e0342166e50f" memberName="amp" virtualName=""
          explicitFocusOrder="0" pos="8 32 64 128" min="-96" max="12" int="0"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pan" id="d8f72bae093dfe35" memberName="pan" virtualName=""
          explicitFocusOrder="0" pos="80 96 112 64" min="-100" max="100"
          int="0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="R label" id="38f0a446950aca39" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="161 120 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="L label" id="fb5b8372200665a9" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="90 120 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="L" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
