#pragma once
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

string GetCurrentDirectory();

bool IsDatabaseExists();

vector<string> GetProfiles();