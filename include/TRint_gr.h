#ifndef _TRint_gr_
#define _TRint_gr_

#include "TRint.h"

class TRint_gr : public TRint
{
    
private:
    Int_t         fNcmd;               // command history number
    TString       fDefaultPrompt;      // default prompt: "root [%d] "
    char          fPrompt[64];         // interpreter prompt
    Bool_t        fInterrupt;          // if true macro execution will be stopped
    Bool_t        fCaughtException;    // TRint just caught an exception or signal
    TFileHandler *fInputHandler;       // terminal input handler
    
    TRint_gr(const TRint_gr&);               // not implemented
    TRint_gr& operator=(const TRint_gr&);    // not implemented
    
    void    ExecLogon();
    Long_t  ProcessRemote(const char *line, Int_t *error = 0);
    Long_t  ProcessLineNr(const char* filestem, const char *line, Int_t *error = 0);
    const char  *TranslateLine(const char* line);
    
public:
    TRint_gr(const char *appClassName, int *argc, char **argv,
             void *options = 0, int numOptions = 0, Bool_t noLogo = kFALSE);
    virtual             ~TRint_gr();
    virtual char       *GetPrompt();
    virtual const char *SetPrompt(const char *newPrompt);
    virtual void        SetEchoMode(Bool_t mode);
    virtual void        HandleException(Int_t sig);
    virtual Bool_t      HandleTermInput();
    virtual void        PrintLogo(Bool_t lite = kFALSE);
    virtual void        Run(Bool_t retrn = kFALSE);
    virtual void        Terminate(int status);
    void        Interrupt() { fInterrupt = kTRUE; }
    virtual Int_t       TabCompletionHook(char *buf, int *pLoc, std::ostream& out);
    
    TFileHandler       *GetInputHandler() { return fInputHandler; }
    
    ClassDef(TRint_gr,1);  //ROOT Interactive Application Interface
};

#endif

