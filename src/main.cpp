#include <iostream>
#include <string>
#include <unordered_set>
#include <map>

#include "pre_utils.h"
#include "ml_utils.h"
#include "config.h"
#include "datasethandler.h"
#include "preprocessing.h"
#include "embedding.h"
#include "nnet.h"

// Private methods
std::vector<std::string> findUnique(hats::DataTable &data);

hats::DataTable getDataset();
void menuSelection();

void readDefaultDatasetTest();
void writeDefaultDatasetTest();
void lowercaseStringTest();
void lowercaseVectorTest();
void punctuationRemovalVectorTest();
void punctuationRemovalStringTest();
void stopwordRemovalVectorTest();
void stopwordRemovalStringTest();
void convertShortTextVectorTest();
void convertShortTextStringTest();
void testWordEmbeddings();
void testSentenceEmbeddings();
void testMLNet();
void trainML();

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
    std::cout << "11. Test Word Embeddings\n";
    std::cout << "12. Test Sentence Embeddings\n";
    std::cout << "13. Test Neural Network\n";
    std::cout << "14. Train ML\n";
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
        testWordEmbeddings();
        break;
    case 12:
        testSentenceEmbeddings();
        break;
    case 13:
        testMLNet();
        break;
    case 14:
        trainML();
        break;
    default:
        std::cout << "Invalid option selected..!!\n\n";
    }
}

void testSentenceEmbeddings() {
    hats::DataTable data = getDataset();
    
    // Preprocess the data
    hats::Preprocessing prerpocessing;
    data = prerpocessing.pipeline(data);

    // Generate a file with first column of the preprocessed data
    hats::DataColumn col = std::make_pair("", data[0].second);
    hats::DataTable commandsData = { col };
    hats::CSVHandler csvHandler;
    std::string filename = "preprocessed_data";
    filename = csvHandler.write_csv(commandsData, filename);

    // Train the fasttext model
    hats::Embedding embedding(filename);
    embedding.train();

    // Check Sentence Embedding - "My name is Arjun!!"
    std::string sentence = "My name is Arjun!!";
    fasttext::Vector vec = embedding.getSentenceEmbedding(sentence);
    std::cout << sentence << std::endl;
    std::cout << vec << std::endl;
}

void testWordEmbeddings() {
    hats::DataTable data = getDataset();
    
    // Preprocess the data
    hats::Preprocessing prerpocessing;
    data = prerpocessing.pipeline(data);

    // Generate a file with first column of the preprocessed data
    hats::DataColumn col = std::make_pair("", data[0].second);
    hats::DataTable commandsData = { col };
    hats::CSVHandler csvHandler;
    std::string filename = "preprocessed_data";
    filename = csvHandler.write_csv(commandsData, filename);

    // Train the fasttext model
    hats::Embedding embedding(filename);
    embedding.train();
    
    // Check Word embedding - "Hello"
    fasttext::Vector vec = embedding.getWordEmbedding("Hello");
    std::cout << "Hello: \n";
    std::cout << vec << std::endl;
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

void readDefaultDatasetTest() {
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
}

hats::DataTable getDataset()
{
    std::string filename = hats::files::SOURCE_DATASET_FILENAME;
    hats::CSVHandler csvHandler(filename);

    return csvHandler.read_csv();
}

void testMLNet() {
    // e.g. {3, 2, 1}
    std::vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);

    hats::Net myNet(topology);

    // Training of Neural Net
    std::vector<double> inputVals;
    myNet.feedForward(inputVals);

    std::vector<double> targetVals;
    myNet.backProp(targetVals);

    std::vector<double> resultVals;
    myNet.getResults(resultVals);
}

void trainML() {
    hats::DataTable data = getDataset();
    
    // Preprocess the data
    hats::Preprocessing prerpocessing;
    data = prerpocessing.pipeline(data);

    // Generate a file with first column of the preprocessed data
    hats::DataColumn col = std::make_pair("", data[0].second);
    hats::DataTable commandsData = { col };
    hats::CSVHandler csvHandler;
    std::string filename = "preprocessed_data";
    filename = csvHandler.write_csv(commandsData, filename);

    // Create a mapping of class labels to its corresponding 
    hats::StringList uniqueLabels = findUnique(data);
    hats::MapStoVi labelMap = hats::oneHotEncode(data);

    // Train the fasttext model
    const int dims = 50;
    hats::Embedding embedding(filename, dims);
    embedding.train();
    
    // Create a Table with sentence vectors
    hats::FasttextDataColumn sentenceVectorColumn = std::make_pair("", 
            std::vector<hats::FasttextVector> {});

    for (int i = 0; i < data[0].second.size(); i++) {
        std::string sent = data[0].second.at(i);

        hats::FasttextVector vec = embedding.getSentenceEmbedding(sent);
        sentenceVectorColumn.second.push_back(vec);
    }
    hats::FasttextVectorData vectorizedData = { sentenceVectorColumn };

    // TODO: Remove this testing output snippets
    std::cout << "\n\n*********************************\n";
    std::cout << data[0].second[0] << std::endl;
    std::cout << vectorizedData[0].second[0] << std::endl;
    std::cout << vectorizedData[0].second[0].size() << std::endl;
    //

    hats::LabelList vectorizedLabelList;
    for (int i = 0; i < data[1].second.size(); i++) {
        std::string label = data[1].second[i];
        vectorizedLabelList.push_back(labelMap[label]);
    }

    // Create a data table for the vectorized sentence and labels
    hats::FasttextDataTable ftDataTable;
    ftDataTable.ftVectorData = vectorizedData;
    ftDataTable.labelList = vectorizedLabelList;

    classificationTrain(ftDataTable, dims, uniqueLabels.size());
}

std::vector<std::string> findUnique(hats::DataTable &data) {
    std::unordered_set<std::string> uniqueLabelsSet(data[1].second.begin(), data[1].second.end());
    std::vector<std::string> uniqueLabels(uniqueLabelsSet.begin(), uniqueLabelsSet.end());

    std::cout << "Unique Label count: " << uniqueLabels.size() << std::endl;
    return uniqueLabels;
}

void classificationTrain(hats::FasttextDataTable &data, 
                            const int &inputDims, const int &numLabels) {

    // Initialize some variables
    int epochs = 10;
    std::vector<int> topology = {inputDims, numLabels};

    hats::Net myNet(topology);

    // Train the neural network for epochs = epochs
    for (int i = 0; i < epochs; i++) {
        // TODO: Complete this code block
    }
}