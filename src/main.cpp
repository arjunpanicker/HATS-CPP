#include <iostream>
#include <string>

#include "Fasttext.h"
#include "datasethandler.h"
#include "config.h"
#include "preprocessing.h"

void menuSelection();
void readDefaultDatasetTest(hats::DataTable* data = NULL);
void writeDefaultDatasetTest();
void lowercaseStringTest();
void lowercaseVectorTest();
void punctuationRemovalVectorTest();
void punctuationRemovalStringTest();
void stopwordRemovalVectorTest();
void stopwordRemovalStringTest();
void convertShortTextVectorTest();
void convertShortTextStringTest();
void testFasttextAPI();

int main(void)
{  
    menuSelection();

    return 0;
}

void menuSelection() {
    int menuSelection{ 0 };
    std::cout << "Select an option:\n";
    std::cout << "****** Basic Tests ******\n";
    std::cout << "1. Read default dataset\n";
    std::cout << "2. Write Default dataset\n";
    std::cout << "3. Preprocessing - Lowercase (Vector)\n";
    std::cout << "4. Preprocessing - Lowercase (string)\n";
    std::cout << "5. Preprocessing - Punctuation Removal (Vector)\n";
    std::cout << "6. Preprocessing - Punctuation Removal (string)\n";
    std::cout << "7. Preprocessing - Stopword Removal (Vector)\n";
    std::cout << "8. Preprocessing - Stopword Removal (string)\n";
    std::cout << "9. Preprocessing - Short-text Conversion (Vector)\n";
    std::cout << "10. Preprocessing - Short-text Conversion (string)\n";
    std::cout << "\n****** Word Embedding Tests ******\n";
    std::cout << "11. Test Fasttext and Args\n";
    std::cout << "\nSelection: ";
    std::cin >> menuSelection;

    switch (menuSelection) {
    case 1: 
        readDefaultDatasetTest();
        break;
    case 2:
        writeDefaultDatasetTest();
        break;
    case 3:
        lowercaseVectorTest();
        break;
    case 4:
        lowercaseStringTest();
        break;
    case 5:
        punctuationRemovalVectorTest();
        break;
    case 6:
        punctuationRemovalStringTest();
        break;
    case 7:
        stopwordRemovalVectorTest();
        break;
    case 8:
        stopwordRemovalStringTest();
        break;
    case 9:
        convertShortTextVectorTest();
        break;
    case 10:
        convertShortTextStringTest();
        break;
    case 11:
        testFasttextAPI();
        break;
    default:
        std::cout << "Invalid option selected..!!\n\n";
    }
}

void testFasttextAPI() {
    // TODO: Add functionality
    

}

void convertShortTextVectorTest() {
    hats::StringList strings = {"btti jla do", "water heater bnd kro", "mk it drk"};
    hats::Preprocessing preprocessing;

    hats::StringList newStrings = preprocessing.convertShortText(strings);

    std::cout << "\n\n";
    for (int i = 0; i < strings.size(); i++) {
        std::cout << strings.at(i) << " ----> ";
        std::cout << newStrings.at(i) << "\n\n";
    }

    std::cout << "*************************************************************";
}

void convertShortTextStringTest() {
    std::string str = "btti jla do";
    hats::Preprocessing preprocessing;

    std::string newStr = preprocessing.convertShortText(str);
    std::cout << str << " ---> " << newStr << "\n\n";
    std::cout << "*************************************************************";
}

void stopwordRemovalVectorTest() {
    hats::StringList strings = { "Hello dae", "ho ho bro!!", "dae ho hi!" };
    hats::Preprocessing preprocessing;

    hats::StringList stopwordsRemovedStrings = preprocessing.removeStopWords(strings);

    std::cout << "\n\n";
    for (int i = 0; i < strings.size(); i++) {
        std::cout << strings.at(i) << " ----> ";
        std::cout << stopwordsRemovedStrings.at(i) << "\n\n";
    }

    std::cout << "*************************************************************";
}

void stopwordRemovalStringTest() {
    std::string str = "Hello dae, ho ho bro!! dae ho hi!";
    hats::Preprocessing preprocessing;

    std::string newstr = preprocessing.removeStopWords(str);
    std::cout << str << " ---> " << newstr << "\n\n";
    std::cout << "*************************************************************";
}

void punctuationRemovalVectorTest() {
    hats::StringList strList = { "Hey, how are you?", "I am fine. My name is @Arjun", "Good to KNOW's" };
    hats::Preprocessing preprocessing;

    hats::StringList punctuationRemovedString = preprocessing.removePunctuation(strList);

    std::cout << "\n\n";
    for (int i = 0; i < strList.size(); i++) {
        std::cout << strList.at(i) << " ----> ";
        std::cout << punctuationRemovedString.at(i) << "\n\n";
    }

    std::cout << "*************************************************************";
}

void punctuationRemovalStringTest() {
    std::string str = "Hi, this is a TEST MessaGe..!! I don't know whether punctuations 'ill be removed or not..";

    hats::Preprocessing preprocessing;
    std::cout << "\n\n" << str << " ----> ";
    std::cout << preprocessing.removePunctuation(str) << "\n\n";

    std::cout << "*************************************************************";
}

void lowercaseVectorTest() {
    hats::StringList strList = {"Hey, how are you?", "I am fine. My name is Arjun", "Good to KNOW"};

    hats::Preprocessing preprocessing;
    hats::StringList convertedStringList = preprocessing.toLowercase(strList);

    std::cout << "\n\n";
    for (int i = 0; i < strList.size(); i++) {
        std::cout << strList.at(i) << " ----> ";
        std::cout << convertedStringList.at(i) << "\n\n";
    }

    std::cout << "*************************************************************";
}

void lowercaseStringTest() {
    std::string str = "Hi, this is a TEST MessaGe..!!";

    hats::Preprocessing preprocessing;
    std::cout << "\n\n" << str << " ----> ";
    std::cout << preprocessing.toLowercase(str) << "\n\n";

    std::cout << "*************************************************************";
}

void writeDefaultDatasetTest() {
    std::string filename = hats::files::NEW_DATASET_FILENAME;

    hats::CSVHandler csvHandler;

    hats::DataColumn col1 = { "command", std::vector<std::string>{"Hello hi how are you", "world", "My", "Name"} };
    hats::DataColumn col2 = { "label", std::vector<std::string>{"Konnichiwa Hajimemashite", "sekai", "Watashino", "Namae"} };

    hats::DataTable data = std::vector<hats::DataColumn>{ col1, col2 };

    csvHandler.write_csv(data, filename);
}

void readDefaultDatasetTest(hats::DataTable* data) {
    std::string filename = hats::files::SOURCE_DATASET_FILENAME;
    hats::CSVHandler csvHandler(filename);

    hats::DataTable csvTable = csvHandler.read_csv();
    std::cout << csvHandler.shape().first;

    for (int col = 0; col != csvHandler.shape().second; col++) {
        std::string colName = ((hats::DataColumn)csvTable[col]).first;
        std::vector<std::string> colValues = ((hats::DataColumn)csvTable[col]).second;
        std::cout << colName << "\n----------\n";
        for (int row = 0; row != colValues.size(); row++) {
            std::cout << colValues[row] << std::endl;
        }
        std::cout << "\n**********************************************************************\n";
    }

    if (data) {
        data = &csvTable;
    }
}