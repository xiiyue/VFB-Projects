#VisualFreeBasic_Form#  Version=5.9.1
Locked=0

[Form]
Name=Form1
ClassStyle=CS_VREDRAW, CS_HREDRAW, CS_DBLCLKS
ClassName=
WinStyle=WS_THICKFRAME,WS_CAPTION,WS_SYSMENU,WS_MINIMIZEBOX,WS_MAXIMIZEBOX,WS_CLIPSIBLINGS,WS_CLIPCHILDREN,WS_VISIBLE,WS_EX_WINDOWEDGE,WS_EX_CONTROLPARENT,WS_EX_LEFT,WS_EX_LTRREADING,WS_EX_RIGHTSCROLLBAR,WS_POPUP,WS_SIZEBOX
Style=3 - 常规窗口
Icon=
Caption=Form1
StartPosition=1 - 屏幕中心
WindowState=0 - 正常
Enabled=True
Repeat=False
Left=0
Top=0
Width=500
Height=310
TopMost=False
Child=False
MdiChild=False
TitleBar=True
SizeBox=True
SysMenu=True
MaximizeBox=True
MinimizeBox=True
Help=False
Hscroll=False
Vscroll=False
MinWidth=0
MinHeight=0
MaxWidth=0
MaxHeight=0
NoActivate=False
MousePass=False
TransPer=0
TransColor=SYS,25
Shadow=0 - 无阴影
BackColor=SYS,15
MousePointer=0 - 默认
Tag=
Tab=True
ToolTip=
ToolTipBalloon=False
AcceptFiles=False

[MyDrawWin]
Name=MyDrawWin1
Caption=
Enabled=True
ButtonTop=False
ButtonMax=True
ButtonMin=True
ButtonClose=True
ButtonSkin=False
ButtonMenu=False
BorderTitle=24
BorderLR=3
BorderB=3
BorderColor=SYS,2
BorderColor2=SYS,3
Fillet=10
Left=80
Top=155
Tag=

[Button]
Name=Command1
Index=-1
Caption=&Pick
TextAlign=1 - 居中
Ico=
Enabled=True
Visible=True
Default=False
OwnDraw=False
MultiLine=False
Font=微软雅黑,9,0
Left=396
Top=223
Width=60
Height=28
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
Tab=True
ToolTip=
ToolTipBalloon=False


[AllCode]
'==================================================================================================================================
'这是旧版本窗口，需要自己人工修改和调整才能正常使用，主要更改项目：
'1）窗口和控件属性：全部需要自己人工重新调整，升级程序只是简单的转换。
'2）窗口和控件事件：升级程序会自动更新到新版的格式，无法保证100%正确，更加自己需要查证。
'3）窗口和控件句柄：新版没有句柄常量，需要用类，如：HWND_FORM1  改为 Form1.hWnd ， HWND_FORM1_PICTURE1 改为 Form1.Picture1.hWnd 
'4）窗口和控件IDC： 新版无IDC常量，需要用类，如：IDC_FORM1_PICTURE1 改为 Form1.Picture1.IDC
'5）新弹出窗口：Form2_Show  改为 Form2.Show 
'6）与字符有关的API：以前默认为 ANSI字符，现在是 Unicode字符，因此相关API 后面要加个 A 来解决，如：PostMessage 改为 PostMessageA ，或使用宽字符变量
'7）API操作控件和窗口，有关字符的，全部为 Unicode字符 ，类型是 CWSTR，CWSTR 不可以直接用在 Len Left Right Mid InStr UCase 等一系列字符操作语句上
'必须前面加个 ** 才能当成宽字符处理（英文中文都算1个字符）如： Len(**b) ,可以赋值到ANSI变量，会自动转换编码：dim a As String = b  (b 为 CWSTR ) 
'或者 Dim b As CWSTR = a  (a 为 String) ,因此用变量过度一下，没什么问题，就是不可以直接返回就用在语句上，如：Len(FF_Control_GetText(..)) 这是错的
'8）编译后的窗口和控件是 Unicode 的，旧版是 ANSI 的在英文系统中无法显示中文。可以用API IsWindowUnicode 检查窗口和控件是不是 Unicode
'9）所有窗口和控件由 CWindow Class 类创建，旧版是直接API创建，可以参考 WinFBX 帮助来查看 CW 的众多附加功能。
'最后预祝大家编程愉快，升级顺利。有任何问题可以在编程群里提问：Basic语言编程QQ群 78458582
'==================================================================================================================================
'这是标准的工程模版，你也可做自己的模版。
'写好工程，复制全部文件到VFB软件文件夹里【template】里即可，子文件夹名为 VFB新建工程里显示的名称
'快去打造属于你自己的工程模版吧。
'32位与64位切换，或其它方式，点击工具栏右边。
'--------------------------------------------------------------------------------
Sub Form1_WM_Create(hWndForm As hWnd,UserData As Integer)  '完成创建窗口及所有的控件后，此时窗口还未显示。注：自定义消息里 WM_Create 此时还未创建控件和初始赋值。

      Me.Caption =  App.EXEName  

End Sub


'                                                                                  
Sub Form1_Command1_BN_Clicked(hWndForm As hWnd, hWndControl As hWnd)  '单击

  Dim wszIconPath As String = App.Path & App.EXEName
  Dim nIconIndex As Long                  ' // Icon index
  Static hIcon As HICON                      ' // Icon handle
  
  '// Activate the Pick Icon Common Dialog Box
  Dim hr As Long = PickIconDlg(0, wszIconPath, SizeOf(wszIconPath), @nIconIndex)
  '// If an icon has been selected...
  If hr = 1 Then
      '// Destroy previously loaded icon, if any
      If hIcon Then DestroyIcon(hIcon)
      '// Get the handle of the new selected icon
      hIcon = ExtractIcon(App.HINSTANCE, wszIconPath, nIconIndex)
      Print wszIconPath, nIconIndex ,hIcon
      '// Replace the application icons
      If hIcon Then
          SendMessageW(hWndForm, WM_SETICON, ICON_SMALL, Cast(lParam, hIcon))
          SendMessageW(hWndForm, WM_SETICON, ICON_BIG, Cast(lParam, hIcon))
       End If
       'If hIcon Then DestroyIcon(hIcon)
  End If

End Sub

