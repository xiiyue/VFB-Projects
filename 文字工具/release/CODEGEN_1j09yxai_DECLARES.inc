'-----------------------------------------------------------------------------
' 由 VisualFreeBasic 5.9.8 生成的源代码
' 生成时间：2026年03月21日 20时16分03秒
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

Declare Function MsgBox Overload(CH_E68F90E7A4BAE69687E69CAC_ As WString , CH_E98089E9A1B9_ As ULong = MB_OK, CH_E6A087E9A298E69687E69CAC_ As WString = App.ProductName , CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND = AfxGetHwndFromPID(GetCurrentProcessId)) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|358]
Declare Function MsgBox Overload(CH_E68F90E7A4BAE69687E69CAC_ As String , CH_E98089E9A1B9_ As ULong = MB_OK, CH_E6A087E9A298E69687E69CAC_ As String = App.ProductName , CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND = AfxGetHwndFromPID(GetCurrentProcessId)) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|363]
Declare Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As WString, CH_E6A087E9A298E69687E69CAC_ As WString = App.ProductName , CH_E98089E9A1B9_ As ULong = MB_OK) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|368]
Declare Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As String, CH_E6A087E9A298E69687E69CAC_ As String = App.ProductName , CH_E98089E9A1B9_ As ULong = MB_OK) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|373]
Declare Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As WString, CH_E98089E9A1B9_ As ULong ) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|378]
Declare Function MsgBox Overload(CH_E788B6E7AA97E58FA3E58FA5E69F84_ As HWND, CH_E68F90E7A4BAE69687E69CAC_ As String, CH_E98089E9A1B9_ As ULong ) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|384]
Declare Function MsgBox Overload( CH_E68F90E7A4BAE69687E69CAC_ As String, CH_E6A087E9A298E69687E69CAC_ As String,ByVal CH_E98089E9A1B9_ As Integer=0,ByVal  CH_E788B6E7AA97E58FA3E58FA5E69F84_ As Hwnd = 0 ) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|390]
Declare Function StrToWStr(sStr As String, CodePage As UINT = CP_ACP) As String '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|399]
Declare Function wStrToStr(WStrPtr As Wstring Ptr, WStrLen As Long = 0, CodePage As UINT = CP_ACP) As String '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|418]
Declare Function DpiScaleI(xy As Long) As Long '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|431]
Declare Function DpiUnScaleI(xy As Long) As Long '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|442]
Declare Sub DrawLine(ByVal hDC as hDC, ByVal X1 as Integer, ByVal Y1 as Integer, ByVal X2 as Integer, ByVal Y2 as Integer, _ '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|465]
ByVal nPenStyle as Integer, ByVal nWidth as Integer, ByVal crColor as Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|466]
Declare Sub DrawFrame(DC as hDC, X1 as Long, Y1 as Long, X2 as Long, Y2 as Long, C as Long, L as Long = PS_NULL, cL as Long = 0, wL as Long = 1) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|496]
Declare Sub DrawCircleFrame(ByVal sDC as hDC, ByVal X as Long, ByVal Y as Long, ByVal hWidth as Long, ByVal hHeight as Long, ByVal xCircle as Long, ByVal yCircle as Long, _ '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|537]
ByVal LineWidth as Long, ByVal LineType as Long , ByVal bColor as Long, ByVal tColor as Long) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|538]
Declare Sub DrawEllipse(ByVal hDC as hDC, ByVal X as Integer, ByVal Y as Integer, ByVal hWidth as Integer, ByVal hHeight as Integer, _ '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|590]
ByVal LineType as Integer ,ByVal LineWidth as Integer, ByVal bColor as  Integer , ByVal tColor as  Integer ) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|591]
Declare Function GetTextWidth(ByVal DC as hDC, nText as String) as Long '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|634]
Declare Function GetTextHeight(ByVal DC as hDC, nText as String) as Long '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|641]
Declare Function LenW(wszStr As StringW) As Integer '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|647]
Declare Sub FF_Redraw(HWND_F as HWnd ) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|652]
Declare Function DpiScaleF(xy As Single) As Single '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\release\CODEGEN_1j09yxai_UTILITY.inc|659]

#include Once "yGDI.inc"
#include Once "Form\ClsForm_e.inc"
#include Once "ClsControl.inc"
#include Once "ClsVirtualCl.inc"

#include Once "ComboBox\ClsComboBox_e.inc"

#include Once "Button\ClsButton_e.inc"

#include Once "Frame\ClsFrame_e.inc"

#include Once "Label\ClsLabel_e.inc"


Type ProcessFuncWithInt As Function(ByVal txt As String, ByVal i As Integer) As String '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|85]
Type Form1_Class_Form Extends Class_Form
    Combo_CH_E7ACA6E58FB7E5AFB9_ As Class_ComboBox
    Command_CH_E7AE80E7B981_ As Class_Button
    Frame1 As Class_Frame
    Label1 As Class_Label
   Declare Function Show(hWndParent As .hWnd =HWND_DESKTOP,Modal As Boolean = False ,UserData As Integer = 0) As .hWnd '加载窗口并且显示, 模态显示用True {2.True.False} UserData 是传递给创建事件的参数，不保存数值
End Type
Dim Shared gFLY_FontNames() As String ,gFLY_FontHandles() As HFONT
DimP CH_E7ACA6E58FB7E5AFB9_(...) As ZString*12 = {"符号对{xx}","中“”", """", "中‘’", "''", "中《》", "<>", "中【】", "[]", "中「」", "{}", "中（）", "()"} '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_init.Inc|1]
DimP g_hHook As HWINEVENTHOOK '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|1]
DimP g_hWndCurrent As HWND      ' 当前前台窗口 '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|2]
DimP g_hWndLast As HWND          ' 上一次的前台窗口（即我们需要的原窗口） '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|3]
Dim Shared Form1 As Form1_Class_Form


Declare Function FF_PUMPHOOK( uMsg As Msg ) As Long '[FILE:#FF_PumpHook#|0]
Declare Function FF_WINMAIN(ByVal hInstance As HINSTANCE) As Long '[FILE:#FF_WinMain#|0]
Declare Sub FF_WINEND(ByVal hInstance As HINSTANCE) '[FILE:#FF_WinMain#|18]
Declare Sub Init_CH_E7ACA6E58FB7E5AFB9_() '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_init.Inc|4]
Declare Sub MyWinEventProc stdcall(ByVal hHook As HWINEVENTHOOK, ByVal Event As DWORD, ByVal hwnd As hwnd, ByVal idObject As Long, ByVal idChild As Long, ByVal dwEventThread As DWORD, ByVal dwmsEventTime As DWORD) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|6]
Declare Function GetSelectedText() As String '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|17]
Declare Sub ReplaceSelectedText(newText As String) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|58]
Declare Sub ProcessSelectedText(processFunc As Function(ByVal txt As String) As String) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|74]
Declare Sub ProcessSelectedTextWithInt(processFunc As ProcessFuncWithInt, i As Integer) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|86]
Declare Function GetSymbolPair(idx As Integer, ByRef leftSym As String, ByRef rightSym As String) As Boolean '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|99]
Declare Function InsertSymbolPair(oldtext As WString, idx As Integer) As String '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|144]
Declare Function ConvertChinese(oldtext As String) As String '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\modules\Module_Fuc.Inc|154]
Declare Function Form1_FORMPROCEDURE(ByVal hWndForm As hWnd, ByVal wMsg As UInteger, ByVal wParam As wParam, ByVal lParam As lParam) As LResult '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\forms\Form1.frm|-289]
Declare Function Form1_CODEPROCEDURE(ByVal hWndControl As HWND, ByVal wMsg As uInteger, ByVal wParam As WPARAM, ByVal lParam As LPARAM) As LRESULT '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\forms\Form1.frm|-60]
Declare Sub Form1_Shown(hWndForm As hWnd, UserData As Integer) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\forms\Form1.frm|2]
Declare Sub Form1_WM_Destroy(hWndForm As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\forms\Form1.frm|15]
Declare Sub Form1_Combo_CH_E7ACA6E58FB7E5AFB9__CBN_SelChange(hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\forms\Form1.frm|23]
Declare Sub Form1_Command_CH_E7AE80E7B981__BN_Clicked(hWndForm As hWnd, hWndControl As hWnd) '[FILE:D:\XYDrive\IDE\VFB\Projects\文字工具\forms\Form1.frm|33]
