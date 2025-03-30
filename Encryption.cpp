#include "Encryption.h"
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

std::string Encryption::CaesarCipherEncode(const std::string& InString, int Shift)
{
    if (InString.length() == 0 || Shift == 0)
        return std::string();

    std::string OutString;
    for (auto letter : InString)
    {
        int pos = (static_cast<int>(letter) + 256 + Shift) % 256;

        char outletter = static_cast<char>(pos);
        std::cout << "letter :" << outletter << std::endl;

        OutString += outletter;
    }
    return OutString;
}

std::string Encryption::CaesarCipherDecode(const std::string& InString, int Shift)
{
    return CaesarCipherEncode(InString, -Shift);
}

std::string Encryption::AtbashCipherEncode(const std::string& InString)
{
    // rule : Mirror(x) = 90 - (x - 65) 

    std::string mirroredstring;

    for (auto letter : InString)
    {
        int pos = static_cast<int>(letter);
        int mirroredpos = 90 - pos + 65;
        char mirroredletter = static_cast<char>(mirroredpos);
        mirroredstring += mirroredletter;
    }
    std::cout << "mirrored string : " << mirroredstring << std::endl;

    return mirroredstring;
}

std::string Encryption::AtbashCipherDecode(const std::string& InString)
{
    AtbashCipherEncode(InString);
}

std::string Encryption::ShuffleAlphabet()
{
    std::string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // use current time as seed for randomness
    // srand(time(0));
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(Alphabet.begin(), Alphabet.end(), std::default_random_engine(seed));
}

std::string Encryption::SubstitutionEncode(const std::string& InString)
{
    return std::string();
}

std::string Encryption::SubstitutionDecode(const std::string& InString)
{
    return std::string();
}

std::map<char, int> Encryption::FrequencyAnalysis(const std::string& InString)
{
    std::map<char, int> Frequency;
    for (auto letter : InString)
    {
        // Frequency.insert(std::make_pair());
        Frequency[letter]++;
    }

    for (auto pair : Frequency)
    {
        std::cout << "map key : " << pair.first << " map value : " << pair.second << std::endl;
    }

    return Frequency;
}
