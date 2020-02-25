#include "reader.h"
#include<cmath>
#include <exception> 

Reader::Reader() {

	//Nucleotides
	nucA = 0;
	nucT = 0;
	nucC = 0;
	nucG = 0;
	//A_ Bigrams
	bigramAA = 0;
	bigramAC = 0;
	bigramAT = 0;
	bigramAG = 0;
	//T_ Bigrams
	bigramTA = 0;
	bigramTC = 0;
	bigramTT = 0;
	bigramTG = 0;
	//C_ Bigrams
	bigramCA = 0;
	bigramCC = 0;
	bigramCT = 0;
	bigramCG = 0;
	//G_ Bigrams
	bigramGA = 0;
	bigramGC = 0;
	bigramGT = 0;
	bigramGG = 0;
	//File Reading Vars
	lengthDNA = 0;
	lineNum = 0;
	charCounter = 0;
	line = " ";
	c = ' ';
	prev = ' ';
	bigram = false;
	totalChar = 0;
	//Mathmatical Vars
	sum = 0;
	mean = 0;
	varience = 0;
	strLengthMinusMean = 0;
	stDeviation = 0;

}
std::ifstream Reader::read(std::string& path) {
	std::ifstream fileStream(path);
	if (!fileStream.is_open()) {
		std::cout << "Error opening file. Check the name of the file or "
			<< "check that it exists."<<std::endl;
		return fileStream;
	}
	try {
		//obtained from: https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
		if (fileStream.peek() == std::ifstream::traits_type::eof()) {
			std::cout << "The file is empty." << std::endl;
			return fileStream;
		}
	}
	//obtained catch from https://en.cppreference.com/w/cpp/language/try_catch
	catch (const std::exception& e) {
		std::cout << "Exception Caught: " <<e << std::endl;
	}
	if (fileStream.good()) {
		while (getline(fileStream, line)) {
			++lineNum;
			for (char& c : line) {
				if (c == 'A' || c == 'a') {
					++sum;
					++totalChar;
					++nucA;
					if (bigram) {
						if (prev == 'A' || prev == 'a') {
							++bigramAA;
						}
						else if (prev == 'T' || prev == 't') {
							++bigramTA;
						}
						else if (prev == 'C' || prev == 'c') {
							++bigramCA;
						}
						else if (prev == 'G' || prev == 'g') {
							++bigramGA;
						}
						bigram = false;
					}
					else {
						prev = c;
						bigram = true;
					}
					
				}
				else if (c == 'T' || c == 't') {
					++sum;
					++totalChar;
					++nucT;
					if (bigram) {
						if (prev == 'A' || prev == 'a') {
							++bigramAT;
						}
						else if (prev == 'T' || prev == 't') {
							++bigramTT;
						}
						else if (prev == 'C' || prev == 'c') {
							++bigramCT;
						}
						else if (prev == 'G' || prev == 'g') {
							++bigramGT;
						}						
						bigram = false;
					}
					else {
						prev = c;
						bigram = true;						
					}				
					
				}
				else if (c == 'C' || c == 'c') {
					++sum;
					++totalChar;
					++nucC;
					if (bigram) {
						if (prev == 'A' || prev == 'a') {
							++bigramAC;
						}
						else if (prev == 'T' || prev == 't') {
							++bigramTC;
						}
						else if (prev == 'C' || prev == 'c') {
							++bigramCC;
						}
						else if (prev == 'G' || prev == 'g') {
							++bigramGC;
						}					
						bigram = false;
					}
					else {
						prev = c;
						bigram = true;
					}			
				
				}
				else if (c == 'G' || c == 'g') {
					++sum;
					++totalChar;
					++nucG;
					if (bigram) {
						if (prev == 'A' || prev == 'a') {
							++bigramAG;
						}
						else if (prev == 'T' || prev == 't') {
							++bigramTG;
						}
						else if (prev == 'C' || prev == 'c') {
							++bigramCG;
						}
						else if (prev == 'G' || prev == 'g') {
							++bigramGG;
						}						
						bigram = false;
					}
					else {
						prev = c;
						bigram = true;
					}					
					
				}
			}
		}
	}
	//NOTE: FILE STREAM WILL BE PASSED INTO CALCULATIONS METHOD
	return fileStream;
	

}
bool Reader::calculations(std::ifstream& fileStream) {
	
	if (!fileStream.is_open()) {
		std::cout << "File Stream is not open. " << std::endl;
		//NEED A FILE STREAM CLOSE?
		return false;
	}

	
	//mean calculation
	mean = (sum / totalChar);


	//varience calculation
	//checks if the file is not empty and the risk flags
	if (fileStream.good()) {
		//gets each line in the file
		while (getline(fileStream, line)) {
			//goes through the chars in the line
			for (char& c : line) {
				//checks is the char is a nucleotide
				if (c == 'A' || c == 'a' || c == 'T' || c == 't' ||
					c == 'C' || c == 'c' || c == 'G' || c == 'g') {
					//increments the char in the line
					++charCounter;
					
				}
				//sum of line chars minus the mean
				strLengthMinusMean += (pow((charCounter - mean), 2));
				//resets the char counter for the next line
				charCounter = 0;
			}
		}
	}

	//varience equation cont.
	varience = strLengthMinusMean / (lineNum);
	//close file stream
	fileStream.close();
	//Standard Deviation Calculation
	stDeviation = pow(varience, .5);
	

	return true;
}
void Reader::curve() {
	//Creates File
	std::ofstream output("JeevanAcharya.out");
	//Student Info
	output << "Jeevan Acharya" << std::endl;
	output << "2313321" << std::endl;
	output << "acharya@chapman.edu" << std::endl;

	//Output
	output << "/n" << "-----------Math Equations-----------" << std::endl;
	output << "Sum: " << sum << std::endl;
	output << "Mean: " << mean << std::endl;
	output << "Varience: " << varience << std::endl;
	output << "Standard Deviation" << stDeviation << std::endl;
	output << "/n" << "-----------Probabilities------------" << std::endl;
	output << "Probability of: " << std::endl;
	output << "A: " << (nucA / totalChar) * 100 << "%" << std::endl;
	output << "B: " << (nucT / totalChar) * 100 << "%" << std::endl;
	output << "C: " << (nucC / totalChar) * 100 << "%" << std::endl;
	output << "G: " << (nucG / totalChar) * 100 << "%" << std::endl;

	output << "/n" << "A_ Bigrams: " << std::endl;
	output << "AA" << (bigramAA / totalChar) * 100 << "%" << std::endl;
	output << "AC" << (bigramAC / totalChar) * 100 << "%" << std::endl;
	output << "AT" << (bigramAT / totalChar) * 100 << "%" << std::endl;
	output << "AG" << (bigramAG / totalChar) * 100 << "%" << std::endl;

	output << "/n" << "T_ Bigrams: " << std::endl;
	output << "TA" << (bigramTA / totalChar) * 100 << "%" << std::endl;
	output << "TC" << (bigramTC / totalChar) * 100 << "%" << std::endl;
	output << "TT" << (bigramTT / totalChar) * 100 << "%" << std::endl;
	output << "TG" << (bigramTG / totalChar) * 100 << "%" << std::endl;

	output << "/n" << "C_ Bigrams: " << std::endl;
	output << "CA" << (bigramCA / totalChar) * 100 << "%" << std::endl;
	output << "CC" << (bigramCC / totalChar) * 100 << "%" << std::endl;
	output << "CT" << (bigramCT / totalChar) * 100 << "%" << std::endl;
	output << "CG" << (bigramCG / totalChar) * 100 << "%" << std::endl;

	output << "/n" << "G_ Bigrams: " << std::endl;
	output << "GA" << (bigramGA / totalChar) * 100 << "%" << std::endl;
	output << "GC" << (bigramGC / totalChar) * 100 << "%" << std::endl;
	output << "GT" << (bigramGT / totalChar) * 100 << "%" << std::endl;
	output << "GG" << (bigramGG / totalChar) * 100 << "%" << std::endl;
}
void Reader::reset() {
	//Nucleotides
	nucA = 0;
	nucT = 0;
	nucC = 0;
	nucG = 0;
	//A_ Bigrams
	bigramAA = 0;
	bigramAC = 0;
	bigramAT = 0;
	bigramAG = 0;
	//T_ Bigrams
	bigramTA = 0;
	bigramTC = 0;
	bigramTT = 0;
	bigramTG = 0;
	//C_ Bigrams
	bigramCA = 0;
	bigramCC = 0;
	bigramCT = 0;
	bigramCG = 0;
	//G_ Bigrams
	bigramGA = 0;
	bigramGC = 0;
	bigramGT = 0;
	bigramGG = 0;
	//File Reading Vars
	lengthDNA = 0;
	lineNum = 0;
	line = " ";
	c = ' ';
	prev = ' ';
	bigram = false;
	charCounter = 0;
	totalChar = 0;
	//Mathmatical Vars
	sum = 0;
	mean = 0;
	varience = 0;
	strLengthMinusMean = 0;
	stDeviation = 0;
}