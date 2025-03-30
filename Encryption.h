#pragma once

#include <iostream>
#include <string>
#include <map> 

class Encryption
{
	// constructor
	// Encryption();

public:
	// caesar cipher
	std::string CaesarCipherEncode(const std::string& InString, int Shift);
	std::string CaesarCipherDecode(const std::string& InString, int Shift);

	// atbash cipher
	std::string AtbashCipherEncode(const std::string& InString);
	std::string AtbashCipherDecode(const std::string& InString);

	// substitution cipher
	std::string ShuffleAlphabet();
	std::string SubstitutionEncode(const std::string& InString);
	std::string SubstitutionDecode(const std::string& InString);

	// AI 
	std::map<char, int> FrequencyAnalysis(const std::string& InString);
};

