//          Copyright (C) 2022 PsiMasTho (1cbb875@gmail.com)
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include "header_data.h"

#include <algorithm>
#include <stdexcept> // runtime_error

using namespace std;

HeaderData::HeaderData()
    : d_vars{}
    , d_attrs{}
    , d_lastVarItr{d_vars.end()}
{ }

void HeaderData::addVar(string const& varName)
{
    auto const [itr, success] = d_vars.insert({varName, {}});
    if(!success)
        throw runtime_error("Failed declaring variable: "s + varName);
    else
        d_lastVarItr = itr;
}

void HeaderData::addAttr(string const& attrName)
{
    d_attrs.addAttr(attrName);
}

void HeaderData::addRegexToLastAttr(std::string const& expr)
{
    d_attrs.addRegexToLastAttr(expr);
}

void HeaderData::addAttrToLastVar(std::string const& attrName)
{
    if(d_lastVarItr == d_vars.end())
        throw runtime_error("Attemtpting to add attribute without a variable: "s + attrName);

    d_lastVarItr->second[d_attrs.getIdx(attrName)] = true;
}

bool HeaderData::doesVarHaveAttr(std::string const& varName, std::string const& attrName) const
{
    auto const itr = d_vars.find(varName);
    if(itr == d_vars.end())
        throw runtime_error("Unknown variable queried: "s + varName);
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
    for(auto [varName, idxBits] : d_vars)
    {
        out << "VAR: " << varName << '\n';
        out << "\tATTRS: " << idxBits.to_string() << '\n';
    }
}