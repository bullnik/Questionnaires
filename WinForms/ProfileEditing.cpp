#include "ProfileEditing.h"

int CurrentAccess = 0;
void SetCurrentAccess(int access) // 1 - write, 0 - read
{
	if (access < 1)
	{
		CurrentAccess = 0;
	}
	else
	{
		CurrentAccess = 1;
	}
}
void SaveFile(Profile profile, string fileName)
{

}
void GetProfileFromFile(string fileName)
{

}
void SetLockState(string fileName, bool lockState)
{

}