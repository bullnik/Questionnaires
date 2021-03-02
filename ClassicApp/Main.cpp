// ��������� ��� ���������� ����������
// ����� ������ ������� .exe ���� �� ����� � ���������� ��������, �� ����� VisualStudio
// ��� ������ ������� �������� ����� ���� �����, � �������� �������� ���� �������� �� �����������
// ���������� ������������ ��������� ��������� ����������� ���������� � �������� ������ ���� ������� � ����� ������ ������������

#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

#define N_DATABASE 3
char Names[N_DATABASE][50] = { "Ivan Petrov","Maria Vasilcova","Anpupij Innokentevich" };

typedef struct _Anketa
{
    char name[50];
    unsigned int age;
}Anketa;

void CreateNewDB(HANDLE hFile)
{
    Anketa a;
    DWORD nBytes;
    SetFilePointer(hFile, 0, 0, FILE_BEGIN);
    SetEndOfFile(hFile);
    for (int i = 0; i < N_DATABASE; i++)
    {
        lstrcpyA(a.name, Names[i]);
        a.age = rand() % 100;
        WriteFile(hFile, &a, sizeof(a), &nBytes, NULL);
    }
}

void ReadDB(HANDLE hFile)
{
    int n;
    Anketa a;
    DWORD nBytes;
    OVERLAPPED ol;
    printf("Enter the number starting from 1:");
    scanf_s("%d", &n, sizeof(n));
    printf("Waiting for permission...\n");
    //----------����������
    ZeroMemory(&ol, sizeof(ol));
    ol.Offset = (n - 1) * sizeof(a);
    LockFileEx(hFile, 0, NULL, sizeof(a), NULL, &ol);
    //----------�������������
    printf("Permission OK\n");
    SetFilePointer(hFile, (n - 1) * sizeof(a), NULL, FILE_BEGIN);
    ReadFile(hFile, &a, sizeof(a), &nBytes, NULL);
    printf("Name: %s\nAge: %d\n", a.name, a.age);
    printf("Press key to stop reading...\n");
    _getch();
    //----------�������������
    ZeroMemory(&ol, sizeof(ol));
    ol.Offset = (n - 1) * sizeof(a);
    UnlockFileEx(hFile, NULL, sizeof(a), NULL, &ol);
    //----------��������������
    printf("Now stop reading\n");
}

void EditDB(HANDLE hFile)
{
    int n;
    Anketa a;
    DWORD nBytes;
    OVERLAPPED ol;
    printf("Enter the number starting from 1:");
    scanf_s("%d", &n, sizeof(n));
    printf("Waiting for permission...\n");
    //----------����������
    ZeroMemory(&ol, sizeof(ol));
    ol.Offset = (n - 1) * sizeof(a);
    LockFileEx(hFile, LOCKFILE_EXCLUSIVE_LOCK, NULL, sizeof(a), NULL, &ol);
    //----------�������������
    printf("Permission OK\n");
    SetFilePointer(hFile, (n - 1) * sizeof(a), NULL, FILE_BEGIN);
    ReadFile(hFile, &a, sizeof(a), &nBytes, NULL);
    printf("Name: %s\nAge: %d\n", a.name, a.age);
    printf("<---EDIT IMITATION--->\n");
    printf("Press key to stop edit...\n");
    _getch();
    //----------�������������
    ZeroMemory(&ol, sizeof(ol));
    ol.Offset = (n - 1) * sizeof(a);
    UnlockFileEx(hFile, NULL, sizeof(a), NULL, &ol);
    //----------��������������
    printf("Now stop edit\n");
}

int main()
{
    int c = 0;
    HANDLE hFile = CreateFile(_TEXT("lab1.dat"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    while (c < 1 || c>3)
    {
        printf("Hello!\n1.Create new database\n2.Read\n3.Edit\nEnter your choice:");
        scanf_s("%d", &c, sizeof(c));
    }
    switch (c)
    {
    case 1:
        CreateNewDB(hFile);
        break;
    case 2:
        ReadDB(hFile);
        break;
    case 3:
        EditDB(hFile);
        break;
    }
    CloseHandle(hFile);
    return 0;
}