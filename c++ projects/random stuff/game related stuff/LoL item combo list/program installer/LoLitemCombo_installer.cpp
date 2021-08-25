#include "CreateShortCut.h"

CreateShortCut csc;
ih.CreateLinkFileBase(
    "C:\\somedirectory\\afile.exe",
    CSC_DESKTOP,
    "The Comment",
    MAKEWORD(0x41, HOTKEYF_ALT + HOTKEYF_CONTROL),
    "-help"
    );