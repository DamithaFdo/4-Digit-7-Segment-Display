//By Damitha Fernando

#include "SevSeg.h"

SevSeg sevseg;                                          // Create a SevSeg object

void setup() {
    byte numDigits = 4;
    byte digitPins[] = {2, 3, 4, 5};                    // Digit control pins (D1,D2,D3,D4)
    byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};  // Segment control pins (a,b,c,d,e,f,g,h)
    bool resistorsOnSegments = false;                   // Set to true if resistors are on segment pins (330ohm recommended)

    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);                           // Adjust brightness (0-100)
}

void loop() {
    //Display a decimal number (1234)
    //sevseg.setNumber(1234, 0);                        // uncomment to DECIMAL mode

    //Display text "ABCI"
    displayText("ABCD");                                // uncomment to TEXT mode

    sevseg.refreshDisplay();                            // Continuously refresh the display
}

// Function to display text on 7-segment display
void displayText(const char *text) {
    const byte customChars[26] = {
        0b01110111, // A
        0b01111111, // B
        0b00111001, // C
        0b00111111, // D
        0b01111001, // E
        0b01110001, // F
        0b01101111, // G
        0b01110110, // H
        0b00000110, // I
        0b00011110, // J
        0b01110110, // K (Displayed as H)
        0b00111000, // L
        0b00010101, // M (Approximate)
        0b00110111, // N
        0b00111111, // O
        0b01110011, // P
        0b01100111, // Q
        0b00110001, // R
        0b01101101, // S
        0b01111000, // T
        0b00111110, // U
        0b00011100, // V
        0b00011101, // W (Approximate)
        0b01110110, // X (Displayed as H)
        0b01101110, // Y
        0b01011011  // Z (Approximate)
    };

    byte segmentData[4] = {0, 0, 0, 0};                 // Initialize to blank display

    for (int i = 0; i < 4; i++) {
        char ch = text[i];

        if (ch >= 'A' && ch <= 'Z') {
            segmentData[i] = customChars[ch - 'A'];
        } else {
            segmentData[i] = 0;                         // Blank character if unsupported
        }
    }

    sevseg.setSegments(segmentData);
}
