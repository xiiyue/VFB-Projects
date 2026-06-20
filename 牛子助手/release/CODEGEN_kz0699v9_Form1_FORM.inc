'[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|729]
'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.9.8 生成的源代码
' 生成时间：2026年03月18日 21时50分16秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------

'------------------------------------------------------------------------------
'VisualFreeBasic 自动生成的 Form1 函数
'------------------------------------------------------------------------------
'{FORM_WS_EX_NOACTIVATE3}  '为无焦点窗口创建定义
Function Form1_Class_Form.Show(hWndParent As .hWnd = HWND_DESKTOP, Modal As Boolean = False, UserData As Integer = 0) As .hWnd  '加载窗口并且显示, 模态显示用True {2.True.False} UserData 是传递给创建事件的参数，不保存数值
   '注：hWnd 是类属性，与API的 hWnd 冲突，因此使用 .hWnd 表示API，就是前面加个小数点。
   If This.Repeat = False Then     '是不是不允许多开窗口
      If IsWindow(This.hWnd) Then 
         This.FlashWindow
         Return This.hWnd
      End If 
   End if 
'{FORM_WS_EX_NOACTIVATE}  '为无焦点窗口创建多线程代码
   Dim pWindow AS CWindow Ptr = New CWindow(!"\u725B\u5B50\u52A9\u624B\u005F\u0046\u006F\u0072\u006D\u0031")
   '创建一个窗口
  Dim NewhWnd As .hWnd = pWindow->Create(hWndParent, !"\u725B\u5821\u52A9\u624B", Cast(WNDPROC, @Form1_FORMPROCEDURE), 0, 0, 204, 193, WS_MINIMIZEBOX Or WS_MAXIMIZEBOX Or WS_CLIPSIBLINGS Or WS_CLIPCHILDREN Or WS_POPUP, WS_EX_WINDOWEDGE Or WS_EX_LEFT Or WS_EX_LTRREADING Or WS_EX_RIGHTSCROLLBAR Or WS_EX_TOPMOST Or WS_EX_CONTROLPARENT)
'{FORM_WS_EX_NOACTIVATE2}  '为无焦点窗口返回窗口句柄
   hWnd = NewhWnd
   If IsWindow(NewhWnd) = 0 Then
      Delete pWindow
      Return 0
      DpiScaleI(1) '放这里，永远不执行，只是为了让代码中包含这个函数，因为必须要这个函数。
   End if
   Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
   vfb_Set_Control_Ptr(NewhWnd,fp)
   Dim rcParent As RECT  '为控件布局属性，初始化数据用
   .GetClientRect(NewhWnd, @rcParent)
   rcParent.Right = DpiUnScaleI(rcParent.Right)  ' 为自动响应DPI，全部调整为 100%DPI 时的数值
   rcParent.Bottom = DpiUnScaleI(rcParent.Bottom) 
   fp->hWndParent = hWndParent
   fp->nName = "Form1"
   
   '给窗口设置其它参数
   pWindow->ClassStyle = CS_VREDRAW Or CS_HREDRAW Or CS_DBLCLKS
   '图标
   fp->BigIcon = LoadImage(app.hInstance, "AAAAA_APPICON", IMAGE_ICON, 48, 48, LR_SHARED)
   fp->SmallIcon = LoadImage(app.hInstance, "AAAAA_APPICON", IMAGE_ICON, 32, 32, LR_SHARED)
   pWindow->BigIcon = fp->BigIcon     '需要在销毁窗口时销毁句柄
   pWindow->SmallIcon = fp->SmallIcon
   '菜单
   '启动位置
   pWindow->Center
   hWnd = NewhWnd '在特殊情况下，多开窗口后发生 hWnd 的值被前一个窗口替换的情况  
   '鼠标穿透 透明度 透明颜色
   
   
   This.TransColor = GetCodeColorGDI(&H197F7F7F)
   fp->TransColor = &H197F7F7F
   This.MousePointer = 0
   This.BackColor = GetCodeColorGDI(&H0F7F7F7F)
   fp->BackColor = &H0F7F7F7F
   
   
         
'[Create main window]  创建主窗口，在此前一行插入。
    Dim hWndControl As .hWnd '控件句柄
    
'[Create control top]  顶部创建控件的代码，（主要为了顶部菜单，必须在所有控件之前创建）在此前一行插入。
        
   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E58092E8AEA1E697B6_(0).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 0
      fp->IDC = 102
      fp->nText = !"\u5012\u8BA1\u65F6"
      This.CH_E58092E8AEA1E697B6_(0).IDC =102
      fp->nName = !"\u5012\u8BA1\u65F6"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E58092E8AEA1E697B6_(0).CAPTION = !"\u5012\u8BA1\u65F6"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E58092E8AEA1E697B6_(0).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E58092E8AEA1E697B6_(0).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E58092E8AEA1E697B6_(0).Font = "Microsoft YaHei,14"
      This.CH_E58092E8AEA1E697B6_(0).FontWidth =0
      This.CH_E58092E8AEA1E697B6_(0).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,4) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 0
      fp->nTop = 10
      fp->nWidth = 90
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 103
      fp->nText = ""
      This.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.IDC =103
      fp->nName = !"\u53D1\u58F0\u8BA1\u65F6\u5668"
      This.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Interval = 500
      fp->Style And= Not &H1 
      This.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Enabled = False
      fp->nLeft = 280
      fp->nTop = 50
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E58092E8AEA1E697B6_(1).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 1
      fp->IDC = 104
      fp->nText = !"\u5012\u8BA1\u65F6"
      This.CH_E58092E8AEA1E697B6_(1).IDC =104
      fp->nName = !"\u5012\u8BA1\u65F6"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E58092E8AEA1E697B6_(1).CAPTION = !"\u5012\u8BA1\u65F6"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E58092E8AEA1E697B6_(1).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E58092E8AEA1E697B6_(1).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E58092E8AEA1E697B6_(1).Font = "Microsoft YaHei,14"
      This.CH_E58092E8AEA1E697B6_(1).FontWidth =0
      This.CH_E58092E8AEA1E697B6_(1).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,4) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 0
      fp->nTop = 60
      fp->nWidth = 90
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E58092E8AEA1E697B6_(2).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 2
      fp->IDC = 105
      fp->nText = !"\u5012\u8BA1\u65F6"
      This.CH_E58092E8AEA1E697B6_(2).IDC =105
      fp->nName = !"\u5012\u8BA1\u65F6"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E58092E8AEA1E697B6_(2).CAPTION = !"\u5012\u8BA1\u65F6"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E58092E8AEA1E697B6_(2).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E58092E8AEA1E697B6_(2).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E58092E8AEA1E697B6_(2).Font = "Microsoft YaHei,14"
      This.CH_E58092E8AEA1E697B6_(2).FontWidth =0
      This.CH_E58092E8AEA1E697B6_(2).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,4) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 0
      fp->nTop = 110
      fp->nWidth = 90
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 106, !"\u5F00\u59CB", 80, 10, 45, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 0
      fp->IDC = 106
      fp->nText = !"\u5F00\u59CB"
      This.CH_E590AFE58AA8_(0).hWnd = hWndControl 
      This.CH_E590AFE58AA8_(0).IDC =106
      fp->nName = !"\u542F\u52A8"
      This.CH_E590AFE58AA8_(0).CAPTION = !"\u5F00\u59CB"
      This.CH_E590AFE58AA8_(0).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 80
      fp->nTop = 10
      fp->nWidth = 45
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 107, !"\u5F00\u59CB", 80, 60, 45, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 1
      fp->IDC = 107
      fp->nText = !"\u5F00\u59CB"
      This.CH_E590AFE58AA8_(1).hWnd = hWndControl 
      This.CH_E590AFE58AA8_(1).IDC =107
      fp->nName = !"\u542F\u52A8"
      This.CH_E590AFE58AA8_(1).CAPTION = !"\u5F00\u59CB"
      This.CH_E590AFE58AA8_(1).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 80
      fp->nTop = 60
      fp->nWidth = 45
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 108, !"\u5F00\u59CB", 80, 110, 45, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 2
      fp->IDC = 108
      fp->nText = !"\u5F00\u59CB"
      This.CH_E590AFE58AA8_(2).hWnd = hWndControl 
      This.CH_E590AFE58AA8_(2).IDC =108
      fp->nName = !"\u542F\u52A8"
      This.CH_E590AFE58AA8_(2).CAPTION = !"\u5F00\u59CB"
      This.CH_E590AFE58AA8_(2).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 80
      fp->nTop = 110
      fp->nWidth = 45
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.Timer1.hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 109
      fp->nText = ""
      This.Timer1.IDC =109
      fp->nName = !"\u0054\u0069\u006D\u0065\u0072\u0031"
      This.Timer1.Interval = 100
      fp->Style And= Not &H1 
      This.Timer1.Enabled = False
      fp->nLeft = 280
      fp->nTop = -20
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 110, !"\u002D\u0035\u0073", 130, 10, 30, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 0
      fp->IDC = 110
      fp->nText = !"\u002D\u0035\u0073"
      This.CH_E5878FE697B6_(0).hWnd = hWndControl 
      This.CH_E5878FE697B6_(0).IDC =110
      fp->nName = !"\u51CF\u65F6"
      This.CH_E5878FE697B6_(0).CAPTION = !"\u002D\u0035\u0073"
      This.CH_E5878FE697B6_(0).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 130
      fp->nTop = 10
      fp->nWidth = 30
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 111, !"\u002D\u0035\u0073", 130, 60, 30, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 1
      fp->IDC = 111
      fp->nText = !"\u002D\u0035\u0073"
      This.CH_E5878FE697B6_(1).hWnd = hWndControl 
      This.CH_E5878FE697B6_(1).IDC =111
      fp->nName = !"\u51CF\u65F6"
      This.CH_E5878FE697B6_(1).CAPTION = !"\u002D\u0035\u0073"
      This.CH_E5878FE697B6_(1).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 130
      fp->nTop = 60
      fp->nWidth = 30
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 112, !"\u002D\u0035\u0073", 130, 110, 30, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 2
      fp->IDC = 112
      fp->nText = !"\u002D\u0035\u0073"
      This.CH_E5878FE697B6_(2).hWnd = hWndControl 
      This.CH_E5878FE697B6_(2).IDC =112
      fp->nName = !"\u51CF\u65F6"
      This.CH_E5878FE697B6_(2).CAPTION = !"\u002D\u0035\u0073"
      This.CH_E5878FE697B6_(2).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 130
      fp->nTop = 110
      fp->nWidth = 30
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 113, !"\u002B\u0035\u0073", 160, 10, 30, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 0
      fp->IDC = 113
      fp->nText = !"\u002B\u0035\u0073"
      This.CH_E58AA0E697B6_(0).hWnd = hWndControl 
      This.CH_E58AA0E697B6_(0).IDC =113
      fp->nName = !"\u52A0\u65F6"
      This.CH_E58AA0E697B6_(0).CAPTION = !"\u002B\u0035\u0073"
      This.CH_E58AA0E697B6_(0).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 160
      fp->nTop = 10
      fp->nWidth = 30
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 114, !"\u002B\u0035\u0073", 160, 60, 30, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 1
      fp->IDC = 114
      fp->nText = !"\u002B\u0035\u0073"
      This.CH_E58AA0E697B6_(1).hWnd = hWndControl 
      This.CH_E58AA0E697B6_(1).IDC =114
      fp->nName = !"\u52A0\u65F6"
      This.CH_E58AA0E697B6_(1).CAPTION = !"\u002B\u0035\u0073"
      This.CH_E58AA0E697B6_(1).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 160
      fp->nTop = 60
      fp->nWidth = 30
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 115, !"\u002B\u0035\u0073", 160, 110, 30, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = 2
      fp->IDC = 115
      fp->nText = !"\u002B\u0035\u0073"
      This.CH_E58AA0E697B6_(2).hWnd = hWndControl 
      This.CH_E58AA0E697B6_(2).IDC =115
      fp->nName = !"\u52A0\u65F6"
      This.CH_E58AA0E697B6_(2).CAPTION = !"\u002B\u0035\u0073"
      This.CH_E58AA0E697B6_(2).Font = "Microsoft YaHei,9,0"
      fp->nLeft = 160
      fp->nTop = 110
      fp->nWidth = 30
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 116, !"\u5B8C\u6210\u725B\u5821\u8FD8\u5269\u591A\u4E45", 20, 150, 170, 30,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @Form1_CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 116
      fp->nText = !"\u5B8C\u6210\u725B\u5821\u8FD8\u5269\u591A\u4E45"
      This.CH_E7899BE5A0A1E7AA97E58FA3_.hWnd = hWndControl 
      This.CH_E7899BE5A0A1E7AA97E58FA3_.IDC =116
      fp->nName = !"\u725B\u5821\u7A97\u53E3"
      This.CH_E7899BE5A0A1E7AA97E58FA3_.CAPTION = !"\u5B8C\u6210\u725B\u5821\u8FD8\u5269\u591A\u4E45"
      This.CH_E7899BE5A0A1E7AA97E58FA3_.Font = "Microsoft YaHei,11"
      fp->nLeft = 20
      fp->nTop = 150
      fp->nWidth = 170
      fp->nHeight = 30
   End IF

'[Create control]  创建控件的代码，在此前一行插入。

'[Create control end]  创建全部控件后需要处理的代码，在此前一行插入。


   PostMessage(NewhWnd, &H1000, &H1000,CAst(lPArAm,UserData)) '触发显示事件
   
   hWndControl = NewhWnd '设置焦点后会发生消息循环的情况，要是同时多开同一个窗口，就发生 hWnd 被赋值为下一个窗口句柄的情况。
   This.CH_E590AFE58AA8_(0).SetFocus
'[SET_FOCUS] '将焦点设置为选项卡顺序中的最低控件 
   Function = FLY_DoMessagePump(pWindow,Modal, hWndControl, hWndParent, SW_SHOWNORMAL, False) ' IsMDIForm 如果这是MDI窗口，请设置标志
End Function

Function Form1_FORMPROCEDURE(ByVal hWndForm As hWnd, ByVal wMsg As UInteger, ByVal wParam As wParam, ByVal lParam As lParam) As LResult 'Form1 窗口回调过程
   Dim tLResult As LResult
   Select Case wMsg
      Case WM_SIZE
         If wParam <> SIZE_MINIMIZED Then
            '[CONTROL_WM_SIZE] 状态栏调整大小
            FLY_VFB_Layout_hWndForm(hWndForm) '控件布局调整大小
            '[CONTROL_WM_SIZE_END] 状态栏调整大小
         End If
      Case WM_PAINT '处理虚拟控件
         Dim fp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(hWndForm)
         if fp Then
            Dim WinCc As Long = GetCodeColorGDI(fp->BackColor)
            If WinCc = -1 Then WinCc = GetSysColor(COLOR_BTNFACE)
            Dim gg As yGDI = yGDI(hWndForm, WinCc, True)
            
'[FORM_PAINT_START]  主窗口开始画画事件，在此前一行插入。
            '[DRAWINGVIRTUALCONTROLS] '描绘虚拟控件，在此下一行插入（这样就最底层先画）。
            Form1.CH_E58092E8AEA1E697B6_(2).hWndForm = hWndForm 
            Form1.CH_E58092E8AEA1E697B6_(2).Drawing(gg,hWndForm,WinCc)  
            Form1.CH_E58092E8AEA1E697B6_(1).hWndForm = hWndForm 
            Form1.CH_E58092E8AEA1E697B6_(1).Drawing(gg,hWndForm,WinCc)  
            Form1.CH_E58092E8AEA1E697B6_(0).hWndForm = hWndForm 
            Form1.CH_E58092E8AEA1E697B6_(0).Drawing(gg,hWndForm,WinCc)  
            
'[FORM_PAINT_END] 主窗口开始画画事件，在此前一行插入。
         End If
   End Select
   '以下CASE从表单上的控件以及用户自己处理的任何这些消息中调用通知事件。
   Select Case wMsg
      Case &H1000
         if wParam = &H1000 then
            Dim rc as Rect '由于控件创建时间比尺寸消息晚，需要重新触发一次
            GetClientRect(hWndForm, @rc)
            SendMessage(hWndForm, WM_SIZE, SIZE_RESTORED, MAKELPARAM(rc.Right - rc.Left, rc.Bottom - rc.Top))
             FORM1_SHOWN(hWndForm ,Cast(Integer,lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|68]
'[FORM_SHOWN]  主窗口第一次显示事件，在此前一行插入。
            InvalidateRect(hWndForm, Null, True)
            UpdateWindow(hWndForm)
            '[Create window shadow]  创建窗口阴影，在此前一行插入。
            Return 0
         End If
      Case WM_COMMAND
         
'[FORM_WM_COMMAND]  主窗口命令处理事件，在此前一行插入。
                  Dim As Long IDC =LoWord(wParam) ,CODE = HiWord(wParam)  '控件处理初始化代码
                   If IDC = 106 And CODE = BN_CLICKED Then  ' 启动(0)
              FORM1_CH_E590AFE58AA8__BN_CLICKED(0,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|124]
           End If
          If IDC = 107 And CODE = BN_CLICKED Then  ' 启动(1)
              FORM1_CH_E590AFE58AA8__BN_CLICKED(1,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|124]
           End If
          If IDC = 108 And CODE = BN_CLICKED Then  ' 启动(2)
              FORM1_CH_E590AFE58AA8__BN_CLICKED(2,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|124]
           End If
          If IDC = 110 And CODE = BN_CLICKED Then  ' 减时(0)
              FORM1_CH_E5878FE697B6__BN_CLICKED(0,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|162]
           End If
          If IDC = 111 And CODE = BN_CLICKED Then  ' 减时(1)
              FORM1_CH_E5878FE697B6__BN_CLICKED(1,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|162]
           End If
          If IDC = 112 And CODE = BN_CLICKED Then  ' 减时(2)
              FORM1_CH_E5878FE697B6__BN_CLICKED(2,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|162]
           End If
          If IDC = 113 And CODE = BN_CLICKED Then  ' 加时(0)
              FORM1_CH_E58AA0E697B6__BN_CLICKED(0,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|177]
           End If
          If IDC = 114 And CODE = BN_CLICKED Then  ' 加时(1)
              FORM1_CH_E58AA0E697B6__BN_CLICKED(1,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|177]
           End If
          If IDC = 115 And CODE = BN_CLICKED Then  ' 加时(2)
              FORM1_CH_E58AA0E697B6__BN_CLICKED(2,hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|177]
           End If
          If IDC = 116 And CODE = BN_CLICKED Then  ' 牛堡窗口
              FORM1_CH_E7899BE5A0A1E7AA97E58FA3__BN_CLICKED(hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|191]
           End If
'[CONTROL_WM_COMMAND]  控件处理事件，在此前一行插入。
      Case WM_HSCROLL
         
'[FORM_WM_HSCROLL]  主窗口和一些特殊控件要的事件，在此前一行插入。
      Case WM_VSCROLL
         
'[FORM_WM_VSCROLL]  主窗口和一些特殊控件要的事件，在此前一行插入。
         
         



Case WM_LBUTTONDOWN
          FORM1_WM_LBUTTONDOWN(hWndForm, Cast(Long, wParam), GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|208]
Case WM_LBUTTONUP
          FORM1_WM_LBUTTONUP(hWndForm, Cast(Long, wParam), GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|235]




Case WM_CONTEXTMENU
          FORM1_WM_CONTEXTMENU(hWndForm, GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|198]





'[Other events in main window]  主窗口其它事件，需要加 Case ，在此前一行插入。 注意每个消息值不可重复，不然后面的无法执行
         '{FORM_WM_DRAWITEM}
         '[FORM_WM_DRAWITEM]
      Case WM_TIMER
         If wParam = 357897 then '虚拟控件要刷新，使用防抖动方式刷新，避免虚拟控件多时，同时设置控件属性，造成大量刷新变卡顿。
            KillTimer hWndForm, 357897
            InvalidateRect hWndForm, NULL, CTRUE
            UpdateWindow hWndForm
         End If
                   If wParam = 103 Then
             Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.hWndForm = hWndForm 
             KillTimer(hWndForm, 103)
             FORM1_CH_E58F91E5A3B0E8AEA1E697B6E599A8__WM_TIMER(hWndForm, Cast(Long, wParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|150]
             Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.hWndForm = hWndForm 
             If Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Enabled = True Then  SetTimer(hWndForm, 103, Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Interval(), NULL) 
          End if 

          If wParam = 109 Then
             Form1.Timer1.hWndForm = hWndForm 
             KillTimer(hWndForm, 109)
             FORM1_TIMER1_WM_TIMER(hWndForm, Cast(Long, wParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|88]
             Form1.Timer1.hWndForm = hWndForm 
             If Form1.Timer1.Enabled = True Then  SetTimer(hWndForm, 109, Form1.Timer1.Interval(), NULL) 
          End if 

'[FORM_WM_TIMER]  时间控件事件
      Case WM_NOTIFY
         Dim FLY_pNotify As NMHDR Ptr = Cast(NMHDR Ptr, lParam)
         '[CONTROLS_NOTIFY]  控件事件，标准控件的事件都是按照这个传递
         
'[FORM_WM_NOTIFY]   主窗口的事件
   End Select
   Select Case wMsg
      Case WM_LBUTTONDOWN, WM_LBUTTONUP, WM_LBUTTONDBLCLK, WM_RBUTTONDOWN, WM_RBUTTONUP, WM_RBUTTONDBLCLK, WM_MOUSEMOVE, WM_CONTEXTMENU, WM_MOUSEWHEEL, WM_Timer
         Dim As Long xPos = GET_X_LPARAM(lParam), yPos = GET_Y_LPARAM(lParam)
         '[VIRTUAL_CONTROL_EVENTS] 处理虚拟控件事件，在此前一行插入。
         
   End Select
   
   
   
'[CALL_FORM_CUSTOM] 处理任何自定义消息。
   
   '以下CASE处理VisualFreeBasic内部要求
   Select Case wMsg
      Case WM_GETMINMAXINFO
         '不要为MDI子窗体处理此消息，因为它会干扰子窗体的最大化。
         If (GetWindowLongPtr(hWndForm, GWL_EXSTYLE) And WS_EX_MDICHILD) <> WS_EX_MDICHILD Then
            DefWindowProcW(hWndForm, wMsg, wParam, lParam)
            Dim FLY_pMinMaxInfo As MINMAXINFO Ptr = Cast(MINMAXINFO Ptr, lParam)
            
            
            
            
            Return 0
         End If
      Case WM_SYSCOMMAND
         If (wParam And &HFFF0) = SC_CLOSE Then
            SendMessage hWndForm, WM_CLOSE, wParam, lParam
            Exit Function
         End If
      Case WM_SETFOCUS
         '将焦点设置回正确的子控件。
         Dim fp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(hWndForm)
         If fp then
            If IsWindow(fp->CtrlFocus) Then '预防控件已经关闭或没控件
               If GetAncestor(fp->CtrlFocus, GA_ROOT) = hWndForm Then '预防控件被设置其它主窗口了
                  SetFocus fp->CtrlFocus
               End If
            End If
         End If
      Case WM_SYSCOLORCHANGE, WM_THEMECHANGED '当对系统颜色设置进行更改, 在主题更改事件之后广播到每个窗口。
         '为窗体上的控件重新创建任何背景画笔。
         '将此消息转发给任何通用控件，因为它们不会自动接收此消息。
         Dim fp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(hWndForm)
         If fp then
            Dim cc as Long = GetCodeColorGDI(fp->BackColor)
            if cc = -1        then cc = GetSysColor(COLOR_BTNFACE)
            If fp->hBackBrush Then DeleteBrush(fp->hBackBrush)
            fp->hBackBrush = CreateSolidBrush(cc)
            dim zhWnd as HWND = GetWindow(hWndForm, GW_CHILD)
            While zhWnd
               dim zfp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(zhWnd)
               if zfp Then
                  Dim zcc as Long = GetCodeColorGDI(zfp->BackColor)
                  if zcc = -1        then zcc = cc
                  If zfp->hBackBrush Then DeleteBrush(zfp->hBackBrush)
                  zfp->hBackBrush = CreateSolidBrush(zcc)
               End if
               zhWnd = GetWindow(zhWnd, GW_HWNDNEXT)
            Wend
         End If
         
      Case WM_SETCURSOR
         dim a as long = LOWORD(lParam)
         if a = 1 then '位于客户区
            Dim fp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(cast(hwnd, wParam))
            if fp Then
               if fp->nCursor then
                  SetCursor(fp->nCursor)
                  Return True
               end if
            end if
         end if
      Case WM_PAINT
         Return True '采用自绘，需要立即返回
      Case WM_ERASEBKGND ' 采用自绘，不需要系统画背景
         Return True '防止擦除背景，不加这个会闪的。 与mCrtl控件冲突，加了后，mCrtl控件有透明的就不会画了。去掉这行，对窗口也无影响。
      Case WM_MOUSEMOVE
         
          FORM1_WM_MOUSEMOVE(hWndForm, Cast(Long, wParam), GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|218]
'[CALL_FORM_WM_MOUSEMOVE]
      Case WM_Close
         '处理模式窗口，发现所有者窗口被禁用后，恢复即可 ------
         '以前在消息循环中处理，关闭窗口后，由于此时所有者窗口还被禁用中，系统就把前台窗口交给下一个窗口
         '虽然在消息循环后面重新设置前台窗口，但会发生快速切换前台窗口的闪，虽然很快很难察觉，特殊情况下还会发生前台失败、闪耀明显感觉等。
         '在关闭窗口前恢复被禁用的所有者窗口，其它无需任何处理就完美解决。
         '本来在消息循环里判断 WM_Close ，然后没想到消息循环里并没有这个消息，只能用在这里才可以。
         Dim hWndParent As hWnd = GetParent(hWndForm)
         If hWndParent Then
            While (GetWindowLongPtr(hWndParent, GWL_STYLE) And WS_CHILD) <> 0 '确定活动控件的顶层窗口
               hWndParent = GetParent(hWndParent)
               If IsWindow(hWndParent) = 0 Then Exit While
               If (GetWindowLongPtr(hWndParent, GWL_EXSTYLE) And WS_EX_MDICHILD) <> 0 Then Exit While
            Wend
            If IsWindow(hWndParent) Then EnableWindow(hWndParent, True)
         End If
      Case WM_DESTROY
         
'[CALL_FORM_WM_DESTROY]  窗口卸载事件
         
                  KillTimer hWndForm, 103
         KillTimer hWndForm, 109
'[DELETE_USER_TIMERS] 删除任何用户定义的Timer控件
         
         Form1.hWnd = 0
         Dim pWindow As CWindow Ptr = AfxCWindowPtr(hWndForm)
         If pWindow Then Delete pWindow
         Dim fp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(hWndForm)
         While fp '清理虚拟控件
            if fp->BigIcon    then DestroyIcon fp->BigIcon
            if fp->SmallIcon  then DestroyIcon fp->SmallIcon
            if fp->hBackBrush then DeleteBrush(fp->hBackBrush)
            If fp->ToolWnd    Then DestroyWindow fp->ToolWnd
            if fp->nCursor    then DestroyCursor fp->nCursor
            Dim sfp As FormControlsPro_TYPE ptr = fp->VrControls
            Delete fp
            fp = sfp
         Wend
         vfb_Remove_Control_Ptr(hWndForm)
      Case WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORSTATIC, WM_CTLCOLORBTN
         '从子控件收到的消息即将显示。在此处设置颜色属性。lParam是Control的句柄。 wParam是hDC。
         Dim fp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(Cast(HWND, lParam))
         If fp then
            Dim cc as Long = GetCodeColorGDI(fp->ForeColor)
            if cc <> -1 then SetTextColor(Cast(hDC, wParam), cc)
            cc = GetCodeColorGDI(fp->BackColor)
            if cc = -1 Then
               Dim wfp As FormControlsPro_TYPE ptr = vfb_Get_Control_Ptr(hWndForm)
               if wfp = 0 then exit select
               cc = GetCodeColorGDI(wfp->BackColor)
            End If
            if cc = -1 then cc = GetSysColor(COLOR_BTNFACE)
            SetBkColor(Cast(hDC, wParam), cc)
            If fp->hBackBrush Then DeleteBrush(fp->hBackBrush)
            fp->hBackBrush = CreateSolidBrush(cc)
            '            SetBkMode Cast(hDC, wParam), TRANSPARENT
            Return Cast(LRESULT, fp->hBackBrush)
         End If
   End Select
   Function = DefWindowProcW(hWndForm, wMsg, wParam, lParam)
End Function

Function Form1_CODEPROCEDURE(ByVal hWndControl As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LRESULT  ' Form1 控件回调
   'Form1 窗口上每个控件的所有消息都在此函数中处理。
   Dim fp As FormControlsPro_TYPE ptr 
   Dim tLResult As LResult
   Dim IDC As Long = GetDlgCtrlId(hWndControl)

'[CONTROL_LEAVEHOVER]  '启用鼠标出窗口检查

'[CALL_CONTROL_CUSTOM]  处理任何自定义消息。

   '以下CASE在处理用户定义事件之前处理内部VisualFreeBasic要求（这些事件在此之后的单独CASE中处理）。
   Select Case wMsg
      Case 0  '需要这一行，万一没控件事件，语句也能成立

         
'[CONTROL_CASE_OTHER]  '控件事件。         

   End Select
   
    Select Case wMsg
       Case WM_DESTROY  '// 需要：删除控件子类
           fp = vfb_Get_Control_Ptr(hWndControl)
           Select Case IDC 
               Case 0  '需要这一行，万一没控件事件，语句也能成立
'[CALL_CONTROL_DESTROY] 销毁。  
           End Select

          SetWindowLongPtrW hWndControl ,GWLP_WNDPROC ,CAST(LONG_PTR ,RemovePropW(hWndControl ,"OLDWNDPROC"))
            vfb_Remove_Control_Ptr(hWndControl)           
            If fp Then
               if fp->hBackBrush then DeleteBrush(fp->hBackBrush)
               If fp->ToolWnd Then DestroyWindow fp->ToolWnd
               if fp->nCursor then DestroyCursor fp->nCursor
               Delete fp
            End If
   
       Case WM_SETFOCUS
         ' 如果这是一个TextBox，我们检查是否需要突出显示文本。
'         If fp Then
'            If ff->SelText Then 
'               SendMessage hWndControl, EM_SETSEL, 0, -1
'            Else
'               SendMessage hWndControl, EM_SETSEL, -1, 0
'            End If   
'         End If
         ' 将焦点控件存储在父窗体中如果此窗体是TabControl子窗体，则需要将CtrlFocus存储在此子窗体的父窗体中。
         Dim FLY_tempLong As Long = GetWindowLongPtr(GetParent(hWndControl), GWL_STYLE)
         If (FLY_tempLong And WS_CHILD) = WS_CHILD Then
            ' 必须是TabControl子对话框
            fp = vfb_Get_Control_Ptr(GetParent(GetParent(hWndControl)))
         Else   
            fp = vfb_Get_Control_Ptr(GetParent(hWndControl))
         End If   
         If fp Then fp->CtrlFocus = hWndControl          
                
   End Select
   '此控件是子类，因此我们必须将所有未处理的消息发送到原始窗口过程。
   FUNCTION = CallWindowProcW(GetPropW(hWndControl, "OLDWNDPROC"), hWndControl, wMsg, wParam, lParam)
   
End Function

' 拖拽标志及记录变量
' Dim Shared bDragging As Boolean '已经搬到定义文件处
' Dim Shared StartScreenX As Long, StartScreenY As Long   ' 鼠标按下时的屏幕坐标 '已经搬到定义文件处
' Dim Shared FormLeftAtDrag As Long, FormTopAtDrag As Long ' 窗体按下时的位置 '已经搬到定义文件处


 
Sub StartDrag(ByVal hWndFrom As Long, ByVal xClient As Long, ByVal yClient As Long)
    Dim pt As POINT
    pt.x = xClient
    pt.y = yClient
    ' 将客户区坐标转换为屏幕坐标
    ClientToScreen(hWndFrom, @pt)
    StartScreenX = pt.x
    StartScreenY = pt.y
    ' 记录当前窗体位置
    FormLeftAtDrag = Form1.Left
    FormTopAtDrag = Form1.Top
    ' 设置拖拽标志并捕获鼠标
    bDragging = True
    SetCapture(Form1.hWnd)   ' 捕获到窗体，使后续鼠标消息都发往窗体
End Sub


'计时器初始值
'可以写成一行= {{7, 30}, {2, 10}, {9, 50}}
' Dim Shared 初始倒计时(1 To 3, 1 To 2) As Integer = _ '已经搬到定义文件处
' { _ '已经搬到定义文件处
'     {7, 30}, _ ' 初始倒计时(1,1) 和 (1,2) '已经搬到定义文件处
'     {2, 10}, _ ' 初始倒计时(2,1) 和 (2,2) '已经搬到定义文件处
'     {9, 50} _  ' 初始倒计时(3,1) 和 (3,2) '已经搬到定义文件处
' } '已经搬到定义文件处

' Dim Shared 固定总时间(1 To 3) As Double  '毫秒 '已经搬到定义文件处
' Dim Shared 使用总时间(1 To 3) As Double  '毫秒 '已经搬到定义文件处
' Dim Shared 开始点(1 To 3) As Double '已经搬到定义文件处
' Dim Shared 工作中(1 To 3) As Boolean '默认false '已经搬到定义文件处
' Dim Shared 发声(1 To 3) As Boolean   'true=正在发声 '已经搬到定义文件处

' 更新控件索引倒计时的显示标签
Sub CH_E69BB4E696B0E58092E8AEA1E697B6E698BEE7A4BA_(i As Integer, CH_E698BEE7A4BAE697B6E997B4_ As Double)
    Dim CH_E58886E9929F_ As Integer, CH_E7A792_ As Integer
    If CH_E698BEE7A4BAE697B6E997B4_ <= 0 Then
        CH_E58886E9929F_ = 0
        CH_E7A792_ = 0
    Else
        CH_E58886E9929F_ = Int(CH_E698BEE7A4BAE697B6E997B4_ / 60000)
        CH_E7A792_ = Int((CH_E698BEE7A4BAE697B6E997B4_ Mod 60000) / 1000)
     End If
     Form1.CH_E58092E8AEA1E697B6_(i).Caption = Format(CH_E58886E9929F_, "00") & ":" & Format(CH_E7A792_, "00")
End Sub

' 重置倒计时
Sub CH_E9878DE7BDAEE58092E8AEA1E697B6_(i As Integer)
   CH_E5B7A5E4BD9CE4B8AD_(i) = False 
   CH_E58F91E5A3B0_(i) = False
   Form1.CH_E590AFE58AA8_(i-1).Caption = "开始"
   Form1.CH_E58092E8AEA1E697B6_(i -1).ForeColor = RGB(0, 0, 0)
   CH_E5BC80E5A78BE782B9_(i) = 0
   CH_E4BDBFE794A8E680BBE697B6E997B4_(i) = CH_E59BBAE5AE9AE680BBE697B6E997B4_(i)
End Sub



'[Form1]事件 : 窗口完全显示后。
'hWndForm  当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'UserData  来自显示窗口最后1个参数，例： Form2.Show(父窗口句柄,模式,UserData)
Sub Form1_Shown(hWndForm As hWnd, UserData As Integer)
   Dim i As Integer
   For i = 1 To 3
    ' 初始化总时间，分钟秒钟转为毫秒
    CH_E59BBAE5AE9AE680BBE697B6E997B4_(i) = CH_E5889DE5A78BE58092E8AEA1E697B6_(i, 1) * 60 * 1000 + CH_E5889DE5A78BE58092E8AEA1E697B6_(i, 2) * 1000
    CH_E4BDBFE794A8E680BBE697B6E997B4_(i) = CH_E59BBAE5AE9AE680BBE697B6E997B4_(i)
    ' 初始化倒计时显示
    Form1.CH_E58092E8AEA1E697B6_(i -1).Caption = Format(CH_E5889DE5A78BE58092E8AEA1E697B6_(i, 1), "00") & ":" & Format(CH_E5889DE5A78BE58092E8AEA1E697B6_(i, 2), "00")
    CH_E5B7A5E4BD9CE4B8AD_(i) = False
    CH_E58F91E5A3B0_(i) = False
   Next i
   Form1.Timer1.Enabled = False
   Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Enabled =False

End Sub

'[Form1.Timer1]事件 : 定时器
'hWndForm  当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
''         本控件为功能控件，就是无窗口，无显示，只有功能。如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 
'wTimerID  定时器ID，区分不同定时器的编号
Sub Form1_Timer1_WM_Timer(hWndForm As hWnd, wTimerID As Long)
   Dim i As Integer
   Dim CH_E6B688E88097E697B6E997B4_ As Double            ' 单位秒
   Dim CH_E698BEE7A4BAE697B6E997B4_ As Double            ' 单位毫秒
   
   For i = 1 To 3
      If CH_E5B7A5E4BD9CE4B8AD_(i) = True Then
         CH_E6B688E88097E697B6E997B4_ = Timer - CH_E5BC80E5A78BE782B9_(i)
         ' 跨夜补偿
         If CH_E6B688E88097E697B6E997B4_ < 0 Then CH_E6B688E88097E697B6E997B4_ = CH_E6B688E88097E697B6E997B4_ + 86400
         
         CH_E698BEE7A4BAE697B6E997B4_ = CH_E4BDBFE794A8E680BBE697B6E997B4_(i) - CH_E6B688E88097E697B6E997B4_ * 1000
         
         ' 倒计时正常结束
         If CH_E698BEE7A4BAE697B6E997B4_ <= 0 Then
            CH_E5B7A5E4BD9CE4B8AD_(i) = False '关闭倒计时，持续显示0：0
            CH_E58F91E5A3B0_(i) = True
            Form1.CH_E590AFE58AA8_(i -1).Caption = "结束"
            Form1.CH_E58092E8AEA1E697B6_(i-1).ForeColor = RGB(255, 0, 0)  '红色
            CH_E698BEE7A4BAE697B6E997B4_ = 0
            Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Enabled =True
         End If
         CH_E69BB4E696B0E58092E8AEA1E697B6E698BEE7A4BA_(i-1,CH_E698BEE7A4BAE697B6E997B4_)
      End If  
   Next i

   ' 如果所有倒计时都停止，则关闭定时器
   If CH_E5B7A5E4BD9CE4B8AD_(1) = False And CH_E5B7A5E4BD9CE4B8AD_(2) = False And CH_E5B7A5E4BD9CE4B8AD_(3) = False Then
        Form1.Timer1.Enabled = False
   End If

End Sub

'[Form1.启动]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub Form1_CH_E590AFE58AA8__BN_Clicked(ControlIndex As Long, hWndForm As hWnd, hWndControl As hWnd)
   If CH_E58F91E5A3B0_(ControlIndex + 1) = True Then
      ' 正在发声，点击就是重置
      CH_E58F91E5A3B0_(ControlIndex + 1) = False
      CH_E9878DE7BDAEE58092E8AEA1E697B6_(ControlIndex + 1)
      CH_E69BB4E696B0E58092E8AEA1E697B6E698BEE7A4BA_(ControlIndex,CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex + 1))
   ElseIf CH_E5B7A5E4BD9CE4B8AD_(ControlIndex + 1) = False Then
      ' 没有发声，且倒计时关闭，点击就是开始
      CH_E5B7A5E4BD9CE4B8AD_(ControlIndex + 1) = True
      Form1.CH_E590AFE58AA8_(ControlIndex).Caption = "重置"
      Form1.CH_E58092E8AEA1E697B6_(ControlIndex).ForeColor = RGB(0, 255, 0) ' 绿色
      CH_E5BC80E5A78BE782B9_(ControlIndex + 1) = Timer
   Else
      '正在倒计时，点击就是手动重置
      CH_E9878DE7BDAEE58092E8AEA1E697B6_(ControlIndex + 1)
      CH_E69BB4E696B0E58092E8AEA1E697B6E698BEE7A4BA_(ControlIndex,CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex + 1))
   End If
   ' 只要有一个倒计时在工作，有一个要发声，就开启定时器
   Form1.Timer1.Enabled = (CH_E5B7A5E4BD9CE4B8AD_(1) Or CH_E5B7A5E4BD9CE4B8AD_(2) Or CH_E5B7A5E4BD9CE4B8AD_(3))
   Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Enabled = (CH_E58F91E5A3B0_(1) Or CH_E58F91E5A3B0_(2) Or CH_E58F91E5A3B0_(3))
End Sub

'[Form1.发声]事件 : 定时器
'hWndForm  当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
''         本控件为功能控件，就是无窗口，无显示，只有功能。如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 
'wTimerID  定时器ID，区分不同定时器的编号
Sub Form1_CH_E58F91E5A3B0E8AEA1E697B6E599A8__WM_Timer(hWndForm As hWnd, wTimerID As Long)
   ' 发声开关打开则运行，无则关闭计时器
   If CH_E58F91E5A3B0_(1) Or CH_E58F91E5A3B0_(2) Or CH_E58F91E5A3B0_(3) Then
      Beep
   Else
      Form1.CH_E58F91E5A3B0E8AEA1E697B6E599A8_.Enabled =False
   End If
End Sub

'[Form1.减时]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub Form1_CH_E5878FE697B6__BN_Clicked(ControlIndex As Long, hWndForm As hWnd, hWndControl As hWnd)
   ' 仅在倒计时进行中有效
    If CH_E5B7A5E4BD9CE4B8AD_(ControlIndex+1) = False Then Exit Sub
    
    ' 减去5秒（5000毫秒）
    CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1) = CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1) - 5000
    If CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1) < 0 Then CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1) = 0
    
    ' 更新对应倒计时显示
    CH_E69BB4E696B0E58092E8AEA1E697B6E698BEE7A4BA_(ControlIndex, CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1))
End Sub

'[Form1.加时]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub Form1_CH_E58AA0E697B6__BN_Clicked(ControlIndex As Long, hWndForm As hWnd, hWndControl As hWnd)
   ' 仅在倒计时进行中有效
    If CH_E5B7A5E4BD9CE4B8AD_(ControlIndex+1) = False Then Exit Sub
    
    ' 减去5秒（5000毫秒）
    CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1) = CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1) + 5000
    ' 更新对应倒计时显示
    CH_E69BB4E696B0E58092E8AEA1E697B6E698BEE7A4BA_(ControlIndex, CH_E4BDBFE794A8E680BBE697B6E997B4_(ControlIndex+1))

End Sub

'[Form1.牛堡窗口]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub Form1_CH_E7899BE5A0A1E7AA97E58FA3__BN_Clicked(hWndForm As hWnd, hWndControl As hWnd)
   CH_E69DA1E5AD90E8AEA1E7AE97_.Show(Form1.hWnd)
End Sub

'[Form1]事件 : 单击鼠标右键，通常用于弹出菜单
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'xPos yPos   当前鼠标位置，相对于屏幕。就是屏幕坐标。
Sub Form1_WM_ContextMenu(hWndForm As hWnd, xPos As Long, yPos As Long)
    Form1.Close() 
End Sub

'[Form1]事件 : 按下鼠标左键
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'MouseFlags  MK_CONTROL   MK_LBUTTON     MK_MBUTTON     MK_RBUTTON    MK_SHIFT     MK_XBUTTON1       MK_XBUTTON2 
''           CTRL键按下   鼠标左键按下   鼠标中键按下   鼠标右键按下  SHIFT键按下  第一个X按钮按下   第二个X按钮按下
'检查什么键按下用  If (MouseFlags And MK_CONTROL)<>0 Then CTRL键按下 
'xPos yPos   当前鼠标位置，相对于窗口。就是在窗口客户区里的坐标。
Sub Form1_WM_LButtonDown(hWndForm As hWnd, MouseFlags As Long, xPos As Long, yPos As Long)
   StartDrag(hWndForm, xPos, yPos)
End Sub

'[Form1]事件 : 移动鼠标
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'MouseFlags  MK_CONTROL   MK_LBUTTON     MK_MBUTTON     MK_RBUTTON    MK_SHIFT     MK_XBUTTON1       MK_XBUTTON2 
''           CTRL键按下   鼠标左键按下   鼠标中键按下   鼠标右键按下  SHIFT键按下  第一个X按钮按下   第二个X按钮按下
'检查什么键按下用  If (MouseFlags And MK_CONTROL)<>0 Then CTRL键按下 
'xPos yPos   当前鼠标位置，相对于窗口。就是在窗口客户区里的坐标。
Sub Form1_WM_MouseMove(hWndForm As hWnd, MouseFlags As Long, xPos As Long, yPos As Long)
   
   If bDragging AndAlso (MouseFlags And 1) Then ' 左键仍按下
      Dim pt As Point
      GetCursorPos(@pt) ' 获取当前鼠标屏幕坐标
      ' 根据起始偏移计算新位置
      Form1.Left = FormLeftAtDrag + (pt.x - StartScreenX)
      Form1.Top  = FormTopAtDrag  + (pt.y - StartScreenY)
   End If
End Sub

'[Form1]事件 : 释放鼠标左键
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'MouseFlags  MK_CONTROL   MK_LBUTTON     MK_MBUTTON     MK_RBUTTON    MK_SHIFT     MK_XBUTTON1       MK_XBUTTON2 
''           CTRL键按下   鼠标左键按下   鼠标中键按下   鼠标右键按下  SHIFT键按下  第一个X按钮按下   第二个X按钮按下
'检查什么键按下用  If (MouseFlags And MK_CONTROL)<>0 Then CTRL键按下 
'xPos yPos   当前鼠标位置，相对于窗口。就是在窗口客户区里的坐标。
Sub Form1_WM_LButtonUp(hWndForm As hWnd, MouseFlags As Long, xPos As Long, yPos As Long)
   If bDragging Then
      bDragging = False
      ReleaseCapture() ' 释放鼠标捕获
   End If
   
End Sub















 