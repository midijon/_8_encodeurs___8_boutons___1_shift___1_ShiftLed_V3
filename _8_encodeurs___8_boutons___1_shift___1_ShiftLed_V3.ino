#include <Bounce.h>
#include <Encoder.h>

const int NUM_OF_BUTTONS = 8;
const int MIDI_CHAN = 1;
const int DEBOUNCE_TIME = 5;
const int ledPin = 32;

Bounce buttons[NUM_OF_BUTTONS + 1] =
{
  Bounce (0, DEBOUNCE_TIME),
  Bounce (1, DEBOUNCE_TIME),
  Bounce (2, DEBOUNCE_TIME),
  Bounce (3, DEBOUNCE_TIME),
  Bounce (4, DEBOUNCE_TIME),
  Bounce (5, DEBOUNCE_TIME),
  Bounce (6, DEBOUNCE_TIME),
  Bounce (7, DEBOUNCE_TIME),
  Bounce (8, DEBOUNCE_TIME),
};

const int MIDI_MODE_NOTES = 0;
const int MIDI_MODE_CCS = 1;

int midiMode = MIDI_MODE_NOTES;

const int MIDI_NOTE_NUMS[NUM_OF_BUTTONS] = {1, 2, 3, 4, 5, 6, 7, 8};
const int MIDI_NOTE_VELS[NUM_OF_BUTTONS] = {110, 110, 110, 110, 110, 110, 110, 110};
const int MIDI_CC_NUMS[NUM_OF_BUTTONS] = {1, 2, 3, 4, 5, 6, 7, 8};
const int MIDI_CC_VALS[NUM_OF_BUTTONS] = {127, 127, 127, 127, 127, 127, 127, 127};

Encoder Enc1(9,10);
int value1;
Encoder Enc2(11,12);
int value2;
Encoder Enc3(39,14);
int value3;
Encoder Enc4(15,16);
int value4;
Encoder Enc5(17,18);
int value5;
Encoder Enc6(19,20);
int value6;
Encoder Enc7(21,22);
int value7;
Encoder Enc8(23,24);
int value8;


  long Enc1_previous = -999;
  long Enc2_previous = -999;
  long Enc3_previous = -999;
  long Enc4_previous = -999;
  long Enc5_previous = -999;
  long Enc6_previous = -999;
  long Enc7_previous = -999;
  long Enc8_previous = -999; 


void setup() {
  pinMode(0, INPUT_PULLUP);
 
  for (int i = 0; i < NUM_OF_BUTTONS + 1; i++)
  {
    pinMode (i, INPUT_PULLUP);
  }
  pinMode(ledPin, OUTPUT);
}

void loop() {

  for (int i = 0; i < NUM_OF_BUTTONS + 1; i++)
  {
    buttons[i].update();
  }


  for (int i = 0; i < NUM_OF_BUTTONS; i++)
  {
    if (buttons[i + 1].fallingEdge())
    {
      if (midiMode == MIDI_MODE_NOTES)
        usbMIDI.sendNoteOn (MIDI_NOTE_NUMS[i], MIDI_NOTE_VELS[i], MIDI_CHAN);
      else
        usbMIDI.sendControlChange (MIDI_CC_NUMS[i], MIDI_CC_VALS[i], MIDI_CHAN);
    }
    
    else if (buttons[i + 1].risingEdge())
    {
      if (midiMode == MIDI_MODE_NOTES)
        usbMIDI.sendNoteOff (MIDI_NOTE_NUMS[i], 0, MIDI_CHAN);
      else
        usbMIDI.sendControlChange (MIDI_CC_NUMS[i], 0, MIDI_CHAN);
    }
  } 
  
  if (buttons[0].fallingEdge())
  {
    midiMode = MIDI_MODE_NOTES;
  }
  else if (buttons[0].risingEdge())
  {
    midiMode = MIDI_MODE_CCS;
  }

    if (buttons[0].fallingEdge())
  {
    digitalWrite(ledPin, HIGH);
  }
  else if (buttons[0].risingEdge())
  {
    digitalWrite(ledPin, LOW);
  }



value1 = Enc1.read();
 if(value1 > 127) {    Enc1.write(127);   }
 else if(value1 < 0) {    Enc1.write(0);  } 
 
value1 = constrain(value1, 0, 127);
    if (value1 != Enc1_previous) {    Enc1_previous = value1;    usbMIDI.sendControlChange(50, value1, 1);  }


value2 = Enc2.read();
 if(value2 > 127) {    Enc2.write(127);   }
 else if(value2 < 0) {    Enc2.write(0);  } 
 
value2 = constrain(value2, 0, 127);
 if (value2 != Enc2_previous) {    Enc2_previous = value2;    usbMIDI.sendControlChange(51, value2, 1);  }


value3 = Enc3.read();
 if(value3 > 127) {    Enc3.write(127);   }
 else if(value3 < 0) {    Enc3.write(0);  } 
 
value3 = constrain(value3, 0, 127);
 if (value3 != Enc3_previous) {    Enc3_previous = value3;    usbMIDI.sendControlChange(52, value3, 1);  }


value4 = Enc4.read();
 if(value4 > 127) {    Enc4.write(127);   }
 else if(value4 < 0) {    Enc4.write(0);  } 
 
value4 = constrain(value4, 0, 127);
 if (value4 != Enc3_previous) {    Enc4_previous = value4;    usbMIDI.sendControlChange(53, value4, 1);  }


value5 = Enc5.read();
 if(value5 >127) {    Enc5.write(127);    }
 else if (value5 < 0) {   Enc5.write(0);  }

value5 = constrain(value5, 0, 127);
 if (value5 != Enc5_previous) {   Enc5_previous = value5;     usbMIDI.sendControlChange(54, value5, 1);  }


value6 = Enc6.read();
 if(value6 >127) {    Enc6.write(127);    }
 else if (value6 < 0) {   Enc6.write(0);  }

value6 = constrain(value6, 0, 127);
 if (value6 != Enc6_previous) {   Enc6_previous = value6;     usbMIDI.sendControlChange(55, value6, 1);  }


value7 = Enc7.read();
 if(value7 >127) {    Enc7.write(127);    }
 else if (value7 < 0) {   Enc7.write(0);  }

value7 = constrain(value7, 0, 127);
 if (value7 != Enc7_previous) {   Enc7_previous = value7;     usbMIDI.sendControlChange(56, value7, 1);  }


value8 = Enc8.read();
 if(value8 >127) {    Enc8.write(127);    }
 else if (value8 < 0) {   Enc5.write(0);  }

value8 = constrain(value8, 0, 127);
 if (value8 != Enc8_previous) {   Enc8_previous = value8;     usbMIDI.sendControlChange(57, value8, 1);  }




  while (usbMIDI.read())
  {
  }
}

