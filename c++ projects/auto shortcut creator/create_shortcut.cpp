#include <windows.h>
#include <shlobj.h>
#include <iostream>
using namespace std;

int main()
{
    CoInitialize(NULL);
    IShellLink* pShellLink = NULL;
    HRESULT hres;
    hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_ALL,
                   IID_IShellLink, (void**)&pShellLink);
    cout << hex << hres << endl;
    if (SUCCEEDED(hres))
    {
        pShellLink->SetPath("C:\\Python27\\python.exe");  // Path to the object we are referring to
        pShellLink->SetDescription("The Python shell");
        pShellLink->SetIconLocation("C:\\Python27\\python.exe", 0);
    
        IPersistFile *pPersistFile;
        hres = pShellLink->QueryInterface(IID_IPersistFile, (void**)&pPersistFile);
        
        if (SUCCEEDED(hres))
        {
            hres = pPersistFile->Save(L"C:\\test.lnk", TRUE);
        
            pPersistFile->Release();
        }
        else
        {
            cout << "Error 2" << endl;
            return 2;
        }
        pShellLink->Release();
    }
    else
    {
        cout << "Error 1" << endl;
        return 1;
    }
    
    return 0;
}