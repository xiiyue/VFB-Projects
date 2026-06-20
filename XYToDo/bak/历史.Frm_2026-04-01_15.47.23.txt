#VisualFreeBasic_Form#  Version=5.9.10
Locked=0

[Form]
Name=历史
Help=False
ClassStyle=CS_VREDRAW,CS_HREDRAW,CS_DBLCLKS
ClassName=
WinStyle=WS_SYSMENU,WS_MINIMIZEBOX,WS_MAXIMIZEBOX,WS_VISIBLE,WS_EX_CONTROLPARENT,WS_EX_LEFT,WS_EX_LTRREADING,WS_EX_RIGHTSCROLLBAR,WS_CLIPSIBLINGS,WS_CLIPCHILDREN,WS_CHILD
Style=0 - 无边框
Icon=
Caption=历史记录
StartPosition=0 - 手动
WindowState=0 - 正常
Enabled=True
Repeat=False
Left=0
Top=0
Width=600
Height=370
TopMost=False
Child=True
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

[ListView]
Name=ListView1
Help=
Index=-1
Style=1 - 报表视图
BStyle=1 - 细边框
Theme=False
ImageNormalS=无图像列表控件
ImageSmallS=无图像列表控件
SingleSel=True
ShowSel=True
Sort=0 - 不排序
SortColumn=False
NoScroll=False
AutoArrange=False
EditLabels=False
OwnerData=False
AlignTop=False
AlignLeft=False
OwnDraw=False
ColumnHeader=True
ColumnEditor=任务||0|350|周期||2|80|次数||2|60|
NoSortHeader=False
BorderSelect=False
Check=False
FlatScrollBars=False
FullRowSelect=False
GridLines=False
HeaderDragDrop=False
InfoTip=False
LabelTip=False
MultiWorkAreas=False
OneClickActivate=False
Regional=False
SimpleSelect=False
SubItemImages=False
TrackSelect=False
TwoClickActivate=False
UnderlineCold=False
UnderlineHot=False
Enabled=True
Visible=True
ForeColor=SYS,8
BackColor=SYS,5
TextBkColor=SYS,5
Font=微软雅黑,9,0
Left=20
Top=60
Width=520
Height=120
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
Tab=True
ToolTip=
ToolTipBalloon=False
AcceptFiles=False

[Label]
Name=Label2
Help=
Index=-1
Style=0 - 无边框
Caption=周期任务记录
Enabled=True
Visible=True
ForeColor=SYS,8
BackColor=SYS,25
Font=微软雅黑,9,0
FontWidth=0
FontAngle=0
TextAlign=0 - 左对齐
Prefix=True
Ellipsis=False
Left=20
Top=30
Width=100
Height=20
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
ToolTip=
ToolTipBalloon=False

[Label]
Name=Label3
Help=
Index=-1
Style=0 - 无边框
Caption=归档普通任务记录
Enabled=True
Visible=True
ForeColor=SYS,8
BackColor=SYS,25
Font=微软雅黑,9,0
FontWidth=0
FontAngle=0
TextAlign=0 - 左对齐
Prefix=True
Ellipsis=False
Left=20
Top=200
Width=100
Height=20
Layout=0 - 不锚定
MousePointer=0 - 默认
Tag=
ToolTip=
ToolTipBalloon=False

[ListView]
Name=ListView2
Help=
Index=-1
Style=1 - 报表视图
BStyle=3 - 凹边框
Theme=False
ImageNormalS=无图像列表控件
ImageSmallS=无图像列表控件
SingleSel=True
ShowSel=True
Sort=0 - 不排序
SortColumn=False
NoScroll=False
AutoArrange=False
EditLabels=False
OwnerData=False
AlignTop=False
AlignLeft=False
OwnDraw=False
ColumnHeader=True
ColumnEditor=任务||0|350|完成时间||2|120|
NoSortHeader=False
BorderSelect=False
Check=False
FlatScrollBars=False
FullRowSelect=False
GridLines=False
HeaderDragDrop=False
InfoTip=False
LabelTip=False
MultiWorkAreas=False
OneClickActivate=False
Regional=False
SimpleSelect=False
SubItemImages=False
TrackSelect=False
TwoClickActivate=False
UnderlineCold=False
UnderlineHot=False
Enabled=True
Visible=True
ForeColor=SYS,8
BackColor=SYS,5
TextBkColor=SYS,5
Font=微软雅黑,9,0
Left=20
Top=230
Width=520
Height=110
Layout=0 - 不锚定
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
Caption=更新记录
TextAlign=1 - 居中
Ico=
Enabled=True
Visible=True
Default=False
OwnDraw=False
MultiLine=False
Font=微软雅黑,9,0
Left=430
Top=10
Width=100
Height=30
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

Sub ShowHistory()
   Dim js       As JSON
   Dim filePath As String
   filePath = App.Path & "data\archived_tasks.json"
   Dim i               As Long
   Dim taskname            As String
   Dim periodType      As Long
   Dim completionCount As Long
   Dim periodText      As String
   Dim finishTime      As Double
   
   ' 清空ListView（标题行已在设计时设置，不清除）
   ListView1.DeleteAllItems
   ListView2.DeleteAllItems
   
   ' 文件不存在则直接返回
   If Not FileExists(filePath) Then
      Exit Sub
   End If
   
   ' 加载JSON文件
   js.FileName = filePath
   
   ' 1. 加载周期任务归档（ListView1：任务、周期、次数）
   i = 0
   Do
      taskname = js.ValueStr("periodic\#" & i & "\Name")
      If taskname = "" Then Exit Do
      
      periodType      = CLng(js.ValueDouble("periodic\#" & i & "\periodType"))
      completionCount = CLng(js.ValueDouble("periodic\#" & i & "\completionCount"))
      
      ' 周期类型转换为中文
      Select Case periodType
         Case 1
            periodText = "日"
         Case 2
            periodText = "周"
         Case 3
            periodText = "月"
         Case 4
            periodText = "年"
         Case Else
            periodText = "无"
      End Select
      
      ' 添加一行到ListView1
      ListView1.AddItem(taskname)
      ListView1.SetItemText(i, 1, periodText)
      ListView1.SetItemText(i, 2, Str(completionCount))
      
      i = i + 1
   Loop
   
   ' 2. 加载普通任务归档（ListView2：任务、完成时间）
   i = 0
   Do
      taskname = js.ValueStr("regular\#" & i & "\Name")
      If taskname = "" Then Exit Do
      
      ' 读取完成时间（FinishTime）
      finishTime = js.ValueDouble("regular\#" & i & "\FinishTime")
      ' 格式化为年月日字符串
      Dim finishDateStr As String = Format(finishTime, "yyyy-mm-dd")
      
      ' 添加一行到ListView2
      ListView2.AddItem(taskname)
      ListView2.SetItemText(i, 1, finishDateStr)
      
      i = i + 1
   Loop
End Sub




'[历史]事件 : 窗口完全显示后。
'hWndForm  当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'UserData  来自显示窗口最后1个参数，例： Form2.Show(父窗口句柄,模式,UserData)
Sub 历史_Shown(hWndForm As hWnd, UserData As Integer)
   ShowHistory()
End Sub

'[历史.Command1]事件 : 单击
'hWndForm    当前窗口的句柄(WIN系统用来识别窗口的一个编号，如果多开本窗口，必须 Me.hWndForm = hWndForm 后才可以执行后续操作本窗口的代码)
'hWndControl 当前控件的句柄(也是窗口句柄，如果多开本窗口，必须 Me.控件名.hWndForm = hWndForm 后才可以执行后续操作本控件的代码 )
Sub 历史_Command1_BN_Clicked(hWndForm As hWnd, hWndControl As hWnd)
   ShowHistory()
End Sub



