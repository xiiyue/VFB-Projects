#VisualFreeBasic_Form#  Version=5.9.8
Locked=0

[Form]
Name=Form2
Help=False
ClassStyle=CS_DBLCLKS,CS_HREDRAW,CS_VREDRAW
ClassName=
WinStyle=WS_MAXIMIZEBOX,WS_MINIMIZEBOX,WS_SYSMENU,WS_VISIBLE,WS_EX_CONTROLPARENT,WS_EX_LEFT,WS_EX_LTRREADING,WS_EX_RIGHTSCROLLBAR,WS_EX_TOOLWINDOW,WS_EX_TOPMOST,WS_CLIPSIBLINGS,WS_CLIPCHILDREN,WS_POPUP
Style=0 - 无边框
Icon=
Caption=警告
StartPosition=0 - 手动
WindowState=0 - 正常
Enabled=True
Repeat=False
Left=0
Top=0
Width=211
Height=125
TopMost=True
Child=False
MdiChild=False
TitleBar=False
SizeBox=False
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
NoActivate=True
MousePass=False
TransPer=0
TransColor=SYS,25
Shadow=0 - 无阴影
BackColor=RGB(255,0,0)
MousePointer=0 - 默认
Tag=
Tab=True
ToolTip=
ToolTipBalloon=False
AcceptFiles=False

[Label]
Name=Label1
Help=
Index=-1
Style=0 - 无边框
Caption=该休息眼睛了
Enabled=True
Visible=True
ForeColor=SYS,8
BackColor=SYS,25
Font=霞鹜文楷 GB 屏幕阅读版 R,18,1
FontWidth=0
FontAngle=0
TextAlign=4 - 置中
Prefix=True
Ellipsis=False
Left=30
Top=10
Width=150
Height=40
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
ToolTip=
ToolTipBalloon=False

[Button]
Name=Command1
Help=
Index=-1
Caption=已  喝
TextAlign=1 - 居中
Ico=
Enabled=True
Visible=True
Default=False
OwnDraw=False
MultiLine=False
Font=霞鹜文楷 GB 屏幕阅读版 R,16,1
Left=30
Top=60
Width=150
Height=50
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
Tab=True
ToolTip=
ToolTipBalloon=False


[AllCode]
'这是标准的工程模版，你也可做自己的模版。
'写好工程，复制全部文件到VFB软件文件夹里【template】里即可，子文件夹名为 VFB新建工程里显示的名称
'快去打造属于你自己的工程模版吧。

'[Form2.Command1]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub Form2_Command1_BN_Clicked(hWndForm As hWnd, hWndControl As hWnd)
   F2Close = True
   Form2.Close 
End Sub






