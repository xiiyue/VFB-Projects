'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.9.8 生成的源代码
' 生成时间：2026年03月21日 20时16分03秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------


Function gFLY_GetFontHandles(mFont As String) As HFONT '由字体字符，返回字体句柄
   Dim As Long i,u=UBound(gFLY_FontNames),aa =-1
   If u > -1 Then
      For i = 0 To u
         If gFLY_FontNames(i) = mFont Then
            Return gFLY_FontHandles(i)
         End If
      Next
   End If
   aa = u + 1
   ReDim Preserve gFLY_FontNames(aa), gFLY_FontHandles(aa)
   gFLY_FontNames(aa) = mFont
   Dim pvv(5) As String, ff as Long, zz as String = mFont
   for i = 0 to 5
      ff = instr(zz, ",")
      if ff = 0 then
         pvv(i) = Trim(zz)
         exit for
      end if
      pvv(i) = Trim(.left(zz, ff -1))
      zz = Mid(zz, ff + 1)
   next
   if valint(pvv(1)) = 0 then pvv(1) = "9"
   If Len(pvv(0)) = 0 Then pvv(0) = "SimSun" '宋体
   gFLY_FontHandles(aa) = AfxCreateFont(pvv(0), ValInt(pvv(1)), -1, IIf(ValInt(pvv(2)) = 0, FW_NORMAL, FW_BOLD), ValInt(pvv(3)), ValInt(pvv(4)), ValInt(pvv(5)))

   If gFLY_FontHandles(aa) = 0 Then  '创建失败
      aa -= 1
      ReDim Preserve gFLY_FontNames(aa), gFLY_FontHandles(aa)
      Return 0
   End If
   Function = gFLY_FontHandles(aa)
End Function
Function GetCodeColorGDI(coColor As Long, defaultColor As Long = -1) As Long  '把控件特殊颜色值，转换为 GDI 色  ,返回-1 为不使用或默认
   '格式：&H01020304  02.03.04为7F时，01值0到30是系统色（25为不使用）其它时候是A通道，GDI+需要 02 04 里值对调
  If (&H00FFFFFF And coColor) = &H7F7F7F Then
      Dim f As Long = Cast(UInteger, (&HFF000000 And coColor)) Shr 24
      If f = 25 Then Return defaultColor   '不使用或默认值 
      If f < 31 Then 
          Return GetSysColor(f)  
      End If  
  End If
  Function = (&H00FFFFFF And coColor) '去掉 A 通道
End Function
Function GetCodeColorGDIplue(coColor As Long, defaultColor As Long = 0) As Long  '把控件特殊颜色值，转换为 GDI+ 色  ,返回0 为不使用或默认
 '格式：&H01020304  02.03.04为7F时，01值0到30是系统色（25为不使用）其它时候是A通道，GDI+需要 02 04 里值对调  
  Dim tColor As Long = coColor 
  If (&H00FFFFFF And coColor) = &H7F7F7F Then
      Dim f As Long = Cast(UInteger, (&HFF000000 And coColor)) Shr 24
      If f = 25 Then Return defaultColor  ' 不使用或默认值 
      If f < 31 Then 
          tColor = GetSysColor(f) Or &HFF000000 '增加 A通道，不透明，不然是全透明  
      End If  
  End If 
  '因为保存的是GDI 的颜色，GDI+ 需要调换
  Dim As UInteger c1 =(&H00FF0000 And tColor),c2 = (&H000000FF And tColor) ,c3 =(&HFF00FF00 And tColor)
  c1 Shr= 16
  c2 Shl= 16 
  Function = c1 Or c2 Or c3  
End Function
Function FLY_ResourceToIcon(ByVal ResImg As String) As HICON '资源获取图标句柄
   Dim nIcon As HICON
   Dim ffi   As Long = InStr(ResImg ,"|")
   if ffi > 0 Then ResImg = Mid(ResImg ,ffi + 1)
   if Left(ResImg ,7) = "BITMAP_" Then
      Dim nBmp As HBITMAP = LoadImageA(app.hInstance ,ResImg ,IMAGE_BITMAP ,0 ,0 ,LR_DEFAULTCOLOR)
      Dim po   As ICONINFO
      po.fIcon    = TRUE
      po.hbmColor = nBmp
      po.hbmMask  = nBmp
      nIcon       = CreateIconIndirect(@po)
      DeleteObject nBmp
   Elseif Left(ResImg ,5) = "ICON_" Or ResImg = "AAAAA_APPICON" Then
      nIcon = LoadImageA(app.hInstance ,ResImg ,IMAGE_ICON ,0 ,0 ,LR_DEFAULTCOLOR) '从资源里加载图标
   Else 
      nIcon = AfxGdipIconFromRes(App.hInstance ,ResImg)
   End if
   Function = nIcon
End Function
' =====================================================================================
' 根据Jose Roca的代码
' 为窗口的整个客户区域创建标准工具提示。
' 参数:
' - hwnd = 窗口句柄
' - strTooltipText = 工具提示文本
' - bBalloon = 气球提示 (TRUE or FALSE)
' 返回值:
'   工具提示控件的句柄
' =====================================================================================
Function FF_AddTooltip(hWndForm As hWnd, strTooltipText As Wstring, bBalloon As Long, X As Long = 0, Y As Long = 0, W As Long = 0, H As Long = 0) As hWnd
   
   If hWndForm = 0 Then Exit Function
   
   Dim hwndTT AS HWND
   Dim dwStyle As Long
   
   dwStyle = WS_POPUP OR TTS_NOPREFIX OR TTS_ALWAYSTIP
   IF bBalloon THEN dwStyle = dwStyle OR TTS_BALLOON
   hwndTT = CreateWindowExW(WS_EX_TOPMOST, "tooltips_class32", "", dwStyle, 0, 0, 0, 0, 0, Cast(HMENU, NULL), 0, ByVal Cast(LPVOID, NULL))
   
   If hwndTT = 0 Then Exit Function
   'SetWindowPos(hwndTT, null, 100, 100, 0, 0,  SWP_NOSIZE Or SWP_NOZORDER Or SWP_NOACTIVATE)
   
   Dim tti As TTTOOLINFOW
   tti.cbSize = SizeOf(tti)
   tti.uFlags = TTF_SUBCLASS
   tti.hWnd = hWndForm
   tti.hinst = GetModuleHandle(ByVal NULL)
   
   GetClientRect(hWndForm, Varptr(tti.Rect))
   tti.Rect.Left = x
   tti.rect.top = y
   if w > 0 then tti.rect.Right = x + w
   if h > 0 then tti.rect.bottom = y + h
   '// 字符串的长度不能超过80个字符，包括终止的空值
   tti.uId = 0
   Dim ff As Long = InStr(strTooltipText, WChr(13, 10) )
   if ff Then
      tti.lpszText =Cast(LPWSTR, Cast(UInteger, @strTooltipText) + ff * 2 + 2) 
      SendMessageW hwndTT, TTM_ADDTOOLW, 0, Cast(LPARAM, Varptr(tti))
      Dim nw As WString * 100 = Left(strTooltipText,ff-1)
      SendMessageW hwndTT, TTM_SETTITLEW, 0, Cast(LPARAM, @nw)
   Else
      tti.lpszText = @strTooltipText
      SendMessageW hwndTT, TTM_ADDTOOLW, 0, Cast(lParam, Varptr(tti))
   End if

   
   Function = hwndTT
   
End Function
Function FLY_DoMessagePump(pWindow As CWindow Ptr, ByVal ShowModalFlag As Long, ByVal hWndForm As HWND, ByVal hWndParent As HWND, ByVal nFormShowState As Long, ByVal IsMDIForm As Long) As HWND
   '如果这是一个MDI子窗体，那么它不能显示为模态。
   If (GetWindowLongPtr(hWndForm, GWL_EXSTYLE) And WS_EX_MDICHILD) = WS_EX_MDICHILD Then ShowModalFlag = False
   If (GetWindowLongPtr(hWndForm, GWL_EXSTYLE) And WS_EX_NOACTIVATE) = WS_EX_NOACTIVATE And nFormShowState = SW_SHOWNORMAL Then nFormShowState = SW_SHOWNOACTIVATE
   If ShowModalFlag = True Then '模式窗口，进入消息循环处理
      '确定活动控件的顶层窗口
      While (GetWindowLongPtr(hWndParent, GWL_STYLE) And WS_CHILD) <> 0
         hWndParent = GetParent(hWndParent)
         If IsWindow(hWndParent) = 0 Then Exit While
         If (GetWindowLongPtr(hWndParent, GWL_EXSTYLE) And WS_EX_MDICHILD) <> 0 Then Exit While
      Wend
      
      '为父窗体禁用鼠标和键盘输入
      If IsWindow(hWndParent) Then EnableWindow(hWndParent, False)
      ShowWindow(hWndForm, nFormShowState)
      UpdateWindow(hWndForm)
      '主消息循环：
      Dim uMsg        As MSG
      Dim zTempString As zString * MAX_PATH
      Dim hWndP       As HWND = pWindow->hWindow
      Dim HACCEL      As HACCEL
      '获取系统版本号
      Dim vi As OSVERSIONINFO, bil As Long
      vi.dwOsVersionInfoSize = SizeOf(OSVERSIONINFO)
      GetVersionEx @vi
      If vi.dwPlatformId = VER_PLATFORM_WIN32_NT Then
         bil = vi.dwMajorVersion * 10 + vi.dwMinorVersion
      End If
      Dim moua As Point, mouh As hWnd
      
      '消息循环开始
      Do While GetMessage(@uMsg, NULL, 0, 0)
         If FF_PUMPHOOK(uMsg) = 0 Then
            If GetForegroundWindow() =hWndP  Then 
               HACCEL = pWindow->AccelHandle
            Else
               HACCEL = 0
            End If    
             '处理菜单命令的快捷键
            If (HACCEL = 0) OrElse (TranslateAcceleratorW(hWndP, HACCEL, @uMsg)) = 0 Then '
               If IsMDIForm = True Then
                  If TranslateMDISysAccel(hWndP, @uMsg) <> 0 Then Continue Do
               End If
               If bil < 62 AndAlso uMsg.message = WM_MOUSEWHEEL Then
                  'WIn7 鼠标滚轮只在当前焦点窗口，WIn10系统是鼠标在什么窗口上滚轮在什么窗口
                  GetCursorPos(@moua)
                  mouh = WindowFromPoint(moua)
                  If mouh <> uMsg.hWnd Then
                     PostMessage(mouh, WM_MOUSEWHEEL, uMsg.wParam, uMsg.lParam)
                     Continue Do
                  End If
               End If
               If IsDialogMessageW(hWndP, @uMsg) = 0 Then
                  TranslateMessage @uMsg
                  DispatchMessage @uMsg
               End If
            End If
         End If
         If IsWindow(hWndForm) = False Then Exit Do ' 如果窗口被销毁，则退出模态消息循环（重要）。
      Loop
      Function        = Cast(hWnd, Cast(LONG_PTR, App.ReturnValue))
      App.ReturnValue = 0
   Else
      ShowWindow hWndForm, nFormShowState
      Function = hWndForm
   End If
End Function

Sub FLY_VFB_Layout_hWndForm(hWndForm As HWND) '处理控件布局
   DIM rcParent AS RECT, rcChild AS RECT
   DIM x        AS LONG, y       AS LONG, xWidth AS LONG, yHeight AS LONG
   GetClientRect(hWndForm, @rcParent)
   rcParent.Right  = DpiUnScaleI(rcParent.Right) ' 为自动响应DPI，全部调整为 100%DPI 时的数值
   rcParent.Bottom = DpiUnScaleI(rcParent.Bottom)
   '真实控件
   Dim zWnd  As HWND = GetWindow(hWndForm, GW_CHILD)
   Dim nHDWP As HDWP = BeginDeferWindowPos(1) '同时更新控件位置
   While zWnd
      Dim fp As FormControlsPro_TYPE Ptr = vfb_Get_Control_Ptr(zWnd)
      If fp <> 0 AndAlso fp->anchor > 0 Then
         GetWindowRect(zWnd, @rcChild)
         FLY_VFB_Layout_Handle(fp, rcParent.Right, rcParent.Bottom, DpiUnScaleI(rcChild.Right - rcChild.Left), DpiUnScaleI(rcChild.Bottom - rcChild.Top), x, y, xWidth, yHeight)
         fp->nLeft   = x
         fp->nTop    = y
         fp->nWidth  = xWidth
         fp->nHeight = yHeight
         nHDWP       = DeferWindowPos(nHDWP, zWnd, 0, DpiScaleI(x), DpiScaleI(y), DpiScaleI(xWidth), DpiScaleI(yHeight), SWP_NOZORDER Or SWP_NOACTIVATE)
      End If
      zWnd = GetWindow(zWnd, GW_HWNDNEXT)
   Wend
   
   '虚拟控件
   Dim fp As FormControlsPro_TYPE Ptr = vfb_Get_Control_Ptr(hWndForm)
   While fp '
      if fp->anchor > 0 Then
         if fp->CtrlFocus Then '非 CW创建的控件，因为不 fp 指针不内置入窗口，真实控件查不到
            GetWindowRect(fp->CtrlFocus, @rcChild)
            FLY_VFB_Layout_Handle(fp, rcParent.Right, rcParent.Bottom, DpiUnScaleI(rcChild.Right - rcChild.Left), DpiUnScaleI(rcChild.Bottom - rcChild.Top), x, y, xWidth, yHeight)
            nHDWP = DeferWindowPos(nHDWP, fp->CtrlFocus, 0, DpiScaleI(x), DpiScaleI(y), DpiScaleI(xWidth), DpiScaleI(yHeight), SWP_NOZORDER Or SWP_NOACTIVATE)
         Else
            FLY_VFB_Layout_Handle(fp, rcParent.Right, rcParent.Bottom, fp->nWidth, fp->nHeight, x, y, xWidth, yHeight)
         End if
         fp->nLeft   = x
         fp->nTop    = y
         fp->nWidth  = xWidth
         fp->nHeight = yHeight
      End if
      Dim sfp As FormControlsPro_TYPE Ptr = fp->VrControls
      fp = sfp
   Wend
   EndDeferWindowPos nHDWP
End Sub

Sub FLY_VFB_Layout_Handle(fp As FormControlsPro_TYPE Ptr, pWidth As Long, pHeight As Long, nWidth As Long, nHeight As Long, ByRef x As Long, ByRef y As Long, ByRef xWidth As Long, ByRef yHeight As Long)
   '处理控件布局
   x = 0 : y = 0 : xWidth = 0 : yHeight = 0
   If fp->nParentFormWidth = 0 AndAlso fp->nParentFormHeight = 0 Then
      '等比例缩放由QQ2719379524（Cy）提供
      fp->nParentFormWidth  = pWidth
      fp->nParentFormHeight = pHeight
      fp->nOrgWidth         = nWidth
      fp->nOrgHeight        = nHeight
      fp->nOrgLeft          = fp->nLeft
      fp->nOrgTop           = fp->nTop
   End If   
   Select Case fp->anchor
      Case 0 'AFX_ANCHOR_NONE
         x       = fp->nLeft
         y       = fp->nTop
         xWidth  = nWidth
         yHeight = nHeight
      Case 1 'AFX_ANCHOR_WIDTH
         x       = fp->nLeft
         y       = fp->nTop
         xWidth  = max(pWidth - fp->nLeft - fp->nRight, 0)
         yHeight = nHeight
      CASE 2 'AFX_ANCHOR_RIGHT
         x       = pWidth - nWidth - fp->nRight
         y       = fp->nTop
         xWidth  = nWidth
         yHeight = nHeight
      CASE 3 'AFX_ANCHOR_CENTER_HORZ
         x       = (pWidth \ 2) + fp->centerX
         y       = fp->nTop
         xWidth  = nWidth
         yHeight = nHeight
      CASE 4 'AFX_ANCHOR_HEIGHT
         x       = fp->nLeft
         y       = fp->nTop
         xWidth  = nWidth
         yHeight = MAX(pHeight - fp->nTop - fp->nBottom, 0)
      CASE 5 'AFX_ANCHOR_HEIGHT_WIDTH
         x       = fp->nLeft
         y       = fp->nTop
         xWidth  = MAX(pWidth - fp->nLeft - fp->nRight, 0)
         yHeight = MAX(pHeight - fp->nTop - fp->nBottom, 0)
      CASE 6 'AFX_ANCHOR_HEIGHT_RIGHT
         x       = pWidth - nWidth - fp->nRight
         y       = fp->nTop
         xWidth  = nWidth
         yHeight = MAX(pHeight - fp->nTop - fp->nBottom, 0)
      CASE 7 'AFX_ANCHOR_BOTTOM
         x       = fp->nLeft
         y       = pHeight - fp->nBottom - nHeight
         xWidth  = nWidth
         yHeight = nHeight
      CASE 8 'AFX_ANCHOR_BOTTOM_WIDTH
         x       = fp->nLeft
         y       = pHeight - fp->nBottom - nHeight
         xWidth  = MAX(pWidth - fp->nLeft - fp->nRight, 0)
         yHeight = nHeight
      CASE 9 'AFX_ANCHOR_BOTTOM_RIGHT
         x       = pWidth  - nWidth      - fp->nRight
         y       = pHeight - fp->nBottom - nHeight
         xWidth  = nWidth
         yHeight = nHeight
      CASE 10 'AFX_ANCHOR_CENTER_HORZ_BOTTOM
         x       = (pWidth \ 2) + fp->centerX
         y       = pHeight      - fp->nBottom - nHeight
         xWidth  = nWidth
         yHeight = nHeight
      Case 11 'AFX_ANCHOR_CENTER_VERT
         x       = fp->nLeft
         y       = (pHeight \ 2) + fp->centerY
         xWidth  = nWidth
         yHeight = nHeight
      CASE 12 'AFX_ANCHOR_CENTER_VERT_RIGHT
         x       = pWidth        - nWidth - fp->nRight
         y       = (pHeight \ 2) + fp->centerY
         xWidth  = nWidth
         yHeight = nHeight
      CASE 13 'AFX_ANCHOR_CENTER
         x       = (pWidth \ 2)  + fp->centerX
         y       = (pHeight \ 2) + fp->centerY
         xWidth  = nWidth
         yHeight = nHeight
      Case 14
         '等比例缩放由QQ2719379524（Cy）提供
         Dim As Double wPercent, hPercent
         wPercent = pWidth        / fp->nParentFormWidth
         hPercent = pHeight       / fp->nParentFormHeight
         x        = fp->nOrgLeft  * wPercent
         y        = fp->nOrgTop   * hPercent
         xWidth   = fp->nOrgWidth * wPercent
         yHeight  = fp->nOrgHeight *hPercent         
   END SELECT
End Sub





'[SourceDB:0-171244]
'在对话框中显示消息(兼容VB6)，等待用户单击按钮，并返回一个 Integer 告诉用户单击哪一个按钮。（选项太多，建议用【工具】菜单里【对话框编辑器】自动产生代码）
'按钮 MB_OK MB_OKCANCEL MB_YESNOCANCEL MB_YESNO MB_RETRYCANCEL MB_ABORTRETRYIGNORE MB_CANCELTRYCONTINUE
'图标 MB_ICONERROR MB_ICONQUESTION MB_ICONWARNING MB_ICONINFORMATION
'默认按钮 MB_DEFBUTTON1 MB_DEFBUTTON2 MB_DEFBUTTON3 MB_DEFBUTTON4
'模态对话框 MB_APPLMODAL MB_SYSTEMMODAL MB_TASKMODAL  
'帮助 MB_HELP
'返回 IDOK IDCANCEL IDYES IDNO IDCANCEL IDRETRY IDCANCEL IDABORT IDRETRY IDIGNORE IDTRYAGAIN IDCONTINUE
Function MsgBox Overload(CH_E68F90E7A4BAE69687E69CAC_ As WString , CH_E98089E9A1B9_ As ULong = MB_OK, CH_E6A087E9A298E69687E69CAC_ As WString = App.ProductName , CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND = AfxGetHwndFromPID(GetCurrentProcessId)) As Integer
   'VB兼容模式
'   PrintA "VB兼容模式"
   Function = MessageBox(CH_E788B6E7AA97E58FA3E58FA5E69F84_, CH_E68F90E7A4BAE69687E69CAC_, CH_E6A087E9A298E69687E69CAC_, CH_E98089E9A1B9_)
End Function
Function MsgBox Overload(CH_E68F90E7A4BAE69687E69CAC_ As String , CH_E98089E9A1B9_ As ULong = MB_OK, CH_E6A087E9A298E69687E69CAC_ As String = App.ProductName , CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND = AfxGetHwndFromPID(GetCurrentProcessId)) As Integer
   'VB兼容模式
'   PrintA "VB兼容模式"
   Function = MessageBox(CH_E788B6E7AA97E58FA3E58FA5E69F84_, CH_E68F90E7A4BAE69687E69CAC_, CH_E6A087E9A298E69687E69CAC_, CH_E98089E9A1B9_)
End Function
Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As WString, CH_E6A087E9A298E69687E69CAC_ As WString = App.ProductName , CH_E98089E9A1B9_ As ULong = MB_OK) As Integer
   'API 模式
'   PrintA "API 模式"
   Function = MessageBox(CH_E788B6E7AA97E58FA3E58FA5E69F84_, CH_E68F90E7A4BAE69687E69CAC_, CH_E6A087E9A298E69687E69CAC_, CH_E98089E9A1B9_)
End Function
Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As String, CH_E6A087E9A298E69687E69CAC_ As String = App.ProductName , CH_E98089E9A1B9_ As ULong = MB_OK) As Integer
   'API 模式
'   PrintA "API 模式"
   Function = MessageBox(CH_E788B6E7AA97E58FA3E58FA5E69F84_, CH_E68F90E7A4BAE69687E69CAC_, CH_E6A087E9A298E69687E69CAC_, CH_E98089E9A1B9_)
End Function
Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As WString, CH_E98089E9A1B9_ As ULong ) As Integer
   'API 模式 ，标题默认
   Dim CH_E6A087E9A298E69687E69CAC_ As WString * 200 = App.ProductName 
'   PrintA "API 模式 ，标题默认"
   Function = MessageBox(CH_E788B6E7AA97E58FA3E58FA5E69F84_, CH_E68F90E7A4BAE69687E69CAC_,CH_E6A087E9A298E69687E69CAC_, CH_E98089E9A1B9_)
End Function
Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As String, CH_E98089E9A1B9_ As ULong ) As Integer
   'API 模式 ，标题默认
   Dim CH_E6A087E9A298E69687E69CAC_ As WString * 200 = App.ProductName 
'   PrintA "API 模式 ，标题默认"
   Function = MessageBox(CH_E788B6E7AA97E58FA3E58FA5E69F84_, CH_E68F90E7A4BAE69687E69CAC_,CH_E6A087E9A298E69687E69CAC_, CH_E98089E9A1B9_)
End Function
Function MsgBox Overload( CH_E68F90E7A4BAE69687E69CAC_ As String, CH_E6A087E9A298E69687E69CAC_ As String,ByVal CH_E98089E9A1B9_ As Integer=0,ByVal  CH_E788B6E7AA97E58FA3E58FA5E69F84_ As Hwnd = 0 ) As Integer
   'WIN9库 模式 ，标题默认
   '   PrintA "WIN9库 模式"
   Function = MessageBox(CH_E788B6E7AA97E58FA3E58FA5E69F84_, CH_E68F90E7A4BAE69687E69CAC_,CH_E6A087E9A298E69687E69CAC_, CH_E98089E9A1B9_)
End Function

'[SourceDB:0-171142]
'普通字符 换成 宽字符 
'返回包含宽字符格式的普通字符串，使用还是要转换的
Function StrToWStr(sStr As String, CodePage As UINT = CP_ACP) As String 'CodePage=语言代码页 简体中文=936 CP_ACP是默认系统语言，不同语言系统用CP_ACP转换会发生乱码
   Dim As UInteger ZStrLen, WStrLen
   Dim ss      As String, ff     As Long
   Dim ZStrPtr as LPCCH, WStrMem as LPWSTR
   ZStrLen = Len(sStr)
   If ZStrLen > 0 Then
      ZStrPtr = StrPtr(sStr)
      WStrLen = ZStrLen * 2
      ss      = String(WStrLen, 0)
      WStrMem = Cast(LPWSTR, StrPtr(ss))
      WStrLen = MultiByteToWideChar(CodePage, 0, ZStrPtr, ZStrLen, WStrMem, WStrLen)
      'WStrLen 是宽字符个数，不是字节数
      Function = Left(ss, WStrLen * 2)
   End If
End Function
'[SourceDB:0-171146]
'宽字符 换成 普通字符
'宽字符是指针
'WStrLen 是宽字符个数，不是字节长度
Function wStrToStr(WStrPtr As Wstring Ptr, WStrLen As Long = 0, CodePage As UINT = CP_ACP) As String
   'WStrLen 是宽字符个数，不是字节长度
   'CodePage	语言代码页 简体中文=936 CP_ACP是默认系统语言，不同语言系统用CP_ACP转换会发生乱码
   If WStrPtr Then
      If WStrLen = 0 Then WStrLen = Len( *WStrPtr)
      If WStrLen = 0 Then Return ""
      Dim ZStr as String
      ZStr = String(WStrLen * 2 + 2, 0)
      Dim ZStrLen As Integer = WideCharToMultiByte(CodePage, 0, WStrPtr, WStrLen, StrPtr(ZStr), WStrLen * 2 + 2, NULL, NULL)
      If ZStrLen Then Function = Left(ZStr, ZStrLen)
   EndIf
End Function
'[SourceDB:0-195547]
Function DpiScaleI(xy As Long) As Long  
   Static bb As Single
   If bb = 0 Then
      Dim HDC As HDC
      HDC = GetDC(HWND_DESKTOP)
      bb  = GetDeviceCaps(HDC, LOGPIXELSX) / 96
      ReleaseDC HWND_DESKTOP, hDC
   End If
   Function = Int(xy * bb)
End Function
'[SourceDB:0-195549]
Function DpiUnScaleI(xy As Long) As Long
   Static bb As Single
   If bb = 0 Then
      Dim HDC As HDC
      hDC = GetDC(HWND_DESKTOP)
      bb  = GetDeviceCaps(HDC, LOGPIXELSX) / 96
      ReleaseDC HWND_DESKTOP, hDC
   End If
   Function = Int(xy / bb)
End Function
'[SourceDB:0-171072]
'画线 DrawLine(ByVal hDc As Long , ByVal X1 As Long ,ByVal Y1 As Long ,ByVal X2 As Long ,ByVal Y2 As Long ,_
'             ByVal nPenStyle As Long, ByVal nWidth As Long, ByVal crColor As Long)
'需要支持高DPI，请代码中加 AfxScaleX(X), AfxScaleY(Y)  
'nPenStyle ------ Long，指定画笔样式，可以是下述常数之一
'PS_SOLID        画笔画出的是实线
'PS_DASH         画笔画出的是虚线（nWidth必须不大于1）
'PS_DOT          画笔画出的是点线（nWidth必须不大于1）
'PS_DASHDOT      画笔画出的是点划线（nWidth必须不大于1）
'PS_DASHDOTDOT   画笔画出的是点-点-划线（nWidth必须不大于1）
'PS_NULL         画笔不能画图
'PS_INSIDEFRAME  由椭圆、矩形、圆角矩形、饼图以及弦等生成的封闭对象框时，画线宽度向内扩展。如指定的准确RGB颜色不存在，就进行抖动处理
'颜色用 BGR(0, 0, 255) 创建  不能用 RGB
Sub DrawLine(ByVal hDC as hDC, ByVal X1 as Integer, ByVal Y1 as Integer, ByVal X2 as Integer, ByVal Y2 as Integer, _
      ByVal nPenStyle as Integer, ByVal nWidth as Integer, ByVal crColor as Long) '画线
   '线条类型 nPenStyle
   '实线 = 0
   '虚线 = 1
   '点线 = 2
   '点划线 = 3
   '双点划线 = 4
   '无线 = 5
   '内收实线 = 6
   Dim hOldPen as HGDIOBJ, hPen as HGDIOBJ, lpPoint as Point
   hPen = CreatePen(nPenStyle, nWidth, crColor) '创建新画笔
   hOldPen = SelectObject(hDC, hPen)            '画笔存入DC
   MoveToEx hDC, X1, Y1, @lpPoint             '设置起点
   LineTo hDC, X2, Y2                      '画到终点
   SelectObject hDC, hOldPen            '销毁
   DeleteObject hPen
   
End Sub
'[SourceDB:0-171071]
'画框 DrawFrame(DC,X1,Y1,X2,Y2,填充色彩,线条类型,线条色彩,线条宽)
'需要支持高DPI，请代码中加 AfxScaleX(X), AfxScaleY(Y)  
'nPenStyle ------ Long，指定画笔样式，可以是下述常数之一
'PS_SOLID        画笔画出的是实线
'PS_DASH         画笔画出的是虚线（nWidth必须不大于1）
'PS_DOT          画笔画出的是点线（nWidth必须不大于1）
'PS_DASHDOT      画笔画出的是点划线（nWidth必须不大于1）
'PS_DASHDOTDOT   画笔画出的是点-点-划线（nWidth必须不大于1）
'PS_NULL         画笔不能画图
'PS_INSIDEFRAME  由椭圆、矩形、圆角矩形、饼图以及弦等生成的封闭对象框时，画线宽度向内扩展。如指定的准确RGB颜色不存在，就进行抖动处理
'颜色用 BGR(0, 0, 255) 创建  不能用 RGB
Sub DrawFrame(DC as hDC, X1 as Long, Y1 as Long, X2 as Long, Y2 as Long, C as Long, L as Long = PS_NULL, cL as Long = 0, wL as Long = 1)
   '画框                                                                   填充色彩  线条类型     线条色彩
   
   Dim hBrush as HBRUSH, hPen as HPEN
   Dim hOldBrush as HGDIOBJ, hOldPen as HGDIOBJ
   
   If c <> -1 Then
      hBrush = CreateSolidBrush(c)
   Else
      hBrush = GetStockObject(HOLLOW_BRUSH) '创建空画笔，才能画出空心来
   End If
   hOldBrush = SelectObject(DC, hBrush)
   
   hPen = CreatePen(L, wl, cl)
   
   hOldPen = SelectObject(DC, hPen)
   
   Rectangle DC, X1, Y1, X2, Y2
   
   SelectObject DC, hOldPen
   
   DeleteObject hPen
   
   SelectObject DC, hOldBrush
   DeleteObject hBrush
   
   
End Sub
'[SourceDB:0-171069]
'圆角矩形 
' DrawCircleFrame(DC,X,Y,W,H,x圆角,y圆角,框线粗细,线条类型 ,边框色,填充色)
'需要支持高DPI，请代码中加 AfxScaleX(X), AfxScaleY(Y)  
'nPenStyle ------ Long，指定画笔样式，可以是下述常数之一
'PS_SOLID        画笔画出的是实线
'PS_DASH         画笔画出的是虚线（nWidth必须不大于1）
'PS_DOT          画笔画出的是点线（nWidth必须不大于1）
'PS_DASHDOT      画笔画出的是点划线（nWidth必须不大于1）
'PS_DASHDOTDOT   画笔画出的是点-点-划线（nWidth必须不大于1）
'PS_NULL         画笔不能画图
'PS_INSIDEFRAME  由椭圆、矩形、圆角矩形、饼图以及弦等生成的封闭对象框时，画线宽度向内扩展。如指定的准确RGB颜色不存在，就进行抖动处理
'颜色用 BGR(0, 0, 255) 创建  不能用 RGB
Sub DrawCircleFrame(ByVal sDC as hDC, ByVal X as Long, ByVal Y as Long, ByVal hWidth as Long, ByVal hHeight as Long, ByVal xCircle as Long, ByVal yCircle as Long, _
      ByVal LineWidth as Long, ByVal LineType as Long , ByVal bColor as Long, ByVal tColor as Long)'圆角矩形
   
   '(ByVal sDC As Long, ByVal X As Long, ByVal Y As Long, ByVal 宽度 As Long, ByVal 高度 As Long, X圆角 As Long, Y圆角 As Long, _
   'ByVal 框线粗细 As Long, ByVal 线条类型 As 线条类型_m, ByVal 边框色 As Long, ByVal 填充色 As Long) '圆角矩形
   '以支持高DPI，以DPI100%设置坐标就可以了
   
   Dim hBrush as HBRUSH, hPen as HPEN
   Dim hOldBrush as HGDIOBJ, hOldPen as HGDIOBJ
   
   If tColor <> -1 Then
      hBrush = CreateSolidBrush(tColor)
   Else
      hBrush = GetStockObject(HOLLOW_BRUSH) '创建空画笔，才能画出空心来
   End If
   hOldBrush = SelectObject(sDC, hBrush)
   
   hPen = CreatePen(LineType, LineWidth, bColor)
   
   hOldPen = SelectObject(sDC, hPen)
   
   RoundRect sDC, X, Y, X + hWidth, Y + hHeight, xCircle, yCircle
   
   SelectObject sDC, hOldPen
   
   DeleteObject hPen
   
   SelectObject sDC, hOldBrush
   DeleteObject hBrush
   
   '参数表
   '参数 类型及说明
   'sDC Long，用于绘图的设备场景
   'X1,Y1 Long，对矩形左上角位置进行说明的X，Y坐标
   'X2,Y2 Long，对矩形右下角位置进行说明的X，Y坐标
   'X3 Long，用于生成圆角效果的一个椭圆的宽度。取值范围从零（表示不加圆角），一直到矩形的宽度（全圆）
   'Y3 Long，用于生成圆角效果的一个椭圆的高度。取值范围从零（表示不加圆角），一直到矩形的高度（全圆）
   
   
End Sub
'[SourceDB:0-171070]
'描绘一个椭圆 
'DrawEllipse(Dc,X,Y,宽度 ,高度,线条类型,框线粗细,边框色,填充色)
'需要支持高DPI，请代码中加 AfxScaleX(X), AfxScaleY(Y)  
'nPenStyle ------ Long，指定画笔样式，可以是下述常数之一
'PS_SOLID        画笔画出的是实线
'PS_DASH         画笔画出的是虚线（nWidth必须不大于1）
'PS_DOT          画笔画出的是点线（nWidth必须不大于1）
'PS_DASHDOT      画笔画出的是点划线（nWidth必须不大于1）
'PS_DASHDOTDOT   画笔画出的是点-点-划线（nWidth必须不大于1）
'PS_NULL         画笔不能画图
'PS_INSIDEFRAME  由椭圆、矩形、圆角矩形、饼图以及弦等生成的封闭对象框时，画线宽度向内扩展。如指定的准确RGB颜色不存在，就进行抖动处理
'颜色用 BGR(0, 0, 255) 创建  不能用 RGB
Sub DrawEllipse(ByVal hDC as hDC, ByVal X as Integer, ByVal Y as Integer, ByVal hWidth as Integer, ByVal hHeight as Integer, _
      ByVal LineType as Integer ,ByVal LineWidth as Integer, ByVal bColor as  Integer , ByVal tColor as  Integer )'描绘一个椭圆
   
   '(ByVal hDc As Long, ByVal X As Long, ByVal Y As Long, ByVal 宽度 As Long, ByVal 高度 As Long, _
   'ByVal 框线粗细 As Long, ByVal 线条类型 As 线条类型_m, ByVal 边框色 As Long, ByVal 填充色 As Long) '圆角矩形
   
   
   Dim hBrush as HGDIOBJ, hPen as HGDIOBJ
   Dim hOldBrush as HGDIOBJ, hOldPen as HGDIOBJ
   
   If tColor <> -1 Then
      hBrush = CreateSolidBrush(tColor)
   Else
      hBrush = GetStockObject(HOLLOW_BRUSH)
   End If
   hOldBrush = SelectObject(hDC, hBrush)
   
   
   'SetBkMode hdc,TRANSPARENT
   '设置这个后，画上的字是透明的
   
   hPen = CreatePen(LineType, LineWidth, bColor)
   
   hOldPen = SelectObject(hDC, hPen)
   
   Ellipse hDC, X, Y, X + hWidth, Y + hHeight
   
   SelectObject hDC, hOldPen
   
   DeleteObject hPen
   
   SelectObject hDC, hOldBrush
   DeleteObject hBrush
   
   '参数表
   
   'X1，Y1 Long，约束矩形采用逻辑坐标的左上角位置
   'X2，Y2 Long，约束矩形采用逻辑坐标的右下角位置
   
   
End Sub

'[SourceDB:0-171078]
'获取文本显示宽度
Function GetTextWidth(ByVal DC as hDC, nText as String) as Long '获取文本显示宽度
   Dim s as SIZE
   GetTextExtentPoint32A DC, StrPtr(nText), Len(nText), @s
   Function = s.cx
End Function
'[SourceDB:0-171076]
'获取文本显示高度
Function GetTextHeight(ByVal DC as hDC, nText as String) as Long '获取文本显示高度
   Dim s as SIZE
   GetTextExtentPoint32A DC, StrPtr(nText), Len(nText), @s
   Function = s.cy
End Function
'[SourceDB:0-197430]
Function LenW(wszStr As StringW) As Integer  '返回宽字符长度（Unicode编码）一个中文算一个字符，一个英文算一个字符
   Return wszStr.WstrLen 
End Function
'[SourceDB:0-171237]
'刷新窗口
Sub FF_Redraw(HWND_F as HWnd )
   if IsWindow(HWND_F) Then
   InvalidateRect (HWND_F , Null, True)
   UpdateWindow (HWND_F)
   end if 
End Sub
'[SourceDB:0-195548]
Function DpiScaleF(xy As Single) As Single
   Static bb As Single
   If bb = 0 Then
      Dim HDC As HDC
      hDC = GetDC(HWND_DESKTOP)
      bb  = GetDeviceCaps(HDC, LOGPIXELSX) / 96
      ReleaseDC HWND_DESKTOP, hDC
   End If
   Function = xy * bb
End Function