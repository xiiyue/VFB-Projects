'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.9.8 生成的源代码
' 生成时间：2026年03月18日 21时50分16秒
' 更多信息请访问 www.yfvb.com 
'-----------------------------------------------------------------------------

' 这里是全局定义源码，所有type、全局变量、函数定义 都在此处。
#include Once "Afx/CGdiPlus/CGdiPlus.inc"
#include Once "afx\CWindow.inc"
'Type FormControlsPro_TYPE '保存控件的私有属性，每个控件都不同，全部在此，各取所需。
'   hWndParent     As hWnd       '父窗口句柄
'   nName          As String     '名称\1\用来代码中识别对象的名称\Command\
'   Index          As Long       '控件数组索引，小于零表示非控件数组
'   IDC            As Long       '
'   CtrlFocus      As HWND       ' 当前焦点在什么控件
'   BigIcon        As HICON      '窗口大图标，主要用来主窗口
'   SmallIcon      As HICON      '窗口小图标
'   nText          as CWSTR      '
'   ControlType    as Long       '控件类型，为了画控件  >=100 为虚拟控件  100=LABEL   TEXT=1 Button=2
'   nData          As String     '编写控件使用，数据存放，无特定，控件根据自己需要存放任意数据。
'   CtlData(99)    As Integer    '为每个控件提供 100 个数据储存(编写控件使用，控件根据自己需要存放任意数据)。
'   UserData(99)   As Integer    '为每个控件提供 100 个数据储存(用户使用)。
'   Style          as UInteger   '样式，每个控件都有自己的定义
'   TransPer       As Long       '透明度\0\窗口透明度，百分比(0--100)，0%不透明 100%全透明\0\
'   TransColor     As Long = &H197F7F7F  '透明颜色\3\透明颜色，需要用 GetCodeColorGDI 或 GetCodeColorGDIplue 转为 GDI 和 GDI+ 颜色值
'   MousePointer   As Long               '指针\2\鼠标在窗口上的形状\0 - 默认,1 - 后台运行,2 - 标准箭头,3 - 十字光标,4 - 箭头和问号,5 - 文本工字光标,6 - 不可用禁止圈,7 - 移动,8 - 双箭头↙↗,9 - 双箭头↑↓,10 - 双箭头向↖↘,11 - 双箭头←→,12 - 垂直箭头,13 - 沙漏,14 - 手型
'   ForeColor      As Long = &H197F7F7F  '文字色 需要用 GetCodeColorGDI 或 GetCodeColorGDIplue 转为 GDI 和 GDI+ 颜色值
'   BackColor      As Long = &H197F7F7F  '背景色 需要用 GetCodeColorGDI 或 GetCodeColorGDIplue 转为 GDI 和 GDI+ 颜色值
'   hBackBrush     As HBRUSH             '背景刷子，返回给窗口和控件用
'   nFont          As String                   '字体\4\用于此对象的文本字体。\微软雅黑,9,0\
'   Tag            As CWSTR                    ' 附加 \ 1 \ 私有自定义文本与控件关联。 \ \
'   ToolTip        As CWSTR                    ' 提示 \ 1 \ 一个提示，当鼠标光标悬停在控件时显示它。 \ \
'   ToolTipBalloon As Long                     ' 气球样式 \ 2 \ 一个气球样式显示工具提示。 \ False \ True, False
'   ToolWnd        As HWND                     '提示窗口句柄，用来销毁
'   nCursor        As HCURSOR                  '鼠标指针句柄
'   nLeft          As Long                     '返回/设置相对于父窗口的 X 响应DPI数值，为 100%DPI数值（像素）
'   nTop           As Long                     '返回/设置相对于父窗口的 Y 响应DPI数值，为 100%DPI数值（像素）
'   nWidth         As Long                     '返回/设置控件宽度 响应DPI数值，为 100%DPI数值（像素）
'   nHeight        As Long                     '返回/设置控件高度 响应DPI数值，为 100%DPI数值（像素））
'   anchor         AS LONG                     '控件布局 自动调整方式
'   nRight         As Long                     '控件布局 用，相对于窗口右边距离 响应DPI数值，为 100%DPI数值（像素））
'   nBottom        As Long                     '控件布局 用，相对于窗口底边距离 响应DPI数值，为 100%DPI数值（像素））
'   centerX        AS LONG                     '控件布局 用 中点  响应DPI数值，为 100%DPI数值（像素）
'   centerY        AS LONG                     '控件布局 用
'   VrControls     As FormControlsPro_TYPE ptr '如果是主窗口带 虚拟控件 ，就是下一个虚拟控件链表指针，直到为 0 表示没了
'End Type




Declare Function gFLY_GetFontHandles(mFont As String) As HFONT
Declare Function GetCodeColorGDI(coColor As Long,defaultColor As Long =-1) As Long
Declare Function GetCodeColorGDIplue(coColor As Long,defaultColor As Long =0) As Long
Declare Function FF_AddTooltip(hWndForm AS HWND, strTooltipText AS wString, bBalloon AS Long, X as Long = 0, Y As Long = 0, W As Long = 0, H As Long = 0) As HWND
Declare Sub FLY_VFB_Layout_hWndForm(hWndForm As HWND) 
Declare Sub FLY_VFB_Layout_Handle(fp As FormControlsPro_TYPE ptr, pWidth AS LONG, pHeight AS LONG, nWidth AS LONG, nHeight AS LONG, ByRef x AS LONG, ByRef y AS LONG, ByRef xWidth AS LONG, ByRef yHeight AS LONG)

Declare Function DpiScaleI(xy As Long) As Long '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|351]
Declare Function DpiUnScaleI(xy As Long) As Long '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|362]
Declare Sub DrawLine(ByVal hDC as hDC, ByVal X1 as Integer, ByVal Y1 as Integer, ByVal X2 as Integer, ByVal Y2 as Integer, _ '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|385]
ByVal nPenStyle as Integer, ByVal nWidth as Integer, ByVal crColor as Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|386]
Declare Sub DrawFrame(DC as hDC, X1 as Long, Y1 as Long, X2 as Long, Y2 as Long, C as Long, L as Long = PS_NULL, cL as Long = 0, wL as Long = 1) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|416]
Declare Sub DrawCircleFrame(ByVal sDC as hDC, ByVal X as Long, ByVal Y as Long, ByVal hWidth as Long, ByVal hHeight as Long, ByVal xCircle as Long, ByVal yCircle as Long, _ '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|457]
ByVal LineWidth as Long, ByVal LineType as Long , ByVal bColor as Long, ByVal tColor as Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|458]
Declare Sub DrawEllipse(ByVal hDC as hDC, ByVal X as Integer, ByVal Y as Integer, ByVal hWidth as Integer, ByVal hHeight as Integer, _ '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|510]
ByVal LineType as Integer ,ByVal LineWidth as Integer, ByVal bColor as  Integer , ByVal tColor as  Integer ) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|511]
Declare Function GetTextWidth(ByVal DC as hDC, nText as String) as Long '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|554]
Declare Function GetTextHeight(ByVal DC as hDC, nText as String) as Long '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|561]
Declare Function LenW(wszStr As StringW) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|567]
Declare Sub FF_Redraw(HWND_F as HWnd ) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\release\CODEGEN_kz0699v9_UTILITY.inc|572]

#include Once "yGDI.inc"
#include Once "Form\ClsForm_e.inc"
#include Once "ClsControl.inc"
#include Once "ClsVirtualCl.inc"

#include Once "Label\ClsLabel_e.inc"

#include Once "Timer\ClsTimer_e.inc"

#include Once "Button\ClsButton_e.inc"

#include Once "Line\ClsLine_e.inc"

#include Once "ComboBox\ClsComboBox_e.inc"

#include Once "TextBox\ClsTextBox_e.inc"

#include Once "UpDown\ClsUpDown_e.inc"


Type Form1_Class_Form Extends Class_Form
    CH_E58092E8AEA1E697B6_(2) As Class_Label
    CH_E58F91E5A3B0E8AEA1E697B6E599A8_ As Class_Timer
    CH_E590AFE58AA8_(2) As Class_Button
    Timer1 As Class_Timer
    CH_E5878FE697B6_(2) As Class_Button
    CH_E58AA0E697B6_(2) As Class_Button
    CH_E7899BE5A0A1E7AA97E58FA3_ As Class_Button
   Declare Function Show(hWndParent As .hWnd =HWND_DESKTOP,Modal As Boolean = False ,UserData As Integer = 0) As .hWnd '加载窗口并且显示, 模态显示用True {2.True.False} UserData 是传递给创建事件的参数，不保存数值
End Type
Type CH_E69DA1E5AD90E8AEA1E7AE97__Class_Form Extends Class_Form
    CH_E59BBAE5AE9AE69687E5AD97_(5) As Class_Label
    Line1 As Class_Line
    CH_E998B6E6AEB5E98089E68BA9_ As Class_ComboBox
    CH_E8BF9BE5BAA6E98089E68BA9_ As Class_ComboBox
    CH_E69DA1E5AD90E8BE93E585A5_ As Class_TextBox
    UpDown1 As Class_UpDown
    CH_E9809FE5BAA6E8BE93E585A5_ As Class_TextBox
    CH_E5B195E7A4BAE697B6E997B4_(1) As Class_Label
    CH_E8AEA1E7AE97E68C89E992AE_ As Class_Button
   Declare Function Show(hWndParent As .hWnd =HWND_DESKTOP,Modal As Boolean = False ,UserData As Integer = 0) As .hWnd '加载窗口并且显示, 模态显示用True {2.True.False} UserData 是传递给创建事件的参数，不保存数值
End Type
Dim Shared gFLY_FontNames() As String ,gFLY_FontHandles() As HFONT
Dim Shared Form1 As Form1_Class_Form


Dim Shared bDragging As Boolean '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|2]
Dim Shared StartScreenX As Long, StartScreenY As Long   ' 鼠标按下时的屏幕坐标 '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|3]
Dim Shared FormLeftAtDrag As Long, FormTopAtDrag As Long ' 窗体按下时的位置 '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|4]
Dim Shared CH_E5889DE5A78BE58092E8AEA1E697B6_(1 To 3, 1 To 2) As Integer = _ '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|27]
{ _ '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|28]
{7, 30}, _ ' 初始倒计时(1,1) 和 (1,2) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|29]
{2, 10}, _ ' 初始倒计时(2,1) 和 (2,2) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|30]
{9, 50} _  ' 初始倒计时(3,1) 和 (3,2) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|31]
} '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|32]
Dim Shared CH_E59BBAE5AE9AE680BBE697B6E997B4_(1 To 3) As Double  '毫秒 '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|34]
Dim Shared CH_E4BDBFE794A8E680BBE697B6E997B4_(1 To 3) As Double  '毫秒 '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|35]
Dim Shared CH_E5BC80E5A78BE782B9_(1 To 3) As Double '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|36]
Dim Shared CH_E5B7A5E4BD9CE4B8AD_(1 To 3) As Boolean '默认false '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|37]
Dim Shared CH_E58F91E5A3B0_(1 To 3) As Boolean   'true=正在发声 '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|38]
Dim Shared CH_E69DA1E5AD90E8AEA1E7AE97_ As CH_E69DA1E5AD90E8AEA1E7AE97__Class_Form


DimP stage(6) As String '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|0]
DimP stageData(6, 2) As Integer = {{1, 100, 4}, {101, 220, 4}, {221, 395, 5}, {396, 595, 5}, {596, 820, 5}, {821, 1120, 6}, {1121, 1450, 6}} '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|8]
Declare Function FF_PUMPHOOK( uMsg As Msg ) As Long '[FILE:#FF_PumpHook#|0]
Declare Function FF_WINMAIN(ByVal hInstance As HINSTANCE) As Long '[FILE:#FF_WinMain#|0]
Declare Sub FF_WINEND(ByVal hInstance As HINSTANCE) '[FILE:#FF_WinMain#|18]
Declare Function Form1_FORMPROCEDURE(ByVal hWndForm As hWnd, ByVal wMsg As UInteger, ByVal wParam As wParam, ByVal lParam As lParam) As LResult '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|-336]
Declare Function Form1_CODEPROCEDURE(ByVal hWndControl As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LRESULT '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|-60]
Declare Sub StartDrag(ByVal hWndFrom As Long, ByVal xClient As Long, ByVal yClient As Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|8]
Declare Sub CH_E69BB4E696B0E58092E8AEA1E697B6E698BEE7A4BA_(i As Integer, CH_E698BEE7A4BAE697B6E997B4_ As Double) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|41]
Declare Sub CH_E9878DE7BDAEE58092E8AEA1E697B6_(i As Integer) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|54]
Declare Sub Form1_Shown(hWndForm As hWnd, UserData As Integer) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|68]
Declare Sub Form1_Timer1_WM_Timer(hWndForm As hWnd, wTimerID As Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|88]
Declare Sub Form1_CH_E590AFE58AA8__BN_Clicked(ControlIndex As Long, hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|124]
Declare Sub Form1_CH_E58F91E5A3B0E8AEA1E697B6E599A8__WM_Timer(hWndForm As hWnd, wTimerID As Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|150]
Declare Sub Form1_CH_E5878FE697B6__BN_Clicked(ControlIndex As Long, hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|162]
Declare Sub Form1_CH_E58AA0E697B6__BN_Clicked(ControlIndex As Long, hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|177]
Declare Sub Form1_CH_E7899BE5A0A1E7AA97E58FA3__BN_Clicked(hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|191]
Declare Sub Form1_WM_ContextMenu(hWndForm As hWnd, xPos As Long, yPos As Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|198]
Declare Sub Form1_WM_LButtonDown(hWndForm As hWnd, MouseFlags As Long, xPos As Long, yPos As Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|208]
Declare Sub Form1_WM_MouseMove(hWndForm As hWnd, MouseFlags As Long, xPos As Long, yPos As Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|218]
Declare Sub Form1_WM_LButtonUp(hWndForm As hWnd, MouseFlags As Long, xPos As Long, yPos As Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\Form1.frm|235]
Declare Function CH_E69DA1E5AD90E8AEA1E7AE97__FORMPROCEDURE(ByVal hWndForm As hWnd, ByVal wMsg As UInteger, ByVal wParam As wParam, ByVal lParam As lParam) As LResult '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|-303]
Declare Function CH_E69DA1E5AD90E8AEA1E7AE97__CODEPROCEDURE(ByVal hWndControl As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LRESULT '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|-60]
Declare Sub CH_E69DA1E5AD90E8AEA1E7AE97__Shown(hWndForm As hWnd, UserData As Integer) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|14]
Declare Sub CH_E69DA1E5AD90E8AEA1E7AE97__CH_E998B6E6AEB5E98089E68BA9__CBN_SelChange(hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|30]
Declare Sub CH_E69DA1E5AD90E8AEA1E7AE97__CH_E8AEA1E7AE97E68C89E992AE__BN_Clicked(hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|49]
Declare Sub CH_E8AEA1E7AE97E697B6E997B4E5B9B6E5B195E7A4BA_(allbar As Integer, nowbar As Integer, speed As Integer, idx As Integer) '[FILE:D:\XYDrive\IDE\VFB\Projects\牛子助手\forms\条子计算.Frm|77]
