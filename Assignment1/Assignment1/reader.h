#ifndef READER_H
#define READER_H
#include <iostream>
#include <fstream>
#include <string>
class Reader {
	public:
		Reader();
		//To read a file
		std::ifstream read(std::string& path);
		//calculations method
		bool calculations(std::ifstream& fileStream);
		//To create a curve using the math statistics
		void curve();
		//Resets Variables
		void reset();

		//Math Getters
		int  getSum(){ return sum;}
		double  getMean(){ return mean; }
		double  getVarience(){ return varience; }
		double  getStDeviation(){ return stDeviation; }
		//Math Setters
		void setSum(int& sum) { this->sum = sum; }
		void setMean(double& mean) { this->mean = mean; }
		void setVarience(double& varience) { this->varience = varience; }
		void setStDeviation(double& stDeviation) { this->stDeviation = stDeviation; }
		//File Reading Getters
		int  getLengthDNA() { return lengthDNA; }
		int  getLineNum() { return lineNum; }
		//File Reading Getters
		void setLengthDNA(int& lenghtDNA) { this->lengthDNA = lengthDNA; }
		void setLineNum(int& lineNum) { this->lineNum = lineNum; }

	private:
		//Nucleotides
		int nucA;
		int nucT;
		int nucC;
		int nucG;
		//A_ Bigrams
		int bigramAA;
		int bigramAC;
		int bigramAT;
		int bigramAG;
		//T_ Bigrams
		int bigramTA;
		int bigramTC;
		int bigramTT;
		int bigramTG;
		//C_ Bigrams
		int bigramCA;
		int bigramCC;
		int bigramCT;
		int bigramCG;
		//G_ Bigrams
		int bigramGA;
		int bigramGC;
		int bigramGT;
		int bigramGG;
		//File Reading Vars
		int lengthDNA;
		int lineNum;
		std::string line;
		char c;
		char prev;
		bool bigram;
		int charCounter;
		int totalChar;
		//Mathmatical Vars
		int sum;
		double mean;
		double varience;
		double strLengthMinusMean;
		double stDeviation;
};
#endif
