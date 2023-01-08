/*
  By: Brendan Luke
  Date: January 7, 2023

  Scope: This header file contains the functions for each button of Mom's LED Candle remotes
*/

#include "Arduino.h"
#include <avr/pgmspace.h>

// Pre-Definitions:
unsigned int wait = 10; // microseconds to wait
int i = 0; // counter variable
int j = 0; // counter variable
int IR_Pin = 8; // IR LED Pin
uint8_t cycles = 22; // number of cycles for "ON" pulse
int shortDel = 1.0*474;
int longDel = 1.0*1474;

const byte addresses [] = {0x00, 0x01, 0x40}; // silver ON/Off (A), All Black (B), Colour (C)
const byte remA [] = {0x80, 0x90}; // On, Off
const byte remB [] = {0x48, 0x78, 0x80, 0xC0, 0x20, 0x60, 0xE0, 0x90, 0x50, 0xF8}; 
// On, Off, 2H, 4H, 6H, 8H, Candle, Light, Dim -, Dim +
const byte remC [] = {
  0x00, 0x80, 0x40, 0x20, 0xA0, 0x60, 0x10, 0x50, 0x30, 0x70, 0x08, 0x88, 0x48, 0x28, 0xA8, 0x68
}; // On, Off, M, 5H, 8H, CC, -, +, WW, CW, Red, Green, Blue, Cyan, Magenta, Purple

void remA_ON() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x00 (0000 0000)
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x80 (1000 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remA_OFF() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x00 (0000 0000)
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x90 (1001 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;  
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_ON() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0x48 (0100 1000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_OFF() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0x78 (0111 1000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_2H() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0x80 (1000 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_4H() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0xC0 (1100 0000)
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_6H() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0x20 (0010 0000)
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel);
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_8H() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0x60 (0110 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_Candle() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0xE0 (1110 0000)
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_Light() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0x90 (1001 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_DimM() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0x50 (0101 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remB_DimP() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x01 (0000 0001)
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  
  // Address Inverted
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  
  // Signal: 0xF8 (1111 1000)
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_ON() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x00 (0000 0000)
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 9) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_OFF() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x80 (1000 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 8) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_M() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_5H() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x20 (0010 0000)
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_8H() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0xA0 (1010 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_CC() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x60 (0110 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 6) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_DimM() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x10 (0001 0000)
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_DimP() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x50 (0101 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_WW() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x30 (0011 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_CW() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x70 (0111 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (j < 5) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_Red() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x08 (0000 1000)
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_Green() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x88 (1000 1000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_Blue() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x48 (0100 1000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_Cyan() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x28 (0010 1000)
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (j < 2) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_Magenta() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0xA8 (1010 1000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}

void remC_Purple() {
  // Wakeup Pulse (8ms ON, 4ms OFF)
  while (i < 304) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(4000);
  
  // Address: 0x40 (0100 0000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Address Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel); j++;
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 7) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
  
  // Signal: 0x68 (0110 1000)
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (j < 3) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(shortDel); j++;
  }
  j = 0;
  
  // Signal Inverted
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(longDel);
  while (i < cycles) {
    digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
  }
  i = 0; delayMicroseconds(shortDel);
  while (j < 4) {
    while (i < cycles) {
      digitalWrite(IR_Pin,HIGH); delayMicroseconds(wait); digitalWrite(IR_Pin,LOW); delayMicroseconds(wait); i++;
    }
    i = 0; delayMicroseconds(longDel); j++;
  }
  j = 0;
}
