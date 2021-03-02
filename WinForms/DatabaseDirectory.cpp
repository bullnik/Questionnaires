#include "DatabaseDirectory.h"

string GetCurrentDirectory()
{
    string output;
    TCHAR path[MAX_PATH];
    GetModuleFileName(NULL, path, MAX_PATH);
    return output;
}

bool IsDatabaseExists()
{
    string path = GetCurrentDirectory();
    path += "/Profiles";
    std::wstring stemp = wstring(path.begin(), path.end());
    LPCWSTR sw = stemp.c_str();
    DWORD dwAttrib = GetFileAttributes(sw);
    return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
        (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

vector<string> GetProfiles()
{
    vector<string> a;
    return a;
}