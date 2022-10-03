#include "header_data.h"

using namespace std;

#include <algorithm>

HeaderData::HeaderData()
:
    d_attrs{},
    d_vars{},
    d_lastVarItr{d_vars.end()}
{}

void HeaderData::addVar(string const& varName)
{
    auto const [itr, success] = d_vars.insert({varName, {}});
    if (!success)
        throw "Bad header file";
    else
        d_lastVarItr = itr;
}

void HeaderData::addAttr(string const& attrName)
{
    d_attrs.push_back(attrName);
}

void HeaderData::addAttr(std::string const& attrName, std::regex attrRegex)
{
    d_attrs.push_back(attrName, attrRegex);
}

void HeaderData::addAttrToLastVar(std::string const& attrName)
{
    if (d_lastVarItr == d_vars.end())
        throw "Attemtpting to add attribute without a variable";

    d_lastVarItr->second[d_attrs.getIdx(attrName)] = true;
}

bool HeaderData::doesVarHaveAttr(std::string const& varName, std::string const& attrName)
{
    auto const itr = d_vars.find(varName);
    if (itr == d_vars.end())
        throw "Unknown variable queried";
    else
        return itr->second[d_attrs.getIdx(attrName)];
}

Attributes const& HeaderData::getAttributes() const
{
    return d_attrs;
}

#include <ostream>
void HeaderData::debugPrint(ostream& out) const
{
    for (auto [varName, idxBits] : d_vars)
    {
        out << "VAR: " << varName << '\n';
        out << "\tATTRS: " << idxBits.to_string() << '\n';
    }
}