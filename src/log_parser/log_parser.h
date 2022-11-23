// Generated by Bisonc++ V6.04.04 on Fri, 07 Oct 2022 23:03:09 +0200

#ifndef LogParser_h_included
#define LogParser_h_included

// $insert baseclass
#include "log_parserbase.h"
// $insert scanner.h
#include "../log_scanner/log_scanner.h"

#include "../log_data_modifier/log_data_modifier.h"
#include "../log_scanner/log_scanner.h"
#include <fstream>
#include <filesystem>

class LogParser : public LogParserBase {
    
    // $insert scannerobject
    LogScanner d_scanner;
    std::string const& d_matched;
    LogDataModifier          d_logDataModifier;
    std::unique_ptr<LogData> d_ret;

public:
    LogParser(std::filesystem::path const& path, HeaderData const& headerData);
    int                      parse();
    std::unique_ptr<LogData> gen();

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
