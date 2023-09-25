/**
 * @file main.cpp
 * @author Jesse Warren
 * @date 2023-09-25
 * @brief Holds the main.
 * 
 * Holds the main, along with every output, and the sequence that must be followed to properly execute the code.
 */

#include <iostream>
#include <fstream>
#include "Steganography.h"

using namespace std;

int main() {
  Steganography steg;

  cout << "Do you wish to encipher or decipher? ";
  string answer; cin >> answer; cout << endl;

  string imagename, textname, outputname;
  
  if(answer == "encipher"){

    cout << "Please input the image-file(ppm only) you wish to encode: ";
    cin >> imagename; cout << endl;
    
    cout << "Please input the text-file you wish to encode it with: ";
    cin >> textname; cout << endl;

    cout << "Please input the name of the image file you wish to extract the new image onto: ";
    cin >> outputname; cout << endl;

    steg.readImage(imagename);

    steg.readCipherText(textname);

    steg.encipher();

    steg.printImage(outputname);
  }
  else if(answer == "decipher"){

    cout << "Please input the image-file(ppm only) you wish to decode: ";
    cin >> imagename; cout << endl; 

    cout << "Please input the text-file you wish to extract the hidden message onto: ";
    cin >> textname; cout << endl;
    
    steg.readImage(imagename);

    steg.decipher();

    steg.printCipherText(textname);
  }
  else
    cout << "No answer selected." << endl;
  
  return 0;
}
