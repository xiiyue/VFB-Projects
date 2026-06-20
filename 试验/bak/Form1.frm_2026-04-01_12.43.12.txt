#VisualFreeBasic_Form#  Version=5.9.10
Locked=0

[Form]
Name=Form1
Help=False
ClassStyle=CS_VREDRAW,CS_HREDRAW,CS_DBLCLKS
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
Width=420
Height=300
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

[Button]
Name=Command1
Help=
Index=-1
Caption=点我
TextAlign=1 - 居中
Ico=
Enabled=True
Visible=True
Default=False
OwnDraw=False
MultiLine=False
Font=微软雅黑,22
Left=140
Top=90
Width=100
Height=50
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
Tab=True
ToolTip=
ToolTipBalloon=False

[Label]
Name=Label1
Help=
Index=-1
Style=0 - 无边框
Caption=Label1
Enabled=True
Visible=True
ForeColor=SYS,8
BackColor=SYS,25
Font=微软雅黑,14
FontWidth=0
FontAngle=0
TextAlign=0 - 左对齐
Prefix=True
Ellipsis=False
Left=10
Top=20
Width=390
Height=40
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
ToolTip=
ToolTipBalloon=False

[Label]
Name=Label2
Help=
Index=-1
Style=0 - 无边框
Caption=Label2
Enabled=True
Visible=True
ForeColor=SYS,8
BackColor=SYS,25
Font=微软雅黑,14
FontWidth=0
FontAngle=0
TextAlign=0 - 左对齐
Prefix=True
Ellipsis=False
Left=10
Top=180
Width=360
Height=50
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
ToolTip=
ToolTipBalloon=False


[AllCode]
Function IsNewDay(lastTime As Double, currentTime As Double = 0) As Boolean
    Dim dayOffset As Double = 4 / 24   ' 4小时对应的OLE数值
    Dim cycleStartLast As Double
    Dim cycleStartCurr As Double
    
    If currentTime = 0 Then currentTime = Now()
    
    ' 计算每个时间点所在的周期起始时间（以凌晨4点为基准）
    cycleStartLast = Int(lastTime - dayOffset) + dayOffset
    cycleStartCurr = Int(currentTime - dayOffset) + dayOffset
    
    ' 如果当前周期起始大于上次周期起始，说明进入了新的一天
    Return (cycleStartCurr > cycleStartLast)
End Function

'[Form1.Command1]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub Form1_Command1_BN_Clicked(hWndForm As hWnd, hWndControl As hWnd)
   Dim a As Double =46107.125
   Dim b As Double = 46107.20833
   Print IsNewDay(a, b) & "|"
   a = 46107.2
   b = 46107.23
   Print IsNewDay(a, b) & "|"
   a = 46107.15 
   b = 46108.1 
   Print IsNewDay(a, b) & "|"
   a = 46107.17
   b = 46108.15
   Print IsNewDay(a, b) & "|"
   a = 46107.17 
   b = 46107.25
   Print IsNewDay(a, b) & "|"
   'Label1.Caption = 
   'Label2.Caption = 
   
End Sub

