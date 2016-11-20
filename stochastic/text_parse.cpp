#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "text_parse.h"

using std::ifstream;
using std::cout;
using std::string;
using std::cin;
using std::cerr;
using std::endl;

//parse input text
void Text_parse::Text_parse(string fileName) //TODO add input file parameter
{
    ifstream inFile;
    ifstream.open(fileName);

    if(inFile.fail()) //check for error in file reading
    {
        cerr << "Error opening parameter file for simulation" << endl;
        exit(1); //exit the program
    }
    while(!inFile.eof()) {

        string pname;
        inFile >> pname;
        if (pname == "diseaseName")
        {
          string s;
          inFile >> s;
          Text_parse::setDiseaseName(s);
        }
        else if (pname == "diseaseModel")
        {
          string s;
          inFile >> s;
          Text_parse::setDiseaseModel(s);
        }
        else if (pname == "alpha")
        {
          int x;
          inFile >> x;
          Text_parse::setAlpha(x);
        }
        else if (pname == "beta")
        {
          int x;
          inFile >> x;
          Text_parse::setBeta(x);
        }
        else if (pname == "mortality")
        {
          int x;
          inFile >> x;
          Text_parse::setMortality(x);
        }
        else if (pname == "range")
        {
          int x;
          inFile >> x;
          Text_parse::setRange(x);
        }
        else if (pname == "pop_width")
        {
          int x;
          inFile >> x;
          Text_parse::setPop_width(x);
        }
        else if (pname == "pop_height")
        {
          int x;
          inFile >> x;
          Text_parse::setPop_height(x);
        }
        else if (pname == "sim_len")
        {
          int x;
          inFile >> x;
          Text_parse::setSim_len(x);
        }
        else if (pname == "seed")
        {
          long l;
          inFile >> l;
        }
        else //incorrect input
        {
            cout << "Input file error detected." << endl;
        }
    }
}

const string &Text_parse::getDiseaseName() const {
    return diseaseName;
}

void Text_parse::setDiseaseName(const string &diseaseName) {
    Text_parse::diseaseName = diseaseName;
}

const string &Text_parse::getDiseaseModel() const {
    return diseaseModel;
}

void Text_parse::setDiseaseModel(const string &diseaseModel) {
    Text_parse::diseaseModel = diseaseModel;
}

int Text_parse::getAlpha() const {
    return alpha;
}

void Text_parse::setAlpha(int alpha) {
    Text_parse::alpha = alpha;
}

int Text_parse::getBeta() const {
    return beta;
}

void Text_parse::setBeta(int beta) {
    Text_parse::beta = beta;
}

int Text_parse::getMortality() const {
    return mortality;
}

void Text_parse::setMortality(int mortality) {
    Text_parse::mortality = mortality;
}

int Text_parse::getRange() const {
    return range;
}

void Text_parse::setRange(int range) {
    Text_parse::range = range;
}

int Text_parse::getPop_width() const {
    return pop_width;
}

void Text_parse::setPop_width(int pop_width) {
    Text_parse::pop_width = pop_width;
}

int Text_parse::getPop_height() const {
    return pop_height;
}

void Text_parse::setPop_height(int pop_height) {
    Text_parse::pop_height = pop_height;
}

int Text_parse::getSim_len() const {
    return sim_len;
}

void Text_parse::setSim_len(int sim_len) {
    Text_parse::sim_len = sim_len;
}

long Text_parse::getSeed() const {
    return seed;
}

void Text_parse::setSeed(long seed) {
    Text_parse::seed = seed;
}
