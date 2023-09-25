/**
 * @file Steganography.cpp
 * @author Jesse Warren
 * @date 2023-09-25
 * @brief Holds the functions.
 * 
 * Holds the work for each function listed within Steganography.h.
 */

#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


//Check the 'README.md' for details on errors, specifically my inability to properly test the code via files, and what I had to resort to.

int Steganography::getNthBit(char cipherChar, int n){
  int bit;
  bit = (cipherChar >> n) % 2; //Shifts the bits by 'n' positions and extracts the least significant position.
  return bit;
}

void Steganography::readImage(string fileName){
  ifstream file;
  file.open(fileName);

  //Pulls numbers from the PMM files and puts them in the class variables.
  file >> magicNumber >> width >> height >> maxColor; 

  int colorholder;

  //Pushes everything into the vector via push_back.
  while(file){
    file >> colorholder;
    colorData.push_back(colorholder);
  }
    
  file.close();
}

void Steganography::printImage(string fileName){
  ofstream file;
  file.open(fileName);

  //Outputs the variables into a file.
  file << magicNumber << endl << width << " " << height << endl << maxColor << endl;
  
  int i = 0;
  int size = colorData.size();

  //Outputs the color numbers into the files, along with the enciphered data.
  while(i < size){
    file << colorData[i] << " ";
    i++;
  }
  
  file.close();
}

void Steganography::readCipherText(string fileName){
  ifstream file;
  file.open(fileName);

  char holder;

  //Pulls each character within the text file into 'char holder'.
  while(file.get(holder)){
    cipherText += holder;
  }
  file.close();
}

void Steganography::printCipherText(string fileName){
  ofstream file;
  file.open(fileName);

  //Simply pulls the new cipherText into the requested text file.
  file << cipherText;

  file.close();
}

void Steganography::cleanImage(){
  int size = colorData.size();
  for(int i = 0; i < size; i++){
    colorData[i] = colorData[i] - (colorData[i] % 2); 
  }
}

void Steganography::encipher(){
  cleanImage();

  int counter = 0;
  int length = cipherText.length();
  char holder = 0;
  
  for(int i = 0; i < length; i++){
    //Pulls the data from cipherText onto holder.
    holder += cipherText[i];

    for(int j = 0; j < 8; j++){
      //Calls 'getNthBit' to collect the least significant bit,
      int bit = getNthBit(holder, j); 

      int& Val = colorData[counter]; 

      //Sets the value of Val based on bit.
      if(bit == 1){  
	Val |= 1;
      }
      else
	Val &= ~1;
      
      counter++;
    }
  }
}

void Steganography::decipher(){
  cipherText.clear();

  int counter = 0;
  int size = colorData.size();
  char holder;

  for(int i = 0; i < size; i++){
    int bit = getNthBit(colorData[i], 0); 

    //Accumulates bits from least significant positions. 
    holder |= (bit << (counter % 8));

    //Checks if a total of 8 bits have been accumulated. 
    if(counter % 8 == 0){
      cipherText += holder;

      holder = 0;
    }

    counter++;
  }
}
