// Generated by Flexc++ V2.11.01 on Fri, 07 Oct 2022 22:01:53 +0200

#ifndef HeaderScanner_H_INCLUDED_
#define HeaderScanner_H_INCLUDED_

// $insert baseclass_h
#include "header_scannerbase.h"

#include <filesystem>
#include "header_token_enums.h"

// $insert classHead
class HeaderScanner: public HeaderScannerBase
{
    public:
        HeaderScanner(std::filesystem::path const &infile);
        
        // $insert lexFunctionDecl
        int lex();

    private:
        int lex_();
        int executeAction_(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum_ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.
};

inline HeaderScanner::HeaderScanner(std::filesystem::path const &infile)
:
    HeaderScannerBase(infile, "-")
{}

// $insert inlineLexFunction
inline int HeaderScanner::lex()
{
    return lex_();
}

inline void HeaderScanner::preCode() 
{
    // optionally replace by your own code
}

inline void HeaderScanner::postCode([[maybe_unused]] PostEnum_ type) 
{
    // optionally replace by your own code
}

inline void HeaderScanner::print() 
{
    print_();
}


#endif // HeaderScanner_H_INCLUDED_

