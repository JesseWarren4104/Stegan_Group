#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <iostream>
#include <vector>

class Steganography {

private:
  string magicNumber;
  int width;
  int height;
  int maxColor;
  vector<int> colorData;
  string cipherText;
  int getNthBit(char cipherChat, int n);

public:
  void readImage(string fileName);
  void printImage(string fileName);
  void readCipherText(string fileName);
  void printCipherText(string fileName);
  void cleanImage();
  void encipher();
  void decipher();

};

#endif


