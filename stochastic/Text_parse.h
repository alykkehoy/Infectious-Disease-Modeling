#ifndef GUARD_TEXT_PARSE_H
#define GUARD_TEXT_PARSE_H

#include <string>

using std::string;

class Text_parse
{
private:
    //disease parameters //
    string diseaseName, diseaseModel;
    int alpha, beta, mortality, range, pop_width, pop_height, sim_len;
    long seed;

public:
    Text_parse(string fileName);
    //getters and setters //
    const string &getDiseaseName() const;
    void setDiseaseName(const string &diseaseName);

    const string &getDiseaseModel() const;
    void setDiseaseModel(const string &diseaseModel);

    int getAlpha() const;
    void setAlpha(int alpha);

    int getBeta() const;
    void setBeta(int beta);

    int getMortality() const;
    void setMortality(int mortality);

    int getRange() const;
    void setRange(int range);

    int getPop_width() const;
    void setPop_width(int pop_width);

    int getPop_height() const;
    void setPop_height(int pop_height);

    int getSim_len() const;
    void setSim_len(int sim_len);

    long getSeed() const;
    void setSeed(long seed);

};
#endif //GUARD_TEXT_PARSE_H
