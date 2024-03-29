// Generated by Bisonc++ V6.04.04 on Fri, 07 Oct 2022 23:06:16 +0200

#ifndef HeaderParser_h_included
#define HeaderParser_h_included

// $insert baseclass
#include "header_parserbase.h"
// $insert scanner.h
#include "../header_scanner/header_scanner.h"

#include "../header_data/header_data.h"
#include <filesystem>
#include <fstream>
#include <iosfwd>

class HeaderParser : public HeaderParserBase {
    
    // $insert scannerobject
    HeaderScanner d_scanner;
    std::string const& d_matched;
    std::unique_ptr<HeaderData> d_ret;

public:
    explicit HeaderParser(std::filesystem::path const &path);
    int                         parse();
    std::unique_ptr<HeaderData> gen();

private:
    void error(); // called on (syntax) errors
    int  lex(); // returns the next token from the
        // lexical scanner.
    void print(); // use, e.g., d_token, d_loc
    void exceptionHandler(std::exception const& exc);

    // support functions for parse():
    void executeAction_(int ruleNr);
    void errorRecovery_();
    void nextCycle_();
    void nextToken_();
    void print_();
};

#endif
