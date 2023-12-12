#include <string>

#define delayMultiplier 100
#define message "Merry christmas and a happy new year"
#define pin 2

bool use_morse = true;

using namespace std;

const char* morse[27] = {
  ".-",
  "-...",
  "-.-.",
  "-..",
  ".",
  "..-.",
  "--.",
  "....",
  "..",
  ".---",
  "-.-",
  ".-..",
  "--",
  "-.",
  "---",
  ".--.",
  "--.-",
  ".-.",
  "...",
  "-",
  "..-",
  "...-",
  ".--",
  "-..-",
  "-.--",
  "--..",
  "/"
};

const char* toMorse(char input) {
  int id = toupper(input) - 65;
  if (id >= 0 && id < 27)
    return morse[id];
  else
    return(morse[26]);
}

string StoMorse(string input) {
  string builder;

  for (int i = 0; i < input.length(); i++) {
    builder = builder + (string)toMorse(input[i]) + " ";
  }

  return builder;
}

string toAscBin(char input) {
    string output = "0";

    for (int i = 6; i >= 0; i--) {
        if (input - pow(2,i) >= 0) {
            input -= pow(2,i);
            output += "1";
        } else {
            output += "0";
        }
    }

    return output;
}


string StoAscBin(string input) {
  string builder;

  for (int i = 0; i < input.length(); i++) {
    builder = builder + (string)toAscBin(input[i]) + " ";
  }

  return builder;
}

string messageMorse;
string messageAscBin;

void setup() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
 
  messageMorse = StoMorse(message);
  messageAscBin = StoAscBin(message);
}

void loop() {
  /* Randomised morse and binary
  if (millis() % 2 == 0) {
    use_morse = false;
  }
  */

  delay(10*delayMultiplier);
  if (use_morse) {
    for (int i = 0; i < messageMorse.length(); i++) {
      if (messageMorse[i] == '.') {
        digitalWrite(pin, LOW);
        delay(1 * delayMultiplier);
        digitalWrite(pin, HIGH);
    }
      else if (messageMorse[i] == '-') {
        digitalWrite(pin, LOW);
        delay(3 * delayMultiplier);
        digitalWrite(pin, HIGH);
      }
      else if (messageMorse[i] == '/') {
        delay(4 * delayMultiplier);
      }
      delay(3 * delayMultiplier);
    }
  } else {
    for (int i = 0; i < messageAscBin.length(); i++) {
      if (messageAscBin[i] == '0') {
        digitalWrite(pin, HIGH);
      }
      else if (messageAscBin[i] == '1') {
        digitalWrite(pin, LOW);
      }
      else if (messageAscBin[i] == ' ') {
        delay(5 * delayMultiplier);
      }
      delay(1 * delayMultiplier);
    }
  }
}
