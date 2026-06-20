'[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|779]
'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.9.8 生成的源代码
' 生成时间：2026年03月18日 21时50分16秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------

'------------------------------------------------------------------------------
'VisualFreeBasic 自动生成的 条子计算 函数
'------------------------------------------------------------------------------
'{FORM_WS_EX_NOACTIVATE3}  '为无焦点窗口创建定义
Function CH_E69DA1E5AD90E8AEA1E7AE97__Class_Form.Show(hWndParent As .hWnd = HWND_DESKTOP, Modal As Boolean = False, UserData As Integer = 0) As .hWnd  '加载窗口并且显示, 模态显示用True {2.True.False} UserData 是传递给创建事件的参数，不保存数值
   '注：hWnd 是类属性，与API的 hWnd 冲突，因此使用 .hWnd 表示API，就是前面加个小数点。
   If This.Repeat = False Then     '是不是不允许多开窗口
      If IsWindow(This.hWnd) Then 
         This.FlashWindow
         Return This.hWnd
      End If 
   End if 
'{FORM_WS_EX_NOACTIVATE}  '为无焦点窗口创建多线程代码
   Dim pWindow AS CWindow Ptr = New CWindow(!"\u725B\u5B50\u52A9\u624B\u005F\u6761\u5B50\u8BA1\u7B97")
   '创建一个窗口
  Dim NewhWnd As .hWnd = pWindow->Create(hWndParent, !"\u725B\u5821", Cast(WNDPROC, @CH_E69DA1E5AD90E8AEA1E7AE97__FORMPROCEDURE), 0, 0, 327, 390, WS_MINIMIZEBOX Or WS_MAXIMIZEBOX Or WS_BORDER Or WS_CAPTION Or WS_SYSMENU Or WS_CLIPSIBLINGS Or WS_CLIPCHILDREN Or WS_POPUP Or WS_SIZEBOX, WS_EX_LEFT Or WS_EX_LTRREADING Or WS_EX_RIGHTSCROLLBAR Or WS_EX_TOOLWINDOW Or WS_EX_CONTROLPARENT)
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
   fp->nName = "条子计算"
   
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
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 0
      fp->IDC = 102
      fp->nText = !"\u5F53\u524D\u9636\u6BB5"
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).IDC =102
      fp->nName = !"\u56FA\u5B9A\u6587\u5B57"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).CAPTION = !"\u5F53\u524D\u9636\u6BB5"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).Font = "Microsoft YaHei,14"
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).FontWidth =0
      This.CH_E59BBAE5AE9AE69687E5AD97_(0).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,2) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 60
      fp->nTop = 20
      fp->nWidth = 90
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 1
      fp->IDC = 103
      fp->nText = !"\u5F53\u524D\u8FDB\u5EA6"
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).IDC =103
      fp->nName = !"\u56FA\u5B9A\u6587\u5B57"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).CAPTION = !"\u5F53\u524D\u8FDB\u5EA6"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).Font = "Microsoft YaHei,14"
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).FontWidth =0
      This.CH_E59BBAE5AE9AE69687E5AD97_(1).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,2) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 30
      fp->nTop = 60
      fp->nWidth = 120
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 2
      fp->IDC = 104
      fp->nText = !"\u5F53\u524D\u6761\u5B50"
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).IDC =104
      fp->nName = !"\u56FA\u5B9A\u6587\u5B57"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).CAPTION = !"\u5F53\u524D\u6761\u5B50"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).Font = "Microsoft YaHei,14"
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).FontWidth =0
      This.CH_E59BBAE5AE9AE69687E5AD97_(2).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,2) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 60
      fp->nTop = 100
      fp->nWidth = 90
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 3
      fp->IDC = 105
      fp->nText = !"\u6761\u5B50\u901F\u5EA6\u0028\u6BCF\u0035\u5206\u0029"
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).IDC =105
      fp->nName = !"\u56FA\u5B9A\u6587\u5B57"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).CAPTION = !"\u6761\u5B50\u901F\u5EA6\u0028\u6BCF\u0035\u5206\u0029"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).Font = "Microsoft YaHei,14"
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).FontWidth =0
      This.CH_E59BBAE5AE9AE69687E5AD97_(3).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,2) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 0
      fp->nTop = 140
      fp->nWidth = 150
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.Line1.hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 106
      fp->nText = ""
      This.Line1.IDC =106
      fp->nName = !"\u004C\u0069\u006E\u0065\u0031"
      fp->Style = (fp->Style And &H0FFFFFFF) Or (Cast(UInteger,0) Shl 28)
      fp->Style = (fp->Style And &HF0FFFFFF) Or (Cast(UInteger,1) Shl 24)
      fp->Style = (fp->Style And &HFF0FFFFF) Or (Cast(UInteger,0) Shl 20)
      fp->Style = (fp->Style And &HFFF0FFFF) Or (Cast(UInteger,0) Shl 16)
      fp->Style = (fp->Style And &HFFFF0FFF) Or (Cast(UInteger,0) Shl 12)
      fp->Style = (fp->Style And &HFFFFF0FF) Or (Cast(UInteger,0) Shl 8)
      fp->ForeColor = &HFF000000
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      fp->nLeft = 10
      fp->nTop = 190
      fp->nWidth = 300
      fp->nHeight = 10
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 4
      fp->IDC = 107
      fp->nText = !"\u672C\u9636\u6BB5\u5269\u4F59"
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).IDC =107
      fp->nName = !"\u56FA\u5B9A\u6587\u5B57"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).CAPTION = !"\u672C\u9636\u6BB5\u5269\u4F59"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).Font = "Microsoft YaHei,14"
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).FontWidth =0
      This.CH_E59BBAE5AE9AE69687E5AD97_(4).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,5) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 20
      fp->nTop = 210
      fp->nWidth = 130
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 5
      fp->IDC = 108
      fp->nText = !"\u5168\u5B8C\u6210\u5269\u4F59"
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).IDC =108
      fp->nName = !"\u56FA\u5B9A\u6587\u5B57"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).CAPTION = !"\u5168\u5B8C\u6210\u5269\u4F59"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).Font = "Microsoft YaHei,14"
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).FontWidth =0
      This.CH_E59BBAE5AE9AE69687E5AD97_(5).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,5) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 20
      fp->nTop = 260
      fp->nWidth = 130
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("COMBOBOX", hWnd, 109, "", 180, 20, 100, 300,WS_CHILD Or WS_VSCROLL Or WS_CLIPSIBLINGS Or CBS_DROPDOWN Or CBS_AUTOHSCROLL Or WS_VISIBLE Or WS_TABSTOP ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 109
      fp->nText = ""
      This.CH_E998B6E6AEB5E98089E68BA9_.hWnd = hWndControl 
      This.CH_E998B6E6AEB5E98089E68BA9_.IDC =109
      fp->nName = !"\u9636\u6BB5\u9009\u62E9"
      SNDMSG(hWndControl, CB_SETITEMHEIGHT, -1, AfxScaleY(20))
      SNDMSG(hWndControl, CB_SETITEMHEIGHT, 0, AfxScaleY(18))
      This.CH_E998B6E6AEB5E98089E68BA9_.ForeColor =GetCodeColorGDI(&H087F7F7F,GetSysColor(COLOR_BTNTEXT))
      fp->ForeColor =&H087F7F7F
      This.CH_E998B6E6AEB5E98089E68BA9_.BackColor =GetCodeColorGDI(&H057F7F7F,GetSysColor(COLOR_BTNFACE))
      fp->BackColor =&H057F7F7F
      This.CH_E998B6E6AEB5E98089E68BA9_.Font = "Microsoft YaHei,12"
      fp->nLeft = 180
      fp->nTop = 20
      fp->nWidth = 100
      fp->nHeight = 22
   End IF

   hWndControl = pWindow->AddControl("COMBOBOX", hWnd, 110, "", 180, 60, 100, 300,WS_CHILD Or WS_VSCROLL Or WS_CLIPSIBLINGS Or CBS_DROPDOWNLIST Or CBS_AUTOHSCROLL Or WS_VISIBLE Or WS_TABSTOP ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 110
      fp->nText = ""
      This.CH_E8BF9BE5BAA6E98089E68BA9_.hWnd = hWndControl 
      This.CH_E8BF9BE5BAA6E98089E68BA9_.IDC =110
      fp->nName = !"\u8FDB\u5EA6\u9009\u62E9"
      SNDMSG(hWndControl, CB_SETITEMHEIGHT, -1, AfxScaleY(20))
      SNDMSG(hWndControl, CB_SETITEMHEIGHT, 0, AfxScaleY(18))
      This.CH_E8BF9BE5BAA6E98089E68BA9_.ForeColor =GetCodeColorGDI(&H087F7F7F,GetSysColor(COLOR_BTNTEXT))
      fp->ForeColor =&H087F7F7F
      This.CH_E8BF9BE5BAA6E98089E68BA9_.BackColor =GetCodeColorGDI(&H057F7F7F,GetSysColor(COLOR_BTNFACE))
      fp->BackColor =&H057F7F7F
      This.CH_E8BF9BE5BAA6E98089E68BA9_.Font = "Microsoft YaHei,12"
      fp->nLeft = 180
      fp->nTop = 60
      fp->nWidth = 100
      fp->nHeight = 22
   End IF

   hWndControl = pWindow->AddControl("TEXTBOX", hWnd, 111, , 180, 100, 100, 30,WS_CHILD Or WS_CLIPSIBLINGS Or ES_LEFT Or WS_VISIBLE Or ES_AUTOHSCROLL Or WS_TABSTOP Or ES_WANTRETURN ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 111
      This.CH_E69DA1E5AD90E8BE93E585A5_.hWnd = hWndControl 
      This.CH_E69DA1E5AD90E8BE93E585A5_.IDC =111
      fp->nName = !"\u6761\u5B50\u8F93\u5165"
      This.CH_E69DA1E5AD90E8BE93E585A5_.TEXT = !"\u0030"
      This.CH_E69DA1E5AD90E8BE93E585A5_.ForeColor =GetCodeColorGDI(&H087F7F7F,GetSysColor(COLOR_BTNTEXT))
      fp->ForeColor =&H087F7F7F
      This.CH_E69DA1E5AD90E8BE93E585A5_.BackColor =GetCodeColorGDI(&H057F7F7F,GetSysColor(COLOR_BTNFACE))
      fp->BackColor =&H057F7F7F
      This.CH_E69DA1E5AD90E8BE93E585A5_.Font = "Microsoft YaHei,12"
      fp->nLeft = 180
      fp->nTop = 100
      fp->nWidth = 100
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("UPDOWN", hWnd, 112, "", 280, 140, 20, 30,WS_CHILD Or WS_CLIPSIBLINGS Or UDS_ARROWKEYS Or UDS_ALIGNRIGHT Or UDS_SETBUDDYINT Or UDS_NOTHOUSANDS Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 112
      fp->nText = ""
      This.UpDown1.hWnd = hWndControl 
      This.UpDown1.IDC =112
      fp->nName = !"\u0055\u0070\u0044\u006F\u0077\u006E\u0031"
      This.UpDown1.MaxValue = 100
      This.UpDown1.MinValue = 1
      This.UpDown1.Value = 1
      fp->nLeft = 280
      fp->nTop = 140
      fp->nWidth = 20
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("TEXTBOX", hWnd, 113, , 180, 140, 100, 30,WS_CHILD Or WS_CLIPSIBLINGS Or ES_LEFT Or WS_VISIBLE Or WS_TABSTOP Or ES_WANTRETURN ,WS_EX_CLIENTEDGE , , Cast(Any Ptr, @CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 113
      This.CH_E9809FE5BAA6E8BE93E585A5_.hWnd = hWndControl 
      This.CH_E9809FE5BAA6E8BE93E585A5_.IDC =113
      fp->nName = !"\u901F\u5EA6\u8F93\u5165"
      This.CH_E9809FE5BAA6E8BE93E585A5_.TEXT = !"\u0031\u0030"
      This.CH_E9809FE5BAA6E8BE93E585A5_.ForeColor =GetCodeColorGDI(&H087F7F7F,GetSysColor(COLOR_BTNTEXT))
      fp->ForeColor =&H087F7F7F
      This.CH_E9809FE5BAA6E8BE93E585A5_.BackColor =GetCodeColorGDI(&H057F7F7F,GetSysColor(COLOR_BTNFACE))
      fp->BackColor =&H057F7F7F
      This.CH_E9809FE5BAA6E8BE93E585A5_.Font = "Microsoft YaHei,12"
      fp->nLeft = 180
      fp->nTop = 140
      fp->nWidth = 100
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E5B195E7A4BAE697B6E997B4_(0).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 0
      fp->IDC = 114
      fp->nText = !"\u0030"
      This.CH_E5B195E7A4BAE697B6E997B4_(0).IDC =114
      fp->nName = !"\u5C55\u793A\u65F6\u95F4"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E5B195E7A4BAE697B6E997B4_(0).CAPTION = !"\u0030"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E5B195E7A4BAE697B6E997B4_(0).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E5B195E7A4BAE697B6E997B4_(0).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E5B195E7A4BAE697B6E997B4_(0).Font = "Microsoft YaHei,14"
      This.CH_E5B195E7A4BAE697B6E997B4_(0).FontWidth =0
      This.CH_E5B195E7A4BAE697B6E997B4_(0).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,3) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 170
      fp->nTop = 210
      fp->nWidth = 100
      fp->nHeight = 30
   End IF

   fp->VrControls = new FormControlsPro_TYPE '创建虚拟控件链表
   fp = fp->VrControls
   If fp Then 
      This.CH_E5B195E7A4BAE697B6E997B4_(1).hWndForm = hWnd 
      fp->hWndParent = hWnd
      fp->Index = 1
      fp->IDC = 115
      fp->nText = !"\u0030"
      This.CH_E5B195E7A4BAE697B6E997B4_(1).IDC =115
      fp->nName = !"\u5C55\u793A\u65F6\u95F4"
      fp->Style = (fp->Style And &H00FFFFFF) Or (Cast(UInteger,0) Shl 24)
      This.CH_E5B195E7A4BAE697B6E997B4_(1).CAPTION = !"\u0030"
      fp->Style Or= &H1 
      fp->Style Or= &H2 
      This.CH_E5B195E7A4BAE697B6E997B4_(1).ForeColorGDIplue =GetCodeColorGDIplue(&H087F7F7F,&HFF000000)
      fp->ForeColor =&H087F7F7F
      This.CH_E5B195E7A4BAE697B6E997B4_(1).BackColorGDIplue =GetCodeColorGDIplue(&H197F7F7F,&HFFE0E0E0)
      fp->BackColor =&H197F7F7F
      This.CH_E5B195E7A4BAE697B6E997B4_(1).Font = "Microsoft YaHei,14"
      This.CH_E5B195E7A4BAE697B6E997B4_(1).FontWidth =0
      This.CH_E5B195E7A4BAE697B6E997B4_(1).FontAngle =0
      fp->Style = (fp->Style And &HFF00FFFF) Or (Cast(UInteger,3) Shl 16)
      fp->Style Or= &H4 
      fp->Style And= Not &H8 
      fp->nLeft = 170
      fp->nTop = 260
      fp->nWidth = 100
      fp->nHeight = 30
   End IF

   hWndControl = pWindow->AddControl("BUTTON", hWnd, 116, !"\u8BA1\u0020\u0020\u0020\u0020\u0020\u7B97", 50, 300, 220, 40,WS_CHILD Or WS_CLIPSIBLINGS Or BS_PUSHBUTTON Or BS_VCENTER Or BS_CENTER Or WS_VISIBLE Or WS_TABSTOP ,0 , , Cast(Any Ptr, @CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE))
   If hWndControl Then 
      Dim fp As FormControlsPro_TYPE ptr = new FormControlsPro_TYPE
      vfb_Set_Control_Ptr(hWndControl,fp)
      fp->hWndParent = hWnd
      fp->Index = -1
      fp->IDC = 116
      fp->nText = !"\u8BA1\u0020\u0020\u0020\u0020\u0020\u7B97"
      This.CH_E8AEA1E7AE97E68C89E992AE_.hWnd = hWndControl 
      This.CH_E8AEA1E7AE97E68C89E992AE_.IDC =116
      fp->nName = !"\u8BA1\u7B97\u6309\u94AE"
      This.CH_E8AEA1E7AE97E68C89E992AE_.CAPTION = !"\u8BA1\u0020\u0020\u0020\u0020\u0020\u7B97"
      This.CH_E8AEA1E7AE97E68C89E992AE_.Font = "Microsoft YaHei,16"
      fp->nLeft = 50
      fp->nTop = 300
      fp->nWidth = 220
      fp->nHeight = 40
   End IF

'[Create control]  创建控件的代码，在此前一行插入。

      This.UpDown1.Buddy = This.CH_E9809FE5BAA6E8BE93E585A5_.hWnd
'[Create control end]  创建全部控件后需要处理的代码，在此前一行插入。


   PostMessage(NewhWnd, &H1000, &H1000,CAst(lPArAm,UserData)) '触发显示事件
   
   hWndControl = NewhWnd '设置焦点后会发生消息循环的情况，要是同时多开同一个窗口，就发生 hWnd 被赋值为下一个窗口句柄的情况。
   This.CH_E998B6E6AEB5E98089E68BA9_.SetFocus
'[SET_FOCUS] '将焦点设置为选项卡顺序中的最低控件 
   Function = FLY_DoMessagePump(pWindow,Modal, hWndControl, hWndParent, SW_SHOWNORMAL, False) ' IsMDIForm 如果这是MDI窗口，请设置标志
End Function

Function CH_E69DA1E5AD90E8AEA1E7AE97__FORMPROCEDURE(ByVal hWndForm As hWnd, ByVal wMsg As UInteger, ByVal wParam As wParam, ByVal lParam As lParam) As LResult '条子计算 窗口回调过程
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
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E5B195E7A4BAE697B6E997B4_(1).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E5B195E7A4BAE697B6E997B4_(1).Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E5B195E7A4BAE697B6E997B4_(0).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E5B195E7A4BAE697B6E997B4_(0).Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(5).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(5).Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(4).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(4).Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.Line1.hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.Line1.Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(3).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(3).Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(2).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(2).Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(1).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(1).Drawing(gg,hWndForm,WinCc)  
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(0).hWndForm = hWndForm 
            CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E59BBAE5AE9AE69687E5AD97_(0).Drawing(gg,hWndForm,WinCc)  
            
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
             CH_E69DA1E5AD90E8AEA1E7AE97__SHOWN(hWndForm ,Cast(Integer,lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|14]
'[FORM_SHOWN]  主窗口第一次显示事件，在此前一行插入。
            InvalidateRect(hWndForm, Null, True)
            UpdateWindow(hWndForm)
            '[Create window shadow]  创建窗口阴影，在此前一行插入。
            Return 0
         End If
      Case WM_COMMAND
         
'[FORM_WM_COMMAND]  主窗口命令处理事件，在此前一行插入。
                  Dim As Long IDC =LoWord(wParam) ,CODE = HiWord(wParam)  '控件处理初始化代码
                   If IDC = 109 And CODE = CBN_SELCHANGE Then  ' 阶段选择
              CH_E69DA1E5AD90E8AEA1E7AE97__CH_E998B6E6AEB5E98089E68BA9__CBN_SELCHANGE(hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|30]
           End If
          If IDC = 116 And CODE = BN_CLICKED Then  ' 计算按钮
              CH_E69DA1E5AD90E8AEA1E7AE97__CH_E8AEA1E7AE97E68C89E992AE__BN_CLICKED(hWndForm, Cast(HWND, lParam))  '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|49]
           End If
'[CONTROL_WM_COMMAND]  控件处理事件，在此前一行插入。
      Case WM_HSCROLL
         
'[FORM_WM_HSCROLL]  主窗口和一些特殊控件要的事件，在此前一行插入。
      Case WM_VSCROLL
         
'[FORM_WM_VSCROLL]  主窗口和一些特殊控件要的事件，在此前一行插入。
         
         















'[Other events in main window]  主窗口其它事件，需要加 Case ，在此前一行插入。 注意每个消息值不可重复，不然后面的无法执行
         '{FORM_WM_DRAWITEM}
         '[FORM_WM_DRAWITEM]
      Case WM_TIMER
         If wParam = 357897 then '虚拟控件要刷新，使用防抖动方式刷新，避免虚拟控件多时，同时设置控件属性，造成大量刷新变卡顿。
            KillTimer hWndForm, 357897
            InvalidateRect hWndForm, NULL, CTRUE
            UpdateWindow hWndForm
         End If
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
         
         '[DELETE_USER_TIMERS] 删除任何用户定义的Timer控件
         
         CH_E69DA1E5AD90E8AEA1E7AE97_.hWnd = 0
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

Function CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE(ByVal hWndControl As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LRESULT  ' 条子计算 控件回调
   '条子计算 窗口上每个控件的所有消息都在此函数中处理。
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
' DimP stage(6) As String '已经搬到定义文件处
stage(0) = "原木"
stage(1) = "青铜"
stage(2) = "白银"
stage(3) = "黄金"
stage(4) = "白金"
stage(5) = "秘银"
stage(6) = "钻石"
' DimP stageData(6, 2) As Integer = {{1, 100, 4}, {101, 220, 4}, {221, 395, 5}, {396, 595, 5}, {596, 820, 5}, {821, 1120, 6}, {1121, 1450, 6}} '已经搬到定义文件处


'[条子计算]事件 : 窗口完全显示后。
'hWndForm  当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'UserData  来自显示窗口最后1个参数，例： Form2.Show(父窗口句柄,模式,UserData)
Sub CH_E69DA1E5AD90E8AEA1E7AE97__Shown(hWndForm As hWnd, UserData As Integer)
   ' 初始化
   Dim i As Integer
   For i = LBound(stage) To UBound(stage)
      CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E998B6E6AEB5E98089E68BA9_.AddItem stage(i)
   Next i
   CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E998B6E6AEB5E98089E68BA9_.ListIndex = 0
   For i = 1 To 4
      CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E8BF9BE5BAA6E98089E68BA9_.AddItem Str(i)
   Next
   CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E8BF9BE5BAA6E98089E68BA9_.ListIndex = 0
End Sub

'[条子计算.阶段选择]事件 : 列表框中更改当前选择时
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub CH_E69DA1E5AD90E8AEA1E7AE97__CH_E998B6E6AEB5E98089E68BA9__CBN_SelChange(hWndForm As hWnd, hWndControl As hWnd)
   Dim s As Integer = CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E998B6E6AEB5E98089E68BA9_.ListIndex
   ' 刷新进度选择下拉框
   If s >= 0 And s <= 6 Then
      Dim CH_E69C80E5A4A7E8BF9BE5BAA6_ As Integer = stageData(s, 2)
      ' 清空进度列表
      CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E8BF9BE5BAA6E98089E68BA9_.Clear
      Dim i As Integer
      For i = 1 To CH_E69C80E5A4A7E8BF9BE5BAA6_
         CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E8BF9BE5BAA6E98089E68BA9_.AddItem Str(i)
      Next
      CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E8BF9BE5BAA6E98089E68BA9_.ListIndex = 0
   End If
End Sub


'[条子计算.计算按钮]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub CH_E69DA1E5AD90E8AEA1E7AE97__CH_E8AEA1E7AE97E68C89E992AE__BN_Clicked(hWndForm As hWnd, hWndControl As hWnd)
   Dim CH_E5BD93E5898DE998B6E6AEB5_    As Integer = CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E998B6E6AEB5E98089E68BA9_.ListIndex
   Dim CH_E5BD93E5898DE8BF9BE5BAA6_    As Integer = CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E8BF9BE5BAA6E98089E68BA9_.ListIndex + 1
   Dim mybar       As Integer = 0 ' 目前获得的条子总量
   Dim barnum      As Integer = ValInt(CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E69DA1E5AD90E8BE93E585A5_.Text) '额外条子量
   Dim speed       As Integer = ValInt(CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E9809FE5BAA6E8BE93E585A5_.Text)
   Dim CH_E5BD93E5898DE58CBAE997B4E5B7A6_ As Integer

   
   '计算区间
   Dim CH_E5A78BE69DA1E9878F_     As Integer = stageData(CH_E5BD93E5898DE998B6E6AEB5_, 0)
   Dim CH_E7BB88E69DA1E9878F_     As Integer = stageData(CH_E5BD93E5898DE998B6E6AEB5_, 1)
   Dim CH_E8BF9BE5BAA6E4B8AAE695B0_   As Integer = stageData(CH_E5BD93E5898DE998B6E6AEB5_, 2)
   Dim CH_E8BF9BE5BAA6E79A84E995BFE5BAA6_ As Integer = (CH_E7BB88E69DA1E9878F_ - CH_E5A78BE69DA1E9878F_ + 1) / CH_E8BF9BE5BAA6E4B8AAE695B0_
   CH_E5BD93E5898DE58CBAE997B4E5B7A6_ = Fix(CH_E5A78BE69DA1E9878F_ + CH_E5BD93E5898DE8BF9BE5BAA6_ *CH_E8BF9BE5BAA6E79A84E995BFE5BAA6_)
   '当前区间右 = Fix(始条量 + (当前进度 + 1) *进度的长度 -1)
   
   mybar = (CH_E5BD93E5898DE58CBAE997B4E5B7A6_ -1) + barnum

   
   ' 计算全部完成需要时间
    CH_E8AEA1E7AE97E697B6E997B4E5B9B6E5B195E7A4BA_(1450, mybar, speed,1)
   
   ' 计算本阶段完成需要时间
    CH_E8AEA1E7AE97E697B6E997B4E5B9B6E5B195E7A4BA_(CH_E7BB88E69DA1E9878F_, mybar, speed,0)
End Sub


Sub CH_E8AEA1E7AE97E697B6E997B4E5B9B6E5B195E7A4BA_(allbar As Integer, nowbar As Integer, speed As Integer, idx As Integer)
   Dim CH_E589A9E4BD99E69DA1E5AD90E695B0_      As Integer
   Dim CH_E589A9E4BD99E5A49AE5B091E4B8AA_5CH_E58886E9929F_ As Integer
   Dim CH_E68980E99C80E697B6E997B4_(1)     As Integer
   CH_E589A9E4BD99E69DA1E5AD90E695B0_          = allbar - nowbar
   CH_E589A9E4BD99E5A49AE5B091E4B8AA_5CH_E58886E9929F_     = (CH_E589A9E4BD99E69DA1E5AD90E695B0_+speed-1)\ speed
   CH_E68980E99C80E697B6E997B4_(0)         = (CH_E589A9E4BD99E5A49AE5B091E4B8AA_5CH_E58886E9929F_ * 5) \ 60   ' hour
   CH_E68980E99C80E697B6E997B4_(1)         = (CH_E589A9E4BD99E5A49AE5B091E4B8AA_5CH_E58886E9929F_ * 5) Mod 60 'min
   CH_E69DA1E5AD90E8AEA1E7AE97_.CH_E5B195E7A4BAE697B6E997B4_(idx).Caption = Format(CH_E68980E99C80E697B6E997B4_(0), "00") & "时"& Format(CH_E68980E99C80E697B6E997B4_(1), "00") & "分"
End Sub





