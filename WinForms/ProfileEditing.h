#pragma once
#include "Profile.h"
#include <string>
using namespace std;

void SetCurrentAccess(int access);
void SaveFile(Profile profile, string fileName);
void GetProfileFromFile(string fileName);
void SetLockState(string fileName, bool lockState);