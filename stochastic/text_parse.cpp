#include <sstream>
#include <string>
#include <iostream>
#include "text_parse.h"

using std::istringstream;
using std::cout;
using std::string;
using std::cin;

//parse input text
void Text_parse::Text_parse(string iline) //TODO add input file parameter
{
  while(getline(cin, iline))
  {
    istringstream iss(iline);
    string pname;
    auto value;
    iss >> pname;
    iss >> value;

    if(pname == "diseaseName")
    {

    }
    else if(pname == "diseaseModel")
    {

    }
    else if(pname == "alpha")
    {

    }
    else if(pname == "beta")
    {

    }
    else if(pname == "mortality")
    {

    }
    else if(pname == "range")
    {

    }
    else if(pname == "pop_width")
    {

    }
    else if(pname == "pop_height")
    {

    }
    else if(pname == "sim_len")
    {

    }
    else if(pname == "seed")
    {

    }
    else //incorrect input
    {
      cout << "Incorrect input, please check parameters";
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
