/**
 * @file Steganography.h
 * @author Jesse Warren
 * @date 2023-09-25
 * @brief Holds the class.
 * 
 * Holds the function and class definitions, along with their descriptions.
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <iostream>
#include <vector>

using namespace std;

class Steganography {

private:
  string magicNumber; //The P3 value for the PPM file.
  int width; //Width of the image.
  int height; //Height of the image.
  int maxColor; //The maximum color depth.
  vector<int> colorData; //The vector which holds every pixel color value.
  string cipherText; //The string which holds the words within the text file.
  int getNthBit(char cipherChat, int n);
  /* Description:
   *    Function returns the 'nth' bit from a character you're trying to encode.
   */
public:
  void readImage(string fileName);
  /* Description:
   *    Reads in the data from the user-inputted file and sets variables equal to it.
   */
  void printImage(string fileName);
  /* Description:
   *    Prints the variables and enciphered text upon a new file, which holds the new encrypted image.
   */
  void readCipherText(string fileName);
  /* Description:
   *    Reads in the user-inputted text file and stores the data inside of it.
   */
  void printCipherText(string fileName);
  /* Description:
   *    Prints the deciphered sentence from the encrypted image onto the new text file.
   */
  void cleanImage();
  /* Description:
   *    Zeroes out the least significant bit of each color value in colorData.
   */
  void encipher();
  /* Description:
   *    Stores the text from cipherText in the image colorData.
   */
  void decipher();
  /* Description:
   *    Reads the ciphertext back from colorData and stores it in cipherText;
   */

};

#endif


