'[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc
'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.9.8 生成的源代码
' 生成时间：2026年03月21日 20时16分03秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------


' 全局变量
' DimP g_hHook As HWINEVENTHOOK '已经搬到定义文件处
' DimP g_hWndCurrent As HWND      ' 当前前台窗口 '已经搬到定义文件处
' DimP g_hWndLast As HWND          ' 上一次的前台窗口（即我们需要的原窗口） '已经搬到定义文件处

' WinEvent 回调函数
Sub MyWinEventProc stdcall(ByVal hHook As HWINEVENTHOOK, ByVal Event As DWORD, ByVal hwnd As hwnd, ByVal idObject As Long, ByVal idChild As Long, ByVal dwEventThread As DWORD, ByVal dwmsEventTime As DWORD)
   If Event = &H3 Then ' EVENT_SYSTEM_FOREGROUND
      ' 更新当前窗口为新窗口
      g_hWndLast = g_hWndCurrent
      g_hWndCurrent = hwnd
   End If
End Sub

' ============================================
' 获取选中的文本，return 选中的文本
' ============================================
Function GetSelectedText() As String
    If g_hWndLast = 0 Then
        MsgBox "未能获取到原窗口，请确保已从其他程序切换到本程序。"
        Return ""
    End If

    ' 激活原窗口
    SetForegroundWindow(g_hWndLast)
    Sleep(100)

    ' 附加线程输入，获取焦点控件句柄
    Dim tid As Long = GetWindowThreadProcessId(g_hWndLast, 0)
    AttachThreadInput(GetCurrentThreadId(), tid, True)
    Dim hFocus As HWND = GetFocus()
    AttachThreadInput(GetCurrentThreadId(), tid, False)
    
    If hFocus = 0 Then
        MsgBox "无法获取目标编辑框句柄。"
        Return ""
    End If

    ' 模拟 Ctrl+C 复制
    keybd_event(VK_CONTROL, 0, 0, 0)
    keybd_event(Asc("C"), 0, 0, 0)
    keybd_event(Asc("C"), 0, KEYEVENTF_KEYUP, 0)
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0)
    Sleep(100)

    ' 读取剪贴板
    Dim selectedText As String = AfxGetClipboardText()
    If selectedText = "" Then
        MsgBox "复制失败，请检查目标窗口是否支持复制。"
        Return ""
    End If

    Return selectedText
End Function

' ============================================
' 处理结果发送回去，参数为新文本，没有return
' ============================================
Sub ReplaceSelectedText(newText As String)
    ' 将新文本写入剪贴板
    AfxSetClipboardText(newText)
    Sleep(50)

    ' 模拟 Ctrl+V 粘贴
    keybd_event(VK_CONTROL, 0, 0, 0)
    keybd_event(Asc("V"), 0, 0, 0)
    keybd_event(Asc("V"), 0, KEYEVENTF_KEYUP, 0)
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0)
    Sleep(100)
End Sub

' ============================================
' 获取选中文本GetSelectedText → 处理(原文本) → 发送ReplaceSelectedText
' ============================================
Sub ProcessSelectedText(processFunc As Function(ByVal txt As String) As String)
    Dim originalText As String = GetSelectedText()
    If originalText = "" Then Exit Sub

    Dim newText As String = processFunc(originalText)
    ReplaceSelectedText(newText)
    Form1.Label1.Caption = "原文：" & originalText & "新文：" & newText
End Sub
' ============================================
' 获取选中文本GetSelectedText → 处理(原文本,参数) → 发送ReplaceSelectedText
' ============================================
' Type ProcessFuncWithInt As Function(ByVal txt As String, ByVal i As Integer) As String '已经搬到定义文件处
Sub ProcessSelectedTextWithInt(processFunc As ProcessFuncWithInt, i As Integer)
    Dim originalText As String = GetSelectedText()
    If originalText = "" Then Exit Sub

    Dim newText As String = processFunc(originalText, i)
    If newText = originalText Then
        Exit Sub
    End If
    ReplaceSelectedText(newText)
End Sub


' 符号对的辅助函数
Function GetSymbolPair(idx As Integer, ByRef leftSym As String, ByRef rightSym As String) As Boolean
    Select Case idx
        Case 1  ' 中文双引号
            leftSym = "“"
            rightSym = "”"
        Case 2  ' 英文双引号
            leftSym = """"
            rightSym = """"
        Case 3  ' 中文单引号
            leftSym = "‘"
            rightSym = "’"
        Case 4  ' 英文单引号
            leftSym = "'"
            rightSym = "'"
        Case 5  ' 中文书名号
            leftSym = "《"
            rightSym = "》"
        Case 6  ' 英文尖括号
            leftSym = "<"
            rightSym = ">"
        Case 7  ' 中文方括号
            leftSym = "【"
            rightSym = "】"
        Case 8  ' 英文方括号
            leftSym = "["
            rightSym = "]"
        Case 9  ' 中文花括号「」
            leftSym = "「"
            rightSym = "」"
        Case 10 ' 英文花括号
            leftSym = "{"
            rightSym = "}"
        Case 11 ' 中文圆括号（）
            leftSym = "（"
            rightSym = "）"
        Case 12 ' 英文圆括号
            leftSym = "("
            rightSym = ")"
        Case Else
            Return False
    End Select
    Return True
End Function

' 符号对的实现
Function InsertSymbolPair(oldtext As WString, idx As Integer) As String
   Dim leftSym As String, rightSym As String
   If Not GetSymbolPair(idx, leftSym, rightSym) Then
      Return oldtext ' 获取失败时，返回原文本，不做修改
   End If
   Return leftSym & oldtext & rightSym
End Function


' 自动检测并转换简繁
Function ConvertChinese(oldtext As String) As String
    If Len(oldtext) = 0 Then Return ""

    ' 1. 将输入文本转换为宽字符串（指定简体中文代码页，确保正确）
    Dim As String wideInput = StrToWStr(oldtext, 936)
    If Len(wideInput) = 0 Then Return ""

    ' 2. 获取宽字符指针和字符个数
    Dim As WString Ptr pInput = Cast(WString Ptr, StrPtr(wideInput))
    Dim As Integer srcLen = Len(wideInput) \ 2   ' 每个宽字符占2字节

    ' 3. 分别获取转换为简体和繁体的目标字符数
    Dim As Integer simpLen = LCMapStringW(LOCALE_SYSTEM_DEFAULT, LCMAP_SIMPLIFIED_CHINESE, _
        pInput, srcLen, NULL, 0)
    Dim As Integer tradLen = LCMapStringW(LOCALE_SYSTEM_DEFAULT, LCMAP_TRADITIONAL_CHINESE, _
        pInput, srcLen, NULL, 0)

    If simpLen = 0 Or tradLen = 0 Then Return ""   ' 转换失败

    ' 4. 分配缓冲区并执行转换
    Dim As String wideSimp = Space(simpLen * 2)   ' 每个宽字符占2字节
    Dim As String wideTrad = Space(tradLen * 2)
    LCMapStringW(LOCALE_SYSTEM_DEFAULT, LCMAP_SIMPLIFIED_CHINESE, _
        pInput, srcLen, Cast(LPWSTR, StrPtr(wideSimp)), simpLen)
    LCMapStringW(LOCALE_SYSTEM_DEFAULT, LCMAP_TRADITIONAL_CHINESE, _
        pInput, srcLen, Cast(LPWSTR, StrPtr(wideTrad)), tradLen)

    ' 5. 比较原文本与两个转换结果，确定方向
    Dim As Integer sameWithSimp = 0, sameWithTrad = 0
    For i As Integer = 0 To srcLen - 1
        If pInput[i] = Cast(WString Ptr, StrPtr(wideSimp))[i] Then sameWithSimp += 1
        If pInput[i] = Cast(WString Ptr, StrPtr(wideTrad))[i] Then sameWithTrad += 1
    Next

    ' 6. 根据相似度返回另一种形式
    Dim As WString Ptr resultW = NULL
    If sameWithSimp >= sameWithTrad Then
        resultW = Cast(WString Ptr, StrPtr(wideTrad))
    Else
        resultW = Cast(WString Ptr, StrPtr(wideSimp))
    End If

    ' 7. 将结果宽字符串转换回普通字符串（指定简体中文代码页）
    Return wStrToStr(resultW, 0, 936)
End Function